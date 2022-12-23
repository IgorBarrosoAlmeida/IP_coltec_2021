//Atividades da Aula 10 - cadeia de caracteres

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#define SUCESSO  0

/* Exercicio 01:
Fazer um programa para contar o número de espaços em brancos de
uma string.*/
#define TAMANHO_STRING (100 + 1)

/*Função que conta os espaços de um string
e retorna essa quantidade*/
int ContaEspacos(char s[TAMANHO_STRING]) {
    int i, QuantidadeEspacos;
    QuantidadeEspacos = 0;

    for (i = 0; i < TAMANHO_STRING; i++) {
        //Conta a quantidade de espaços
        if (s[i] == ' ') {
            QuantidadeEspacos++;
        }

    }
    
    //Retorna a quantidade de espaços para o código principar
    return QuantidadeEspacos;
}

void exercicio01() {
    char s[TAMANHO_STRING];
    int QuantidadeDeEspacos;

    //Workaround para jogar o \n que está no stdin depois do scanf
    getchar();

    //Lê a string
    printf("Digite uma string:\n");
    fgets(s, TAMANHO_STRING, stdin);

    QuantidadeDeEspacos = ContaEspacos(s);

    printf("O numero de espacos digitados eh:\n%d\n", QuantidadeDeEspacos);
}

/*Exercicio 02:
Fazer um programa para imprimir uma string, recebida como entrada
do usuário, sem os espaços em branco.*/

//Procedimento que imprime a string sem nenhum espaço
void ImprimeSemEspaco(char s[TAMANHO_STRING]) {
    int i;
    int tamanhoTexto;

    tamanhoTexto = strlen(s);

    //Pula os espaços e imprime o que não é espaço
    for (i = 0; i < tamanhoTexto; i++) {

            if (s[i] == ' ') {
                continue;
            }
            else {
                printf("%c", s[i]);
                
            }
    }
    printf("\n");
}

void exercicio02() {
    char s[TAMANHO_STRING];

    //Workaround para jogar o \n que está no stdin depois do scanf
    getchar();

    //Lê a string
    printf("Digite uma string:\n");
    fgets(s, TAMANHO_STRING, stdin);

    ImprimeSemEspaco(s);
}

/*Exercicio 03:
Fazer um programa para contar o número de vogais numa string.*/

/*Função que conta a quantidade de vogais de uma string
e retorna essa quantidade*/
int ContaVogais(char s[TAMANHO_STRING]) {
    int i, NumVogais = 0;

    for (i = 0; i < TAMANHO_STRING; i++) {
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U') {
            NumVogais++;
        }
    }

    return NumVogais;
}

void exercicio03() {
    char s[TAMANHO_STRING];
    int NumVogais;

    //Workaround para jogar o \n que está no stdin depois do scanf
    getchar();

    //Lê a string
    printf("Digite uma string:\n");
    fgets(s, TAMANHO_STRING, stdin);

    NumVogais = ContaVogais(s);

    // Imprime a quantidade de vogais para o usuario
    printf("A string digitada tem %d vogais.\n", NumVogais);
}

/*Exercicio 04:
Escrever um programa para ler uma string (com mais de uma palavra)
e faça com que a primeira letra de cada palavra que em maiúscula. Para
isso, basta subtrair 32 do elemento que deseja alterar para maiúsculo.*/
void PrimeirasLetrasMaiuscula(char s[TAMANHO_STRING]) {
    int i;

    for (i = 0; i < TAMANHO_STRING; i++) {
        if (s[i] == ' ') {
            s[i + 1] = toupper(s[i + 1]);
        }
    }

    printf("O texto transformado eh: \n%s\n", s);
}

void exercicio04() {
    char s[TAMANHO_STRING];
    
    getchar();

    printf("Digite uma string com mais de uma palavra:\n");
    fgets(s, TAMANHO_STRING, stdin);

    PrimeirasLetrasMaiuscula(s);

}

/*Exercicio05:
Escreva um programa que receba uma string de tamanho máximo 100,
e verique se é um palíndromo. Uma palavra é dita ser um palíndromo se
a sequência de seus caracteres da esquerda para a direita é igual a
sequência de seus caracteres da direita para a esquerda. Ex: arara, asa.*/
typedef uint8_t bool_t;
#define VERDADEIRO (0)
#define FALSO (!VERDADEIRO)

void VerificaPalindromo(char StringConvertida[TAMANHO_STRING], int tamanhoTexto) {
    char sComparacao[TAMANHO_STRING], sUsuariocopy[TAMANHO_STRING];
    int i, j = 0;
    bool_t ehPalindromo = FALSO;

    strcpy(sUsuariocopy, StringConvertida);

    for (i = tamanhoTexto - 1; i >= 0; i--) {
        sComparacao[j] = sUsuariocopy[i];
        
        j++;
    }

    ehPalindromo = strcmp(sComparacao, sUsuariocopy);

    printf("\n");

    if (ehPalindromo == VERDADEIRO) {
        printf("A string digitada eh um palindromo\n");
    }
    else if (ehPalindromo != VERDADEIRO) {
        printf("A string digitada nao eh um palindromo\n");
    }
    
}

void exercicio05() {
    char sUsuario[TAMANHO_STRING];
    int tamanhoTexto;
    getchar();

    printf("Digite uma palavra para verificar se ela eh um palindromo:\n");
    scanf("%s", sUsuario);
    tamanhoTexto = strlen(sUsuario);

    VerificaPalindromo(sUsuario, tamanhoTexto);
}

/*Exercicio 06
Faça um programa que leia uma frase e determine se ela é um palíndromo. Use
funções e/ou procedimentos.*/

void exercicio06() {
    char sUsuario[TAMANHO_STRING], StringConvertida[TAMANHO_STRING];
    int i, j = 0, tamanhoTexto;

    getchar();



    printf("Digite uma frase para verificar se ela eh um palindromo:\n");
    fgets(sUsuario, TAMANHO_STRING, stdin);

    for (i = 0; i < strlen(sUsuario); i++) {
        if (isalpha(sUsuario[i])) {
            if (isupper(sUsuario[i])) {
                sUsuario[i] = tolower(sUsuario[i]);
            }
            StringConvertida[j] = sUsuario[i];
            j++;
        }
        
    }
    tamanhoTexto = strlen(StringConvertida);
    
    VerificaPalindromo(StringConvertida, tamanhoTexto);
}

int main(int argc, char** argv) {
    int nExercicio;

    do {
        printf("Digite o numero do exercicio que quer executar (1 a 6). Digite 0 para sair: ");
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