/*Você foi solicitado a fazer um sistema para uma pizzaria com objetivo
de facilitar o preparo das pizzas.
Esse sistema duas partes:
- Módulo de Ingredientes
Nesse módulo existe uma lista de pares contendo <código, ingrediente>.
Para realizar os testes, sua lista de ingredientes deve conter, pelo
menos, 20 ingredientes.
- Módulo de Receitas
Nesse módulo existe uma lista de receitas de pizza. Cada receita de
pizza é composta de uma lista de códigos de ingredientes e as quantidades
utilizadas daquele ingrediente naquela receita, bem como um código da
receita.*/

//Inclusões
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Constantes
#define SUCESSO								(0)
#define TAMANHO_MAXIMO_INGREDIENTE			(100 + 1)
#define TAMANHO_MAXIMO_RECEITA				(100 + 1)
#define DIRETORIO_ARQUIVO_INGREDIENTES		"./Ingredientes"
#define DIRETORIO_ARQUIVO_RECEITAS			"./Receitas"
#define VERDADEIRO							(1 == 1)
#define FALSO								(!VERDADEIRO)

//definições tipos
typedef int bool_t;

//Estruturas
//Estrutura que guarda as informações dos ingredientes: Codigo, nome, e quantidade (quando usado no cadastro de receitas)
typedef struct Ingrediente {
	int Codigo;
	char NomeIngrediente[TAMANHO_MAXIMO_INGREDIENTE];
	float Quantidade;
} Ingrediente_t;

//Estrutura que guarda as informações das receitas: Codigo, nome, quantidade de ingredientes que tem na receita e os proprios ingredientes
typedef struct Receitas {
	char Nome[TAMANHO_MAXIMO_RECEITA];
	int Codigo, QuantidadeIngredientes;
	Ingrediente_t* Ingredientes;
} Receitas_t;

/*-----------------------------------Funções ingredientes---------------------------------------------------------*/

//Procedimento que atualiza a lista de ingredientes no arquivo "Ingredientes":
void AtualizaListaIngredientes(FILE* Arquivo, Ingrediente_t* Ingredientes, int QuantidadeIngredientes) {
	fseek(Arquivo, 0, SEEK_SET); //Garante que o arquivo está na posição inicial.
	
	//Grava a lista de ingredientes no arquivo:
	(void)fprintf(Arquivo, "%d\n", QuantidadeIngredientes); 
	for (int i = 0; i < QuantidadeIngredientes; i++) {
		fprintf(Arquivo, "%d", Ingredientes[i].Codigo);
		fprintf(Arquivo, "%s\n",Ingredientes[i].NomeIngrediente);
	}
}

//Procedimento que preenche a estrutura dos ingredientes (cadastra os ingredientes):
void CadastraIngrediente(Ingrediente_t* Ingrediente){
	(void)printf("Digite o codigo(numerico) para o ingrediente(ex:3): ");
	scanf("%d", &(Ingrediente->Codigo));
	getchar(); //Tira o \n
	(void)printf("Digite o ingrediente(ex:Tomate(s)): ");
	fgets(Ingrediente->NomeIngrediente ,TAMANHO_MAXIMO_INGREDIENTE, stdin);
	Ingrediente->NomeIngrediente[strlen(Ingrediente->NomeIngrediente) - 1] = '\0'; // Tira o \n do final
}

//Procedimento que imprime a lista de ingredientes para que o usuario veja:
void ImprimeListaIngredientes(int QuantidadeIngredientes, Ingrediente_t* Ingrediente) {
	(void)printf("\nLista de ingredientes:\n");
	(void)printf("|Codigo\t|Ingrediente:\n"); //Cabeçalho
	//Imprime cada ingrediente na tabela:
	for (int i = 0; i < QuantidadeIngredientes; i++) {
		(void)printf("|%d\t|%s\n", Ingrediente[i].Codigo, Ingrediente[i].NomeIngrediente);
	}
	(void)printf("\n");
}

//Procedimento que lista os ingredientes na ordem pedida pelo usuario:
void LinstaIngredientes(int QuantidadeIngredientes, Ingrediente_t* Ingrediente) {
	int Ordenacao;
	Ingrediente_t* CopiaIngrediente; //A variavel local "CopiaIngrediente" é usada para que a ordem de cadastro seja preservada no "vetor de estruturas" apontado pela variavel "Ingrediente".
	Ingrediente_t Aux;

	//Se "QuantidadeIngredientes" é 0 então quer dizer que nenhum ingrediente foi cadastrado, isso é informado ao usuario:
	if (QuantidadeIngredientes == 0) {
		(void)printf("Nenhum ingrediente cadastrado ate o momento\n\n"); 
		return;
	}
	(void)printf("\n");
	do {
		(void)printf("Voce deseja ver a lista de ingrediente em qual ordem?\n1 = ordem de criacao\n2 = ordem por codigo\n3 = ordem por descricao\n");
		scanf("%d", &Ordenacao);
		getchar(); //Tira o \n

		if (Ordenacao == 1) { //Ordem de criação.
			ImprimeListaIngredientes(QuantidadeIngredientes, Ingrediente);//Imprime a lista de ingredientes ordenados por ordem de criacao.
			break;
		}
		else if (Ordenacao == 2) { //Ordem por codigo.
			CopiaIngrediente = (Ingrediente_t*)malloc(QuantidadeIngredientes * sizeof(Ingrediente_t));

			//Todos os ingredientes contidos em "Ingrediente" são copiados para "copiaIngrediente".
			for (int i = 0; i < QuantidadeIngredientes; i++) {
				CopiaIngrediente[i] = Ingrediente[i];
			}

			//Ordena os elementos de "CopiaIngrediente" de acordo com o codigo do ingrediente.
			for (int i = 0; i < QuantidadeIngredientes; i++) {
				for (int j = QuantidadeIngredientes - 1; j > i; j--) {
					if (CopiaIngrediente[j].Codigo < CopiaIngrediente[j - 1].Codigo) {
						Aux = CopiaIngrediente[j];
						CopiaIngrediente[j] = CopiaIngrediente[j - 1];
						CopiaIngrediente[j - 1] = Aux;
					}
				}
			}

			ImprimeListaIngredientes(QuantidadeIngredientes, CopiaIngrediente); //Imprime a lista de ingredientes ordenados por ordem de codigo.

			free(CopiaIngrediente); //Libera a memoria alocada.
			break;
		}
		else if (Ordenacao == 3) { //Ordem por descrição.
			CopiaIngrediente = (Ingrediente_t*)malloc(QuantidadeIngredientes * sizeof(Ingrediente_t));

			//Todos os ingredientes contidos em "Ingrediente" são copiados para "copiaIngrediente":
			for (int i = 0; i < QuantidadeIngredientes; i++) {
				CopiaIngrediente[i] = Ingrediente[i];
			}

			//Ordena os elementos de "CopiaIngrediente" na ordem alfabetica do nome dos ingredientes:
			for (int i = 0; i < QuantidadeIngredientes; i++) {
				for (int j = QuantidadeIngredientes - 1; j > i; j--) {
					if (strcmp(CopiaIngrediente[j].NomeIngrediente, CopiaIngrediente[j - 1].NomeIngrediente) < 0) {
						Aux = CopiaIngrediente[j];
						CopiaIngrediente[j] = CopiaIngrediente[j - 1];
						CopiaIngrediente[j - 1] = Aux;
					}
				}
			}

			ImprimeListaIngredientes(QuantidadeIngredientes, CopiaIngrediente); //Imprime a lista de ingredientes ordenados por ordem de descricao.

			free(CopiaIngrediente); //Libera a memoria alocada.
			break;
		}
		else {
			(void)printf("Numero invalido, digite um numero entre 1 e 3\n\n");
		}
	} while (VERDADEIRO);
}

/*-----------------------------------------Funções Receitas-----------------------------------------------------*/

//Procedimento que atualiza a lista de receitas no arquivo "receitas":
void AtualizaListaReceitas(FILE* Arquivo, Receitas_t* Receitas, int QuantidadeReceitas) {
	fseek(Arquivo, 0, SEEK_SET); //Garante que o arquivo está na posição inicial.

	//Grava no arquivo todas as informações sobre as receitas:
	fprintf(Arquivo, "%d\n", QuantidadeReceitas);
	for (int i = 0; i < QuantidadeReceitas; i++) {
		fprintf(Arquivo, "%d\n", Receitas[i].Codigo);
		fprintf(Arquivo, "%s\n", Receitas[i].Nome);
		fprintf(Arquivo, "%d\n", Receitas[i].QuantidadeIngredientes);
		for (int j = 0; j < Receitas[i].QuantidadeIngredientes; j++) {
			fprintf(Arquivo, "%d %f\n", Receitas[i].Ingredientes[j].Codigo, Receitas[i].Ingredientes[j].Quantidade);
		}
	}
}

void OrdenaIngredientesDaReceitaPordescricao(int QuantidadeIngredientes, Receitas_t* Receitas) {
	Ingrediente_t Aux;
	int i, j;

	for (i = 0; i < QuantidadeIngredientes; i++) {
		for (j = QuantidadeIngredientes - 1; j > i; j--) {
			if (strcmp(Receitas->Ingredientes[j].NomeIngrediente, Receitas->Ingredientes[j - 1].NomeIngrediente) < 0) {
				Aux = Receitas->Ingredientes[j];
				Receitas->Ingredientes[j] = Receitas->Ingredientes[j - 1];
				Receitas->Ingredientes[j - 1] = Aux;
			}
		}
	}
}

//Procedimento que cadastra receitas:
void CadastraReceitas(Receitas_t* Receitas) {
	int ordem = 0;

	(void)printf("Digite o codigo(numerico) da receita: ");
	scanf("%d", &(Receitas->Codigo)); //Pega o codigo da receita
	getchar(); //Tira o \n

	(void)printf("Digite agora o nome da receita: "); //Pega o nome da receita
	fgets(Receitas->Nome, TAMANHO_MAXIMO_RECEITA, stdin);
	Receitas->Nome[strlen(Receitas->Nome) - 1] = '\0'; // Tira o \n do final

	(void)printf("Quantos ingredientes tem essa receita? "); //Pega a quantidade de ingredientes de uma receita
	scanf("%d", &Receitas->QuantidadeIngredientes);

	Receitas->Ingredientes = (Ingrediente_t*)malloc(Receitas->QuantidadeIngredientes * sizeof(Ingrediente_t)); //Aloca espaço na memoria para os ingredientes da receita

	//Cadastra os ingredientes das receitas:
	(void)printf("\nDigite o codigo do ingrediente e a quantidade usada desse ingrediente na receita respectivamente(ex:7 2):\n");
	for (int i = 0; i < Receitas->QuantidadeIngredientes; i++) {
			(void)printf("Ingrediente %d: ", i + 1);
			scanf("%d %f", &(Receitas->Ingredientes[i].Codigo), &(Receitas->Ingredientes[i].Quantidade));
			getchar(); //Tira o \n
	}
}

//Imprime a lista que mostra todas as receitas cadastradas até o momento:
void ImprimeListaReceitas(Receitas_t* Receitas, int QuantidadeReceitas) {
	(void)printf("|Codigo\t|Receita:\n");
	for (int i = 0; i < QuantidadeReceitas; i++) {
		(void)printf("|%d\t|%s\n", Receitas[i].Codigo, Receitas[i].Nome);
	}
	(void)printf("\n");
}

//Procedimento que permite o usuario ver uma lista das receitas cadastradas e escolher uma pra ver detalhadamente
void VizualizaReceitas(int QuantidadeReceitas, Receitas_t* Receitas, Ingrediente_t* Ingrediente, int QuantidadeIngredientes) {
	int Ordenacao, CodigoDaReceita, AchouAReceita = FALSO, Ordenacao2;
	Receitas_t* CopiaReceitas; //A variavel local "CopiaReceitas" é usada para que a ordem de cadastro seja preservada no "vetor de estruturas" apontado pela variavel "Receitas".
	Receitas_t Aux, CopiaReceita;

	(void)printf("\n");
	//Se a quantidadade de receitas é igual a 0, quer dizer que nenhuma receita foi cadastrada até o momento. Isso é informado ao usuario.
	if (QuantidadeReceitas == 0) {
		(void)printf("Nenhuma receita cadastrada ate o momento\n");
		return;
	}
	//Ordena a lista de receita de acordo com o desejo do usuario:
	do {
		(void)printf("Voce deseja ver a lista de Receitas em qual ordem?\n1 = ordem de criacao\n2 = ordem por codigo\n3 = ordem por descricao(nome da receita)\n");
		scanf("%d", &Ordenacao);
		getchar(); //Tira o \n

		if (Ordenacao == 1) { //Ordem de criação
			ImprimeListaReceitas(Receitas, QuantidadeReceitas);
			break;
		}
		else if (Ordenacao == 2) { //Ordem por codigo
			CopiaReceitas = (Receitas_t*)malloc(QuantidadeReceitas * sizeof(Receitas_t)); //Aloca espaço para a copia das receitas.

			//Copia toda a estrutura "Receitas" para "CopiaReceitas".
			for (int i = 0; i < QuantidadeReceitas; i++) {
				CopiaReceitas[i] = Receitas[i];
			}

			//Ordena com base no codigo da receita:
			for (int i = 0; i < QuantidadeReceitas; i++) {
				for (int j = QuantidadeReceitas - 1; j > i; j--) {
					if (CopiaReceitas[j].Codigo < CopiaReceitas[j - 1].Codigo) {
						Aux = CopiaReceitas[j];
						CopiaReceitas[j] = CopiaReceitas[j - 1];
						CopiaReceitas[j - 1] = Aux;
					}
				}
			}

			ImprimeListaReceitas(CopiaReceitas, QuantidadeReceitas); //Imprime "CopiaReceitas" que agora esta ordenada.

			free(CopiaReceitas); //Libera a memoria alocada para a copia das receitas.
			break;
		}
		else if (Ordenacao == 3) { //Ordem por descrição
			CopiaReceitas = (Receitas_t*)malloc(QuantidadeReceitas * sizeof(Receitas_t)); //Aloca espaço para a copia das receitas.
			
			//Copia toda a estrutura "Receitas" para "CopiaReceitas".
			for (int i = 0; i < QuantidadeReceitas; i++) {
				CopiaReceitas[i] = Receitas[i];
			}

			//Ordena na ordem alfabetica do nome das receitas:
			for (int i = 0; i < QuantidadeReceitas; i++) {
				for (int j = QuantidadeReceitas - 1; j > i; j--) {
					if (strcmp(CopiaReceitas[j].Nome, CopiaReceitas[j - 1].Nome) < 0) {
						Aux = CopiaReceitas[j];
						CopiaReceitas[j] = CopiaReceitas[j - 1];
						CopiaReceitas[j - 1] = Aux;
					}
				}
			}

			ImprimeListaReceitas(CopiaReceitas, QuantidadeReceitas); //Imprime "CopiaReceitas" que agora esta ordenada.

			free(CopiaReceitas); //Libera a memoria alocada para a copia das receitas.
			break;
		}
		else {
			(void)printf("Numero invalido, digite um numero entre 1 e 3\n");
		}
	} while (VERDADEIRO);

	(void)printf("Digite o codigo da receita que voce deseja vizualizar: ");
	scanf("%d", &CodigoDaReceita);
	getchar(); //Tira o \n

	do {
		(void)printf("Voce deseja vizualizar essa receita ordenada por:\n1 = descricao\n2 = ordem de cadastro\n");
		scanf("%d", &Ordenacao2);

		if (Ordenacao2 == 1 || Ordenacao2 == 2) {
			break;
		}
		else {
			(void)printf("Numero digitado invalido, digite 1 ou 2.\n");
		}
		
	} while (VERDADEIRO);
	//Imprime a receita pedida pelo usuario:
	for (int i = 0; i < QuantidadeReceitas; i++) {
		if (Receitas[i].Codigo == CodigoDaReceita) {
			for (int j = 0; j < Receitas[i].QuantidadeIngredientes; j++) {
				for (int k = 0; k < QuantidadeIngredientes; k++) {
					if (Receitas[i].Ingredientes[j].Codigo == Ingrediente[k].Codigo) {
						strcpy(Receitas[i].Ingredientes[j].NomeIngrediente, Ingrediente[k].NomeIngrediente);
					}
				}
			}
			if (Ordenacao2 == 1) { //Ordem de descrição
				CopiaReceita = Receitas[i]; //Copia a receita para uma variavel para não perder 

				OrdenaIngredientesDaReceitaPordescricao(CopiaReceita.QuantidadeIngredientes, &(CopiaReceita));
				
				(void)printf("\nCodigo: %d\n", CopiaReceita.Codigo);
				(void)printf("Nome: %s\n", CopiaReceita.Nome);
				(void)printf("Ingredientes:\n");
				for (int j = 0; j < CopiaReceita.QuantidadeIngredientes; j++) {
					(void)printf("%.2f %s\n", CopiaReceita.Ingredientes[j].Quantidade, CopiaReceita.Ingredientes[j].NomeIngrediente);
				}
				(void)printf("\n");
			}
			else if (Ordenacao2 == 2) { //Ordem de cadastro
				(void)printf("\nCodigo: %d\n", Receitas[i].Codigo);
				(void)printf("Nome: %s\n", Receitas[i].Nome);
				(void)printf("Ingredientes:\n");
				for (int j = 0; j < Receitas[i].QuantidadeIngredientes; j++) {
					(void)printf("%.2f %s\n", Receitas[i].Ingredientes[j].Quantidade, Receitas[i].Ingredientes[j].NomeIngrediente);
				}
				(void)printf("\n");
			}
			AchouAReceita = VERDADEIRO;
			break;
		}
	}

	if (AchouAReceita == FALSO) {
		(void)printf("A receita com o codigo digitado nao existe\n\n");
	}
}

/*-----------------------------------------------------------------------------------------------------------------*/

//Main é a parte inicial do programa que orienta o usuario às outras funçõe.
int main(int argc, char** argv) {
	int Funcao, QuantidadeIngredientes = 0, IngredientesAMais = 0, QuantidadeReceitas = 0, ReceitasAMais;
	FILE* Arquivo;
	Ingrediente_t* Ingrediente;
	Receitas_t* Receitas;

	//Abre o arquivo dos ingredientes para leitura
	Arquivo = fopen(DIRETORIO_ARQUIVO_INGREDIENTES, "r");
	
	if (Arquivo != NULL) {
		fseek(Arquivo, 0, SEEK_SET); //Garante que "o arquivo está na primeira posição".
		fscanf(Arquivo, "%d", &QuantidadeIngredientes);
	}

	Ingrediente = (Ingrediente_t*)malloc(QuantidadeIngredientes * sizeof(Ingrediente_t)); //Aloca espaço para os ingredientes que estão no arquivo.

	//Se o arquivo for aberto é lido as informações necessarias e o arquivo é fechado
	if (Arquivo != NULL) {
		for (int i = 0; i < QuantidadeIngredientes; i++) {
			fscanf(Arquivo, "%d", &(Ingrediente[i].Codigo));
			fgets(Ingrediente[i].NomeIngrediente, TAMANHO_MAXIMO_INGREDIENTE, Arquivo);
			Ingrediente[i].NomeIngrediente[strlen(Ingrediente[i].NomeIngrediente) - 1] = '\0'; // Tira o \n do final
		}

		fclose(Arquivo);
	}

	//Abre o arquivo de receitas para leitura
	Arquivo = fopen(DIRETORIO_ARQUIVO_RECEITAS, "r");

	if (Arquivo != NULL) {
		fseek(Arquivo, 0, SEEK_SET);
		fscanf(Arquivo, "%d", &QuantidadeReceitas);
		fgetc(Arquivo);
	}

	Receitas = (Receitas_t*)malloc(QuantidadeReceitas * sizeof(Receitas_t)); //Aloca espaço para as receitas que estão no arquivo

	//Se o arquivo for aberto é lido as informações necessarias e o arquivo é fechado
	if (Arquivo != NULL) {
		for (int i = 0; i < QuantidadeReceitas; i++) {
			fscanf(Arquivo, "%d", &(Receitas[i].Codigo));
			fgetc(Arquivo);
			fgets(Receitas[i].Nome, TAMANHO_MAXIMO_RECEITA, Arquivo);
			Receitas[i].Nome[strlen(Receitas[i].Nome) - 1] = '\0'; // Tira o \n do final
			fscanf(Arquivo, "%d", &(Receitas[i].QuantidadeIngredientes));
			fgetc(Arquivo);

			Receitas[i].Ingredientes = (Ingrediente_t*)malloc(Receitas[i].QuantidadeIngredientes * sizeof(Ingrediente_t)); //Aloca espaço para os ingredientes das receitas que estão no arquivo;

			//Le o codigo e a quantidade de cada ingrediente da receita:
			for (int j = 0; j < Receitas[i].QuantidadeIngredientes; j++) {
				fscanf(Arquivo, "%d %f", &(Receitas[i].Ingredientes[j].Codigo), &(Receitas[i].Ingredientes[j].Quantidade));
				fgetc(Arquivo);
			}
		}

		fclose(Arquivo);
	}

	//"central de controle" que direciona o usuario ao resto do programa
	do {
		(void)printf("Digite o numero correspondente a funcao do sistema que voce deseja acessar:\n1.Cadastrar ingrediente(s).\n2.Lista de ingredientes.\n3.Cadastrar receita(s).\n4.Vizualizar receita(s).\n0.Sair.\n");
		scanf("%d", &Funcao);

		getchar(); //Tira o \n
		switch (Funcao){
		case 0: break;
		case 1: { //Cadastro de novos ingredientes:
			(void)printf("\n");
			(void)printf("Quantos ingredientes voce deseja cadastrar? ");
			scanf("%d", &IngredientesAMais);

			QuantidadeIngredientes += IngredientesAMais;

			Ingrediente = (Ingrediente_t*)realloc(Ingrediente, QuantidadeIngredientes * sizeof(Ingrediente_t));

			for (int i = QuantidadeIngredientes - IngredientesAMais; i < QuantidadeIngredientes; i++) {
				(void)printf("\nCadastre o %d ingrediente:", i + 1);
				CadastraIngrediente(&(Ingrediente[i]));
			}
			(void)printf("\n");
			Arquivo = fopen(DIRETORIO_ARQUIVO_INGREDIENTES, "w");
			if (Arquivo != NULL) {
				AtualizaListaIngredientes(Arquivo, Ingrediente, QuantidadeIngredientes);
				fclose(Arquivo);
			}
			break;
		}
		case 2: { //Listagem dos ingredientes já existentes
			LinstaIngredientes(QuantidadeIngredientes, Ingrediente);
			break;
		}
		case 3: {//Cadastra receitas
			(void)printf("Quantas receitas voce deseja cadastrar? ");
			scanf("%d", &ReceitasAMais);

			QuantidadeReceitas += ReceitasAMais;

			Receitas = (Receitas_t*)realloc(Receitas, QuantidadeReceitas * sizeof(Receitas_t));

			for (int i = QuantidadeReceitas - ReceitasAMais; i < QuantidadeReceitas; i++) {
				(void)printf("\nCadastre a %d receita\n", i + 1);
				CadastraReceitas(&(Receitas[i]));
			}
			(void)printf("\n");
			Arquivo = fopen(DIRETORIO_ARQUIVO_RECEITAS, "w");
			if (Arquivo != NULL) {
				AtualizaListaReceitas(Arquivo, Receitas, QuantidadeReceitas);
				fclose(Arquivo);
			}
			break;
		}
		case 4: {//Lista as receitas e detalha uma
			VizualizaReceitas(QuantidadeReceitas, Receitas, Ingrediente, QuantidadeIngredientes);
			break;
		}
		default:
			(void)printf("Numero invalido\n\n");
			break;
		}
	} while (Funcao != 0);

	free(Ingrediente); //Libera o espaço da memoria onde estavam os ingredientes.

	//Libera o espaço na memoria onde estavam os ingredientes das receitas:
	for (int i = 0; i < QuantidadeReceitas; i++) {
		free(Receitas[i].Ingredientes);
	}
	free(Receitas); //Libera o espaço na memoria onde estavam as receitas.

	return SUCESSO;
}