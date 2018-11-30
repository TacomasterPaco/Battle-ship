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
void Singleplayer(void)
{
    cout<<"Se seleccionó el modo un jugador"<<endl;
}
void Multiplayer(void)
{
    cout<<"Se seleccionó el modo multiplayer"<<endl;
    {
    const int martizss=6;
    int first_to_go=1 ,turns = 0, boats_sunk1 =8,boats_sunk2 =8,x=0,y=0,
    matrizplyer2[martizss][martizss]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    matrizplyer1[martizss][martizss]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//0=water,1=miss,2=boat,3=hit
    /*srand(time(0));
    first_to_go=rand() % 2+1;*/
    for(turns;turns<72;turns++){//limit 72 due to number of possilbe turnsorhits
        if(first_to_go==1){
            playerturn(x,y);//func to set coord og shoot
            if((matrizplyer2[x][y]%2)==0){//if water or boat increase value by one to chage to miss ot hit
                matrizplyer2[x][y]++;
                if(matrizplyer2[x][y]==3){
                    cout<<"\nAcertaste\n";//of hit, says and reduces boats leaf to win and turn-- do it doesnt count the free hit as a turn
                    boats_sunk1--;
                    turns--;
                    continue;
                }
                else{
                    cout<<"\nFallaste\nJugador 2\n";
                    first_to_go++;
                }
            }
            else if((matrizplyer2[x][y]%2)==1){
                cout<<"\nYa disparaste ahí\n";
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
void color(int X)
{
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}
void computerturn(int&x,int&y)
{
    cout<<"si";
    srand(time(0));
    x=rand() % 5+0;
    srand(time(0));
    y=rand() % 5+0;
    if(x>5||x<-1){
        computerturn(x,y);
    }
    else if(y>5||y<-1){
        computerturn(x,y);
    }
    else
        cout<<"\n";
    return;
}
void playerturn(int&x,int&y){
    cout<<" Ingrese la coordenada en x:";
    cin>>x;
    cout<<"Ingrese la coordenana en y:";
    cin>>y;
    x--;
    y--;
    if(x>5||x<-1){
        cout<<"Ingresar una cordenada correcta\n";
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




