#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>

void preenche_valor(int *p);
void imprime_valor(int *p);

main(){
	
	int vetor[5];
	int *p;
	p = &vetor[0];
	
	preenche_valor(p);
	imprime_valor(p);
	return 0;	
}



void preenche_valor(int *p)
{int i;
	for (i=0; i<5;i++)
	{
		
		printf("\n Digite um valor para %d \n", i);
		scanf (" \n %d", (p+i));
		fflush(stdin);
	} 
}

void imprime_valor(int *p)
{
	int i;
	for (i=0; i<5;i++)
	{
	printf("\n Valor do Vetor %d : %d \n", i, *p+i);
	}
}
