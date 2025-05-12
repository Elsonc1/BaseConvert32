#include <stdio.h>
#include <string.h>
#include <ctype.h>

int charParaValor(char c) {
	if (isdigit(c))
		return c - '0';
	else if (isalpha(c)) {
		char maiusculo = toupper(c);
		if (maiusculo >= 'A' && maiusculo <= 'V')
			return maiusculo - 'A' + 10;
	}
	return -1;
}

int converterParaDecimal(const char* numero, int baseOrigem) {
	int resultado = 0;
	int valor;

	for (int i = 0; numero[i] != '\0'; i++) {
		valor = charParaValor(numero[i]);
		if (valor < 0 || valor >= baseOrigem) {
			printf("Erro: Caractere '%c' C) invC!lido para a base %d.\n", numero[i], baseOrigem);
			return -1;
		}
		resultado = resultado * baseOrigem + valor;
	}

	return resultado;
}

int main() {
	char numero[100];
	int baseOrigem;

	printf("=== ConversC#o de Base para Decimal ===\n\n");
	printf("Digite o nC:mero a ser convertido (com dC-gitos entre 0-9 e A-V): ");
	scanf("%s", numero);

	printf("Informe a base do nC:mero informado (entre 2 e 32): ");
	scanf("%d", &baseOrigem);

	if (baseOrigem < 2 || baseOrigem > 32) {
		printf("Erro: A base deve estar entre 2 e 32.\n");
		return 1;
	}

	int resultado = converterParaDecimal(numero, baseOrigem);

	if (resultado != -1)
		printf("\nResultado: O nC:mero %s na base %d equivale a %d em decimal.\n", numero, baseOrigem, resultado);

	return 0;
}