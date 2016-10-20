#include <stdio.h>
#include <stdlib.h>
#include "variaveis_globais.h"

void movimento(int c,int *x,int *y)
{
     switch(c)
        {
        case 'w':
            *y-=1;
            break;
        case 's':
            *y+=1;
            break;
        case 'a':
            *x-=1;
            break;
        case 'd':
            *x+=1;
            break;}
}

void direcao(int *x, int *y)
{
    static char c, c2, f,ldpause, d;
    int antgx=*x, antgy=*y;

    fflush(stdin);//????
    if(kbhit())
    {
        d=getch();
        if(d=='w' || d=='s' || d=='a' || d=='d'){
        c2=c;
        c=d;
        f=1;}
    }
    movimento(c,x,y);

    if ((barra[*y][*x]==1 || barra[*y][*x]==2)&& f==1)
    {
        *x=antgx;
        *y=antgy;
        movimento(c2,x,y);
    }
    else f=0;
    if(*x>=27) *x=0;
    else if(*x<=0) *x=27;
    if (barra[*y][*x]==1 ||barra[*y][*x]==2)
    {
        *x=antgx;
        *y=antgy;
    }
}

void dirrand(int *x, int *y,int fant,int xpac,int ypac)
{

    int n, antgx=*x, antgy=*y;
    static int cont=0,mov[4];
    if (*x==14 && *y==14){
        *y-=1;

    }
    //Faz seguir o Pacman
   else if(*x==xpac || *y==ypac)
    {
        if(*x>xpac && *y==ypac)*x-=1;
        else if(*x<xpac && *y==ypac)*x+=1;
        else if(*y>ypac && *x==xpac)*y-=1;
        else *y+=1;
        mov[fant]=5;
    }
    else//Move aleatóriamente
    {

        n=rand()%4;
        //if((barra [*y-1][*x]==0 && barra [*y+1][*x]==0 &&(barra [*y][*x-1]==1  &&barra [*y][*x+1]==1))&& mov[fant]!=5);
        //else if(((barra [*y-1][*x]==1 && barra [*y+1][*x]==1) && (barra [*y][*x-1]==0 && barra [*y][*x+1]==0))&&(barra [*y][*x-1]!=3 && barra [*y][*x+1]!=3)&& mov[fant]!=5);
        //else
            mov[fant]=n;

        switch(mov[fant])
        {
        case 0:
            *x-=1;
            break;
        case 1:
            *x+=1;
            break;
        case 2:
            *y-=1;
            break;
        case 3:
            *y+=1;
            break;
        }
    }
    do
    {
        if(barra[*y][*x]==2) //Barreira especial para a caixa dos fantasmas
        {
            *y-=1;
            dirrand(x,y,fant,0,0);
        }
        else if(barra[*y][*x]==1||barra[*y][*x]==3)//Recurssividade para que o fantasma não fique batendo na parede
        {
            *x=antgx;
            *y=antgy;
            dirrand(x,y,fant,0,0);
        }
    }
    while(barra[*y][*x]==1||barra[*y][*x]==3);
}

int random(int num1,int num2,int num3,int num4)
{
    int escolhido=0;
    do {
    switch (rand()%4){
      case 0:
        escolhido = num1;
        break;
         case 1:
        escolhido = num2;
        break;
         case 2:
        escolhido = num3;
        break;
         case 3:
        escolhido = num4;
        break;
    }
    }while(escolhido==0);
    return escolhido;

}

int decmov(int pos,int x,int y)
{
if ((pos*barra[y][x])==0)return pos;
    else return 0;
}

int escolhemovfant(int x,int y)
{
int static testeA=0,testeB=0,testeC=0,testeD=0;
int posa=1,posb=2,posc=3,posd=4;
    posa=decmov(posa,x,y-1);
    posb=decmov(posb,x,y+1);
    posc=decmov(posc,x-1,y);
    posd=decmov(posd,x+1,y);

    return random(posa,posb,posc,posd);
}

void moverfant(int n,int *x,int *y,int xpac,int ypac)
{
     if(*x==xpac || *y==ypac)
    {
        if(*x>xpac && *y==ypac)*x-=1;
        else if(*x<xpac && *y==ypac)*x+=1;
        else if(*y>ypac && *x==xpac)*y-=1;
        else *y+=1;
    }
    else {
            switch(n)
        {
        case 1:
            *y-=1;
            break;
        case 2:
            *y+=1;
            break;
        case 3:
            *x-=1;
            break;
        case 4:
            *x+=1;
            break;
        }
    }
}

