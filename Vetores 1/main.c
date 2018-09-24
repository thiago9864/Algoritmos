#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

/******* ORDENAÇÃO POR INSERÇÃO ********/


void insereOrdenado(int vet[], int tam, int indice) {
    int i, indice_inserir, valor_inserir;
    valor_inserir = vet[indice];

    printf("\nArmazena %d\n", valor_inserir);

    indice_inserir = 0;

    for(i=0; i < indice; i++) {
      printf("vet[%d]=%d < vet[%d]=%d\n", i, vet[i], indice, vet[indice]);
      if(vet[i] > indice_inserir) {
         printf("insere %d na posição %d\n",valor_inserir, i);
      }
    }

    for(i=indice-1; i >= 0; i--) {
      printf("--> avança %d para posicao %d\n", i, i+1);
    }


    //vet[indice_inserir] = valor_inserir;

    printf("---------");

}
void ordenacaoPorInsercao(int vet[], int tam) {
    int i, j;
/*
    for(i=0; i < (tam-1); i++) {
        j = i + 1;
        insereOrdenado(vet, tam, j);

        printf("Vetor parcial: ");
        imprimeVetor(vet, tam);
    }
*/
   insereOrdenado(vet, tam, 1);
   insereOrdenado(vet, tam, 2);
    //insereOrdenado(vet, tam, 2);
    //insereOrdenado(vet, tam, 3);


}

void preencheVetorAleatoriamente (int vet[], int tam)
{
    int i; //o vetor sera preenchido com valores de 0 a 999
    srand(time(NULL));
    for (i = 0; i < tam; i++)
        vet[i] = rand() % 1000;
}




/******* ORDENAÇÃO POR SELEÇÃO ********/


int retornaIndiceMenor(int vet[], int tam, int inicio) {
    int i, indiceDoMenor = -1;
    int menor = vet[inicio];
    printf("Iniciando por: %d\n", inicio);
    for(i=inicio+1; i < tam; i++) {
        if(vet[i] <= menor){
            menor = vet[i];
            indiceDoMenor = i;
        }
    }
    printf("Menor numero: %d, no indice: %d\n", menor, indiceDoMenor);
    return indiceDoMenor;
}
void trocaPosicao(int vet[], int tam, int pa, int pb) {

    printf("Inverte indice %d e %d\n", pb, pa);

    int aux = vet[pa];
    vet[pa] = vet[pb];
    vet[pb] = aux;
}

void ordenaPorSelecao(int vet[], int tam) {
    int i, indiceDoMenor;

    for(i=0; i < tam; i++) {
        printf("Iteração %d\n", i);
        indiceDoMenor = retornaIndiceMenor(vet, tam, i);

        if(indiceDoMenor != -1) {
            printf("Vetor anterior: ");
            imprimeVetor(vet, TAMANHO);

            trocaPosicao(vet, tam, i, indiceDoMenor);

            printf("Vetor parcial: ");
            imprimeVetor(vet, TAMANHO);
        } else {
            printf("Pula para proximo indice...\n");
        }
        printf("-------------------------------------\n");
    }
}



/******* ORDENAÇÃO POR CONTAGEM ********/


void ordenaPorContagem(int vet[], int tam, int minimo, int maximo) {
    int num, cont, i, j, k;
    int tamVetorContagem = maximo - minimo + 1;
    int vetorContagem[tamVetorContagem];

    //inicia vetor de contagem
    for(i=0; i<tamVetorContagem; i++) {
        vetorContagem[i] = 0;
    }

    for(i=0; i < tam; i++) {
        num = vet[i];
        j = num - minimo;
        printf("Adicionar 1 a posição %d do vetor de contagem\n", j);
        vetorContagem[j] = vetorContagem[j] + 1;
    }
    /*
    for(i=0, num=minimo; i < tam && num <= maximo; i++, num++){
        printf("Procura por ocorrências de %d\n", i);
        cont = 0;

        for(j=0; j < tam; j++){
            if(vet[j] == num) {
                cont++;
            }
        }

        vetorContagem[i] = cont;
        printf("Vetor contagem: ");
        imprimeVetor(vetorContagem, tamVetorContagem);

        printf("----\n");
    }
    */

    k=0;

    for(i=0; i < tamVetorContagem; i++){
        num = minimo + i;
        cont = vetorContagem[i];

        printf("Inserir %d, %d vezes, no indice %d: \n", num, cont, k);

        for(j=0; j < cont; j++) {
            vet[k] = num;
            k++;
        }
    }

    printf("-------------------------------------\n");
}




void imprimeVetor (int vet[], int tam)
{
    int i;
    printf("(");
    for (i = 0; i < tam; i++) {
        if(i!=0){
            printf(", ");
        }
        printf("%d", vet[i]);

    }
    printf(")\n");
}


int main()
{
    int vetorInsercao[TAMANHO] = {5, 3, 6, 0, 3, 4, 1, 7, 2, 6};

    printf("Vetor original: ");
    imprimeVetor(vetorInsercao, TAMANHO);

    printf("\n######### ORDENA POR INSERCAO #########\n\n");

    ordenacaoPorInsercao(vetorInsercao, TAMANHO);

   // printf("\n######### ORDENA POR SELECAO #########\n\n");

    //ordenaPorSelecao(vetorInsercao, TAMANHO);

    //printf("\n######### ORDENA POR CONTAGEM #########\n\n");

    //ordenaPorContagem(vetorInsercao, TAMANHO, 0, 7);
    imprimeVetor(vetorInsercao, TAMANHO);


    return 0;
}

