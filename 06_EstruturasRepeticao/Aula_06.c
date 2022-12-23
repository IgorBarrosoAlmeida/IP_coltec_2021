//Exercicios aula 6

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*Exercicio 1
Elabore um programa que calcule N! (fatorial de N), sendo que o
valor inteiro de N é fornecido pelo usuário.*/

void exercicio01(void) {
    int i, NUM;
    int fatorial;

    printf("Digite um numero para saber seu fatorial: \n");
    scanf_s("%i", &NUM);

    fatorial = 1;
    for (i = 2; i <= NUM; i++) {
        fatorial *= i;
    }
    printf("%d!: %i\n", NUM, fatorial);
}

/*Exercicio 2
Escrever um algoritmo que lê um valor N inteiro e positivo e que
calcula e escreve o valor de E: E = 1 + 1/2! + 1/3! + ... + 1/N!*/

void exercicio02(void) {
    int NUM, div;
    float E;
    int i, j;

    printf("Digite numero para saber seu valor de E:\n");
    scanf_s("%i", &NUM);

    E = 1.0;

    for (i = 2; i <= NUM; i++){
        div = 1;
        for (j = 1; j <= i; j++) {
            div *= j;
        }
        E += (1.0 / div);
    }
    printf("O valor de E para o numero %i eh %f\n", NUM, E);

}


/*Exercicio 3
Faça um programa que, dado um conjunto de valores inteiros e
positivos (fornecidos um a um pelo usuário), determine qual o
menor e o maior valor do conjunto. O final do conjunto de valores é
conhecido através do valor zero, que não deve ser considerado.*/

void exercicio03(void) {
    int Numeros;
    int Maior, Menor;
    
    Maior = 0;
    Menor = 0;

    printf("Escreva uma sequencia de números inteiros e positivos (digite e aperte enter).\nQuando quiser parar digite 0:\n");

    do {
        scanf_s("%d", &Numeros);

        if (Menor == 0) {
            Menor = Numeros;
        }
        if (Numeros != 0) {           
            if (Numeros > Maior) {
                Maior = Numeros;
            }
            if (Numeros < Menor) {
                Menor = Numeros;
            }
        }
    } while (Numeros != 0);

    printf("O maior numero digitado foi %d e o menor foi %d\n", Maior, Menor);

}


/*Exercicio 4
Fazer um programa para calcular e mostrar os N primeiros termos
da série de Fibonacci. O número N é fornecido pelo usuário. A série
de Fibonacci é : 1 1 2 3 5 8 13 ... Isto é f1 = f2 = 1, f3 = f1 + f2,
f4 = f2 + f3...*/

void exercicio04(void) {    
    int NUM, fib = 0, temp2 = 1, i, temp1;

    printf("Digite um nuemro para saber a serue fibannacci:\n");
    scanf_s("%i", &NUM);

    

    for (i = 1; i <= NUM; i++) {
        printf("Termo %i = %i\n", i, fib);
        temp1 = fib + temp2;
        fib = temp2;
        temp2 = temp1;
    }
}




/*Exercicio 5
A conversão de graus Fahrenheit para Centígrados é obtida pela
fórmula C = 9*(F-32)/5. Escreva um programa que calcule e
escreva uma tabela de graus centígrados em função de graus
Fahrenheit que variem de 50 a 150 de 1 em 1.*/

void exercicio05(void) {
    float C, f;
    float MenorF = 50, MaiorF = 150;

    printf("Tabela de conversão de Fahrenheit para centígrados\n");
    printf("!-----------------------------------!\n");
    printf("!Fahrenheit ! \tCentígrados!\n");
    for (f = MenorF; f <= MaiorF; f++) {
        C = (f - 32) * 5/9;
        printf("!-----------------------------------!\n");
        printf("!%.2f ! \t%.2f!\n", f, C);
    }
    printf("!-----------------------------------!\n");
}

#define Sucesso 0;

int main(int argc, char** argv) {

    int nExercicio;

    do {
        printf("Digite o numero do exercicio que quer executar (1 a 5). Digite 0 para sair: ");
        scanf_s("%d", &nExercicio);

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
        default: {
            printf("Voce escolheu um exercicio invalido.\n");
        }
        }
    } while (nExercicio != 0);
    
    return Sucesso;
}