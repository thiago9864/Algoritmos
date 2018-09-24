#include <stdio.h>
#include <stdlib.h>

int verificaEspacosMatriz (int m[6][7])
{
     int i, j;
     for(i = 0; i < 6; i++)
     {
        for(j = 0; j < 7; j++)
        {
           if(m[i][j] == 0)
           {
              return 1;
           }
        }
     }

     return 0;
}

int verificaEspacosColuna (int m[6][7], int j)
{
    int i;
    if(j >= 0)
    {
        for(i = 0; i < 6; i++)
        {
            if(m[i][j] == 0)
            {
               return 1;
            }
        }
    }
    return 0;
}

void colocaPeca (int m[6][7], int num)
{
     int coluna, i, j, espaco;
     printf("Informe a coluna escolhida:");
     scanf("%d", &coluna);
     printf("\n");
     j = coluna - 1;
     espaco = verificaEspacosColuna(m, j);
     while(coluna < 1 || coluna > 7 || espaco == 0)
     {
        printf("Coluna invalida!\n");
        printf("Informe a coluna escolhida:");
        scanf("%d", &coluna);
        j = coluna - 1;
        espaco = verificaEspacosColuna(m, j);
     }

     for(i = 5; i >= 0; i--)
     {
         if(m[i][j] == 0)
         {
            m[i][j] = num;
            return;
         }
     }
}

int verificaDiagonal1 (int m[6][7])
{
    int cont, i, j, k;
    for(i = 5; i > 2; i--)
    {
        for(j = 0; j < 4; j++)
        {
           cont = 0;
           for(k = 1; k < 4; k++)
           {
               if(m[i][j] == m[i-k][j+k] && m[i][j] != 0)
               {
                  cont++;
               }
               if(cont == 3)
               {
                 return 1;
               }

           }

        }
    }
    return 0;
}

int verificaDiagonal2 (int m[6][7])
{
    int cont, i, j, k;
    for(i = 0; i < 3; i++)
    {
       for(j = 0; j < 4; j++)
       {
          cont = 0;
          for(k = 1; k < 4 ;k++)
          {
              if(m[i][j] == m[i+k][j+k] && m[i][j] != 0)
              {
                 cont++;
              }
              if(cont == 3)
              {
                 return 1;
              }
          }

       }
    }
    return 0;
}

int verificaVertical (int m[6][7])
{
    int cont, i, j, k;
    for(j = 0; j < 7; j++)
    {
        for(i = 5; i > 0; i--)
        {
           cont = 0;
           for(k = 1; k < 4; k++)
           {
               if(m[i][j] == m[i-k][j] && m[i][j] != 0)
               {
                  cont++;
               }
               if(cont == 3)
               {
                  return 1;
               }
           }

        }
     }
     return 0;
}

int verificaHorizontal (int m[6][7])
{

    int cont, i, j, k;
    for(i = 5; i >= 0; i--)
    {
       for(j = 0; j < 6; j++)
       {
          cont = 0;
          for(k = 1; k < 4; k++)
          {
              if(m[i][j] == m[i][j+k] && m[i][j] != 0)
              {
                 cont++;
              }
              if(cont == 3)
              {
                return 1;
              }
          }
       }

    }
    return 0;
}

int verificaGanhador (int m[6][7])
{
    int ganhou;
    ganhou = verificaHorizontal(m);
    if(ganhou == 1)
    {
       return ganhou;
    }

    ganhou = verificaVertical(m);
    if(ganhou == 1)
    {
       return ganhou;
    }

    ganhou = verificaDiagonal1(m);
    if(ganhou == 1)
    {
       return ganhou;
    }

    ganhou = verificaDiagonal2(m);
    if(ganhou == 1)
    {
       return ganhou;
    }
    return ganhou;
}

void imprimeMatriz (int m[6][7])
{
    int i, j;
    for(i = 0; i < 6; i++)
    {
       for(j = 0; j < 7; j++)
       {
          printf("%3d", m[i][j]);
       }
       printf("\n");
    }
}

int main ()
{
    int m[6][7], i, j, jogador1, jogador2, espacos, ganhou;
    jogador1 = 1;
    jogador2 = 2;
    espacos = 1;
    for(i = 0; i < 6; i++)
    {
        for(j = 0; j < 7; j++)
        {
            m[i][j] = 0;
        }
    }
    imprimeMatriz(m);
    while(espacos == 1)
    {
       printf("\nVez do jogador 1\n");
       colocaPeca(m, jogador1);
       imprimeMatriz(m);
       ganhou = verificaGanhador(m);
       if(ganhou != 0)
       {
          printf("\nFim de jogo! Vitoria!\n");
          break;
       }
       espacos = verificaEspacosMatriz(m);
       if (espacos == 0)
       {
          break;
       }

       printf("\nVez do jogador 2\n");
       colocaPeca(m, jogador2);
       imprimeMatriz(m);
       ganhou = verificaGanhador(m);
       if(ganhou != 0)
       {
          printf("\nFim de jogo! Vitoria!");
          break;
       }
       espacos = verificaEspacosMatriz(m);

    }
    if (ganhou == 0)
    {
       printf("Nao ha vencedor!");
    }
    return 0;
}
