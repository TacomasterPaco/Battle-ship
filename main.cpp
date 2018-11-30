#include <iostream>
#include <iomanip>
#include<cstdlib>
#include <windows.h>
#include <string>

using namespace std;

void desplegarMenu();
void Singleplayer();
void Multiplayer();
void color(int X);
void playerturn (int& x,int& y);
void computerturn(int&x,int&y);

int main()
{
   int op=0;

    while(op!=3)
    {
        desplegarMenu();
        cin>>op;
        if(op>0&&op<4)
        {
        switch(op)
        {
        case 1:
            system("cls");
            Singleplayer();
            break;
        case 2:
            system("cls");
            Multiplayer();

            break;
        case 3:
            system("cls");
            cout<<"Off"<<endl;
            break;
        }
        }
    if(op<1||op>3)
        {
            system("cls");
            color(4);
            cout<<endl<<"\tINGRESE UNA OPCION CORRECTA"<<endl;
        }
    }
return 0;
}
void desplegarMenu(void)
{
    color(48);
    cout<<("\n");
    cout<<("\t    PixelShip");
    cout<<("\n");
    color(15);
    cout<<("\t\t$\t\t\t\n\t\t$|\n\t\t$|$\n\t\t$|$$\n\t\t$|$$$\n\t\t$|$$$$");
    cout<<("\n\t\t |\n\t\t |");
    color(14);
    cout<<("\n\t$$$$$$$$$$$$$$$$$$$$$$$$$\n\t -----------------------");
    cout<<("\n\t  $$$$/)$$$$$$$$$$$$$$$\n\t~~~$$$(/$$$$$$$$$$$$$$~~~\n\t~~~~$$$$$$$$$$$$$$$$$~~~~");
    cout<<("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~\n\t~~~~~~~~~~~~~~~~~~~~~~~~~");
    color(8);
    cout<<("\n\n\t1- Un Jugador\n\n\t2- Multrijugador\n\n\t3- Salir\n\n\tIntroduce una opción:");
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
                    cout<<"\nhit\n";//of hit, says and reduces boats leaf to win and turn-- do it doesnt count the free hit as a turn
                    boats_sunk1--;
                    turns--;
                    continue;
                }
                else{
                    cout<<"\nmixx\nnext2\n";
                    first_to_go++;
                }
            }
            else if((matrizplyer2[x][y]%2)==1){
                cout<<"\nalredy fired there\n";
                turns--;
                continue;
            }
        }
        else if(first_to_go==2){
            playerturn(x,y);
            if((matrizplyer1[x][y]%2)==0){
                matrizplyer1[x][y]++;
                if(matrizplyer1[x][y]==3){
                    cout<<"\nhit\n";
                    boats_sunk2--;
                    turns--;
                    continue;
                }
                else{
                    cout<<"\nmiss\nnext1\n";
                    first_to_go--;
                }
            }
            else if((matrizplyer1[x][y]%2)==1){
                cout<<"\naleady fired there\n";
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

