#include "variaveis_globais.h"

void movanima1(int anim)
{
    int i,j=4,sub=14;
    if (anim>13){
    for(i=0;i<=(anim-sub)*j;i++)putchar(' ');}
  else{
    for(i=0;i<=anim*j;i++)putchar(' ');}
}

void movanima2(int distanc)
{
    int i;
for(i=0;i<=distanc;i++)putchar(' ');
}

void titulo1(void)
{
    static int anim_menu1=0,anim=0;
    int i,K,distanc=48;
    anim_menu1++;
    if(anim==17)anim=0;
    if (anim_menu1==3 || anim_menu1==6)anim++;
    if(anim_menu1<=3)//controle de velocidade da animação
    {   mudacor(9+anim_menu1);
        printf("     _______                              __       __\n"
               "    |       \\                            |  \\     /  \\\n"
               "    | $$$$$$$\\ ______    _______         | $$\\   /  $$  ______   _______\n"
               "    | $$__/ $$|      \\  /       \\ ______ | $$$\\ /  $$$ |      \\ |       \\      \n"
               "    | $$    $$ \\$$$$$$\\|  $$$$$$$|      \\| $$$$\\  $$$$  \\$$$$$$\\| $$$$$$$\\\n"
               "    | $$$$$$$ /      $$| $$       \\$$$$$$| $$\\$$ $$ $$ /      $$| $$  | $$\n"
               "    | $$     |  $$$$$$$| $$_____         | $$ \\$$$| $$|  $$$$$$$| $$  | $$ \n"
               "    | $$      \\$$    $$ \\$$     \\        | $$  \\$ | $$ \\$$    $$| $$  | $$\n"
               "     \\$$       \\$$$$$$$  \\$$$$$$$         \\$$      \\$$  \\$$$$$$$ \\$$   \\$$\n\n");

        mudacor(14);
        if(anim>13){
        movanima1(anim);
        printf("    ____");movanima2(distanc);printf("       \n");
        movanima1(anim);
        printf("   /    \\"); movanima2(distanc);printf(" ______\n");
        movanima1(anim);
        printf("  /     /");movanima2(distanc); printf("/      \\\n");
        movanima1(anim);
        printf("  |    / ");movanima2(distanc);  printf("|  ()()|\n");
        movanima1(anim);
        printf("  |    \\ ");for(i=0;i<distanc/4;i++)printf(" O  ");putchar(' '); printf("|      |\n");
        movanima1(anim);
        printf("  \\     \\");movanima2(distanc);printf("|      |\n");
        movanima1(anim);
        printf("   \\____/");movanima2(distanc);printf("|/\\/\\/\\|\n\n");
        }
        else{
         movanima1(anim);printf("       ""       ""   ____\n");
         movanima1(anim);printf(" ______""       ""  /    \\\n");
         movanima1(anim);printf("/      \\""      "" /     /\n");
         movanima1(anim);printf("|  ()()|""      "" |    /\n");// for(i=0;i<anim;i++) // printf(" () "); // putchar(' ');
         for(K=anim*2;K>(anim);K--)printf(" O  ");printf(" ");printf("|      |""      "" |    \\"); // for(i=12;i>anim;i--) // printf(" () ");
         for(i=13;i>anim;i--)printf(" O  ");printf(" O");putchar('\n');
         movanima1(anim);printf("|      |""      "" \\     \\\n");
         movanima1(anim);printf("|/\\/\\/\\|""      ""  \\____/\n\n");

    }}
    if (anim_menu1>3)//controle de velocidade da animação
    { mudacor(9+anim_menu1);
        printf("     _______                             __       __\n"
               "    /       \\                           /  \\     /  |\n"
               "    $$$$$$$  | ______    _______        $$  \\   /$$ |  ______   _______\n"
               "    $$ |__$$ |/      \\  /       |______ $$$  \\ /$$$ | /      \\ /       \\\n"
               "    $$    $$/ $$$$$$  |/$$$$$$$//      |$$$$  /$$$$ | $$$$$$  |$$$$$$$  |\n"
               "    $$$$$$$/  /    $$ |$$ |     $$$$$$/ $$ $$ $$/$$ | /    $$ |$$ |  $$ |\n"
               "    $$ |     /$$$$$$$ |$$ \\_____        $$ |$$$/ $$ |/$$$$$$$ |$$ |  $$ |\n"
               "    $$ |     $$    $$ |$$       |       $$ | $/  $$ |$$    $$ |$$ |  $$ |\n"
               "    $$/       $$$$$$$/  $$$$$$$/        $$/      $$/  $$$$$$$/ $$/   $$/\n\n");
        mudacor(14);
        if(anim>13){

        movanima1(anim);
        printf("   ____ ");movanima2(distanc);printf("       \n");
        movanima1(anim);
        printf("  /    \\ ");movanima2(distanc);printf(" ______\n");
        movanima1(anim);
        printf(" /      \\");movanima2(distanc);printf("/      \\\n");
        movanima1(anim);
        printf(" |   ___|");movanima2(distanc);printf("|  ()()|\n");
        movanima1(anim);
        printf(" |      |");for(i=0;i<distanc/4;i++)printf(" O  ");putchar(' ');printf("|      |\n");
        movanima1(anim);
        printf(" \\      /");movanima2(distanc);printf("|      |\n");
       movanima1(anim);
        printf("  \\____/ ");movanima2(distanc);printf("|\\/\\/\\/|\n\n");
        }
        else{
         movanima1(anim);printf("       ""       ""   ____\n");
         movanima1(anim);printf(" ______""       ""  /    \\\n");
         movanima1(anim);printf("/      \\""      "" /      \\\n");
         movanima1(anim);printf("|  ()()|""      "" |   ___|\n");//for(i=0;i<anim;i++)printf(" () ");putchar(' ');
         for(K=anim*2;K>(anim);K--)printf(" O  ");putchar(' ');printf("|      |""      "" |      | ");//for(i=15;i>anim;i--)printf(" () ");
         for(i=13;i>anim;i--)printf(" O  ");putchar(' ');putchar('\n');
         movanima1(anim);printf("|      |""      "" \\      /\n");
         movanima1(anim);printf("|\\/\\/\\/|""      ""  \\____/\n\n");}
         if(anim_menu1==6)anim_menu1=0;//zerar o contador da animação


    }
}
