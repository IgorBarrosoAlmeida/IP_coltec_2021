// Exercícios Aula 13 - Structs

//Inclusões
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

/*Exercício 01:
Faça um programa para leitura, via teclado, dos dados de um
aluno. Os dados a serem guardados na estrutura aluno são os
seguintes: nome, curso, idade. Ao final, imprima estas informações
na tela.*/

//Constantes:
#define TAMANHO_MAX_NOME (50 + 1)
#define TAMANHO_MAX_CURSO (30 + 1)
#define QUANTIDADE_NOTAS (3)
#define SUCESSO 0

//Tipos:
typedef struct DadosAlunos{
    char nome[TAMANHO_MAX_NOME];
    char curso[TAMANHO_MAX_CURSO];
    int idade;
    float nota[QUANTIDADE_NOTAS];
    float media;
} Dados_t;

/*Função que lê os dados dos alunos*/
void LeDadosAlunos(Dados_t *Alunos) {
    
    //Lê o nome
    printf("Digite o nome do aluno: ");
    fgets(Alunos->nome, TAMANHO_MAX_NOME, stdin);
    Alunos->nome[strlen(Alunos->nome) - 1] = '\0'; // Remove o \n do final

    //Lê o curso
    printf("Digite o curso do aluno: ");
    fgets(Alunos->curso, TAMANHO_MAX_CURSO, stdin);
    Alunos->curso[strlen(Alunos->curso) - 1] = '\0'; // Remove o \n do final

    //Lê a idade
    printf("Digite a idade do aluno: ");
    scanf("%d", &(Alunos->idade));
}

void exercicio01() {
    Dados_t Alunos;

    LeDadosAlunos(&Alunos);

    //Imprime os dados coletados
    printf("O aluno %s, do curso de %s, tem %d anos\n", Alunos.nome, Alunos.curso, Alunos.idade);
}

/*Exercício 02:
Considere a mesma estrutura definida anteriormente. Acrescente
à estrutura um vetor com as notas das três provas feitas pelo aluno,
calcule a sua média e diga se ele foi aprovado ou não (media >=
60).*/

//Constantes:
#define NOTA_MINIMA  60

/*Função que calcula a media das notas do aluno*/
float calculaMediaFloat(Dados_t *Alunos) {
    float soma = 0;
    uint8_t i;
    
    //Soma todas as notas
    for (i = 0; i < QUANTIDADE_NOTAS; i++) {
        soma += Alunos->nota[i];
    }

    //retorna a media
    return soma/QUANTIDADE_NOTAS;
}

void exercicio02() {
    Dados_t Alunos;
    uint8_t i;
    float media;

    //Lê as notas das provas
    for (i = 0; i < QUANTIDADE_NOTAS; i++) {
        printf("Digite a nota da prova %d: ", i + 1);
        scanf("%f", &Alunos.nota[i]);
    }

    media = calculaMediaFloat(&Alunos);

    //Imprime com base na media, se o aluno foi reprovado ou aprovado
    printf("A media das notas do aluno eh: %.2f\n", media);
    if (media < NOTA_MINIMA) {
        printf("O aluno foi reprovado.\n");
    }
    else if (media >= NOTA_MINIMA) {
        printf("O aluno foi aprovaodo.\n");
    }
}

/*Exercício 03:
Altere o programa do exercício 2 para que ele leia as informações
de N alunos. Imprima a média de cada aluno e a média geral da
turma.*/

/*Função que calcula a media de um numero N de alunos*/
float* calculaMediaFloat_ex03(Dados_t* Alunos, int  QuantidadeAlunos) {
    float soma;
    float* media;
    uint8_t i, j;

    //Aloca espaço na memoria para a media
    media = (float*)malloc(QuantidadeAlunos * sizeof(float));

    //Calcula a media para cada aluno
    for (j = 0; j < QuantidadeAlunos; j++) {
        printf("Digite a nota do aluno %d\n", j + 1);
        
        soma = 0;
        
        for (i = 0; i < QUANTIDADE_NOTAS; i++) {
            printf("Nota prova %d: ", i + 1);
            scanf("%f", &Alunos->nota[i]);

            soma += Alunos->nota[i];
        }

        media[j] = soma / QUANTIDADE_NOTAS;
    }

    return media;
}

void exercicio03() {
    Dados_t Alunos;
    int QuantidadeAlunos;
    float* media;
    uint8_t i;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &QuantidadeAlunos);
    
    media = calculaMediaFloat_ex03(&Alunos, QuantidadeAlunos);

    //Imime com base na mediapr, se o aluno foi reprovado ou aprovado
    for (i = 0; i < QuantidadeAlunos; i++) {
        printf("A media das notas do aluno %d eh: %.2f\n", i + 1, media[i]);
        if (media[i] < NOTA_MINIMA) {
            printf("O aluno foi reprovado.\n");
        }
        else if (media[i] >= NOTA_MINIMA) {
            printf("O aluno foi aprovaodo.\n");
        }
    }
    
    //Libera o espaço na memoria
    free(media);
}

/*Exercício 04:
Acrescente um procedimento ao exercício 3 que ordene a
estrutura de alunos em ordem crescente da média das notas. Ao
final, imprima todas as informações na tela (ordenadas pela média
das notas).*/

/*Função que lê os dados dos alunos, inclusive a nota*/
void LeDadosAlunos_ex04(Dados_t* Alunos, int QuantidadeAlunos) {
    uint8_t i;
    char lixo;

    //Lê o nome do aluno
    printf("Digite o nome do aluno: ");
    fgets(Alunos->nome, TAMANHO_MAX_NOME, stdin);
    Alunos->nome[strlen(Alunos->nome) - 1] = '\0'; // Remove o \n do final

    //Lê o curso do aluno
    printf("Digite o curso do aluno: ");
    fgets(Alunos->curso, TAMANHO_MAX_CURSO, stdin);
    Alunos->curso[strlen(Alunos->curso) - 1] = '\0'; // Remove o \n do final

    //Lê a idade do aluno
    printf("Digite a idade do aluno: ");
    scanf("%d%c", &(Alunos->idade), &lixo);
    
    //Lê a nota das provas
    for (i = 0; i < QUANTIDADE_NOTAS; i++) {
        printf("Digite a nota da prova %d: ", i + 1);
        scanf("%f%c", &Alunos->nota[i], &lixo);
    }
}

/*Função que imprime as informações do aluno que tirou a menor nota, até o aluno que tirou a melhor*/
void ImprimeEmOrdemCrescente(int QuantidadeAlunos, Dados_t* Alunos) {
    uint8_t i, j;
    Dados_t auxiliar;

    //Organiza as informações colocando os dados dos alunos que tiveram a pior media para os que tiveram melhor media
    for (i = 0; i < QuantidadeAlunos; i++) {
        //Vai de media em media
        for (j = i + 1; j < QuantidadeAlunos; j++) {
            if (Alunos[i].media > Alunos[j].media) {

                //Se a media atual for maior que a proxima media, a posição dos dados é invertida
                auxiliar = Alunos[i];
                Alunos[i] = Alunos[j];
                Alunos[j] = auxiliar;
            }
        }
        //Imprime todas as informações
        printf("Aluno: %s\n", Alunos[i].nome);
        printf("Curso: %s\n", Alunos[i].curso);
        printf("Idade: %d\n", Alunos[i].idade);
        printf("media: %.2f\n", Alunos[i].media);
        if (Alunos[i].media < NOTA_MINIMA) {
            printf("Reprovado.\n");
        }
        else if (Alunos[i].media >= NOTA_MINIMA) {
            printf("Aprovaodo.\n");
        }
    }
}

void exercicio04() {
    Dados_t *Alunos;
    int QuantidadeAlunos;
    float soma;
    uint8_t i, j;
    char lixo;

    //Lê a quantidade de alunos
    printf("Digite a quantidade de alunos: ");
    scanf("%d%c", &QuantidadeAlunos, &lixo);

    //Aloca espaço na memoria para as estruturas
    Alunos =(Dados_t*)malloc(QuantidadeAlunos * sizeof(Dados_t));
    
    //Lê os dados e calcula a media
    for (i = 0; i < QuantidadeAlunos; i++) {
        LeDadosAlunos_ex04(&Alunos[i], QuantidadeAlunos);
        
        soma = 0;
        for (j = 0; j < QUANTIDADE_NOTAS; j++) {
            soma += Alunos[i].nota[j];
        }
        Alunos[i].media = soma / QUANTIDADE_NOTAS;
    }

    ImprimeEmOrdemCrescente(QuantidadeAlunos, Alunos);
    
    //Libera o espaço alocado
    free(Alunos);
}

/*Código que pergunta ao usuario qual exercicio deseja executar:*/
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