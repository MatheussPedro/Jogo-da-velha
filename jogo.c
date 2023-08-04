#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

const char x = 'X', ball = 'O';
char jogador_vez (int rodada){
    if(rodada % 2 == 0){
            return ball;
        }else{
            return x;
        };
    };
char escreve_jogo (char game[3][3],int linhas, int colunas, int rodadas){
  for (int i = 0; i < 3; i++)
  {
   for (int j = 0; j < 3; j++)
        {   
            if (rodadas == 0)
            {
                game[i][j] = '@';
            }else{
            if (i == linhas && j == colunas && game[i][j] != x && game[i][j] != ball)
            {
                 game[i][j] = jogador_vez(rodadas);
            };
          };
        };
        system("cls");
        printf(" 0   1   2\n");
    };
    for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf(" %c ", game[i][j]);
                if (j < 2)
                {
                    printf("|");
                };
                if (j == 2)
                    {
                        printf(" %d ", i);
                    };
            };
            if(i < 2){
         printf("\n ---------- ");
         printf("\n");
            };
        };
}
char verifica_ganhador(char jogo[3][3]){
    for (int i = 0; i < 3; i++)
     {
      if ((jogo[i][0] == x && jogo[i][1] == x && jogo[i][2] == x) || (jogo[i][0] == ball && jogo[i][1] == ball && jogo[i][2] == ball))
        {
            return 1;
        }else if ((jogo[0][i] == x && jogo[1][i] == x && jogo[2][i] == x) || (jogo[0][i] == ball && jogo[1][i] == ball && jogo[2][i] == ball))
        {
            return 1;
        }else if ((jogo[0][0] == x && jogo[1][1] == x  && jogo[2][2] == x) || (jogo[0][0] == ball && jogo[1][1] == ball  && jogo[2][2] == ball)
        || (jogo[0][2] == x && jogo[1][1] == x  && jogo[2][0] == x) || (jogo[0][2] == ball && jogo[1][1] == ball  && jogo[2][0] == ball))
        {
            return 1;
          }
         }
        return 0;}
int main (){
    int linhas, colunas, rodadas, end = 1;
    char jogo[3][3];
while (end != 0)
{
        for (rodadas = 0; rodadas < 9; rodadas++){
          do
            {
             escreve_jogo(jogo, linhas, colunas, rodadas);
             printf("\nVez do jogador %c", jogador_vez(rodadas + 1));
             printf("\nEscreva a linha\n");
             scanf("%d", &linhas);
             printf("\nEscreva a coluna\n");
             scanf("%d", &colunas);
             system("cls");
            }while (linhas < 0 || linhas > 2 || colunas < 0 || colunas > 2 || jogo[linhas][colunas] != '@');
             jogo[linhas][colunas] = jogador_vez(rodadas + 1);
            if (verifica_ganhador(jogo))
            {
                break;}
        };
            escreve_jogo(jogo, linhas, colunas, rodadas);
            printf("\n%s\n", verifica_ganhador(jogo) ? "Houve um ganhador!" : "Empate!");
            printf("\nPressione 1 continuar ou 0 para sair");
            scanf("%d" , &end);
            system("cls");}
    printf("Jogo finalizado");
    return 0;
}