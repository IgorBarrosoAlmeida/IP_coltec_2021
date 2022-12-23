//Aula 14 - Arquivos de texto

//Inclusões 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//Constantes 
#define SUCESSO          0
#define DiretorioMaximo (200 + 1)

/*Exercício 1:
Faça uma função que retorne o número de linhas de um arquivo.*/

/*---------------------------------------------------------------*/

//Função que recebe um arquivo já aberto e retorna o numero de linhas desse arquivo:
int NumDeLinhasDoArquivo(FILE* Arquivo) {
    int NumDeLinhas = 0;
    char CaractereAtual;
    
    //lê caractere por caractere e conta os \n (quebra de linha)
    while (1) {
        fscanf(Arquivo, "%c", &CaractereAtual);

        //sai do "while" quando o chega no final do arquivo
        if (feof(Arquivo)) {
            break;
        }

        if (CaractereAtual == '\n') {
            NumDeLinhas++;
        }
    }
    //Retorna o numero de linhas do arquivo
    return NumDeLinhas + 1;
}

/*---------------------------------------------------------------*/

void exercicio01() {
    FILE* Arquivo;
    char diretorio[DiretorioMaximo];
    int NumDeLinhas;

    //Pega o caminho referente ao arquivo que o usuario quer saber a quantidade de linhas
    (void)printf("Digite o diretorio do arquivo que voce deseja saber a quantidade de linhas: ");
    fgets(diretorio, DiretorioMaximo, stdin);
    diretorio[strlen(diretorio) - 1] = '\0';

    //Abre o arquivo
    Arquivo = fopen(diretorio, "r");

    //Testa se o arquivo foi aberto, se não foi uma mensagem vai para o fluxo padrão de erro "stderr"
    if (Arquivo == NULL) {
        fprintf(stderr, "Nao foi possivel abrir o arquivo.\n");
        return;
    }

    NumDeLinhas = NumDeLinhasDoArquivo(Arquivo);

    //"Seta" o arquivo para o inicio
    fseek(Arquivo, 0, SEEK_SET);

    (void)printf("O numero de linhas desse arquivo eh: %d\n", NumDeLinhas);

    fclose(Arquivo);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*Exercício 2:
Faça uma função que retorne o número de caracteres de um
arquivo. Espaços e quebras de linha não devem ser contados.*/

/*---------------------------------------------------------------*/

//Função que recebe um arquivo e retorna a quantidade de caracteres que esse arquivo tem
//sem contar os espaços e as quebras de linha (\n)
int NumDeCaracteresDoArquivo(FILE* Arquivo) {
    int NumCaracteres = 0;
    char CaractereAtual;

    //Conta a quantidade de caracteres do arquivo
    while (1){
        fscanf(Arquivo, "%c", &CaractereAtual);

        //sai do "while" quando o chega no final do arquivo
        if (feof(Arquivo)) {
            break;
        }

        if (CaractereAtual != ' ' && CaractereAtual != '\n') {
            NumCaracteres++;
        }
    }
    //Retorna a quantidade de caracteres
    return NumCaracteres;
}

/*---------------------------------------------------------------*/

void exercicio02() {
    FILE* Arquivo;
    char diretorio[DiretorioMaximo];
    int NumCaracteres;

    //Pega o caminho referente ao arquivo que o usuario quer saber a quantidade de caracteres
    (void)printf("Digite o diretorio do arquivo que voce deseja saber a quantidade de caracteres: ");
    fgets(diretorio, DiretorioMaximo, stdin);
    diretorio[strlen(diretorio) - 1] = '\0';

    //Abre o arquivo
    Arquivo = fopen(diretorio, "r");

    //Testa se o arquivo foi aberto, se não foi uma mensagem vai para o fluxo padrão de erro "stderr"
    if (Arquivo == NULL) {
        fprintf(stderr, "Nao foi possivel abrir o arquivo.\n");
        return;
    }

    NumCaracteres = NumDeCaracteresDoArquivo(Arquivo);

    //"Seta" o arquivo para o inicio
    fseek(Arquivo, 0, SEEK_SET);

    (void)printf("O numero de caracteres do arquivo eh: %d\n", NumCaracteres);

    fclose(Arquivo);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*Exercícoi 3:
Faça um programa que leia de um arquivo as informações sobre
o nome e as 2 notas de diversos alunos. Imprima a listagem de
alunos e suas respectivas médias. O programa deve criar o arquivo
de entrada e criar um arquivo de saída com o nome e a média de
cada aluno. Armazene as informações dos alunos em um registro
(struct).*/

/*Exercício 4:
Adicione ao programa anterior uma função para calcular o desvio
padrão e a variância das médias dos alunos. Grave essa informação
no final do arquivo de saída.*/

//Constantes:

#define NOMEMAXIMO (60 + 1)
#define NUM_NOTAS   2

//Estruras{
typedef struct DadosAluno {
    char Nome[NOMEMAXIMO];
    float Notas[NUM_NOTAS], media;
}DadosAluno_t;

/*---------------------------------------------------------------*/

//Função que lê os dados do arquivo de alunos, calcula a media do aluno e coloca todos esses dados na estrutura "dados"
void LeDadosDosAlunosECalculaMedia(DadosAluno_t* Dados, FILE* Arquivo) {
    float soma = 0;
    
    //Lê o nome do aluno
    fgets(Dados->Nome, NOMEMAXIMO, Arquivo);
    Dados->Nome[strlen(Dados->Nome) - 1] = '\0'; //Tira o \n do final

    //Lê as notas do alunos
    for (int i = 0; i < NUM_NOTAS; i++) {
        fscanf(Arquivo, "%f\n", &(Dados->Notas[i]));
    }

    //Calcula a soma das notas do aluno
    for (int i = 0; i < NUM_NOTAS; i++) {
        soma += Dados->Notas[i];
    }

    //Calcula a media
    Dados->media = soma / NUM_NOTAS;
}

//Função que calcula a variancia das medias dos alunos
float CalculaVariancia(DadosAluno_t* Dados, int QuantidadeAlunos){
    float mediaTotal, soma = 0, SomaDosQuadrados = 0;

    //Soma as medias dos alunos
    for (int i = 0; i < QuantidadeAlunos; i++) {
        soma += Dados[i].media;
    }

    //Calcula a quantidade
    mediaTotal = soma / QuantidadeAlunos;

    //Calcula a soma dos quadrados conforme a formula da variancia ((Numero - Media)^2)
    for (int i = 0; i < QuantidadeAlunos; i++) {
        SomaDosQuadrados += pow(Dados[i].media - mediaTotal, 2);
    }

    //Retorna a variancia das medias dos alunos
    return SomaDosQuadrados / (QuantidadeAlunos - 1);
}

//Função que calcula desvio padrão das medias do alunos
float CalculaDesvioPadrao(DadosAluno_t* Dados, int QuantidadeAlunos) {
    float mediaTotal, soma = 0, SomaDosQuadrados = 0;

    //Calcula a soma das medias dos alunos
    for (int i = 0; i < QuantidadeAlunos; i++) {
        soma += Dados[i].media;
    }

    //Calcula a media geral dos alunos
    mediaTotal = soma / QuantidadeAlunos;

    //Calcula a soma dos quadrados
    for (int i = 0; i < QuantidadeAlunos; i++) {
        SomaDosQuadrados += pow(Dados[i].media - mediaTotal, 2);
    }

    //Calcula o desvio padrão conforma a formula (raiz quadrada da soma dividido pelo numero de dados)
    return sqrt(SomaDosQuadrados / QuantidadeAlunos);
}

//Função que imprime os dados dos alunos para o usuario
void ImprimirDadosDosAlunos(DadosAluno_t* Dados, FILE* Arquivo) {
    //Imprime o nome
    printf("Nome: %s\n", Dados->Nome);
    //Imprime as notas das provas
    printf("Notas: ");
    for (int i = 0; i < NUM_NOTAS; i++) {
        printf("%f   |", Dados->Notas[i]);
    }
    //Imprime a media das provas
    printf("\nmedia: %f\n", Dados->media);
    printf("-----------------------------------------------------\n");
}

void imprimeDadosGerais(int QuantidadeAlunos, DadosAluno_t* Dados, float variancia, float desvio) {
    float mediaTotal, soma = 0;

    //Soma as medias dos alunos
    for (int i = 0; i < QuantidadeAlunos; i++) {
        soma += Dados[i].media;
    }
    //Calcula a media geral dos alunos
    mediaTotal = soma / QuantidadeAlunos;

    //Imprime a media geral, a variancia e o desvio padrão para o usuario
    printf("Media geral das notas: %f\n", mediaTotal);
    printf("Variancia: %f\n", variancia);
    printf("Desvio padrao: %f\n", desvio);
}

/*---------------------------------------------------------------*/

void exercicio03e04() {
    char diretorio[DiretorioMaximo];
    FILE* Arquivo;
    int QuantidadeAlunos;
    DadosAluno_t* Dados;
    float variancia, desvio;

    //Pega o caminho referente ao arquivo que contem os dados dos alunos
    (void)printf("Digite o diretorio do arquivo que tem os dados dos alunos: ");
    fgets(diretorio, DiretorioMaximo, stdin);
    diretorio[strlen(diretorio) - 1] = '\0';

    //Abre o arquivo
    Arquivo = fopen(diretorio, "r");

    //Testa se o arquivo foi aberto, se não foi uma mensagem vai para o fluxo padrão de erro "stderr"
    if (Arquivo == NULL) {
        fprintf(stderr, "Nao foi possivel abrir o arquivo.\n");
        return;
    }

    //Lê a quantidade de alunos
    fscanf(Arquivo, "%d\n", &QuantidadeAlunos);

    Dados = (DadosAluno_t*)malloc(QuantidadeAlunos * sizeof(DadosAluno_t));

    //Lê os dados de cada aluno
    for (int i = 0; i < QuantidadeAlunos; i++) {
        LeDadosDosAlunosECalculaMedia(&Dados[i], Arquivo);
    }

    //Imprime os dados para o usuario
    for (int i = 0; i < QuantidadeAlunos; i++) {
        ImprimirDadosDosAlunos(&Dados[i], Arquivo);
    }

    variancia = CalculaVariancia(Dados, QuantidadeAlunos);
    desvio = CalculaDesvioPadrao(Dados, QuantidadeAlunos);

    imprimeDadosGerais(QuantidadeAlunos, Dados, variancia, desvio);

    fclose(Arquivo);

    //Abre o arquivo de saida
    Arquivo = fopen("./Saida.txt", "w");

    //Testa se o arquivo foi aberto, se não foi uma mensagem vai para o fluxo padrão de erro "stderr"
    if (Arquivo == NULL) {
        fprintf(stderr, "Nao foi possivel abrir o arquivo.\n");
        return;
    }

    //Escreve os nomes e as medias no arquivo de saida
    fprintf(Arquivo, "%d\n", QuantidadeAlunos);
    for (int i = 0; i < QuantidadeAlunos; i++) {
        fprintf(Arquivo, "%s\n", Dados[i].Nome);
        fprintf(Arquivo, "%f\n", Dados[i].media);
    }

    //escreve a variancia no arquivo de saida
    fprintf(Arquivo, "%f\n", variancia);
    fprintf(Arquivo, "%f", desvio);

    fclose(Arquivo);
    free(Dados);
}

//Main. O usuario escolhe qual exercicio ele deseja executar
int main(int argc, char** argv){
    int nExercicio;
    char lixo;

    do {
        printf("Digite o numero do exercicio que quer executar (1 a 3). Digite 0 para sair: ");
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
            exercicio03e04();
            break;
        }
        default: {
            printf("Voce escolheu um exercicio invalido.\n");
        }
        }
    } while (nExercicio != 0);

	return SUCESSO;
}