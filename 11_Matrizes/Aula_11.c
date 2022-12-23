// Exercicios da aula 11 - Matrizes

//inclusões:

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

/*Exercicio 01:
Faça um programa que leia uma matriz 5x5 e um procedimento
que imprima sua transposta.*/

//Constantes:
#define NUM_LINHAS  5
#define NUM_COLUNAS 5
#define SUCESSO     0

/*Função utilizada para ler os elementos da matriz */
void LeMatriz(float Matriz[NUM_LINHAS][NUM_COLUNAS]) {
    uint8_t i, j;

    for (i = 0; i < NUM_LINHAS; i++) {
        for (j = 0; j < NUM_COLUNAS; j++) {
            scanf("%f", &Matriz[i][j]);
        }
    }
}

/*Função que imprime uma tabela para os valores de uma matriz */
void ImprimeTabelaMatriz(float Matriz[NUM_LINHAS][NUM_COLUNAS]) {
    uint8_t i, j;

    //imprime a tabela:
    printf("------------------------------------------\n");
    for (i = 0; i < NUM_LINHAS; i++) {
        printf("|");
        for (j = 0; j <= NUM_COLUNAS; j++) {
            if (j == NUM_COLUNAS) {
                printf("\n");
                printf("------------------------------------------\n");
            }
            else {
                printf("%2.f\t|", Matriz[i][j]);
            }

        }
    }
    printf("\n");

}

/* Função que imprime uma tabela transposta à uma matriz recebida como parametro*/
void ImprimeTransposta(float Matriz[NUM_LINHAS][NUM_COLUNAS]) {
    uint8_t i, j;
    float transposta[NUM_LINHAS][NUM_COLUNAS];

    //Preenche a matriz "transposta"
    for (i = 0; i < NUM_LINHAS; i++) {
        for (j = 0; j < NUM_COLUNAS; j++) {
            transposta[i][j] = Matriz[j][i];
            printf("matriz[%d][%d]: %2.f\n", i, j, transposta[i][j]);
        }
    }
    //Chama uma função que imprime a tabela da Matriz
    printf("A tabela dessa matriz eh:\n");
    ImprimeTabelaMatriz(transposta);

}

void exercicio01() {
    float Matriz[NUM_LINHAS][NUM_COLUNAS];

    //Lê os numeros da matriz
    printf("Digite uma os elementos de uma matriz (5x5), para reseber sua transposta:\n");
    LeMatriz(Matriz);

    //Imprime a tabela da matriz
    printf("Tabela da matriz digitada:\n");
    ImprimeTabelaMatriz(Matriz);
    //Imprime a transposta da matriz
    ImprimeTransposta(Matriz);

}

/*Exercicio 02:
Crie uma função que receba uma matriz de números reais e
retorne a soma dos elementos desta matriz.*/

//Constrantes:
#define NUM_LINHAS_ex02 5
#define NUM_COLUNAS_ex02 2

/*Função utilizada para ler os elementos da matriz*/
void LeMatriz_ex02(float Matriz[NUM_LINHAS_ex02][NUM_COLUNAS_ex02]) {
    uint8_t i, j;

    for (i = 0; i < NUM_LINHAS_ex02; i++) {
        for (j = 0; j < NUM_COLUNAS_ex02; j++) {
            scanf("%f", &Matriz[i][j]);
        }
    }
}

/*Função que recebe uma matriz e calcula a soma dos seus elementos*/
float SomaMatriz(float Matriz[NUM_LINHAS_ex02][NUM_COLUNAS_ex02]) {
    uint8_t i, j;
    float Soma = 0;

    //Calcula a soma dos elementos 
    for (i = 0; i < NUM_LINHAS_ex02; i++) {
        for (j = 0; j < NUM_COLUNAS_ex02; j++) {
            Soma += Matriz[i][j];
        }
    }

    //retorna os elementos
    return Soma;
}

void exercicio02() {
    float Matriz[NUM_LINHAS_ex02][NUM_COLUNAS_ex02], soma;

    //Lê os valores da matriz
    printf("Digite os elementos de uma matriz:\n");
    LeMatriz_ex02(Matriz);
    soma = SomaMatriz(Matriz);

    //imprime a soma dos elementos da matriz
    printf("A soma dos elementos da matriz eh: %2.f\n", soma);
}

/*Exercicio 03:
Faça um programa que leia um vetor de dimensão 5 e uma
matriz quadrada de dimensão 5. Crie um procedimento que
multiplique o vetor pela matriz. Imprima o resultado.*/

#define TAMANHO_VETOR 5

void LeVetor(float Vetor[TAMANHO_VETOR]) {
    int i;

    for (i = 0; i < TAMANHO_VETOR; i++) {
        scanf("%f", &Vetor[i]);
    }
}

void MultiplicaVetor_Imprime(float Matriz[NUM_LINHAS][NUM_COLUNAS], float Vetor[TAMANHO_VETOR]) {
    uint8_t i, j;
    float Multiplicacao[NUM_LINHAS];

    for (i = 0; i < NUM_LINHAS; i++) {
        for (j = 0; j < NUM_COLUNAS; j++) {
            Multiplicacao[i] += Vetor[j] * Matriz[i][j];
        }
        printf("===\n");
        printf("|");
        printf("%2.f|\n", Multiplicacao[i]);
    }
}

void ImprimeTabelaVetor(float Vetor[TAMANHO_VETOR]) {
    uint8_t i;

    for (i = 0; i < TAMANHO_VETOR; i++) {
        printf("===\n");
        printf("|");
        printf("%2.f|\n", Vetor[i]);
    }
}

void exercicio03() {
    float Matriz[NUM_LINHAS][NUM_COLUNAS], Vetor[TAMANHO_VETOR];

    printf("Digite os elementos da matriz:\n");
    LeMatriz(Matriz);

    printf("Agora digite os elementos do vetor:\n");
    LeVetor(Vetor);

    printf("A tabela da matriz eh:\n");
    ImprimeTabelaMatriz(Matriz);

    printf("A tabela do Vetor eh:\n");
    ImprimeTabelaVetor(Vetor);

    printf("E o resultado da multiplicacao dos dois eh:\n");
    MultiplicaVetor_Imprime(Matriz, Vetor);
}

/*Exercicio 04:
Faça um programa para ler a quantidade de um total de 5
produtos que uma empresa tem em suas 7 lojas e imprimir em uma
tabela:
a) o total de cada produto nestas lojas
b) a loja que tem menos produtos*/

//Constantes:
#define NUM_LOJAS     7
#define NUM_PRODUTOS  5
#define MAIOR_VALOR_32b (0x7FFFFFFF)

//Lê a quantidade de todos os produtos
void LeProdutoPorLoja(int QuantidadeProdutos[NUM_LOJAS][NUM_PRODUTOS]) {
    uint8_t i, j;

    for (i = 0; i < NUM_LOJAS; i++) {
        for (j = 0; j < NUM_PRODUTOS; j++) {
            printf("Loja %d, produto %d: ", (i + 1), (j + 1));
            scanf("%d", &QuantidadeProdutos[i][j]);
        }
    }
}

/*Função que imprime a quantidade total de cada produto*/
void ImprimeTotalProdutoPorLoja(int QuantidadeProdutos[NUM_LOJAS][NUM_PRODUTOS]) {
    int TotalProdutosPorLoja, TotalGeral = 0;
    uint8_t i, j;

    printf("Total:\t|");

    for (i = 0; i < NUM_PRODUTOS; i++) {
        TotalProdutosPorLoja = 0;
        for (j = 0; j < NUM_LOJAS; j++) {
            TotalProdutosPorLoja += QuantidadeProdutos[j][i];
        }
        TotalGeral += TotalProdutosPorLoja;
        printf("%d\t\t|", TotalProdutosPorLoja);
    }
    printf("%d", TotalGeral);
    printf("\n");
}

/*imprime a tabela com a quantidade de produtos,
quantidade total de produtos
e a loja que tem menos produtos*/
void ImprimeTabelaLojaProduto(int QuantidadeProdutos[NUM_LOJAS][NUM_PRODUTOS]) {
    uint8_t i, j;
    int QuantidadeTotal, menornumero = MAIOR_VALOR_32b, LojaMenorQuantidade;

    //Cabeçalho da tabela
    printf("Loja:\t produto 1:\t produto 2:\tproduto 3:\t produto 4:\tproduto 5:\t Total por loja:\n");

    //tabela
    for (i = 0; i < NUM_LOJAS; i++) {
        QuantidadeTotal = 0;

        //Imprime qual é a loja referente à linha da tabela
        printf("|%d\t|", (i + 1));

        //imprime a quantidade de produtos na tabela
        for (j = 0; j < NUM_PRODUTOS; j++) {
            printf("%d\t\t|", QuantidadeProdutos[i][j]);
            QuantidadeTotal += QuantidadeProdutos[i][j];
        }

        //Verifica qual é a loja que tem menos produtos
        if (QuantidadeTotal < menornumero) {
            menornumero = QuantidadeTotal;
            LojaMenorQuantidade = i + 1;
        }
        printf("%d", QuantidadeTotal);
        printf("\n===========================================================================================\n");
    }
    ImprimeTotalProdutoPorLoja(QuantidadeProdutos);

    //Fala qual é a loja com menor quantidade de produtos
    printf("A loja com a menor quantidade de produtos eh:\n%d\n", LojaMenorQuantidade);
}

void exercicio04() {
    int QuantidadeProdutos[NUM_LOJAS][NUM_PRODUTOS];

    //Lê a quantidade de cada produto, em cada loja
    printf("Digite a quantidade de produtos na respectiva loja:\n");
    LeProdutoPorLoja(QuantidadeProdutos);

    /*imprime a tabela com a quantidade de produtos,
    quantidade total de produtos
    e a loja que tem menos produtos*/
    ImprimeTabelaLojaProduto(QuantidadeProdutos);
}

/*Código usado para que o usuario escolha qual exercicio quer executar*/
int main(int argc, char** argv) {
    int nExercicio;
    char lixo;

    do {
        printf("Digite o numero do exercicio que quer executar (1 a 4). Digite 0 para sair: ");
        scanf("%d%c", &nExercicio, &lixo);

        switch (nExercicio) {
        case 0: break;
        case 1: {
            exercicio01();
            break;
        }
        case 2: {
            exercicio02();
            break;
        }
        case 3: {
            exercicio03();
            break;
        }
        case 4: {
            exercicio04();
            break;
        }
        default: {
            printf("Voce escolheu um exercicio invalido.\n");
        }
        }
    } while (nExercicio != 0);

    return SUCESSO;
}