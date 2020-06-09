#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct aluno Aluno;
struct aluno {
int matricula;
char nome[30];
};

typedef struct elemento Elemento;
struct elemento {
Pessoa p;
Elemento* prox;
};

Elemento* lstCria()
{ return NULL; }

int lstVazia(Elemento* lst)
{ return (lst==NULL); }

void ler()
{
    Aluno aux;
    printf("\n Registro de Aluno.");
    printf("\n Digite a matricula: ");
    scanf("%d", &aux.matricula);
    printf("\n Digite um nome: ");
    scanf("%s", aux.nome);
    return aux;
}

Elemento lstInsere(Elemento *lst)
{
    Aluno aux = ler();
    Elemento* novo = (Elemento*) malloc (sizeof(Elemento));
    novo->Aluno = aux;
    novo->prox = lst;
    return novo;
}

Elemento lstInsereFinal(Elemento *lst)
{
    Aluno aux = ler();
    Elemento *p;
    Elemento *anterior = NULL;

    Elemento* novo = (Elemento*) malloc (sizeof(Elemento));
    novo->Aluno = aux;
    novo->prox = NULL;

    if(lstVazia(lst))
    {
    lst = novo;
    }   else 
        {
        p = lst;
        }

    while (p!=NULL)  
    {
    anterior = p;
    p = p->prox;
    }

    anterior->prox = novo;
}

Elemento lstRemove(Elemento* lst, int auxMatricula, char auxNome[30])
{
    Elemento* anterior = NULL; //ponteiro p elemento anterior
    Elemento* p = lst;         // ponteiro p percorrer lista

    while (p!=NULL && p->matricula != auxMatricula)
    {
    anterior = p;
    p = p->prox;
    }

    if(p==NULL)
    {return lst;}

        if(anterior==NULL)
        {lst = p->prox} 
        else
        {anterior->prox = p->prox;}
    free(p);
    return lst;
}

Elemento lstBusca(Elemento* lst, int auxMatricula)
{
    Elemento* p;
    for (p=lst; p!=NULL; p=p->prox)
    {
        if (p->matricula == auxMatricula)
        {
        printf("\n Matricula encontrada!");
        return p;
        }
    }
    printf("\n Matricula não encontrada.")
    return NULL;
}

void lstImprime(Elemento* lst)
{
    int i=1;
    Elemento* p;
    for(p=lst; p!=NULL; p->prox)
    {
    printf("\n--- Aluno %d ---", i);
    printf("\n Nome: %s", p->nome);
    printf("\n Matricula: %d", p->matricula);
    i++;
    }
}

Elemento lstLimpa(Elemento* lst)
{
    Elemento* p = lst;
    Elemento* px;
        while(p!=NULL)
        {
        px = p->prox;
        free(p)
        p=px;
        }
return NULL;
}

Elemento lstInsereOrdemCrescente(Elemento* lst, int auxMatricula)
{   
    Elemento* novo;
    Elemento* ant = NULL;  
    Elemento* p = lst;     

    while (p != NULL && p->info < auxMatricula) 
    { 
    ant = p; 
    p = p-> prox; 
    }

    novo = (Elemento*) malloc(sizeof(Elemento));
    novo -> info = auxMatricula;

        if (ant == NULL) 
        { novo -> prox = lst; lst = novo; }
        else 
        { 
        novo -> prox = ant -> prox;
        ant->prox = novo; 
        }

    return lst;
}

Elemento lstInsereOrdemDecrescente(Elemento* lst, int auxMatricula)
{   
    Elemento* novo;
    Elemento* ant = NULL;  
    Elemento* p = lst;     

    while (p != NULL && p->info > auxMatricula) 
    { 
    ant = p; 
    p = p-> prox; 
    }

    novo = (Elemento*) malloc(sizeof(Elemento));
    novo -> info = auxMatricula;

        if (ant == NULL) 
        { novo -> prox = lst; lst = novo; }
        else 
        { 
        novo -> prox = ant -> prox;
        ant->prox = novo; 
        }

    return lst;
}



int main()
{
Elemento *lst; 

lst = lst_cria();

lst = lstInsere();

return 0;
}
