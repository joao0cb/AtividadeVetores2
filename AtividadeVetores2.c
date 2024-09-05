#include <stdio.h>

void preencherVetor(int vetor[], int TAM);
void menu(int vetor[], int *TAM);
int buscaBinaria(int vetor[], int TAM);
int removerElemento(int vetor[], int *TAM, int valor);
int inserirElemento(int vetor[], int *TAM, int valor);

int main() {
    int TAM;
    do {
        printf("Escolha um tamanho para o vetor (Entre 3 e 50)\n");
        scanf("%d", &TAM);
        if(TAM < 3 || TAM > 50) {
            printf("Tamnho para vetor inválido. Tente outro.");
        }
    } while(TAM < 3 || TAM > 50);

    int vetor[50];

    preencherVetor(vetor, TAM);
    menu(vetor, &TAM);

    return 0;
}

void preencherVetor(int vetor[], int TAM) {
    int valor, i, j, mem;

    for (i = 0; i < TAM; ++i) {
        printf("Digite um valor para o vetor: ");
        scanf("%d", &valor);
        mem = 0;

        while(mem < i && vetor[mem] < valor) {
            ++mem;
        }
        for(j = i; j > mem; --j) {
            vetor[j] = vetor[j - 1];
        }
        vetor[mem] = valor;
    }
    printf("\nVetor ordenado:\n");
    for(i = 0; i < TAM; ++i) {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");
}

void menu(int vetor[], int *TAM) {
    while(1) {
        int opcao;
        printf("\nSelecione uma das opções abaixo:\n");
        printf("   1 - Imprimir todo o vetor.\n");
        printf("   2 - Consultar em que posição um elemento se encontra dentro do vetor.\n");
        printf("   3 - Remover um elemento do vetor.\n");
        printf("   4 - Inserir (apenas 1 valor) no vetor.\n");
        printf("   0 - Digite 0 para fechar o programa.\n\n");
        scanf("%d", &opcao);
        if(opcao == 1) {
            printf("\nVetor:\n");
            for(int i = 0; i < *TAM; ++i) {  // Usar *TAM aqui
                printf("%d ", vetor[i]);
            }
        printf("\n\n");
        } else if(opcao == 2) {
            int posicao = buscaBinaria(vetor, *TAM);  // Usar *TAM aqui
            if(posicao != -1) {
                printf("Valor encontrado na posição: %d\n", posicao);
            } else {
                printf("Valor não encontrado no vetor.\n");
            }
        } else if(opcao == 3) {
            int valor;
            printf("Digite o valor que deseja remover: ");
            scanf("%d", &valor);
            int result = removerElemento(vetor, TAM, valor);
            if (result != -1) {
                printf("\nValor removido. Vetor atualizado:\n");
                for (int i = 0; i < *TAM; ++i) {  // Usar *TAM aqui
                    printf("%d ", vetor[i]);
                }
                printf("\n\n");
            } else {
                printf("Valor não encontrado no vetor.\n");
            } 
        } else if(opcao == 4) {
            if(*TAM < 50) {  // Usar *TAM aqui
                int valor;
                printf("Qual valor que você deseja inserir? ");
                scanf("%d", &valor);
                inserirElemento(vetor, TAM, valor);
                printf("Vetor atualizado:\n");
                for (int i = 0; i < *TAM; ++i) {  // Usar *TAM aqui
                    printf("%d ", vetor[i]);
                }
                    printf("\n");
            } else {
                printf("Capacidade máxima do vetor atingida.\n");
            }
        } else if(opcao == 0) {
            break;
        }
    }
}

int buscaBinaria(int vetor[], int TAM) {
    int esq = 0, dir = TAM-1, meio, valor;
    printf("Qual valor você quer encontrar? ");
    scanf("%d", &valor);
    while(esq <= dir) {
        meio = (esq + dir) / 2;
        if(valor < vetor[meio]) {
            dir = meio - 1;
            } else if(valor > vetor[meio]) {
                esq = meio + 1;
        } else {
            return meio;
        }
    } return -1;
}

int removerElemento(int vetor[], int *TAM, int valor) {
    int posicao = buscaBinaria(vetor, *TAM);
    if (posicao == -1) {
        return -1;
    }
    for (int i = posicao; i < *TAM - 1; ++i) {
        vetor[i] = vetor[i + 1];
    }
    (*TAM)--;
    return posicao;
}

int inserirElemento(int vetor[], int *TAM, int valor) {
    int i, mem = 0;
    while (mem < *TAM && vetor[mem] < valor) {
        mem++;
    }
    for (i = *TAM; i > mem; i--) {
        vetor[i] = vetor[i - 1];
    }
    vetor[mem] = valor;
    (*TAM)++;
    return mem;
}