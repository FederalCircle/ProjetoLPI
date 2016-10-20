#include "variaveis_globais.h"

int mapa()
{
       //Desenho do Mapa
   int i, j,contcomida=0;
   //matriz e ponteiro para desenho do mapa
    char b[31][29],*a[31];
   //Cada ponteiro de 'a' apontando para uma linha de 'b'
        for(i=0; i<31; i++)
            a[i]=b[i];
    if (estagio%3==0){
        a[0] ="311111111111MAGD111111111114";
        a[1] ="2            bb            2";
        a[2] ="2 caad caaad bb caaad caad 2";
        a[3] ="2tb00b b000b bb b000b b00bt2";
        a[4] ="2 faae faaae fe faaae faae 2";
        a[5] ="2                          2";
        a[6] ="2 caad cd caaaaaad cd caad 2";
        a[7] ="2 faae bb faadcaae bb faae 2";
        a[8] ="2      bb    bb    bb      2";
        a[9] ="611114 bfaad bb caaeb 311115";
        a[10]="000002 b000b fe b000b 200000";
        a[11]="000002 bcaae    faadb 200000";
        a[12]="000002 bb0000000000bb 200000";
        a[13]="111115 fe0311aa1140fe 611111";
        a[14]="0        0200000020        0";
        a[15]="111114 cd0611111150cd 311111";
        a[16]="000002 bb0000000000bb 200000";
        a[17]="000002 bfd  caad  ceb 200000";
        a[18]="000002 bce ce00fd fdb 200000";
        a[19]="311115 fe  fadcae  fe 611114";
        a[20]="2            bb            2";
        a[21]="2 caad caaad bb caaad caad 2";
        a[22]="2 fadb faaae fe faaae bcae 2";
        a[23]="2   bb                bb   2";
        a[24]="714 bb cd caaaaaad cd bb 319";
        a[25]="715 fe bb faadcaae bb fe 619";
        a[26]="2      bb    bb    bb      2";
        a[27]="2tcaaaaefaad bb caaefaaaadt2";
        a[28]="2 faaaaaaaae fe faaaaaaaae 2";
        a[29]="2                          2";
        a[30]="6111111111111111111111111115";
    }
    else if(estagio%3==1){
        a[0] ="311111111111MAGD111111111114";
        a[1] ="2t                        t2";
        a[2] ="2 caaaaaaaaaa  aaaaaaaaaad 2";
        a[3] ="2 b                      b 2";
        a[4] ="2 b caaaaaaaaaaaaaaaaaad b 2";
        a[5] ="2 b b                  b b 2";
        a[6] ="2 b b caaaaad  caaaaad b b 2";
        a[7] ="2 b b bcaaadb  bcaaadb b b 2";
        a[8] ="2 b b bb   fe  fe   bb b b 2";
        a[9] ="2 b   bb cd      cd bb   b 2";
        a[10]="2 b b bb bb caad bb bb b b 2";
        a[11]="2 b b bb fe faae fe bb b b 2";
        a[12]="2 b b bb 0000000000 bb b b 2";
        a[13]="2   b bb 0311aa1140 bb b   2";
        a[14]="61115 fe 0200000020 fe 61115";
        a[15]="0        0611111150        0";
        a[16]="31114 cd 0000000000 cd 31114";
        a[17]="2   b bb cd      cd bb b   2";
        a[18]="2 b b bb bb caad bb bb b b 2";
        a[19]="2 b b bb bb b00b bb bb b b 2";
        a[20]="2 b b bb fe faae fe bb b b 2";
        a[21]="2 b b bb            bb b b 2";
        a[22]="2 b   bb   cd  cd   bb   b 2";
        a[23]="2 b b bfaaaeb  bfaaaeb b b 2";
        a[24]="2 b b faaaaae  faaaaae b b 2";
        a[25]="2 b b                  b b 2";
        a[26]="2 b faaaaaaaaaaaaaaaaaae b 2";
        a[27]="2 b                      b 2";
        a[28]="2 faaaaaaaaaa  aaaaaaaaaae 2";
        a[29]="2t                        t2";
        a[30]="6111111111111111111111111115";
    }
//mapa MAGD
        else if(estagio%3==2){
        a[0] ="311111111111MAGD111111111114";
        a[1] ="2                          2";
        a[2] ="2 ca ad              ca ad 2";
        a[3] ="2 b   fd   caaaad   ce   b 2";
        a[4] ="2 b    fd ce    fd ce    b 2";
        a[5] ="2 b     fae      fae     b 2";
        a[6] ="2 b                      b 2";
        a[7] ="2 faaaaaaaaaa  aaaaaaaaaae 2";
        a[8] ="2                          2";
        a[9] ="2 caaa aaaaaaaaaaaaaa aaad 2";
        a[10]="2 b                      b 2";
        a[11]="2 b   caaaaaa  aaaaaad   b 2";
        a[12]="2 b   b              b   b 2";
        a[13]="2 b   fd 0311aa1140 ce   b 2";
        a[14]="0 b   ce 0200000020 fd   b 0";
        a[15]="2 b   b  0611111150  b   b 2";
        a[16]="2 fa                    ae 2";
        a[17]="2    aaaaaaaaa aaaaaaaa    2";
        a[18]="2 b                      b 2";
        a[19]="2 b  caaaaaaaaaaaaaaad   b 2";
        a[20]="2 b  faaaaaaad       b   b 2";
        a[21]="2 b          b           b 2";
        a[22]="2 faaaaa aaaae       faaae 2";
        a[23]="2                          2";
        a[24]="2    caaaaaaa  aaaaaaad    2";
        a[25]="2  cae                fad  2";
        a[26]="2 ce       caaaad       fd 2";
        a[27]="2tb        faaaae        bt2";
        a[28]="2 faaaaaaa aaaaaa aaaaaaae 2";
        a[29]="2                          2";
        a[30]="6111111111111111111111111115";
       }


    //Interpretação dos Códigos e impressão do Mapa
    for(i=0; i<31; i++)
    {
        for(j=0; j<28; j++)
        {
            barra[i][j]=0; // Deixa o mapa completamente livre, para depois pôr barreiras
            switch(a[i][j])
            {
            //Caracteres de linha dupla
            case '1':
                matriz[i][j]=205;
                break;
            case '2':
                matriz[i][j]=186;
                break;
            case '3':
                matriz[i][j]=201;
                break;
            case '4':
                matriz[i][j]=187;
                break;
            case '5':
                matriz[i][j]=188;
                break;
            case '6':
                matriz[i][j]=200;
                break;
            case '7':
                matriz[i][j]=204;
                break;
            case '8':
                matriz[i][j]=203;
                break;
            case '9':
                matriz[i][j]=185;
                break;

            //Caracteres de uma linha
            case 'a':
                matriz[i][j]=196;
                break;
            case 'b':
                matriz[i][j]=179;
                break;
            case 'c':
                matriz[i][j]=218;
                break;
            case 'd':
                matriz[i][j]=191;
                break;
            case 'e':
                matriz[i][j]=217;
                break;
            case 'f':
                matriz[i][j]=192;
                break;

            //NOME
            case 'M':
                matriz[i][j]='M';
                break;
            case 'A':
                matriz[i][j]='A';
                break;
            case 'G':
                matriz[i][j]='G';
                break;
            case 'D':
                matriz[i][j]='D';
                break;

            //Comida normal, especial e espaços vazios
            case 't':
                matriz[i][j]=248;
                break;
            case ' ':
                matriz[i][j]=250;
                break;
            case '0':
                matriz[i][j]=' ';
                break;
            }
            //Mapa sendo impresso


            //Atribuição das barreiras no mapa
            if(i==13 && (j==14 || j==13)){
            mudacor(7);
            putchar(matriz[i][j]);barra[i][j]=2;}
            else if(matriz[i][j]!=250 && matriz[i][j]!=' '&& matriz[i][j]!=248)
                { mudacor(9);
                  putchar(matriz[i][j]);
                    barra[i][j]=1;}
            else if(j==27||j==0)
            {
             mudacor(14);
             putchar(matriz[i][j]);
              barra[i][j]=3;}
            else{
            mudacor(14);
            putchar(matriz[i][j]);}
            if(matriz[i][j]==250||matriz[i][j]==248){
            mudacor(14);
            contcomida++;
            //putchar(matriz[i][j]);
            }
            //printf("%d",barra[i][j]);
            //Sleep(20);
        }
        putchar('\n');

    }
    return contcomida;
}


