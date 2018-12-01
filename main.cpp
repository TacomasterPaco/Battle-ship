#include <iostream> //Libreria que son de entrada y salida
#include <iomanip> //Libreria que permite manipular la intefaz
#include<cstdlib> //Nos permite gestionar la memoria dinamicamente y generar numeros
                //aleatorios(que es para lo que la usamos en este progama)
#include <windows.h>////Es una libreria  que contiene las declaraciones de todas las funcionees
                    //de  la biblioteca Windows API.
#include <string> //Nos sirve para manipular arreglos y strings

using namespace std;

void desplegarMenu(); //Esta función nos permite desplegar el menú.

void Singleplayer(); //Cuando se presiona 1 en el menú, nos lleva a la función SinglePlayer
void Multiplayer(); //Cuando presionamos 2 en el menú, nos lleva a la función MultiPlayer
void color(int X); //Ésta función hace referencia a un comando que nos permite cambiar el color de las letras dependiendo de donde se selccione
void playerturn (int& x,int& y); //Ésta función hace referencia a cuando le toca jugar a la persona,
                                    //En caso de que sea Multiplayer la función se llamará 2 veces
                                    // y si es singleplayer solo una vez.
void computerturn(int&x,int&y);//Ésta función se llama cuando se selecciona singleplayer.

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
return 0;
}
void desplegarMenu(void)                                            //Ésta es la función "Desplegar Menú, no recibe valores pues son puros cout´s
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
void Singleplayer(void)
{
    cout<<"Se seleccionó el modo un jugador"<<endl;
}
void Multiplayer(void)
{
    cout<<"Se seleccionó el modo multiplayer"<<endl;
    {
    const int martizss=6;
    int first_to_go=0 ,turns = 0, boats_sunk1 =8,boats_sunk2 =8,x=0,y=0,
    matrizplyer2[martizss][martizss]={0};
    matrizplyer1[martizss][martizss]={0};//0=water,1=miss,2=boat,3=hit
    srand(time(0));
    first_to_go=rand() % 2+1;
    for(turns;turns<72;turns++){//Aquí se limita  a 72 el número de tiros. Pues las matrices son de 6x6=32 y como son dos matrices=72
        if(first_to_go==1){
            playerturn(x,y);//Llama a la funciòn playerturn
            if((matrizplyer2[x][y]%2)==0){//Si el valor del agua o del bote incrementa en uno, se cambiara a miss o hit
                matrizplyer2[x][y]++;
                if(matrizplyer2[x][y]==3){
                    cout<<"\nAcertaste\n";
                    boats_sunk1--;//A la variable boats_sunkl se le resta 1
                    turns--;//A la variable turns se le resta 1
                    continue;//Se regresa al inicio del For
                }
                else{
                    cout<<"\nFallaste\nJugador 2\n";
                    first_to_go++;//A la variable first_to_go se le resta 1
                }
            }
            else if((matrizplyer2[x][y]%2)==1){ //Si al disparar en un espacio, este se encuentra en fallo, se escribirá un mensaje diciendo que
                cout<<"\nYa disparaste ahí\n";  //ya había disparado ahí previamente
                turns--;
                continue;
            }
        }
        else if(first_to_go==2){
            playerturn(x,y);
            if((matrizplyer1[x][y]%2)==0){
                matrizplyer1[x][y]++;
                if(matrizplyer1[x][y]==3){
                    cout<<"\nAcertaste\n";
                    boats_sunk2--;
                    turns--;
                    continue;
                }
                else{
                    cout<<"\nFallaste\nJugador 1\n";
                    first_to_go--;
                }
            }
            else if((matrizplyer1[x][y]%2)==1){
                cout<<"\nYa disparaste ahi\n";
                turns--;
                continue;
            }
        }
    }
}
}
void color(int X)    //Ésta es la función que nos permite cambiar el color del menú
{
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}
void computerturn(int&x,int&y,int&lasthitcompturn,int lasthitcomx, int lasthitcomy)
{
    cout<<"si";
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
void playerturn(int&x,int&y){           //Ésta función se llama cuando es el turno del jugador
    cout<<" Ingrese la coordenada en x:";
    cin>>x;
    cout<<"Ingrese la coordenana en y:";
    cin>>y;                                 //La parte de arriba nos pide que se ingresen las coordenadas, y se almacenan en la variable "x" y "y"
    x--;                                    //Como la matriz del programa inicia 0 en vez de 1,es diferente a la que ve el usuario
    y--;                                    //Es decir, se le resta uno para que concuerde la coordenada que el usuario ingreso con la
                                            //con la que el usuario ve
    if(x>5||x<-1){                                          //Ésta parte del programa es la que no permite al usuario introducir

        cout<<"Ingresar una cordenada correcta\n";          //otro valor diferente al que está permitido por las matrices y en las coordenada "x" y "y"
        playerturn(x,y);
    }
    else if(y>5||y<-1){
        cout<<"Ingrese una cordenada correcta\n";
        playerturn(x,y);
    }
    else
        cout<<"\n";
    return;
}



