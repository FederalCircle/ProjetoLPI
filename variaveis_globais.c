#include <stdio.h>
#include <windows.h>

//center of axis is set to the top left cornor of the screen
COORD coordi= {0,0};

typedef struct coord
{
    int x, y;
} coord;

typedef struct dado
{
    int score;
    char name[7];
} dado;

int estagio=0;
int matriz[31][28];
int barra[31][28];
char nome[7];

void gotoxy(int x,int y)
{
    coordi.X=x;
    coordi.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordi);
}
void mudacor(int i)
{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void arquivos(int ponto)
{
    dado player[10]; player[0].score=0;
    dado tempor1[10], tempor2[10];
    dado novo;
    int i,j, pontos[10][10], jogadores, controle;
    char dados[10][15], control[15], c;

    FILE *file;
    file = fopen("ranking.bin","r+b");
    fclose(file);
    //DESCOBRIMOS QUANTOS JOGADORES TEMOS
    //PEGAMOS TODOS AS STRINGS DE ATÉ 10 JOGADORES
    fopen("ranking.bin","rb");
    if (file == NULL) jogadores=0;
    else {
        jogadores = fread(player, sizeof(dado), 10, file);
    }
    fclose(file);

    //PEGAMOS OS DADOS DO JOGADOR ATUAL
    novo.score=ponto;
    strcpy(novo.name,nome);

    //ORGANIZAMOS EM ORDEM E SALVAMOS
    if(jogadores==0){
        if(player[0].score==0)
        {  file = fopen("ranking.bin","wb");
           fwrite(&novo, sizeof(dado), 1, file);
           fclose(file);
        }
    }
    else
    {   for(i=jogadores-1; i>=0; i--)
      {     if(novo.score<=player[i].score)
        {   file = fopen("ranking.bin","rb");
            printf("%i --- %i",novo.score, player[i].score);
            getch();
            fread(&tempor1, sizeof(dado), i+1, file);   //COPIAMOS ATÉ O LOCAL DESEJADO
            fseek(file, sizeof(dado)*(i+1),SEEK_SET); //LOCAL PARA COMEÇO DE GRAVAÇÃO
 controle = fread(&tempor2, sizeof(dado), jogadores-(i+1), file);  //SALVAMOS O QUE HÁ DEPOIS
            fclose(file);

            file = fopen("ranking.bin","wb");
            fwrite(tempor1, sizeof(dado), i+1, file);  //ESCREVEMOS OS PRIMEIROS
            fwrite(&novo, sizeof(dado), 1, file);     //ESCREVEMOS O NOVO PLAYER
            fwrite(tempor2, sizeof(dado), controle, file); //ESCREVEMOS O QUE HAVIA DEPOIS
            fclose(file);
            break;
    }
            if(novo.score>player[i].score) {
            file = fopen("ranking.bin","rb");
            fread(&tempor1, sizeof(dado), 1, file);  //GUARDAMOS TODOS OS JOGADORES
            fclose(file);

            file = fopen("ranking.bin","wb");
            fwrite(&novo, sizeof(dado), 1, file);     //ESCREVEMOS O NOVO PLAYER
            fwrite(tempor1, sizeof(dado), 1, file);  //ESCREVEMOS OS DEMAIS JOGADORES

            break;
            }
    }
    }
}
void GAMEOVER(int ponto)
{
    char rp;

    system("cls");
    printf("\n\n\n\n\n\t\tGAME OVER"
           "\n\n\t\tPontuacao:%d"
           "\n\n\tPressione qualquer tecla...\n\n", ponto);
    fflush(stdin);
    getch();
    arquivos(ponto);
  //  ====-------
  // antigo corpo de arquivos
  // -----========
    system("cls");
    printf("\n\n\n\n\n\tPontuacao salva.\n\n\tPressione Qualquer tecla...");
    getch();
    main();
}
