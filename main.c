#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <dos.h>
#include "animacao.h"
#include "variaveis_globais.h"
#include "Mapa.h"
#include "func_movimento.h"

void ajuda()
{
    printf("\n\n\t\t\t\t INICIANDO O JOGO:\n\n"
           "\t\t\tPARA INICIAR ESCOLHA A PRIMEIRA OPCAO NO MENU!\n\n"
           "\t\t\t\t PRIMEIRO PASSOS NO JOGO:\n\n"
           "\t\t\t\tUSE AS TECLAS DIRECIONAIS:\n"
           "\t\t\t\t-->\"w\" PARA SE MOVER PRA CIMA."
           "\n\t\t\t\t-->\"a\" PARA SE MOVER PRA ESQUERDA."
           "\n\t\t\t\t-->\"s\" PARA SE MOVER PRA BAIXO."
           "\n\t\t\t\t-->\"d\" PARA SE MOVER PRA DIREITA.\n");
    printf("\t\tpara consultar a pontuacao, escolha a opcao de numero 2 no menu\n\t\tpara sair, escolha a opcao de numero 4 no menu\n");
    printf("\t\t\pressione qualquer tecla para continuar...");
    getch();
    main();
}

void ranking()
{
    dado player[10];
    int aux=10, imp, quantidade;
    FILE *arq;
    arq = fopen("ranking.bin", "rb");
    if(arq==NULL)
        {
            system("cls");
            printf("\n\n\t\t  NOME\t\t\t\t\tSCORE\n\n");
            while(aux>0){ printf("\t\t  --- . . . . . . . . . . . . . . . . . ---\n\n"); aux--;}
            printf("\n\n\t\tPressione qualquer tecla para voltar ao menu...");
            getch(); main();
        }
    fclose(arq);

    //PEGAMOS TODOS AS STRINGS DOS 10 JOGADORES
    arq = fopen("ranking.bin", "rb");

    quantidade = fread(player, sizeof(dado), 10, arq);

    fclose(arq);
    //IMPRIMINDO OS JOGADORES
     system("cls");
     printf("\n\n\t\t  NOME\t\t\t\t\tSCORE\n\n");
    for(imp=0; imp<quantidade; imp++)
    {
        printf("\t      %d.  %s . . . . . . . . . . . . . . . . . %i\n\n", imp+1, player[imp].name, player[imp].score);
    }
    printf("\n\t\tPressione qualquer tecla para voltar ao menu...");
    getch();main();
}

void jogo(int vida)
{
    int i, j, pis=1, t=50,aux[5],auxy[5], ponto=0,especial[4]={0,0,0,0};
    int contcomida=0,duracaoesp,trocarface,delayfant[4]={0,0,0,0},contfantc=1;
    int movatual[4],movaux;
    coord pm, fant[4];
    system("cls");

    //DEFINIÇÃO DE COORDENADAS INICIAIS
    pm.x=14;
    pm.y=16;
    for(i=0; i<4; i++)
    {
        fant[i].x=12;
        fant[i].y=12;
        aux[i]=fant[i].x;
        auxy[i]=fant[i].y;
    }
    contcomida=mapa();
    gotoxy(14, 16);mudacor(14); putchar('O');
    gotoxy(fant[0].x, fant[0].y);mudacor(12); putchar(182);
    getch();
    fflush(stdin);
    while(1)
    {

            for(i=0; i<4; i++)
            {   if(especial[i])mudacor(9);
                else i==0?mudacor(13):i==1?mudacor(11):i==2?mudacor(15):i==3?mudacor(6):0;
                if(fant[i].y==14 && fant[i].x==14 && delayfant[i]==0){contfantc++;delayfant[i]=contfantc;}
                else if(delayfant[i]==0)delayfant[i]=1;
                if(pis%(especial[i]==1?20:((20*delayfant[i])-estagio))==0){
                auxy[i]=fant[i].y;
                aux[i]=fant[i].x;
               // movaux=escolhemovfant(fant[i].x,fant[i].y);
               // if(barra [fant[i].y-1][fant[i].x]==0 && barra [fant[i].y+1][fant[i].x]==0 &&barra [fant[i].y][fant[i].x-1]==1 &&barra [fant[i].y][fant[i].x+1]==1);
               // else if(barra [fant[i].y-1][fant[i].x]==1 && barra [fant[i].y+1][fant[i].x]==1 &&barra [fant[i].y][fant[i].x-1]==0 &&barra [fant[i].y][fant[i].x+1]==0);
               // else movatual[i]=movaux;
               // moverfant(movatual[i],&fant[i].x,&fant[i].y,pm.x,pm.y);


                dirrand(&fant[i].x, &fant[i].y,i,pm.x, pm.y);
                    gotoxy(fant[i].x,fant[i].y);
                    putchar(182);
                    if(fant[i].y!=auxy[i] || fant[i].x!=aux[i])
                    {
                        gotoxy(aux[i],auxy[i]);
                        mudacor(14);
                        printf("%c",matriz[auxy[i]][aux[i]]);
                    }

                if(fant[i].x==pm.x && fant[i].y==pm.y)
                {
                    if(especial[i]==1)
                    {
                        ponto+=100;
                        fant[i].x=14;
                        fant[i].y=14;
                        especial[i]=0;
                    }
                    else if(vida!=0)
                    {
                        vida--;
                        pm.x=14;
                        pm.y=16;
                        for(j=0; j<4; j++)
                        {

                            aux[j]=fant[j].x;
                            auxy[j]=fant[j].y;
                            fant[j].x=14;
                            fant[j].y=14;
                            gotoxy(aux[j],auxy[j]); putchar(matriz[auxy[j]][aux[j]]);
                        }
                    }
                    else GAMEOVER(ponto);
                }
 delayfant[i]=0; }
        }
        auxy[4]=pm.y;
        aux[4]=pm.x;
        if(pis%19==0)
        {
            //Informações adicionais na tela
            for(i=3; i>vida; i--)
            {
                gotoxy(3+i, 31); putchar(' ');
            }
            for(i=vida;i>0;i--){
            gotoxy(3+i,31);mudacor(12);
            printf("%c",3);}
            gotoxy(9,31);mudacor(15);
            printf("%s - ",nome);
            gotoxy(15,31);mudacor(15);
            printf("%d",ponto);

            direcao(&pm.x, &pm.y);
             if( (matriz[pm.y][pm.x]==250||matriz[pm.y][pm.x]==248))
                {
                    contcomida--;
                    if(contcomida==0){estagio+=1;jogo(vida);}
                    if(matriz[pm.y][pm.x]==248)
                    {   for(i=0;i<4;i++)
                        especial[i]=1;
                        duracaoesp=0;
                    }
                    else ponto++;
                    matriz[pm.y][pm.x]=' ';
                    mudacor(14);
                    if(trocarface>2){ putchar('C');trocarface++;}
                    gotoxy(pm.x,pm.y);
                    if(pis%10==0){
                            putchar('O');}
                    else if(pis%10!=0){ putchar('C');}
                    if(pm.y!=auxy[4] || pm.x!=aux[4])
                    {
                        gotoxy(aux[4],auxy[4]);
                        putchar(' ');
                    }

                }
                else if( matriz[pm.y][pm.x]==' ')
                {   mudacor(14);
                    gotoxy(pm.x,pm.y);
                    if(pis%40<20) putchar('O');
                    else putchar('C');
                    if(pm.y!=auxy[4] || pm.x!=aux[4])
                    {
                        gotoxy(aux[4],auxy[4]);
                        putchar(' ');
                    }
                }
              for(i=0; i<4; i++)  {
                if(fant[i].x==pm.x && fant[i].y==pm.y)
                {
                    if(especial[i]==1)
                    {
                        ponto+=100;
                        fant[i].x=14;
                        fant[i].y=14;
                        especial[i]=0;
                    }
                   else if(vida!=0)
                    {
                        vida--;
                       // gotoxy(pm.x,pm.y); putchar(matriz[pm.x][pm.y]);
                        pm.x=14;
                        pm.y=16;
                        for(j=0; j<4; j++)
                        {

                            aux[j]=fant[j].x;
                            auxy[j]=fant[j].y;
                            fant[j].x=14;
                            fant[j].y=14;
                            gotoxy(aux[j],auxy[j]); putchar(matriz[auxy[j]][aux[j]]);
                        }
                    }
                   else GAMEOVER(ponto);
                }
              }
        }

        Sleep(10);
        contfantc=0;
        pis++;
        duracaoesp++;
        if(duracaoesp==750){
                for(i=0;i<4;i++)
                especial[i]=0;}
        if(trocarface>4)trocarface=0;
    }
}

void main()
{
    char ast[4]={'>',' ',' '}, dir;
    int n=0, cont=0;
    while(1)
    {
        system("cls");
        titulo1();
        mudacor(15);

        printf("\n\n\t\t\t\t%c Jogar\n"
               "\t\t\t\t%c Pontuacoes\n"
               "\t\t\t\t%c Ajuda\n"
               "\t\t\t\t%c Sair\n",ast[0], ast[1], ast[2],ast[3] );
        fflush(stdin);
        if(kbhit())
        {Beep(700,50);
            dir=getch();
            if(dir=='w' && n!=0)
            {
                ast[n]=' ';
                n--;
                ast[n]='>';
            }
            else if(dir=='s' && n!=3)
            {
                ast[n]=' ';
                n++;
                ast[n]='>';
            }
            else if(dir=='\n'||dir=='\r')
            {   putchar ('\7');
                if(n==0)
                {
                    while(1){
                    system("cls"); titulo1(); mudacor(15);
                    printf("\n\n\t\tDigite seu nome em 3 letras:\n\t\t\t\t");
                    fflush(stdin);
                    if(kbhit())
                    {
                      gets(nome);

                      jogo(3);
                    } Sleep(100);
                    }
                }
                else if(n==1)
                {
                ranking();
                }
                else if(n==2){
                    system("cls");
                    ajuda();
                }
                else if(n==3)
                {
                    system("cls");
                    exit(1);
                }
            }
        }
        Sleep(100);
    }
}

