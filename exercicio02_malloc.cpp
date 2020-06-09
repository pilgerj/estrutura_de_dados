/*
Implementar um algoritmo que armazene um vetor de struct aluno. Este vetor deve ser criado
dinamicamente através da função malloc ou calloc. O programador deve questionar o usuário
sobre quantos alunos ele deseja armazenar. De posse do número de alunos, o espaço de
memória adequado deve ser alocado e posteriormente a leitura dos dados dos alunos deve ser
realizada.
Após a leitura de todos os alunos, deve ser chamada uma função lista_alunos para mostrar na
tela todos os valores relacionados aos alunos
*/

#include <stdio.h>
#include <stdlib.h>

struct aluno 
{
 int matricula;
 char nome[30];
 float media;
}; 

void cadastrar(struct aluno *p, int qtd);
void imprimir(struct aluno *p, int qtd);

int main()
{
int qtd=0;
struct aluno *p;

printf("\n Digite a quantidade de alunos que deseja inserir: \n");
scanf("%d", &qtd);

p = (struct aluno *) malloc(qtd * sizeof(struct aluno));

	if(p)
	{
		cadastrar(p, qtd);
		imprimir(p, qtd);
	}
	else
	{
		printf("\n Espaco insuficiente de memoria!");
		free(p);
	}

return 0; 

}

void cadastrar(struct aluno *p, int qtd)
{
	for (int i=0; i<qtd; i++)
	{
	printf("\n Digite a matricula do aluno: ");
	scanf("%d", &(p+i)->matricula);
	fflush(stdin);
	
	printf("\n Digite o nome do aluno: ");
	//scanf("%c", &(p+i)->nome);
	fgets((p+i)->nome,sizeof((p+i)->nome),stdin);
	fflush(stdin);
	
	printf("\n Digite sua media obtida: ");
	scanf("%f", &(p+i)->media);
	fflush(stdin);
	}
}

void imprimir(struct aluno *p, int qtd)	
{
	printf("\n --------------------------");
	printf("\n --- Alunos Cadastrados ---");
	printf("\n --------------------------");
	printf("\n");
	for (int i=0; i<qtd; i++)
	{	
	printf("\n__________________________________________");
	printf ("\n Matricula do aluno: %d", (p+i)->matricula);
	printf ("\n Nome do aluno: %s", (p+i)->nome);
	printf ("\n Media trimestral obitda: %.1f", (p+i)->media);
	printf("\n__________________________________________");
	}	
	
}
	

