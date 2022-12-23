#include <stdio.h>
#define SUCESSO   0;

/*Atividades da aula 09*/

/* Exercicio 01
Faça um programa que leia, via teclado, 20 valores do tipo
inteiro e determine qual o menor valor existente no vetor e
imprima o valor e seu índice no vetor;*/
#define _TAMANHO_DO_VETOR  (20)

void exercicio01() {
    int Valores[_TAMANHO_DO_VETOR], i, MenorValor, IndiceDoMenorValor;

    //Leitura dos 20 valores
    for (i = 0; i < _TAMANHO_DO_VETOR; i++){
        printf("Digite o %d numero [menor que 100000]\n", (i + 1));
        scanf("%d", &Valores[i]);
        
        if (Valores[i] > 100000) {
            printf("(valor invalido, o numero deve ser menor que 100000)\n");
        }
    }

    MenorValor = 100000;
    
    //Verifica qual é o menor valor
    for (i = 0; i < _TAMANHO_DO_VETOR; i++) {
        if (Valores[i] < MenorValor) {
            MenorValor = Valores[i];
            IndiceDoMenorValor = i;
        }
    }

    //mostra para o usuario o menor valor
    printf("O menor valor digitado foi:\n%d (o %d valor digitado)\n", MenorValor, (IndiceDoMenorValor + 1));
        
}

#define MAXIMO_VETOR (1000)

/* Exercicio 02
Desenvolva um programa que leia um vetor de números reais,
um escalar e imprima o resultado da multiplicação do vetor
pelo escalar;*/
void exercicio02() {
    int TamanhoDoVetor, i;
    float ValorVetores[MAXIMO_VETOR], escalar, produto;

    //Leitura do tamanho do vetor
    printf("Qual o tamanho desejado para o vetor real? [Quantidade maxima %d]\n", MAXIMO_VETOR);
    scanf("%d", &TamanhoDoVetor);

    //Leitura dos valores do vetor
    for (i = 0; i < TamanhoDoVetor; i++) {
        printf("Digite o %d numero\n", (i + 1));
        scanf("%f", &ValorVetores[i]);
    }

    //Leitura do valor escalar
    printf("Agora digite o escalar:\n");
    scanf("%f", &escalar);

    //Imprime a tabela com os vetores o escalar e o produto entre eles
    printf("Vetor: \t Escalar: \t Produto:\n");
    for (i = 0; i < TamanhoDoVetor; i++) {
        produto = (ValorVetores[i] * escalar);
        printf("%2.f      \t %2.f        \t %2.f\n", ValorVetores[i], escalar, produto);
    }
}

/*Exercicio 03
Faça um programa que leia 2 vetores de tamanho 10 e calcule
o produto escalar deles;*/
#define Tamanho_Vetor  (10)

void exercicio03() {
    int Vetor1[Tamanho_Vetor], Vetor2[Tamanho_Vetor], i, produto = 0;

    printf("Digite os valores para preencher os vetores 1 e 2\n");

    //Leitura dos valores do vetor 1
    printf("Primeiro para o vetor 1:\n");
    for (i = 0; i < Tamanho_Vetor; i++) {
        printf("Valor %d:\n", (i + 1));
        scanf("%d", &Vetor1[i]);
    }

    //Leitura dos valores do vetor 2
    printf("Agora para o vetor 2:\n");
    for (i = 0; i < Tamanho_Vetor; i++) {
        printf("Valor %d:\n", (i + 1));
        scanf("%d", &Vetor2[i]);
    }

    //calcula o produto escalar dos vetores 1 e 2
    for (i = 0; i < Tamanho_Vetor; i++) {
        produto += Vetor1[i] * Vetor2[i];
    }

    //Mostra o resultado do calculo para o usuario
    printf("O produto escalar dos vetores eh:\n%d\n", produto);

}

/*Exercicio 04
Faça um programa que leia um vetor de um tamanho escolhido
pelo usuário e calcule a média aritmética de seus valores.*/
#define TAMANHO_MAX_VETOR (1000)

void exercicio04() {
    int  Vetor_Tamanho, i;
    float media, ValorVetores[TAMANHO_MAX_VETOR], soma = 0;

    //Leitura do tamanho do vetor
    printf("Digite a quantidade de vetores necessaria [maximo 1000]:\n");
    scanf("%d", &Vetor_Tamanho);

    printf("Agora digite os numeros para preencher os vetores\n");

    //Leitura dos valores do vetor
    for (i = 0; i < Vetor_Tamanho; i++) {
        printf("%d:  \n", (i + 1));
        scanf("%f", &ValorVetores[i]);
    }

    //Calcula a media
    for (i = 0; i < Vetor_Tamanho; i++) {
        soma += ValorVetores[i];
    }

    media = soma / Vetor_Tamanho;

    //Mostra a media para o usuario
    printf("A media aritimetica dos vetores dados eh:\n%.2f\n", media);

}

/*Esse código serve para escolher o exercicio que queremos executar*/
int main(int argc, char** argv) {
    int nExercicio;

    do {
        printf("Digite o numero do exercicio que quer executar (1 a 4). Digite 0 para sair: ");
        scanf("%d", &nExercicio);

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