/*Trabalho Prático 02 - Restaurante*/

//Inclusões
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

//Constantes
#define SUCESSO                  (0)
#define QUANTIDADE_INGREDIENTES  (22)
#define TAMANHO_MAX_NOME_RECEITA (50 + 1)
#define SIM                      (1)
#define NAO                      (0)

//Tipos:
typedef struct ingredientes {
    int Codigo;
    const char* Ingrediente;
} ingredientes_t;

typedef struct ingredientesEscolhido {
    int CodigoEscolhido;
    int Quantidade;
} IngredientesEscolhidos_t;

typedef struct Receita {
    int Codigo;
    char Nome[TAMANHO_MAX_NOME_RECEITA];
    IngredientesEscolhidos_t* Receita;
    int QuantidadeDeIngredientes;
} Receita_t;

/*---------------------------------------------------------------------------------------*/

//Procedimento que imprime a lista de ingredientes
void ListarIngredientes(ingredientes_t Ingredientes[QUANTIDADE_INGREDIENTES]) {
    uint8_t i;

    (void)printf("\nLista de ingredientes:\n");

    for (i = 0; i < QUANTIDADE_INGREDIENTES; i++) {
        (void)printf("%02d: %s\n", Ingredientes[i].Codigo, Ingredientes[i].Ingrediente);
    }
}

/*---------------------------------------------------------------------------------------*/

//Procedimento que lê os ingredientes para cadastrar a receita
void LeIngredientesParaReceita(Receita_t* ReceitasCadastradas) {
    IngredientesEscolhidos_t* IngredientesEscolhidos;
    int QuantidadeDeIngredientes, i, SimOuNao, QuantidadeAMaisDeIngredientes;

    //Lê a quantidade de ingredientes necessarios para a receita
    (void)printf("\nDigite a quantidade de ingredientes diferentes necessarios para receita:\n");
    scanf("%d", &QuantidadeDeIngredientes);

    getchar(); //Para tirar o "\n"

    //Aloca a memoria para os ingredientes da receita
    IngredientesEscolhidos = (IngredientesEscolhidos_t*)malloc(QuantidadeDeIngredientes * sizeof(IngredientesEscolhidos_t));

    (void)printf("Digite o codigo dos ingredientes e a quantidade separados por espaco. Ex: 1 3 (tres fatias de mussarela)\n");

    //Lê a os ingredientes da receita
    for (i = 0; i < QuantidadeDeIngredientes; i++) {
        (void)printf("Ingrediente %d: ", i + 1);
        scanf("%d %d", &(IngredientesEscolhidos[i].CodigoEscolhido), &(IngredientesEscolhidos[i].Quantidade));

        getchar();
    }
    
    //Se o usuario quiser adcionar mais ingredientes
    do {
        printf("Voce deseja adicionar mais ingredientes (Digite 1 para sim e 0 para nao)?\n");
        scanf("%d", &SimOuNao);

        getchar(); //Para tirar o "\n"

        if (SimOuNao == SIM) {
            (void)printf("Quantos ingredientes a mais voce precisa?\n");
            scanf("%d", &QuantidadeAMaisDeIngredientes);

            getchar(); //Para tirar o "\n"

            //Faz a "QuantidadeDeIngredientes" ter a quantidade certa de ingrediente
            QuantidadeDeIngredientes += QuantidadeAMaisDeIngredientes;

            //Realoca o espaço
            IngredientesEscolhidos = (IngredientesEscolhidos_t*)realloc(IngredientesEscolhidos, QuantidadeDeIngredientes * sizeof(IngredientesEscolhidos_t));

            //Lê os ingredientes a mais
            for (i = QuantidadeDeIngredientes - QuantidadeAMaisDeIngredientes; i < QuantidadeDeIngredientes; i++) {
                (void)printf("Ingrediente %d: ", i + 1);
                scanf("%d %d", &(IngredientesEscolhidos[i].CodigoEscolhido), &(IngredientesEscolhidos[i].Quantidade));
            }
        }
    } while (SimOuNao != NAO);
   
    //Passa os valores para a variavel certa
    ReceitasCadastradas->QuantidadeDeIngredientes = QuantidadeDeIngredientes;
    ReceitasCadastradas->Receita = IngredientesEscolhidos;
}

/*---------------------------------------------------------------------------------------*/

//Função que cadrasta uma receita e retorna essa receita
Receita_t CriarReceitas() {
    Receita_t ReceitasCadastradas;

    LeIngredientesParaReceita(&ReceitasCadastradas);

    (void)printf("Digite o codigo numerico para registrar a receita:\n");
    scanf("%d", &(ReceitasCadastradas.Codigo));

    getchar(); //Tira o "\n"

    //Lê o nome da receita
    (void)printf("Agora digite o nome da receita(maximo 20 caracteres):\n");
    fgets(ReceitasCadastradas.Nome, TAMANHO_MAX_NOME_RECEITA, stdin);

    //Retorna a receita
    return ReceitasCadastradas;
}

/*---------------------------------------------------------------------------------------*/

//Imprime a tabela das receitas que já foram cadastradas
void ImprimeReceitasCadastradas(int QuantidadeTotalDeReceitas, Receita_t* ReceitasCadastradas) {
    int i;
    
    (void)printf("Receitas ja cadastradas:\n");
    (void)printf("\nCodigo:\t|Nome:\n");

    for (i = 0; i < QuantidadeTotalDeReceitas; i++) {
        (void)printf("%d    \t|%s\n", ReceitasCadastradas[i].Codigo, ReceitasCadastradas[i].Nome);
    }
}

/*---------------------------------------------------------------------------------------*/

void VisualizarReceitasCriadas(Receita_t* ReceitasCadastradas, int QuantidadeTotalDeReceitas) {
    int CodigoReceita, SimOuNao, j, i, k;


    //Declaração dos ingredientes para as receitas cadastradas
    ingredientes_t Ingredientes[QUANTIDADE_INGREDIENTES] = {
        {1, "massa para a pizza\0"},            //Ingrediente 1
        {2, "fatia(s) de mussarela\0"},         //Ingrediente 2
        {3, "fatia(s) de cheddar\0"},           //Ingrediente 3
        {4, "fatia(s) de gorgonzola\0"},        //Ingrediente 4
        {5, "fatia(s) de parmesao\0"},          //Ingrediente 5
        {6, "Kg de catupiry \0"},               //Ingrediente 6
        {7, "tira(s) de bacon\0"},              //Ingrediente 7
        {8, "calabresa(s)\0"},                  //Ingrediente 8
        {9, "grama(s) de frango desfiado\0"},   //Ingrediente 9
        {10, "cubo(s) de carne de porco\0"},    //Ingrediente 10
        {11, "grama(s) de carne moida\0"},      //Ingrediente 11
        {12, "rodela(s) de tomate\0"},          //Ingrediente 12
        {13, "pacote(s) de molho de tomate\0"}, //Ingrediente 13
        {14, "rodela(s) de cebola\0"},          //Ingrediente 14
        {15, "azeitona(s)\0"},                  //Ingrediente 15
        {16, "tira(s) de pimentao\0"},          //Ingrediente 16
        {17, "grama(s) de oregano\0"},          //Ingrediente 17
        {18, "folha(s) de manjericao\0"},       //Ingrediente 18
        {19, "grama(s) de milho\0"},            //Ingrediente 19
        {20, "barra(s) de chocolate preto\0"},  //Ingrediente 20
        {21, "barra(s) de chocolate branco\0"}, //Ingrediente 21
        {22, "grama(s) de brigadeiro\0"},       //Ingrediente 22
    };

    //Imprime as receitas enquanto o usuario não informar 0
    do {
        (void)printf("Digite o codigo da receita que deseja visualizar: ");
        scanf("%d", &CodigoReceita);

        getchar();

        for (i = 0; i < QuantidadeTotalDeReceitas; i++) {
            if (CodigoReceita == ReceitasCadastradas[i].Codigo) {
                (void)printf("Codigo da receita: %d\n", ReceitasCadastradas[i].Codigo);
                (void)printf("Nome da receita: %s\n", ReceitasCadastradas[i].Nome);

                for (j = 0; j < ReceitasCadastradas[i].QuantidadeDeIngredientes; j++) {
                    for (k = 0; k < QUANTIDADE_INGREDIENTES; k++) {
                        if (ReceitasCadastradas[i].Receita[j].CodigoEscolhido == Ingredientes[k].Codigo) {
                            printf("%d %s\n", ReceitasCadastradas[i].Receita[j].Quantidade, Ingredientes[k].Ingrediente);
                            break;
                        }
                    }
                }
                break;
            }
        }
        (void)printf("Voce deseja visualizar outra receita? (Digite 1 para sim ou 0 para nao): ");
        scanf("%d", &SimOuNao);

        getchar();

    } while (SimOuNao != NAO);
}

/*---------------------------------------------------------------------------------------*/

//O main direciona para as funções 
int main(int argc, char** argv) {
    int EscolhaModulo, QuantidadeReceitas = 0, i, QuantidadeTotalDeReceitas = 0, GuardaoIanterior = 0;
    Receita_t* ReceitasCadastradas = 0;

    //Declaração dos ingredientes para a lista
    ingredientes_t Ingredientes[QUANTIDADE_INGREDIENTES] = {
        {1, "Massa para a pizza\0"},            //Ingrediente 1
        {2, "Mussarela (em fatias)\0"},         //Ingrediente 2
        {3, "cheddar (em fatias)\0"},           //Ingrediente 3
        {4, "Gorgonzola (em fatias)\0"},        //Ingrediente 4
        {5, "Parmesao (em fatias)\0"},          //Ingrediente 5
        {6, "Catupiry (em Kg)\0"},              //Ingrediente 6
        {7, "Bacon (em tiras)\0"},              //Ingrediente 7
        {8, "Calabresa\0"},                     //Ingrediente 8
        {9, "Frango desfiado (em gramas)\0"},   //Ingrediente 9
        {10, "Carne de porco (em cubos)\0"},    //Ingrediente 10
        {11, "Carne moida (em gramas)\0"},      //Ingrediente 11
        {12, "Tomate (em rodelas)\0"},          //Ingrediente 12
        {13, "Molho de tomate\0"},              //Ingrediente 13
        {14, "Cebola (em rodelas)\0"},          //Ingrediente 14
        {15, "Azeitona\0"},                     //Ingrediente 15
        {16, "Pimentao (em tiras)\0"},          //Ingrediente 16
        {17, "Oregano (em gramas)\0"},          //Ingrediente 17
        {18, "Manjericao (em folhas)\0"},       //Ingrediente 18
        {19, "Milho (em gramas)\0"},            //Ingrediente 19
        {20, "Chocolate preto (em barras)\0"},  //Ingrediente 20
        {21, "Chocolate branco (em barras)\0"}, //Ingrediente 21
        {22, "Brigadeiro (em gramas)\0"},       //Ingrediente 22
    };

    (void)printf("BEM VINDO AO REGISTRADOR DE RECEITAS\n");

    //Repete até que o usuario digite 0
    do {
        //O usuario decide qual função do programa ele quer acessar.
        (void)printf("\nDigite o numero referente ao que voce deseja (Digite 0 para finalizar):\n1.Ver lista de ingredientes;\n2.Criar receitas;\n3.Visualizar receitas criadas;\n");
        scanf("%d", &EscolhaModulo);

        getchar(); //Para tirar o "\n"

        switch (EscolhaModulo) {
        case 1: {
            ListarIngredientes(Ingredientes); //Faz a lista de todos os ingredientes
            break;
        }
        case 2: {
            //Lê a quantidade de receitas, para a repetição
            (void)printf("\nQuantas receitas voce deseja registrar?\n");
            scanf("%d", &QuantidadeReceitas); 

            getchar(); //Para tirar o "\n"

            //Soma para ter o total de receitas cadastradas durante a execução do codigo
            QuantidadeTotalDeReceitas += QuantidadeReceitas;

            //Aloca/realoca o espaço para as receitas
            ReceitasCadastradas = (Receita_t*)realloc(ReceitasCadastradas, QuantidadeTotalDeReceitas * sizeof(Receita_t));

            //Repete de acordo com a quantidade de receitas informadas
            for (i = 0; i < QuantidadeReceitas; i++) {
                //guarda a receita no lugar certo dentro da variavel "ReceitasCadastradas"
                ReceitasCadastradas[GuardaoIanterior + i] = CriarReceitas();
            }
            //Guarda o "i" para que na proxima vez que o usuario entre nesse modulo, a(s) receita(s) seja(am) cadastrada(s) a partir do espaço certo
            GuardaoIanterior = i;

            break;
        }
        case 3: {
            //Imprime a tabela das receitas que já foram cadastradas
            ImprimeReceitasCadastradas(QuantidadeTotalDeReceitas, ReceitasCadastradas);

            //Imprime a receita que o usuario quer vizualizar
            VisualizarReceitasCriadas(ReceitasCadastradas, QuantidadeTotalDeReceitas);
            break;
        }
        case 0: {
            break;
        }
        default:
            (void)printf("Numero invalido, Digite 1, 2, 3 ou 0\n");
            break;
        }
    } while (EscolhaModulo != 0);

    //Desaloca as memorias que foram alocadas
    for (i = 0; i < QuantidadeTotalDeReceitas; i++) {
        free(ReceitasCadastradas[i].Receita);
    }
    free(ReceitasCadastradas);

    return SUCESSO;
}