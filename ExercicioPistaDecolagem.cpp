#include <stdio.h>
#define TRUE 1
#define FALSE 0
/*
a) Informar se a pista de decolagem está vazia;
b) Listar a quantidade de avioees aguardando na pista de decolagem (fila);
c) Autorizar a decolagem do primeiro avião da fila e informar todos os seus dados na tela;
d) Adicionar um avioes a pista de decolagem;
e) Listar os dados de todos os avioes que estao na pista de decolagem;
*/
 
struct aviao{
    char prefixo[6];
    char nome[10];  
    char companhia[20];
    Aviao* prox;
};
typedef struct aviao Aviao;
 
struct pista{
    Pista *topo = NULL;
    Pista *final = NULL;
    int tam=0;
};
typedef struct pista Pista;
 
void criarFila(Pista* fila){
    fila->topo=NULL;
    fila->final=NULL;
    fila->tam=0;
}
 
int verificarFila(Pista* fila){
if (fila==NULL){
	printf("\n A fila esta vazia!");
}
}

void ler(){
    Aviao aux;
    printf("\n Digite o Prefixo do Aviao: ");
    scanf("%s", &aux.prefixo);
    printf("\n Digite o Nome do Aviao: ");
    scanf("%s", &aux.nome);
    printf("\n Digite o Nome da Companhia: ");
    scanf("%s", &aux.companhia);
    return aux;
}
 
void adicionarNovoAviaoNaFila(Pista *fila, Aviao aviao){
    Aviao aux = ler();
    Pista* prox;
    Pista* ant = NULL;

    Aviao* novo = (Aviao*) malloc (sizeof(Aviao));
    strcpy(novo->companhia, aux.companhia);
    strcpy(novo->nome, aux.nome);
	strcpy(novo->prefixo, aux.prefixo);	
	novo->prox = NULL;
  

    if(verificarFila(Pista *fila)){
       fila->topo = novo;
       fila->final = novo;
    }
    else{
        fila->final->prox = novo; //aponta o link do ultimo elemento para o  igual a " aviao->prox
        fila->final = novo;    //atualiza o final da Pista
    }
    
	printf("\n %s Inserido! ", novo->prefixo);
    fila->tam++;
}

void autorizarSaida(Pista *fila){
	if(verificarFila(fila))
	else{
		Aviao* aviao = fila->topo; // pega o aviao que esta no topo
		fila->topo = aviao->prox;  // o topo da fila vira o "prox" que esta no aviao que ira decolar
		printf("\n %s decolou !", aviao->prefixo);
		free(aviao); //libera o espaco do aviao q saiu
		fila->tam--; // diminiu o tam da fila.
	}
}
  
  
void exibirPista(Pista *fila){
	if (verificarFila(fila))
	else{
		Pista* p = fila;
		printf("\n --- Ordem da Pista de Decolagem --- \n");
		while(p!=NULL){
			printf("\n Prefixo da Aeronave: %s", p->topo->prefixo);
			printf("\n Nome da Aeronave: %s", p->topo->nome);
			printf("\n Companhia da Aeronave: %s", p->topo->companhia);
		p->final->prox;
		}
	}
}  




  
main(){
 
Pista *pista;

pista = (Pista*) malloc (sizeof(Pista));

criarFila(pista);

     






}






