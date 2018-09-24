#include <stdio.h>
#include <stdlib.h>

void printv(char vet[], int tam){
    int i;
    printf("(");
    for(i=0; i<tam; i++){
            if(i>0){
                printf(", ");
            }
        printf("%c", vet[i]);
    }
    printf(")\n");
}
int strTam(char str[]){
    int i = -1;
    for(i=0; str[i] != '\0'; i++);
    return i;
}
void deslocaTexto(char str[], int dist, int inicio, int tam){
    int i;
    int l = strTam(str);
    int ls = l - inicio;

    if(l + dist > tam || inicio + dist < 0) {
        return;
    }

    for(i = 0; i <= ls; i++){
        if(dist >= 0){
            //printf(">>> move %d para %d\n", l-i, l-i+dist);
            str[l-i+dist] = str[l-i];
            str[l-i] = ' ';
        } else {
            //printf("<<< move %d para %d\n", inicio+i, inicio+dist+i);
            str[inicio+dist+i] = str[inicio+i];
            str[inicio+i] = ' ';
        }
    }
}
int procuraPalavra(char palavra[], char texto[], int inicio){
    int i, j;
    for(i = inicio; texto[i] != '\0'; i++){
        //printf("procura palavra a partir de %d\n", i);

        for(j = 0; ; j++){

           // printf("%c == %c\n", texto[i+j], palavra[j]);
            if(palavra[j] == '\0'){
                //printf("palavra encontrada!\n");
                return i;
            }
            if(palavra[j] != texto[i+j]){
                //printf("caracter diferente!\n");
                break;
            }
        }
    }
    return -1;
}
int escrevePalavra(char palavra[], char texto[], int posicao) {
    int i;
    for(i = 0; palavra[i] != '\0'; i++){
        texto[posicao + i] = palavra[i];
    }
}
int replace(char palavra[], char texto[], char substituto[], int inicio) {
    int pos_encontrada = 0;
    int in = inicio;
    int tam_palavra = strTam(palavra);
    int dist = strTam(substituto) - tam_palavra;

    while(pos_encontrada != -1) {
        pos_encontrada = procuraPalavra(palavra, texto, pos_encontrada+tam_palavra);

        printf("pos_encontrada: %d\n", pos_encontrada);

        if(pos_encontrada + tam_palavra <= strTam(texto)) {

            printf("dist: %d\n", dist);

            if(dist!=0){
                //libera espaço
                deslocaTexto(texto, dist, pos_encontrada + tam_palavra, strTam(texto));
            }

            printf("espaço liberado: %s\n", texto);

            //escreve palavra
            escrevePalavra(palavra, texto, pos_encontrada);
        }
    }
}


int main()
{
    char vetor[10] = {'a', 'b', 'c', '\0'};
    char str[50] = "string pra teste do vetor teste";
    char str_teste[] = "teste";
    char palavra[] = "algoritmos";

   // printv(vetor, 10);
   // printf("tam-str: %d\n", strTam(vetor));

   // deslocaTexto(vetor, 3, 0, 10);

    //printv(vetor, 10);
   // printf("tam-str: %d\n", strTam(vetor));

   // printf("-----------\n");

    //deslocaTexto(vetor, -2, 3, 10);

   //printv(vetor, 10);
   // printf("tam-str: %d\n", strTam(vetor));

   // printf("-----------\n");

   // printf("pos: %d\n", procuraPalavra(str_teste, str, 0));// 11
   // printf("pos: %d\n", procuraPalavra(str_teste, str, 11+5));// 11

    //escrevePalavra(palavra, str, 11);

    printf("%s\n", str);

    replace(str_teste, str, palavra, 0);

    printf("%s\n", str);

    return 0;
}
