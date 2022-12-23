// Exercícios Aula 12 - Alocação dinâmica + Ponteiros

//Inclusões
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

/*Exercício 01:
Implemente uma função que aloque dinamicamente um vetor
de inteiros. Essa função deverá receber como parâmetro um
inteiro representando o tamanho do vetor, e retornar um
ponteiro representando o vetor alocado.*/

/*Função que aloca dinamicamente um vetor de inteiros 
e retorna o ponteiro que representa a primeira posição do vetor*/
int* AlocaVetorInt(int TamanhoVetor) {
    //retorna o resultado da função malloc
    return (int *)malloc(TamanhoVetor * sizeof(int));
}

void exercicio01() {
    int* Vetor;
    int TamanhoVetor;
    
    //Lê o tamanho do vetor 
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &TamanhoVetor);

    Vetor = AlocaVetorInt(TamanhoVetor);

    free(Vetor);
}

/*Exercício 02:
Implemente uma função que aloque dinamicamente uma
matriz de números reais. Essa função deverá receber como
parâmetro dois inteiros representando o tamanho da matriz, e
retornar um ponteiro de ponteiros representando a matriz
alocada.*/

//Função que aloca dinamicamente uma matriz de float
float** AlocaMatrizReal(int Linhas, int Colunas) {
    float** Matriz;
    uint8_t i;

    Matriz = (float**)malloc(Linhas * sizeof(float *));
    
    for (i = 0; i < Linhas; i++) {
        Matriz[i] = (float*)malloc(Colunas * sizeof(float));
    }

    return Matriz;
}

//Função usada para dar free em uma matriz
void LiberaMatriz(float** Matriz, int Linhas) {
    uint8_t i;

    for (i = 0; i < Linhas; i++) {
        free(Matriz[i]);
    }

    free(Matriz);
}

void exercicio02() {
    float** Matriz;
    int Linhas, Colunas;

    //Lê a quantidade de linhas e colunas
    printf("Digite a quantidade de linhas e colunas da matriz:\n");
    scanf("%d %d", &Linhas, &Colunas);

    Matriz = AlocaMatrizReal(Linhas, Colunas);

    LiberaMatriz(Matriz, Linhas);
}

/*Exercício 03:
Faça ̧a um programa que leia um vetor de um tamanho
escolhido pelo usuário e calcule a média aritmética de seus
valores.*/
float* AlocaVetorFloat(int TamanhoVetor) {
    //retorna o resultado da função malloc
    return (float*)malloc(TamanhoVetor * sizeof(float));
}

float CalculaMediaVetor(float* Vetor, int TamanhoVetor) {
    float soma = 0;
    uint8_t i;
    
    //Calcula a média dos elementos do vetor
    for (i = 0; i < TamanhoVetor; i++) {
        printf("Digite o Vetor[%d]: ", i);
        scanf("%f", &Vetor[i]);
        soma += Vetor[i];
    }

    return soma / TamanhoVetor;
}

void exercicio03() {
    float* Vetor;
    float media;
    int TamanhoVetor;

    //Lê o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &TamanhoVetor);

    Vetor = AlocaVetorFloat(TamanhoVetor);

    media = CalculaMediaVetor(Vetor, TamanhoVetor);

    //Mostra para o usuario a média dos vetores
    printf("A media dos valores digitados eh:\n%f\n", media);
    
    free(Vetor);

}

/*Exercício 04:
Faça um programa que leia um vetor de números reais de
tamanho escolhido pelo usuário e descubra qual é o maior e
menor valor existente no vetor, junto de seu índice.*/

/*Função que lê um vetor real*/
void LeVetorReal(float* Vetor, int TamanhoVetor) {
    uint8_t i;
    
    for (i = 0; i < TamanhoVetor; i++) {
        printf("Digite o vetor[%d]", i);
        scanf("%f", &Vetor[i]);
    }
}

/*Função que indica o maior numero digitado e seu indice*/
void QualMaiorVetor(float* Vetor, int TamanhoVetor) {
    uint8_t i, IndiceMaior = 0;
    float  MaiorNum = INT_MIN;

    //Testa de numero em numero para ver qual é o maior
    for (i = 0; i < TamanhoVetor; i++) {
        if (Vetor[i] > MaiorNum) {
            MaiorNum = Vetor[i];
            IndiceMaior = i;
        }
    }

    //Mostra o numero ao usuario
    printf("O maior numero digitade foi: %f (indice %d)\n", MaiorNum, IndiceMaior);
}

/*Função que indica o menor numero digitado e seu indice*/
void QualMenorVetor(float* Vetor, int TamanhoVetor) {
    uint8_t i, IndiceMenor = 0;
    float MenorNum = INT_MAX;

    //Testa de numero em numero para ver qual é o menor
    for (i = 0; i < TamanhoVetor; i++) {
        if (Vetor[i] < MenorNum) {
            MenorNum = Vetor[i];
            IndiceMenor = i;
        }
    }

    //Mostra o numero ao usuario
    printf("O menor numero digitade foi: %f (indice %d)\n", MenorNum, IndiceMenor);
}

void exercicio04() {
    int TamanhoVetor;
    float* Vetor;

    //Lê o tamanho do vetor
    printf("Digite o tamanho do vetor desejado: ");
    scanf("%d", &TamanhoVetor);

    Vetor = AlocaVetorFloat(TamanhoVetor);

    LeVetorReal(Vetor, TamanhoVetor);

    QualMaiorVetor(Vetor, TamanhoVetor);
    QualMenorVetor(Vetor, TamanhoVetor);

    free(Vetor);
}

/*Exercício 05:
Implemente um programa que receba uma matriz de números
reais e retorne a soma dos elementos desta matriz. A matriz
deverá ser alocada dinamicamente.*/

/*Função que soma todos os elementos de uma matriz*/
float SomaElementosMatriz(float** Matriz, int Linhas, int Colunas) {
    float Soma = 0;
    uint8_t i, j;

    //Vai de elemento em elemento somando todos
    for (i = 0; i < Linhas; i++) {
        for (j = 0; j < Colunas; j++) {
            Soma += Matriz[i][j];
        }
    }

    return Soma;
}

void exercicio05() {
    float** Matriz;
    float Soma;
    int Linhas, Colunas, i, j;

    //Lê o tamanho da matriz
    printf("Digite o tamanho da matriz (linhas colunas): ");
    scanf("%d %d", &Linhas, &Colunas);

    Matriz = AlocaMatrizReal(Linhas, Colunas);

    //Lê os valores da matriz
    printf("Digite os valores da matriz:\n");
    for (i = 0; i < Linhas; i++) {
        for (j = 0; j < Colunas; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%f", &Matriz[i][j]);
        }
    }

    Soma = SomaElementosMatriz(Matriz, Linhas, Colunas);

    printf("A soma dos elementos da matriz eh: %.2f\n", Soma);

    LiberaMatriz(Matriz, Linhas);
}

/*Exercício 06:
Faça um programa para ler a quantidade de um total de X
produtos que uma empresa tem em suas Y lojas e imprimir em
uma tabela:
1 o total de cada produto nestas lojas
2 a loja que tem menos produtos*/

/*Função que imprime a quantidade total de cada produto*/
void ImprimeTotalProdutoPorLoja(float** LojaProduto, int Lojas, int Produtos) {
    float TotalProdutosPorLoja, TotalGeral = 0;
    uint8_t i, j;

    printf("Total:\t|");

    for (i = 0; i < Produtos; i++) {
        TotalProdutosPorLoja = 0;
        for (j = 0; j < Lojas; j++) {
            TotalProdutosPorLoja += LojaProduto[j][i];
        }
        TotalGeral += TotalProdutosPorLoja;
        printf("%2.f\t\t|", TotalProdutosPorLoja);
    }
    printf("%2.f", TotalGeral);
    printf("\n");
}

/*imprime a tabela com a quantidade de produtos,
quantidade total de produtos
e a loja que tem menos produtos*/
void ImprimeTabelaLojaProduto(float** LojaProduto, int Lojas, int Produtos) {
    uint8_t i, j;
    float QuantidadeTotal, menornumero = INT_MAX, LojaMenorQuantidade = 0;

    //Cabeçalho da tabela
    printf("Loja:\n");

    //tabela
    for (i = 0; i < Lojas; i++) {
        QuantidadeTotal = 0;

        //Imprime qual é a loja referente à linha da tabela
        printf("|%d\t|", (i + 1));

        //imprime a quantidade de produtos na tabela
        for (j = 0; j < Produtos; j++) {
            printf("%2.f\t\t|", LojaProduto[i][j]);
            QuantidadeTotal += LojaProduto[i][j];
        }

        //Verifica qual é a loja que tem menos produtos
        if (QuantidadeTotal < menornumero) {
            menornumero = QuantidadeTotal;
            LojaMenorQuantidade = i + 1;
        }
        printf("%2.f", QuantidadeTotal);
        printf("\n===========================================================================================\n");
    }
    ImprimeTotalProdutoPorLoja(LojaProduto, Lojas, Produtos);

    //Fala qual é a loja com menor quantidade de produtos
    printf("A loja com a menor quantidade de produtos eh:\n%2.f\n", LojaMenorQuantidade);
}

void exercicio06() {
    float** LojaProduto;
    int Lojas, produtos, i, j;

    //Lê a quantidade de lojas e de produtos
    printf("Digite a quantidade de lojas e a quantidade de produtos (ex: X Y)\n");
    scanf("%d %d", &Lojas, &produtos);

    LojaProduto = AlocaMatrizReal(Lojas, produtos);

    //Lê a quantidade de produtos em cada loja
    printf("Digite os valores da matriz:\n");
    for (i = 0; i < Lojas; i++) {
        for (j = 0; j < produtos; j++) {
            printf("Loja %d produto %d: ", i + 1, j + 1);
            scanf("%f", &LojaProduto[i][j]);
        }
    }

    ImprimeTabelaLojaProduto(LojaProduto, Lojas, produtos);

    LiberaMatriz(LojaProduto, Lojas);
}

//Constantes:
#define SUCESSO  0

/*Código usado para que o usuario escolha qual exercicio quer executar*/
int main(int argc, char** argv) {
    int nExercicio;
    char lixo;

    do {
        printf("Digite o numero do exercicio que quer executar (1 a 6). Digite 0 para sair: ");
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
        case 5: {
            exercicio05();
            break;
        }
        case 6: {
            exercicio06();
            break;
        }
        default: {
            printf("Voce escolheu um exercicio invalido.\n");
        }
        }
    } while (nExercicio != 0);

    return SUCESSO;
}