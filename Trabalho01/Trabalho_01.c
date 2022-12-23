/*trabalho 1.
construir uma calculadora simples capaz de realizar contas
utilizando sempre dois operandos de ponto flutuante e um operador (adição
(+), subtração (-), multiplicação (*), divisão (/), módulo (%) e
exponenciação (#)).*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define SUCESSO 0;

int main(int argc, char** argv) {
	float a, b, result = 0;
	char s;	
	int d, e, i, f;
	a = 'z';
	b = 'y';
	d = 'x';
	e = 'w';

	do {

		printf("Operacao:  \n");
		scanf("%f %c %f", &a, &s, &b);

		if ((a != 'z') && (b != 'y')) {
			switch (s) {
			case '+':
				result = (a + b);
				printf("Resultado: \n%f\n", result);
				break;
			case '-':
				result = (a - b);
				printf("Resultado: \n%f\n", result);
				break;
			case '*':
				result = (a * b);
				printf("Resultado: \n%f\n", result);
				break;
			case '/':
				result = (a / b);
				printf("Resultado: \n%f\n", result);
				break;
			case '%':
				d = a;
				e = b;
				result = (d % e);
				printf("Resultado: \n%f\n", result);
				break;
			case '#':
				d = a;
				f = d;
				e = b;
				for (i = 1; i < e; i++) {
					f *= d;
				}
				printf("Resultado: \n%i\n", f);
				break;
			default:
				break;
			}
		}
		
	} while ((a != 'z') && (b != 'y'));


	
	return SUCESSO;
}