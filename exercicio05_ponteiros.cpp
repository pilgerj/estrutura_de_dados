#include <stdio.h>
#include <stdlib.h>

struct TipoProduto
{
int codigo;
char descricao[60];
};

void leitura(struct TipoProduto *p, int qtd);
void escrita(struct TipoProduto *p, int qtd);

main ()
{
 int qtd = 3;
 struct TipoProduto *p;
 struct TipoProduto vetor[3];
 p = vetor;
 leitura(p, qtd);
 escrita(p, qtd);
}

void leitura(struct TipoProduto *p, int qtd)
{
	int i;
	for (i=0; i<qtd; i++) 
	{
	printf (" Digite o codigo: \n");
	scanf("%d", &(p+i)->codigo);
	fflush(stdin);
	
	printf (" Digite a descricao: \n");
	scanf("%s", (p+i)->descricao);
	fflush(stdin);
	}
}

void escrita(struct TipoProduto *p, int qtd)
{
	int i;
	for (i=0; i<qtd; i++) 
	{
	printf("\n  Codigo do produto: %d", (p+i)->codigo);
	printf("\n  Descricao do produto: %s", (p+i)->descricao);
	}
}
