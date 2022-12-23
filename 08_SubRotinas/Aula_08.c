#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <iostream>
#define SUCESSO 0;

/*Exercicio 1
Faça um programa que apresente o seguinte menu para o
usuário:
Escolha uma opção de cálculo para dois números:
1 Soma
2 Produto
3 Quociente
4 Sair*/

float soma(float NUM1, float NUM2) {
    return (NUM1 + NUM2);
}

float produto(float NUM1, float NUM2) {
    return (NUM1 * NUM2);
}

float Quociente(float NUM1, float NUM2) {
    return (NUM1 / NUM2);
}

void exercicio01() {
    int operacao;
    float result, NUM1, NUM2;;

    /*repete enquanto o usuario não digitar 4*/
    do {
        /*Pergunta ao usuario qual operação ele quer fazer*/
        printf("Digite o numero correspondente a operacao que deseja (digite 4 para sair):\n1 Soma\n2 Produto\n3 Quociente\n4 Sair\n");
        scanf("%d", &operacao);

        /*Faz as operações*/
        switch (operacao) {
        case 4: break;
        case 1: {
            printf("Agora digite dois numeros para que a operação seja feita:\n");
            scanf("%f %f", &NUM1, &NUM2);
            result = soma(NUM1, NUM2);
            printf("Resultado: %f\n", result);
            break;
        }
        case 2: {
            printf("Agora digite dois numeros para que a operação seja feita:\n");
            scanf("%f %f", &NUM1, &NUM2);
            result = produto(NUM1, NUM2);
            printf("Resultado: %f\n", result);
            break;
        }
        case 3: {
            printf("Agora digite dois numeros para que a operação seja feita:\n");
            scanf("%f %f", &NUM1, &NUM2);
            result = Quociente(NUM1, NUM2);
            printf("Resultado: %f\n", result);
            break;
        }
        }

    } while ( operacao != 4);
}

/*Exercicio 2 
Faça uma função que receba a idade de uma pessoa em anos,
meses e dias e retorna essa idade expressa em dias.*/

int FuncaoIdadeDias(int anos, int meses, int dias) {
    anos = anos * 360;
    meses = meses * 30;
    
    return (anos + meses + dias);
}


void exercicio02() {
    int anos, meses, dias, IdadeEmDias;

    /*Pede as informações para o usuario*/
    printf("Digite sua idade em anos, meses, e dias (Ex: 20, 10, 60):\n");
    scanf("%d, %d, %d", &anos, &meses, &dias);

    /*Função que calcula a idade em dias*/
    IdadeEmDias = FuncaoIdadeDias (anos, meses, dias);

    printf("Sua idade em dias é:\n%d\n", IdadeEmDias);
}

/*Exercicio 3
Faça um procedimento que receba por parâmetro o tempo de
duração de um experimento expresso em segundos e imprima
na tela esse mesmo tempo em horas, minutos e segundos.*/


void calculoSegEmHoras(int tempo) {
    int horas, minutos, segundos;

    /*transforma o tempo em horas, minutos e segundos*/
    minutos = tempo / 60;
    horas = minutos / 60;
    minutos = minutos - (horas * 60);
    segundos = tempo - (minutos * 60) - ((horas * 60) * 60);
    printf("%i:%i:%i\n", horas, minutos, segundos);
    
}

void exercicio03() {
    int tempo;
     
    /*interação com o usuario*/
    printf("Digite o tempo de duracao do experimento (em segundos):\n");
    scanf("%i", &tempo);

    calculoSegEmHoras(tempo);
}

/*Exercicio 4
Implemente uma função que receba um número inteiro como
entrada e verique se esse número é primo ou não. Um
número é primo quando este possui apenas dois divisores (1 e
ele mesmo).*/

int primo(int numero, int div) {
    int i;
    for (i = 2; i < numero; i++) {
        if (numero % i == 0) {
            div++;
        }
    }
    return div;
}

void exercicio04() {
    int numero, ehprimo, div;

    div = 0;
    printf("Digite um numero para saber se ele é primo:\n");
    scanf("%d", &numero);
    
    ehprimo = primo(numero, div);

    if (ehprimo > 0) {
        printf("O numero digitado nao eh primo\n");
    }
    else if (ehprimo == 0) {
        printf("O numero digitado eh primo\n");
        }
}

/*Exercicio 5
Faça uma função que receba um valor N inteiro e positivo e
que calcula o fatorial deste valor. Retorne o resultado.*/

uint64_t fat(int NUM) {
    int i;
    uint64_t Fatorial;
    Fatorial = 1;

    for (i = 1; i <= NUM; i++) {
        Fatorial *= i;
    }

    return Fatorial;
}

void exercicio05() {
    int NUM;
    uint64_t Fatorial;

    printf("Digite um numero para saber seu fatorial\n");
    scanf("%d", &NUM);

    Fatorial = fat(NUM);
    printf("O fatorial do numero digitado eh:\n%llu\n", Fatorial);
}

/*Código utilizdo para escolher o exercicio que deseja executar*/

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

    return SUCESSO;
}