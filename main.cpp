#include <iostream> //Libreria que son de entrada y salida
#include <iomanip> //Libreria que permite manipular la intefaz
#include<cstdlib> //Nos permite gestionar la memoria dinamicamente y generar numeros
                //aleatorios(que es para lo que la usamos en este progama)
#include <windows.h>////Es una libreria  que contiene las declaraciones de todas las funcionees
                    //de  la biblioteca Windows API.
#include <string> //Nos sirve para manipular arreglos y strings
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

void desplegarMenu(); //Esta función nos permite desplegar el menú.

void Singleplayer(); //Cuando se presiona 1 en el menú, nos lleva a la función SinglePlayer
void Multiplayer(); //Cuando presionamos 2 en el menú, nos lleva a la función MultiPlayer
void color(int X); //Ésta función hace referencia a un comando que nos permite cambiar el color de las letras dependiendo de donde se selccione
void playerturn (int&,int&); //Ésta función hace referencia a cuando le toca jugar a la persona,
                                    //En caso de que sea Multiplayer la función se llamará 2 veces
                                    // y si es singleplayer solo una vez.
void computerturn(int&,int&,int&,int,int);//Ésta función se llama cuando se selecciona singleplayer.

const int NUMFILAS=6;
const int NUMCOLAS=6;
int matrizJugador[NUMFILAS][NUMCOLAS]={0};
int matrizEnemigo[NUMFILAS][NUMCOLAS]={0};
int matrizOculta[NUMFILAS][NUMCOLAS]={0};
int matrizJugador2[NUMFILAS][NUMCOLAS]={0};

int posBarco1[3]={2,2,2};
int posBarco2[2]={2,2};
int posBarco3[2]={2,2};
int posBarco4[1]={2};
int posEnemigo1[3]={2,2,2};
int posEnemigo2[2]={2,2};
int posEnemigo3[2]={2,2};
int posEnemigo4[1]={2};
int k=0, x=1, y=1, y1=0, x1=0;
int orientacion= 0;

void imprimirPantalla();
void posicionarBarco1(int &k);
void posicionarBarco2(int &k);
void posicionarBarco3(int &k);
void posicionarBarco4(int &k);
void ponerBarcos();
void darcoordenadas1(int &orientacion, int &x, int &y);

int main()
{
   int op=0; //Aquí se inicializa Op, que es la operación que seleccionará el usuario en el menú

    while(op!=3) //Mientras op sea diferente de 3, se mostrará lo siguiente:
    {
        desplegarMenu(); //Se llama a la función desplegarMenu
        cin>>op;        //Se introduce la operación que se quiere realizar
        if(op>0&&op<4) //Si el usuario inserta un numero que esté fuera de rango, se seguirá desplegando el menú
                        //hasta que inserte una opción correcta que se menciona abajo.
        {
        switch(op)   //Un Switch para las operaciones disnopibles para realizar
        {
        case 1:                 //En el caso 1, se llama a la función system("cls") la cuál limpia la pantalla dependiendo de donde
            system("cls");      //y después se llama a la función SinglePlayer.
            Singleplayer();
            break;
        case 2:                 // En el caso 2, al igual que en el pasado, está la función system("cls"), y después se llama a la función
            system("cls");     //y después se llama a la función Multiplayer.
            Multiplayer();
            break;
        case 3:                //En el caso 3, tenemos la misma función system("cls"). Y un cout con Off, el cuál termina el programa
            system("cls");
            cout<<"Off"<<endl;
            break;
        }
        }
    if(op<1||op>3)              //Cuando se selecciona una opción fuera de rango, como se había mencionado antes. Te pide que ingreses
        {                       //una opción válida
            system("cls");
            color(4);
            cout<<endl<<"\tINGRESE UNA OPCION CORRECTA"<<endl;
        }
    }
  
  imprimirPantalla();
  
  
  
return 0;//AQUI ACABA MAIN----------------------------------------------------------------------------------------------------
}

void desplegarMenu(void)
{
    color(48); //Esta línea nos permite cambiar el color de rápida
    cout<<("\n");
    cout<<("\t    PixelShip");  //Todo este texto es la imagen de inicio del menú
    cout<<("\n");
    color(15);  //Aquí se cambia de color otra vez
    cout<<("\t\t$\t\t\t\n\t\t$|\n\t\t$|$\n\t\t$|$$\n\t\t$|$$$\n\t\t$|$$$$");
    cout<<("\n\t\t |\n\t\t |");
    color(14);  //Aqui cambiamos de color otra vez
    cout<<("\n\t$$$$$$$$$$$$$$$$$$$$$$$$$\n\t -----------------------");            //Al igual que lo anterior, esto forma parte de la imagen de inicio
    cout<<("\n\t  $$$$/)$$$$$$$$$$$$$$$\n\t~~$$$(/$$$$$$$$$$$$$$~\n\t~$$$$$$$$$$$$$$$$$~~");
    cout<<("\n\t~~~~~~~~~\n\t~~~~~~~~~");
    color(8);  //Otro color que cambiamos
    cout<<("\n\n\t1- Un Jugador\n\n\t2- Multijugador\n\n\t3- Salir\n\n\tIntroduce una opción:");
}

void imprimirPantalla()
{
    cout<<setw(5)<<"1"<<setw(4)<<"2"<<setw(4)<<"3"<<setw(4)<<"4"<<setw(4)<<"5"<<setw(4)<<"6";
    for(int i=0;i<NUMFILAS;i++)
    {
        cout<<endl<<i+1;
        for(int j=0;j<NUMCOLAS;j++)
            cout<<setw(4)<<matrizJugador2[i][j];
    }
    cout<<"\n------------------------------------\n";
    cout<<setw(5)<<"1"<<setw(4)<<"2"<<setw(4)<<"3"<<setw(4)<<"4"<<setw(4)<<"5"<<setw(4)<<"6";
    for(int i=0;i<NUMFILAS;i++)
    {
        cout<<endl<<i+1;
        for(int j=0;j<NUMCOLAS;j++)
            cout<<setw(4)<<matrizJugador[i][j];
    }
}

void posicionarBarco1(int &k)
{
    cout<<"\n\nPosiciona el barco #1 (3 espacios)\n";
    darcoordenadas1(orientacion,x,y);
    if (orientacion)
    {
        do
        {
            cout<<"dame x2\n";
            cin>>x1;
            x1--;
        }
        while(!(x-x1==2 || x-x1==-2));
        if(x-x1==-2)
        {
            for(int i=0; i<3;i++)
            {
                matrizJugador[y][x+i]=posBarco1[i];
            }
        }
        else
        {
            for(int i=0; i<3;i++)
            {
                matrizJugador[y][x-i]=posBarco1[i];
            }
        }
    }
    else
    {
        do
        {
            cout<<"dame y2\n";
            cin>>y1;
            y1--;
        }
        while(!(y-y1==2 || y-y1==-2));
        if(y-y1==-2)
        {
            for(int i=0; i<3;i++)
            {
                matrizJugador[y+i][x]=posBarco1[i];
            }
        }
        else
        {
            for(int i=0; i<3;i++)
            {
                matrizJugador[y-i][x]=posBarco1[i];
            }
        }
    }
    system("cls");
}

void posicionarBarco2(int &k)
{
    cout<<"\n\nPosiciona el barco #2 (2 espacios)\n";
    darcoordenadas1(orientacion,x,y);
    if (orientacion)
    {
        do
        {
            cout<<"dame x2\n";
            cin>>x1;
            x1--;
        }
        while(!(x-x1==1 || x-x1==-1));
        if(x-x1==-1)
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y-1][x+1]==0)
                {
                    matrizJugador[y][x]=posBarco2[0];
                    matrizJugador[y][x+1]=posBarco2[1];
                }
                else
                    k--;
        }
        else
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y][x-1]==0)
                {
                    matrizJugador[y][x]=posBarco2[0];
                    matrizJugador[y][x-1]=posBarco2[1];
                }
                else
                    k--;
        }
    }
    else
    {
        do
        {
            cout<<"dame y2\n";
            cin>>y1;
            y1--;
        }
        while(!(y-y1==1 || y-y1==-1));
        if (y-y1==-1)
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y+1][x]==0)
                {
                    matrizJugador[y][x]=posBarco2[0];
                    matrizJugador[y+1][x]=posBarco2[1];
                }
                else
                    k--;
        }
        else
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y-1][x]==0)
                {
                    matrizJugador[y][x]=posBarco2[0];
                    matrizJugador[y-1][x]=posBarco2[1];
                }
                else
                    k--;
        }
    }
    system("cls");
}

void posicionarBarco3(int &k)
{
    cout<<"\n\nPosiciona el barco #3 (2 espacios)\n";	
		//Esta función recibe una variable entera pero desde la dirección
    darcoordenadas1(orientacion,x,y);
    if (orientacion)
    {
        do
        {
            cout<<"dame x2\n";
            cin>>x1;
            x1--;
        }
        while(!(x-x1==1 || x-x1==-1));
        if (x-x1==-1)
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y][x+1]==0)
                {
                    matrizJugador[y][x]=posBarco3[0];
                    matrizJugador[y][x+1]=posBarco3[1];
                }
                else
                    k--;
        }
        else
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y][x-1]==0)
                {
                    matrizJugador[y][x]=posBarco3[0];
                    matrizJugador[y][x-1]=posBarco3[1];
                }
                else
                    k--;
        }
    }
    else
    {
        do
        {
            cout<<"dame y2\n";
            cin>>y1;
            y1--;
        }
        while(!(y-y1==1 || y-y1==-1));
        if(y-y1==-1)
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y+1][x]==0)
                {
                    matrizJugador[y][x]=posBarco3[0];
                    matrizJugador[y+1][x]=posBarco3[1];
                }
                else
                    k--;
        }
        else
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y-1][x]==0)
                {
                    matrizJugador[y][x]=posBarco3[0];
                    matrizJugador[y-1][x]=posBarco3[1];
                }
                else
                    k--;
        }

    }
    system("cls");
}

void posicionarBarco4(int &k)
{
    cout<<"\n\nPosiciona el barco #4 (1 espacio)\n";
    darcoordenadas1(orientacion,x,y);
    if (matrizJugador[y][x]==0)
        matrizJugador[y][x]=posBarco4[0];
    else
        k--;
    system("cls");
}

void darcoordenadas1(int &orientacion, int &x, int &y)
{
    cout<<"\nHORIZONTAL(1) O VERTICAL(0)\n";
    cin>>orientacion;
    do{
    cout<<"dame x1\n";
    cin>>x;
    cout<<"dame y1\n";
    cin>>y;
    if (!((x<=6 && x>=1) && (y<=6 && y>=1) && (orientacion==1 || orientacion==0)))
        cout<<"Coordenada fuera de rango\n";
    }
    while(!((x<=6 && x>=1) && (y<=6 && y>=1) && (orientacion==1 || orientacion==0)));
    x--;
    y--;
}

void Singleplayer(void)
{
    cout<<"Se seleccionó el modo singleplayer"<<endl;
    imprimirpantalla();
    ponerBarcos();
    int first_to_go=0, boats_sunk1 =8,boats_sunk2 =8,x=0,y=0,lasthitcomx=0,lasthitcomy=0,lasthitcompturn=0,
    srand(time(0));
    first_to_go=rand() % 2+1;
    for(int i =0;i<72;i++){//limit 72 due to number of possilbe turnsorhits
      if(boats_sunk1==0||boats_sunk2==0)
        i=72;
        if(first_to_go==1){
            playerturn(x,y);//func to set coord og shoot
            if((matrizEnemigo[x][y]%2)==0){//if water or boat increase value by one to chage to miss ot hit
                matrizEnemigo[x][y]++;
                if(matrizEnemigo[x][y]==3){
                    cout<<"\nhit\n";//of hit, says and reduces boats leaf to win and turn-- do it doesnt count the free hit as a turn
                    boats_sunk1--;
                    continue;
                }
                else{
                    cout<<"\nmixx\nnext2\n";
                    first_to_go++;
                }
            }
            else if((matrizEnemigo[x][y]%2)==1){
                cout<<"\nalredy fired there\n";
                continue;
            }
        }
        else if(first_to_go==2){
            computerturn(x,y,lasthitcompturn,lasthitcomx,lasthitcomy);
            if((matrizJugador[x][y]%2)==0){
                matrizJugador[x][y]++;
                if(matrizJugador[x][y]==3){
                    cout<<"\nhit\n";
                    boats_sunk2--;
                    continue;
                }
                else{
                    cout<<"\nmiss\nnext1\n";
                    first_to_go--;
                }
            }
            else if((matrizJugador[x][y]%2)==1){
                cout<<"\naleady fired there\n";
                continue;
            }
        }
    }
}
void Multiplayer(void)
{
    cout<<"Se seleccionó el modo multiplayer"<<endl;
    int first_to_go=0, boats_sunk1 =8,boats_sunk2 =8,x=0,y=0,lasthitcomx=0,lasthitcomy=0,lasthitcompturn=0,
    srand(time(0));
    first_to_go=rand() % 2+1;
    for(int i =0;i<72;i++){//limit 72 due to number of possilbe turnsorhits
      if(boats_sunk1==0||boats_sunk2==0)
        i=72;
        if(first_to_go==1){
            playerturn(x,y);//func to set coord og shoot
            if((matrizEnemigo[x][y]%2)==0){//if water or boat increase value by one to chage to miss ot hit
                matrizEnemigo[x][y]++;
                if(matrizEnemigo[x][y]==3){
                    cout<<"\nhit\n";//of hit, says and reduces boats leaf to win and turn-- do it doesnt count the free hit as a turn
                    boats_sunk1--;
                    continue;
                }
                else{
                    cout<<"\nmixx\nnext2\n";
                    first_to_go++;
                }
            }
            else if((matrizEnemigo[x][y]%2)==1){
                cout<<"\nalredy fired there\n";
                continue;
            }
        }
        else if(first_to_go==2){
            playerturn(x,y);
            if((matrizJugador[x][y]%2)==0){
                matrizJugador[x][y]++;
                if(matrizJugador[x][y]==3){
                    cout<<"\nhit\n";
                    boats_sunk2--;
                    continue;
                }
                else{
                    cout<<"\nmiss\nnext1\n";
                    first_to_go--;
                }
            }
            else if((matrizJugador[x][y]%2)==1){
                cout<<"\naleady fired there\n";
                continue;
            }
        }
    }
}

void color(int X)
{
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}
void computerturn(int&x,int&y,int&lasthitcompturn,int lasthitcomx, int lasthitcomy)
{
    srand(time(0));
    x=rand() % 5+0;
    srand(time(0));
    y=rand() % 5+0;
    if(lasthitcompturn)
    {
        switch (lasthitcompturn){
            case 1:
                x=lasthitcomx+1;
                y=lasthitcomy;
                lasthitcompturn++;
                return;
            case 2:
                x=lasthitcomx;
                y=lasthitcomy+1;
                lasthitcompturn++;
                return;
            case 3:
                x=lasthitcomx-1;
                y=lasthitcomy;
                lasthitcompturn++;
                return;
            case 4:
                x=lasthitcomx;
                y=lasthitcomy-1;
                lasthitcompturn=0;
                return;
        }
    }
    if(x>5||x<-1){
        computerturn(x,y,lasthitcompturn,lasthitcomx,lasthitcomy);
    }
    else if(y>5||y<-1){
        computerturn(x,y,lasthitcompturn,lasthitcomx,lasthitcomy);
    }
    else
        cout<<"\n";
    return;
}
void playerturn(int&x,int&y){
    cout<<"x:";
    cin>>x;
    cout<<"y:";
    cin>>y;
    x--;
    y--;
    if(x>5||x<-1){
        cout<<"poner cordenada correcta\n";
        playerturn(x,y);
    }
    else if(y>5||y<-1){
        cout<<"poner cordenada correcta\n";
        playerturn(x,y);
    }
    else
        cout<<"\n";
    return;
}

void ponerBarcos()
{
  for (k = 1; k <= 4; k++)
    {
        switch (k)
        {
        case 1:
            posicionarBarco1(k);
            imprimirPantalla();
            break;
        case 2:
            posicionarBarco2(k);
            imprimirPantalla();
            break;
        case 3:
            posicionarBarco3(k);
            imprimirPantalla();
            break;
        case 4:
            posicionarBarco4(k);
            imprimirPantalla();
            break;
        }
    }
}
