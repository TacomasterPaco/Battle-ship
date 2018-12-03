/**
  * @file main.cpp
  * @version 1.0
  * @date 12/02/2018
  * @author Juan Pablo Martinez Cantú, Ruben Dominguez Chavez, Daniel Alberto Cota Ochoa, Hugo Edibray Becerra Gandara
  *
  *
  */
#include <iostream> //Libreria que son de entrada y salida
#include <iomanip> //Libreria que permite manipular la intefaz
#include <cstdlib> //Nos permite gestionar la memoria dinamicamente y generar numeros
                //aleatorios(que es para lo que la usamos en este progama)
#include <windows.h>////Es una libreria  que contiene las declaraciones de todas las funcionees
                    //de  la biblioteca Windows API.
#include <string> //Nos sirve para manipular arreglos y strings
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

/**
  * @brief Es la constante que define x en la matriz
  *
  */
const int NUMFILAS=6;
/**
  * @brief Es la constante que define y en la matriz
  *
  */

const int NUMCOLAS=6;
/**
  *@brief Esta matriz es de 6x6, y todos sus valores son 0 ya que este es el valor del agua.
  *@brief Esta matriz se muestra para el jugador, por lo tanto tambien salen los barcos y donde te han tirado
  */
int matrizJugador[NUMFILAS][NUMCOLAS]={0};
/**
  *@brief Esta matriz es de 6x6, y todos sus valores son 0 ya que este es el valor del agua.
  *@brief Matriz donde tiene guardad la informacion del enemigo y solo se muestra al enemigo en la parte de abajo
  *@brief (Cuando es modo SinglePlayer no se muestra)
  *@brief Tiene guardado donde estan los barcos
  */

int matrizEnemigo[NUMFILAS][NUMCOLAS]={0};
/**
  *@brief Esta matriz es de 6x6, y todos sus valores son 0 ya que este es el valor del agua.
  *@brief Es la matriz para el segundo jugador o para la computadora.
  *@brief Solo es visual, muestra donde has dado o fallado
  */
int matrizRevelada[NUMFILAS][NUMCOLAS]={0};
/**
  *@brief Esta matriz es de 6x6, y todos sus valores son 0 ya que este es el valor del agua
  @brief Es visual para el jugador 1 para que vea donde ha tirado
  */
int matrizJugador2[NUMFILAS][NUMCOLAS]={0};
/**
  *@brief Un arreglo que sirve para posicionar el barco del jugador que ocupa 3 lugares, tiene almacenados los valores 2
  *@brief Pues es el valor que tiene el bote en la logica del juego
  */
int posBarco1[3]={2,2,2};
/**
  *@brief Un arreglo que sirve para posicionar el barco del jugador que ocupa 2 lugares, tiene almacenados los valores 2
  *@brief Pues es el valor que tiene el bote en la logica del juego
  */
int posBarco2[2]={2,2};
/**
  *@brief Un arreglo que sirve para posicionar el barco del jugador que ocupa 2 lugares, tiene almacenados los valores 2
  *@brief Pues es el valor que tiene el bote en la logica del juego
  */
int posBarco3[2]={2,2};
/**
  *@brief Un arreglo que sirve para posicionar el barco del jugador que ocupa 1 lugar, tiene almacenados los valores 2
  *@brief Pues es el valor que tiene el bote en la logica del juego
  */
int posBarco4[1]={2};
/**
  *@brief Un arreglo que sirve para posicionar el barco tanto del enemigo como del jugador 2
  *@brief Ocupa 3 lugares, tiene almacenados los valores 2
  *@brief Pues es el valor que tiene el bote en la logica del juego
  */
int posEnemigo1[3]={2,2,2};
/**
  *@brief Un arreglo que sirve para posicionar el barco tanto del enemigo como del jugador 2
  *@brief Ocupa 2 lugares, tiene almacenados los valores 2
  *@brief Pues es el valor que tiene el bote en la logica del juego
  */

int posEnemigo2[2]={2,2};
/**
  *@brief Un arreglo que sirve para posicionar el barco tanto del enemigo como del jugador 2
  *@brief Ocupa 2 lugares, tiene almacenados los valores 2
  *@brief Pues es el valor que tiene el bote en la logica del juego
  */

int posEnemigo3[2]={2,2};
/**
  *@brief Un arreglo que sirve para posicionar el barco tanto del enemigo como del jugador 2
  *@brief Ocupa 1 lugar, tiene almacenados los valores 2
  *@brief Pues es el valor que tiene el bote en la logica del juego
  */
int posEnemigo4[1]={2};
/**
  *@brief Variable utilizada para poner el orden de los barcos
  */
int k=0;
/**
  *@brief Variable utilizada para colocar barcos en "x"
  */
int x=1;
/**
  *@brief Variable utilizada para colocar barcos en "y"
  */
int y=1;
/**
  *@brief Variable utilizada para medir distancia en "y"
  */
int y1=0;
/**
  *@brief Variable utilizada para medir distancia en "x"
  */
int x1=0;
/**
  *@brief Variable utilizada para escoger en que orientacion poner los barcos
  */

int orientacion= 0;
/**
  *@brief Variable utilizada para que el usuario seleccione la operacion que desea realizar
  */

int op=0; //Aquí se inicializa Op, que es la operación que seleccionará el usuario en el menú
/**
  *@brief Variable utilizada para junto con un srand, ver quien va primero
  */
int first_to_go=1; //quien va primero y a quien le toca

/**
 *@brief Esta funcion se encarga de imprimir las coordenadas que el usuario ve
 *@brief tiene un ciclo for que hace que se vayan imprimiendo hasta llegar a el numero menor de numfilas
 *@brief
 */
void imprimirPantalla();
/**
 *@brief Funcion encarga de posicionar el primer barco del jugador, el cual es de 3 lugares
 *@param K. Se usa la direccion de la variable
 */
void posicionarBarco1(int &k);
/**
 *@brief Funcion encarga de posicionar el segundo barco del jugador, el cual es de 2 lugares
 *@param K. Se usa la direccion de la variable
 */
void posicionarBarco2(int &k);
/**
 *@brief Funcion encarga de posicionar el tercer barco del jugador, el cual es de 2 lugares
 *@param K. Se usa la direccion de la variable
 */
void posicionarBarco3(int &k);
/**
 *@brief Funcion encarga de posicionar el cuarto barco del jugador, el cual es de 1 lugar
 *@param K. Se usa la direccion de la variable
 */
void posicionarBarco4(int &k);
/**
 *@brief Funcion encarga de posicionar el primer barco del enemigo, el cual es de 3 lugares
 *@param K. Se usa la direccion de la variable
 */
void posicionarEnemigo1(int &k);
/**
 *@brief Funcion encarga de posicionar el segundo barco del enemigo, el cual es de 2 lugares
 *@param K. Se usa la direccion de la variable
 */
void posicionarEnemigo2(int &k);
/**
 *@brief Funcion encarga de posicionar el tercer barco del enemigo, el cual es de 2 lugares
 *@param K. Se usa la direccion de la variable
 */
void posicionarEnemigo3(int &k);
/**
 *@brief Funcion encarga de posicionar el cuarto barco del enemigo, el cual es de 1 lugar
 *@param K. Se usa la direccion de la variable
 */
void posicionarEnemigo4(int &k);
/**
 *@brief Se encarga de almacenar todas demas funciones de poner barcos del jugador 1
 */
void ponerBarcos();
/**
 *@brief Se encarga de almacenar todas demas funciones de poner barcos del jugador 2(o computadora, en SinglePlayer)
 */
void ponerBarcos2();
/**
 *@brief Se encarga de las coordenas de "x", "y" y la orientacion en la que se quiere poner el barco del primer jugador.
 *@param Orientacion. Se usa la direccion de la variable
 *@param X. Se usa la direccion de la variable
 *@param Y. Se usa la direccion de la variable
 */
void darcoordenadas1(int &orientacion, int &x, int &y);
/**
 *@brief Se encarga de las coordenas de "x", "y" y la orientacion en la que se quiere poner el barco del segundo jugador(o computadora en SinglePlayer)
 *@param Orientacion. Se usa la direccion de la variable
 *@param X. Se usa la direccion de la variable
 *@param Y. Se usa la direccion de la variable
 */
void darcoordenadas2(int &orientacion, int &x, int &y);
/**
 *@brief Se encarga de mostrar el menú, consiste de un barco y las opciones, es void, por lo tanto no devuelve nada.
 *@brief Tiene una función que nos permite cambiar el valor de manera rápida cambiando sólo los numeros
 */
void desplegarMenu(); //Esta función nos permite desplegar el menú.
/**
 *@brief Se encarga del procedimiento logico para un jugador contra la computadora
 */
void Singleplayer(); //Cuando se presiona 1 en el menú, nos lleva a la función SinglePlayer
/**
 *@brief Se encarga del procedimiento logico para un jugador contra otro jugador
 */
void Multiplayer(); //Cuando presionamos 2 en el menú, nos lleva a la función MultiPlayer
/**
 *@brief Esta funcion esta relacionada directamente con un comando que nos permite cambiar facilmente el color de un texto, solo con cambiar los numeros
 *@param X. Esta variable esta declarada dentro de la funcion y es la que permite el cambio de color rapido
 */
void color(int X); //Ésta función hace referencia a un comando que nos permite cambiar el color de las letras dependiendo de donde se selccione
/**
 *@brief Es la responsable de cuando el usuario va a tirar, ya sea el primer jugador o el segundo.
 *@param X. Coordenada en X
 *@param Y. Cooordenada en Y
 */
void playerturn (int&,int&); //Ésta función hace referencia a cuando le toca jugar a la persona,
                                    //En caso de que sea Multiplayer la función se llamará 2 veces
                                    // y si es singleplayer solo una vez.
/**
 *@brief Es la que se ejecuta cuando la computadora va a tirar,se selecciona un valor "x" y "y" del 0 al 5 al azar
 *@brief Si en los tiros recientes acierta, se utiliza recursion y un switch para que la computadora revise los puntos alrededor del ultimo "Hit"
 *@param X. Coordenada en X
 *@param Y. Cooordenada en Y.U
 *@param lasthitcompturn. Usa la direccion de la variable.Se suma 1 cada vez que le da a un barco y se usa para saber el caso en el que va a tirar alrededor el ultimo punto en el que marco "Hit"
 *@param lasthitcomx. Almacena la coordenada en "x" en el ultimo punto donde marco "hit"
 **@param lasthitcomy. Almacena la coordenada en "y" en el ultimo punto donde marco "hit"
 */

void computerturn(int&,int&,int&,int,int);//Ésta función se llama cuando se selecciona singleplayer.

/**
 * @brief Hace que el programa se espere 2 segundos para que el usuario pueda ver la pantalla
 */
void delay();



int main()
{

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
            op=3;
            break;
        case 2:                 // En el caso 2, al igual que en el pasado, está la función system("cls"), y después se llama a la función
            system("cls");     //y después se llama a la función Multiplayer.
            Multiplayer();
            op=3;
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

  if(op!=3)
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
    cout<<("\n\t  $$$$/)$$$$$$$$$$$$$$$\n\t~~~$$$(/$$$$$$$$$$$$$$~~~\n\t~~~~$$$$$$$$$$$$$$$$$~~~~");
    cout<<("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~\n\t~~~~~~~~~~~~~~~~~~~~~~~~~");
    color(8);  //Otro color que cambiamos
    cout<<("\n\n\t1- Un Jugador\n\n\t2- Multijugador\n\n\t3- Salir\n\n\tIntroduce una opcion:");
}

void imprimirPantalla()
{
    cout<<setw(5)<<"1"<<setw(4)<<"2"<<setw(4)<<"3"<<setw(4)<<"4"<<setw(4)<<"5"<<setw(4)<<"6";
    for(int i=0;i<NUMFILAS;i++)
    {
        cout<<endl<<i+1;
        for(int j=0;j<NUMCOLAS;j++){
            cout<<setw(4);
            if(first_to_go==1)
                cout<<matrizJugador2[i][j];
            else
                cout<<matrizRevelada[i][j];
        }
    }
    cout<<"\n------------------------------------\n";
    cout<<setw(5)<<"1"<<setw(4)<<"2"<<setw(4)<<"3"<<setw(4)<<"4"<<setw(4)<<"5"<<setw(4)<<"6";
    for(int i=0;i<NUMFILAS;i++)
    {
        cout<<endl<<i+1;
        for(int j=0;j<NUMCOLAS;j++){
            cout<<setw(4);
            if(first_to_go==1)
                cout<<matrizJugador[i][j];
            else
                cout<<matrizEnemigo[i][j];
        }
    }
}

void posicionarBarco1(int &k)
{
    cout<<"\n\nPosiciona el barco #1 (3 espacios)\n";
    darcoordenadas1(orientacion,x,y); //pide x y y
    if (orientacion) //deternima si pide x1 o y1 dependiendo la orientacion
    {
        do
        {
            cout<<"x2:\n";
            cin>>x1; //pide la segunda coordenada
            x1--; //recorre el valor para concordar con los arreglos
        }
        while(!(x-x1==2 || x-x1==-2)); //no te deja salir a menos que pongas la segunda coordenada con la distancia correcta
        if(x-x1==-2) //dependiendo si la distancia negativa o positiva va a poner el barco
        {
            for(int i=0; i<3;i++)
            {
                matrizJugador[y][x+i]=posBarco1[i]; //pone el primer barco en la matriz del jugador
            }
        }
        else
        {
            for(int i=0; i<3;i++)
            {
                matrizJugador[y][x-i]=posBarco1[i]; //pone el primer barco en la matriz del jugador
            }
        }
    }
    else
    {
        do
        {
            cout<<"y2:\n";
            cin>>y1; //pide la segunda coordenada
            y1--;
        }
        while(!(y-y1==2 || y-y1==-2));
        if(y-y1==-2) //dependiendo si la distancia negativa o positiva va a poner el barco
        {
            for(int i=0; i<3;i++)
            {
                matrizJugador[y+i][x]=posBarco1[i]; //pone el primer barco en la matriz del jugador
            }
        }
        else
        {
            for(int i=0; i<3;i++)
            {
                matrizJugador[y-i][x]=posBarco1[i]; //pone el primer barco en la matriz del jugador
            }
        }
    }
    system("cls"); //borra la pantalla
}

void posicionarBarco2(int &k)
{
    cout<<"\n\nPosiciona el barco #2 (2 espacios)\n";
    darcoordenadas1(orientacion,x,y); //pide x y y
    if (orientacion)
    {
        do
        {
            cout<<"x2:\n";
            cin>>x1; //pide la segunda coordenada
            x1--;
        }
        while(!(x-x1==1 || x-x1==-1));
        if(x-x1==-1) //dependiendo si la distancia negativa o positiva va a poner el barco
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y][x+1]==0) //checa si se puede poner el barco en los espacios en blanco
                {
                    matrizJugador[y][x]=posBarco2[0]; //pone el barco casilla 1
                    matrizJugador[y][x+1]=posBarco2[1]; //pone barco en la casilla 2
                }
                else
                    k--; //retrocede al barco aterior que es el mismo si la condicion no se cumple
        }
        else
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y][x-1]==0) //checa si se puede poner el barco en los espacios en blanco
                {
                    matrizJugador[y][x]=posBarco2[0];
                    matrizJugador[y][x-1]=posBarco2[1];
                }
                else
                    k--; //retrocede al barco aterior que es el mismo si la condicion no se cumple
        }
    }
    else
    {
        do
        {
            cout<<"y2:\n";
            cin>>y1;
            y1--;
        }
        while(!(y-y1==1 || y-y1==-1));
        if (y-y1==-1) //dependiendo si la distancia negativa o positiva va a poner el barco
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y+1][x]==0) //checa si se puede poner el barco en los espacios en blanco
                {
                    matrizJugador[y][x]=posBarco2[0];
                    matrizJugador[y+1][x]=posBarco2[1];
                }
                else
                    k--;
        }
        else
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y-1][x]==0) //checa si se puede poner el barco en los espacios en blanco
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
            cout<<"x2:\n";
            cin>>x1;
            x1--;
        }
        while(!(x-x1==1 || x-x1==-1));
        if (x-x1==-1)
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y][x+1]==0) //checa si se puede poner el barco en los espacios en blanco
                {
                    matrizJugador[y][x]=posBarco3[0];
                    matrizJugador[y][x+1]=posBarco3[1];
                }
                else
                    k--;
        }
        else
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y][x-1]==0) //checa si se puede poner el barco en los espacios en blanco
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
            cout<<"y2:\n";
            cin>>y1;
            y1--;
        }
        while(!(y-y1==1 || y-y1==-1));
        if(y-y1==-1)
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y+1][x]==0) //checa si se puede poner el barco en los espacios en blanco
                {
                    matrizJugador[y][x]=posBarco3[0];
                    matrizJugador[y+1][x]=posBarco3[1];
                }
                else
                    k--;
        }
        else
        {
                if (matrizJugador[y][x]==0 && matrizJugador[y-1][x]==0) //checa si se puede poner el barco en los espacios en blanco
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
    do{
    cout<<"\nHORIZONTAL(1) O VERTICAL(0)\n";
    cin>>orientacion;
    cout<<"x1:\n"; 
    cin>>x; //pide la coordenada en x
    cout<<"y1:\n";
    cin>>y; //pide la coordenada en y
    if (!((x<=6 && x>=1) && (y<=6 && y>=1) && (orientacion==1 || orientacion==0))) //checa que las coordenadas esten dentro de la matriz
        cout<<"Coordenada fuera de rango\n";
    }
    while(!((x<=6 && x>=1) && (y<=6 && y>=1) && (orientacion==1 || orientacion==0))); //te pide que las vuelvas a ingresar
    x--;
    y--;

}

void Singleplayer(void)
{
    cout<<"Se seleccionó el modo singleplayer"<<endl;
    int boats_sunk1=8,boats_sunk2=8,x=0,y=0,lasthitcomx=0,lasthitcomy=0,lasthitcompturn=0; 
	/*
	boats_sunk1 casillas restantes para jugador 1
	boats_sunk2 casillas restantes para jugador 2 o com
	x coordenadas en x
	y coordenadas en y
	*/
    imprimirPantalla();
    ponerBarcos();
    ponerBarcos2();
    srand(time(0)); //marca un seed para tener diferentes randoms
    first_to_go=rand() % 2+1;
    for(int i =0;i<72;i){//limit 72 due to number of possilbe turns
      if(boats_sunk1==0||boats_sunk2==0){ //por si alguien pierde que se pase a este if
        i=72;
        if(boats_sunk1==0){
	    system("cls");
            cout<<"Player 1 gano\n";
            continue;}
        else{
	    system("cls");
            cout<<"Com gano\n";
            continue;}

      }
        system("cls");
        if(first_to_go==1){
            imprimirPantalla();
            playerturn(x,y);//func to set coord og shoot
            if((matrizEnemigo[y][x]%2)==0){//if water or boat increase value by one to chage to miss ot hit
                matrizEnemigo[y][x]++; //hace que el valor se 1 en agua y 3 en barco, asi se sabe si le dio o no
                matrizJugador2[y][x]=matrizEnemigo[y][x]; //la asigna a la matriz visible
                if(matrizEnemigo[y][x]==3){
                    cout<<"\nhit\n";//if hit, says and reduces boats leaf to win and turn-- do it doesnt count the free hit as a turn
                    boats_sunk1--;
                    delay ();
                    continue;
                }
                else{
                    cout<<"\nmiss\nSiguiente: Comp\n";
                    delay ();
                    first_to_go++;
                }
            }
            else if((matrizEnemigo[y][x]%2)==1){
                cout<<"\nYa disparo alli\n";
                delay ();
                continue;
            }
        }
        else if(first_to_go==2){
            computerturn(x,y,lasthitcompturn,lasthitcomx,lasthitcomy);
            if((matrizJugador[y][x]%2)==0){
                matrizJugador[y][x]++;
                matrizRevelada[y][x]=matrizJugador[y][x];
                if(matrizJugador[y][x]==3){
                    cout<<"\nhit\n";
                    lasthitcomx=x;
                    lasthitcomy=y;
                    lasthitcompturn=1;
                    boats_sunk2--;
                    delay ();
                    continue;
                }
                else{
                    cout<<"\nmiss\nSiguiente: Jugador\n";
                    first_to_go--;
                    delay ();
                }
            }
            else if((matrizJugador[y][x]%2)==1){
                continue;
            }
        }
    }
}
void Multiplayer(void)
{
    cout<<"Se seleccionó el modo multiplayer"<<endl;
    int boats_sunk1 =8,boats_sunk2 =8,x=0,y=0,lasthitcomx=0,lasthitcomy=0,lasthitcompturn=0,useless=0;
    imprimirPantalla();
    ponerBarcos();
    system("cls");
    first_to_go++;
    imprimirPantalla();
    ponerBarcos2();
    srand(time(0));
    first_to_go=rand() % 2+1;
    for(int i =0;i<72;i){//limit 72 due to number of possilbe turnsorhits
      if(boats_sunk1==0||boats_sunk2==0){
        i=72;
        if(boats_sunk1==0){
	    system("cls");
            cout<<"Player 1 gano";
            continue;}
        else{
	    system("cls");
            cout<<"Player2 gano";
            continue;}

      }
        system("cls");
	cout<<"\nListo player"<<first_to_go<<"?(poner un numero)\n"; //para pasar de turno
        cin>>useless; //solo es para tener una espera entre turnos
        if(first_to_go==1){
            imprimirPantalla();
            playerturn(x,y);//func to set coord og shoot
            if((matrizEnemigo[y][x]%2)==0){//if water or boat increase value by one to chage to miss ot hit
                matrizEnemigo[y][x]++;
                matrizJugador2[y][x]=matrizEnemigo[y][x];
                if(matrizEnemigo[y][x]==3){
                    cout<<"\nhit\n";//of hit, says and reduces boats leaf to win and turn-- do it doesnt count the free hit as a turn
                    boats_sunk1--;
		    delay ();
                    continue;
                }
                else{
                    cout<<"\nmiss\nSiguiente: Jugador2\n";
		    delay ();
                    first_to_go++;
                }
            }
            else if((matrizEnemigo[y][x]%2)==1){
                cout<<"\nYa disparo alli\n";
		delay ();
                continue;
            }
        }
        else if(first_to_go==2){
            imprimirPantalla();
            playerturn(x,y);
            if((matrizJugador[y][x]%2)==0){
                matrizJugador[y][x]++;
                matrizRevelada[y][x]=matrizJugador[y][x];
                if(matrizJugador[y][x]==3){
                    cout<<"\nhit\n";
                    boats_sunk2--;
		    delay ();
                    continue;
                }
                else{
                    cout<<"\nmiss\nSiguiente: Jugador1\n";
		    delay ();
                    first_to_go--;
                }
            }
            else if((matrizJugador[y][x]%2)==1){
                cout<<"\nYa disparo alli\n";
		delay ();
                continue;
            }
        }
    }
}

void color(int X)
{
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X); //esta instruccion nos deja manipular los colores de la consola
}
void computerturn(int&x,int&y,int&lasthitcompturn,int lasthitcomx, int lasthitcomy)
{
    x=rand() % 5+0;
    y=rand() % 5+0;
    if(lasthitcompturn>0)
    {
        switch (lasthitcompturn){
            case 1:
                x=lasthitcomx+1;
                y=lasthitcomy;
                lasthitcompturn++;
                if(x>5||x<-1||y>5||y<-1){
                    computerturn(x,y,lasthitcompturn,lasthitcomx,lasthitcomy);
                }
                return;
            case 2:
                x=lasthitcomx;
                y=lasthitcomy+1;
                lasthitcompturn++;
                if(x>5||x<-1||y>5||y<-1){
                    computerturn(x,y,lasthitcompturn,lasthitcomx,lasthitcomy);
                }
                return;
            case 3:
                x=lasthitcomx-1;
                y=lasthitcomy;
                lasthitcompturn++;
                if(x>5||x<-1||y>5||y<-1){
                    computerturn(x,y,lasthitcompturn,lasthitcomx,lasthitcomy);
                }
                return;
            case 4:
                x=lasthitcomx;
                y=lasthitcomy-1;
                lasthitcompturn=0;
                if(x>5||x<-1||y>5||y<-1){
                    computerturn(x,y,lasthitcompturn,lasthitcomx,lasthitcomy);
                }
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
    cout<<"\nx:";
    cin>>x;
    cout<<"y:";
    cin>>y;
    x--;
    y--;
    if(x>5||x<-1){
        cout<<"poner coordenada correcta\n";
        playerturn(x,y);
    }
    else if(y>5||y<-1){
        cout<<"poner coordenada correcta\n";
        playerturn(x,y);
    }
    else
        cout<<"\n";
    return;
}

void ponerBarcos()
{
  for (k = 1; k <= 4; k++) //este for nos ayuda a que se incremente la funcion y tener control si no es valida algun dato introducido por el usuario
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
void ponerBarcos2()
{
  for (k = 1; k <= 4; k++)
    {
        switch (k)
        {
        case 1:
            posicionarEnemigo1(k);
            if(op==2)
                imprimirPantalla();
            break;
        case 2:
            posicionarEnemigo2(k);
            if(op==2)
                imprimirPantalla();
            break;
        case 3:
            posicionarEnemigo3(k);
            if(op==2)
                imprimirPantalla();
            break;
        case 4:
            posicionarEnemigo4(k);
            if(op==2)
                imprimirPantalla();
            break;
        }
    }
}
void darcoordenadas2(int &orientacion, int &x, int &y)
{
    if(op==2){
        do{
            cout<<"\nHORIZONTAL(1) O VERTICAL(0)\n";
            cin>>orientacion;
            cout<<"x1:\n";
            cin>>x;
            cout<<"y1:\n";
            cin>>y;
            if (!((x<=6 && x>=1) && (y<=6 && y>=1) && (orientacion==1 || orientacion==0)))
                cout<<"Coordenada fuera de rango\n";
            }
            while(!((x<=6 && x>=1) && (y<=6 && y>=1) && (orientacion==1 || orientacion==0)));
            x--;
            y--;
    }
    else{
        srand(time(0));
        orientacion=rand() % 1+0;
        x=rand() % 5+0;
        y=rand() % 5+0;
    }


}
void posicionarEnemigo1(int &k)
{
    if(op==2)
        cout<<"\n\nPosiciona el barco #1 (3 espacios)\n";
    darcoordenadas2(orientacion,x,y);
    if (orientacion)
    {
        do
        {
            if(op==2){
                cout<<"x2:\n";
                cin>>x1;
                x1--;}
            else{
                srand(time(0));
                x1=rand() % 5+0;
            }
        }
        while(!(x-x1==2 || x-x1==-2));
        if(x-x1==-2)
        {
            for(int i=0; i<3;i++)
            {
                matrizEnemigo[y][x+i]=posBarco1[i];
            }
        }
        else
        {
            for(int i=0; i<3;i++)
            {
                matrizEnemigo[y][x-i]=posBarco1[i];
            }
        }
    }
    else
    {
        do
        {
            if(op==2){
                cout<<"y2:\n";
                cin>>y1;
                y1--;}
            else{
                srand(time(0));
                y1=rand() % 5+0;
            }
        }
        while(!(y-y1==2 || y-y1==-2));
        if(y-y1==-2)
        {
            for(int i=0; i<3;i++)
            {
                matrizEnemigo[y+i][x]=posBarco1[i];
            }
        }
        else
        {
            for(int i=0; i<3;i++)
            {
                matrizEnemigo[y-i][x]=posBarco1[i];
            }
        }
    }
    system("cls");
}

void posicionarEnemigo2(int &k)
{
    if(op==2)
        cout<<"\n\nPosiciona el barco #2 (2 espacios)\n";
    darcoordenadas2(orientacion,x,y);
    if (orientacion)
    {
        do
        {
            if(op==2){ //para multiplayer
                cout<<"x2:\n";
                cin>>x1;
                x1--;}
            else{ //para un jugador
                srand(time(0));
                x1=rand() % 5+0;
            }
        }
        while(!(x-x1==1 || x-x1==-1));
        if(x-x1==-1)
        {
                if (matrizEnemigo[y][x]==0 && matrizEnemigo[y][x+1]==0)
                {
                    matrizEnemigo[y][x]=posBarco2[0];
                    matrizEnemigo[y][x+1]=posBarco2[1];
                }
                else
                    k--;
        }
        else
        {
                if (matrizEnemigo[y][x]==0 && matrizEnemigo[y][x-1]==0)
                {
                    matrizEnemigo[y][x]=posBarco2[0];
                    matrizEnemigo[y][x-1]=posBarco2[1];
                }
                else
                    k--;
        }
    }
    else
    {
        do
        {
            if(op==2){
                cout<<"y2:\n";
                cin>>y1;
                y1--;}
            else{
                srand(time(0));
                y1=rand() % 5+0;
            }
        }
        while(!(y-y1==1 || y-y1==-1));
        if (y-y1==-1)
        {
                if (matrizEnemigo[y][x]==0 && matrizEnemigo[y+1][x]==0)
                {
                    matrizEnemigo[y][x]=posBarco2[0];
                    matrizEnemigo[y+1][x]=posBarco2[1];
                }
                else
                    k--;
        }
        else
        {
                if (matrizEnemigo[y][x]==0 && matrizEnemigo[y-1][x]==0)
                {
                    matrizEnemigo[y][x]=posBarco2[0];
                    matrizEnemigo[y-1][x]=posBarco2[1];
                }
                else
                    k--;
        }
    }
    system("cls");
}

void posicionarEnemigo3(int &k)
{
    if(op==2)
        cout<<"\n\nPosiciona el barco #3 (2 espacios)\n";
		//Esta función recibe una variable entera pero desde la dirección
    darcoordenadas2(orientacion,x,y);
    if (orientacion)
    {
        do
        {
            if(op==2){
                cout<<"x2:\n";
                cin>>x1;
                x1--;}
            else{
                srand(time(0));
                x1=rand() % 5+0;
            }
        }
        while(!(x-x1==1 || x-x1==-1));
        if (x-x1==-1)
        {
                if (matrizEnemigo[y][x]==0 && matrizEnemigo[y][x+1]==0)
                {
                    matrizEnemigo[y][x]=posBarco3[0];
                    matrizEnemigo[y][x+1]=posBarco3[1];
                }
                else
                    k--;
        }
        else
        {
                if (matrizEnemigo[y][x]==0 && matrizEnemigo[y][x-1]==0)
                {
                    matrizEnemigo[y][x]=posBarco3[0];
                    matrizEnemigo[y][x-1]=posBarco3[1];
                }
                else
                    k--;
        }
    }
    else
    {
        do
        {
            if(op==2){
                cout<<"y2:\n";
                cin>>y1;
                y1--;}
            else{
                srand(time(0));
                y1=rand() % 5+0;
            }

        }
        while(!(y-y1==1 || y-y1==-1));
        if(y-y1==-1)
        {
                if (matrizEnemigo[y][x]==0 && matrizEnemigo[y+1][x]==0)
                {
                    matrizEnemigo[y][x]=posBarco3[0];
                    matrizEnemigo[y+1][x]=posBarco3[1];
                }
                else
                    k--;
        }
        else
        {
                if (matrizEnemigo[y][x]==0 && matrizEnemigo[y-1][x]==0)
                {
                    matrizEnemigo[y][x]=posBarco3[0];
                    matrizEnemigo[y-1][x]=posBarco3[1];
                }
                else
                    k--;
        }

    }
    system("cls");
}

void posicionarEnemigo4(int &k)
{
    if(op==2)
        cout<<"\n\nPosiciona el barco #4 (1 espacio)\n";
    darcoordenadas2(orientacion,x,y);
    if (matrizEnemigo[y][x]==0)
        matrizEnemigo[y][x]=posBarco4[0];
    else
        k--;
    system("cls");
}
void delay()
{
    for(int i = (time(NULL) + 2); time(NULL) != i; time(NULL));
}

/*
Este fue un proyecto que nos llevo un mes entero y en ese mes tuvimos muchas
discusiones, gritos, alegrias,etc. Por lo que estamos muy orgullosos de nuestro
primer proyecto en la programacion, esperamos tener mas oportunidades asi para
aprender de una forma autodidacta. Hecho por:

-Juan Pablo Martinez
-Hugo Edibray Becerra
-Daniel Alberto Cota
-Ruben Dominguez :)
*/
