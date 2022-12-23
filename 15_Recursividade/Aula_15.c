// Aula 15 - Recursividade.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.

//Inclusões
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//Constantes
#define SUCESSO   0

/*Exercicio 1 
Faça um procedimento recursivo que receba dois valores
inteiros a e b e imprima o intervalo fechado entre eles. Se a for
maior que b mostrar mensagem de erro.*/

/*----------------------------------------------------------------------*/

//procedimento que recebe dois numeros e imprime o intervalo entre eles
void ImprimeIntervalo(int ValorA, int ValorB) {
    //Imprime todos os numeros
    (void)printf("%d ", ValorA);

    //Se o valor a é maior que o valor b não é possivel imprimir o intervalo
    if (ValorA > ValorB) {
        (void)printf("\nNumeros invalidos, o primeiro numero deve ser menor que o segundo\n");
        return;
    }
    //Se o valor A é menor que o valor B, então o intervalo será imprimido
    else if(ValorA < ValorB) {
        ValorA++;
        //Parte recursiva
        ImprimeIntervalo(ValorA, ValorB);
    }
    else {
        (void)printf("\n");
        return;
    }
}

/*----------------------------------------------------------------------*/

void exercicio01() {
    int ValorA, ValorB;

    //Pede os numeros
    (void)printf("Digite dois numeros para que seja impresso o intervalo fechado entre eles (o primeiro deve ser menor que o segundo)\n");
    scanf("%d %d", &ValorA, &ValorB);

    getchar(); //Para tirar o '\n' do buffer
    
    ImprimeIntervalo(ValorA, ValorB);
    (void)printf("\n");
}

/*Exercicio 2
Seja S um vetor de inteiros. Descreva funções recursivas para
calcular:
1 o elemento máximo de S;
2 a soma dos elementos de S;
3 média aritmética dos elementos de S.*/

//Constantes
#define QUANTIDADE_MAXIMA_VETOR 5

/*----------------------------------------------------------------------*/

//Função que retorna o maior numero de um dado vetor
int ElementoMaximoDoVetor(int * Vetor, int PosicaoVetor, int MaiorNum) {
    //Se o vetor atual for maior que o maior numero, ele se torna o novo maior
    if (Vetor[PosicaoVetor] > MaiorNum) {
        MaiorNum = Vetor[PosicaoVetor];
    }

    //Se o vetor chegou a posição 0, então já passou por todo o vetor
    if (PosicaoVetor == 0) {
        if (Vetor[0] > MaiorNum) {
            return Vetor[0];
        }
        else {
            return MaiorNum;
        }
    }

    //Parte recursiva
    ElementoMaximoDoVetor(Vetor, PosicaoVetor - 1, MaiorNum);
}

//Função que soma os elementos de um dado vetor
int SomaDosElementos(int* Vetor, int PosicaoVetor, int Soma) {
    //Soma o vetor atual
    Soma += Vetor[PosicaoVetor];

    //Se o vetor chegou a posição 0, então já passou por todo o vetor
    if (PosicaoVetor == 0) {
        return Soma;
    }

    //Parte recursiva
    SomaDosElementos(Vetor, PosicaoVetor - 1, Soma);
}

//Função que calcula a media aritmetica de um vetor, usando a função RECURSIVA "SomaDosElementos"
float MediaAritimetidcaDosElementosDoVetor(int* Vetor, int PosicaoVetor, int Soma) {
    return SomaDosElementos(Vetor, PosicaoVetor, Soma) / ((1.0f) * QUANTIDADE_MAXIMA_VETOR);
}

/*----------------------------------------------------------------------*/

void exercicio02() {
    int Vetor[QUANTIDADE_MAXIMA_VETOR], ElementoMaximo, SomaElementos = 0, PosicaoVetor = QUANTIDADE_MAXIMA_VETOR - 1, MaiorNum = INT_MIN;
    float MediaElementos;

    //O usuario preenche o vetor
    (void)printf("\nPreencha o vetor de %d posicoes\n", QUANTIDADE_MAXIMA_VETOR);
    for (int i = 0; i < QUANTIDADE_MAXIMA_VETOR; i++) {
        scanf("%d", &Vetor[i]);
    }

    //Pega o elemento maximo, a media dos elementos, e a soma dos elementos do vetor dado
    ElementoMaximo = ElementoMaximoDoVetor(Vetor, PosicaoVetor, MaiorNum);
    MediaElementos = MediaAritimetidcaDosElementosDoVetor(Vetor, PosicaoVetor, SomaElementos);
    SomaElementos = SomaDosElementos(Vetor, PosicaoVetor, SomaElementos);

    //Imprime os dados
    (void)printf("Elemento maximo do vetor: %d\n", ElementoMaximo);
    (void)printf("Soma dos elementos do vetor: %d\n", SomaElementos);
    (void)printf("Media dos elementos do vetor: %f\n", MediaElementos);
    
    (void)printf("\n");
}

/*Exercicio 3
Escreva uma função recursiva para calcular o N-ésimo número
da sequência de Fibonacci.*/

/*----------------------------------------------------------------------*/

//Função que calcula o N-ésimo número da sequência de Fibonacci
long long int CalculaFibonacci(float n) {

    //A recursividade para aqui
    if ((n == 1) || (n == 2)) {
        return 1;
    }
    //Segue a formula da serie de Fibonacci (F(n) = F(n - 1) + F(n - 2))
    return CalculaFibonacci(n - 1) + CalculaFibonacci(n - 2);    //Parte recursiva
}

/*----------------------------------------------------------------------*/

void exercicio03() {
    long long int fibonacci, n;

    //Pede o numero para o usuario
    (void)printf("\nDigite o numero para a serie de fibonacci\n");
    scanf("%lli", &n);

    fibonacci = CalculaFibonacci(n);

    (void)printf("O numero da serie fibonacci correspondente ao numero digitado eh: %lli\n", fibonacci);
}

/*Exercicio 4
Escreva uma função recursiva para determinar o número de
dígitos de um inteiro N.*/

//Constantes
#define SUCESSO_CONTAGEM 1

/*----------------------------------------------------------------------*/

//Função que conta os digitos de um numero inteiro
int ContaDigitos(int n, int ContagemDeDigitos) {

    //Se o numero for menor que 10 então a contagem acabou
    if (n < 10) {
        return ContagemDeDigitos;
    }
    else {
        return ContaDigitos(n / 10, ContagemDeDigitos + 1);    //Parte recursiva
    }
}

/*----------------------------------------------------------------------*/

void exercicio04() {
    int n;
    int  ContagemDeDigitos = 1;

    //Pede o numero ao usuario
    (void)printf("\nDigite um numero para saber a sua quantidade de digitos\n");
    scanf("%d", &n);

    getchar(); //Para tirar o '\n' do buffer

    ContagemDeDigitos = ContaDigitos(n, ContagemDeDigitos);

    (void)printf("A quantidade de digitos do numero eh: %d\n", ContagemDeDigitos);
}

/*Exercicio 5
Escreva uma função recursiva que busque por um determinado
elemento em um vetor de inteiros.*/

#define TAMANHO_MAXIMO_VETOR_EX05E06  10

/*----------------------------------------------------------------------*/

//Função que olha de elemento em elemento no vetor para saber onde esta um dado numero
int AchaInteiroNoVetor(int* Vetor, int posicaoAtual, int n) {
    //Se a posição atual for igual ao numero dado retorna a posição
    if (Vetor[posicaoAtual] == n) {
        return posicaoAtual;
    }
    else {
        return AchaInteiroNoVetor(Vetor, posicaoAtual + 1, n);    //Parte recursiva
    }
}

/*----------------------------------------------------------------------*/

void exercicio05() {
    int Vetor[TAMANHO_MAXIMO_VETOR_EX05E06] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n, posicaoNoVetor, posicaoAtual = 0;
    //Pega com o usuario um numero de 1 a 10
    (void)printf("\nDigite um numero de 1 a 10, para saber em qual posicao do vetor ele esta: ");
    scanf("%d", &n);
    //testa se o numero realmente esta entre 1 e 10
    if (n < 1 || n > 10) {
        fprintf(stderr, "O Numero digitado deve ser um numero entre 1 e 10\n");
    }

    posicaoNoVetor = AchaInteiroNoVetor(Vetor, posicaoAtual, n);

    (void)printf("O inteiro digitado esta na posicao %d do vetor", posicaoNoVetor);
}

/*Desafio
Implemente uma função recursiva que realize a busca binária
em um vetor de números inteiros.*/

//Constantes
#define SEM_O_NUMERO  (-1)


/*----------------------------------------------------------------------*/

//Função de busca binaria
int BuscaBinaria(int* Vetor, int n, int inicio, int fim) {
    int meio;

    //Se o inicio for maior que o fim, então o numero não está no vetor
    if (inicio <= fim) {
        //"coloca" o meio no meio
        meio = (inicio + fim) / 2;

        //Se o numero é igual ao numero de posição meio, a posição meio é retornada
        if (n == Vetor[meio]){
        return meio;
        }
        //Se o numero é menor que o numero de posição meio, o numero está entre o inicio e o meio, então o fim é igual a meio - 1
        else if(n < Vetor[meio]) {
            fim = meio - 1;
            return BuscaBinaria(Vetor, n, inicio, fim);    //Parte recursiva
        }
        //Se o numero é maior que o numero de posição meio, o numero está entre o meio e o fim, então o inicio é igual a meio + 1
        else if (n > Vetor[meio]) {
            inicio = meio + 1;
            return BuscaBinaria(Vetor, n, inicio, fim);    //Parte recursiva
        }

    }

    //Se o numero não estiver no vetor retorna -1
    return SEM_O_NUMERO;
}

/*----------------------------------------------------------------------*/

void desafio() {
    int Vetor[TAMANHO_MAXIMO_VETOR_EX05E06] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, n;

    //Pega o numero com o usuario
    (void)printf("Digite um numero para saber em qual posicao do vetor o numero esta: ");
    scanf("%d", &n);

    n = BuscaBinaria(Vetor, n, 0, TAMANHO_MAXIMO_VETOR_EX05E06 - 1);

    //Testa se o numero está ou não no vetor
    if (n == SEM_O_NUMERO) {
        (void)printf("O numero digitado nao esta no vetor\n");
    }
    else {
        (void)printf("O numero digitado esta na posicao %d\n", n);
    }
}

//Main. O usuario escolhe qual exercicio ele deseja executar
int main(int argc, char** argv) {
    int nExercicio;
    char lixo;

    do {
        (void)printf("Digite o numero do exercicio que quer executar (1 a 5, e 6 para o desafio). Digite 0 para sair: ");
        scanf("%d%c", &nExercicio, &lixo);

        switch (nExercicio) {
        case 0: break;
        case 1: {
            exercicio01();
            (void)printf("\n");
            break;
        }
        case 2: {
            exercicio02();
            (void)printf("\n");
            break;
        }
        case 3: {
            exercicio03();
            (void)printf("\n");
            break;
        }
        case 4: {
            exercicio04();
            (void)printf("\n");
            break;
        }
        case 5: {
            exercicio05();
            (void)printf("\n");
            break;
        }
        case 6: {
            desafio();
            (void)printf("\n");
            break;
        }
        default: {
            (void)printf("Voce escolheu um exercicio invalido.\n");
        }
        }
    } while (nExercicio != 0);


    return SUCESSO;
}