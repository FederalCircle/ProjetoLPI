#ifndef variaveis_globais.h
#define variaveis_globais.h

typedef struct coord{
    int x, y;
} coord;
typedef struct dado{
    int score;
    char name[7];
} dado;

int estagio;
int matriz[31][28];
int barra[31][28];
char nome[7];

void gotoxy(int x,int y);
void mudacor(int i);
void arquivos(int ponto);
void GAMEOVER(int ponto);

#endif
