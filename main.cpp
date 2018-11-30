#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

void playerturn (int& x,int& y);
void computerturn(int&x,int&y);


int main()

{
    const int martizss=6;
    int first_to_go=1 ,turns = 0, boats_sunk1 =8,boats_sunk2 =8,x=0,y=0,lasthitx=0,lastjity=0,lasthitmarker=0,
    matrizplyer2[martizss][martizss]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    matrizplyer1[martizss][martizss]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//0=water,1=miss,2=boat,3=hit
    /*srand(time(0));
    first_to_go=rand() % 2+1;*///randi for who goes first
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
void computerturn(int&x,int&y){
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
676676
    aber al cine
    aber al cine
