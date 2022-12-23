/*aula_4.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.*/

#include <iostream>
#include <stdio.h> 
#define sucesso 0;

//exercicio 1
//Construir um algoritmo para ler 5 valores inteiros, calcular e imprimir a soma desses valores;
void exercicio_1()
{
    //Variaveis.
    int a, b, c, d, e, soma;

    //Interação com o usuario.
    printf("digite 5 números (digite 1 e de enter, e continue)\n");
    scanf_s("%i", &a);
    scanf_s("%i", &b);
    scanf_s("%i", &c);
    scanf_s("%i", &d);
    scanf_s("%i", &e);

    soma = a + b + c + d + e;
    printf("A soma dos números é: %i\n", soma);
}

//exercicio 2
/*Construir um algoritmo para ler 6 valores reais, calcular e
imprimir a média aritmética desses valores;*/

void exercicio_2() {
    
    //Variaveis.
    float a, b, c, d, e, f, media;

    //Interação com o usuario.
    printf("Digite 6 números (digite 1 número e dê enter, e continue) \n");
    scanf_s("%f", &a);
    scanf_s("%f", &b);
    scanf_s("%f", &c);
    scanf_s("%f", &d);
    scanf_s("%f", &e);
    scanf_s("%f", &f);

    media = (a + b + c + d + e + f) / 6;
    printf("A média aritimetica dos números é %f\n", media);
}

//Exercicio 3
/*Fazer um algoritmo para gerar e imprimir o resultado do
número H, sendo H = 1 + 1/2 + 1/3 + 1/4 + 1/5;*/

void exercicio_3() {

    //Variaveis
    float H;

    //Valor e mostra o valor
    H = 1 + 1/2 + 1/3 + 1/4 + 1/5;
    printf("h é igual a: %f", H);

}

//Exercicio 4
/*Calcular o aumento que será dado a um funcionário, obtendo
do usuário as seguintes informações : salário atual e a
porcentagem de aumento. Apresentar o novo valor do salário e
o valor do aumento;*/

void exercicio_4() {
    //Variaveis
    float Salario_atual, Salario_novo, porcentagem_de_aumento, aumento;

    //Interação com o usuario
    printf("Digite o salario atual do funcionario\n");
    scanf_s("%f", &Salario_atual);

    printf("Digite a porcentagem de aumento salarial do funcionario\n");
    scanf_s("%f", &porcentagem_de_aumento);

    //Calcula o novo salário e dá o valor

    aumento = Salario_atual * (porcentagem_de_aumento / 100);
    Salario_novo = Salario_atual + aumento;
    printf("O salario novo desse funcionario é: %f\nAumento: %f", Salario_novo, aumento);
	
}

//Exercicio 5
/*A nota final de um aluno é dada pela média ponderada das
notas das provas. Sabendo que o professor deu 3 provas, com
pesos 4, 3 e 3, respectivamente, calcule a nota nal do aluno;*/

#define PESO_PROVA_1 4
#define PESO_PROVA_2 3
#define PESO_PROVA_3 3

void exercicio_5() {
    //Variaveis
    float Nota1, Nota2, Nota3, NotaFinal;

    //Interação com o usuario
    printf("Digite o a nota da prova 1\n");
    scanf_s("%f", &Nota1);
    printf("Digite o a nota da prova 2\n");
    scanf_s("%f", &Nota2);
    printf("Digite o a nota da prova 3\n");
    scanf_s("%f", &Nota3);

    //Calcula a nota final
    NotaFinal = ((Nota1 * PESO_PROVA_1) + (Nota2 * PESO_PROVA_2) + (Nota3 * PESO_PROVA_3)) / (PESO_PROVA_1 + PESO_PROVA_2 + PESO_PROVA_3);
    printf("A nota final do aluno é %f", NotaFinal);
}


//Código para escolher o exercicio

int main(int argc, char** argv) {
    int nExercicio;
    printf("Digite o numero do exercicio que quer executar [1 a 5]: ");
    scanf_s("%d", &nExercicio);

    switch (nExercicio) {
    case 1: {
        exercicio_1();
        break;
    }
    case 2: {
        exercicio_2();
        break;
    }
    case 3: {
        exercicio_3();
        break;
    }
    case 4: {
        exercicio_4();
        break;
    }
    case 5: {
        exercicio_5();
        break;
    }
    default: {
        printf("Voce escolheu um exercicio invalido.\n");
    }


           return sucesso;
    }
}
