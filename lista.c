#include<stdio.h>
#include<stdlib.h>


/* ----------------------------------- */
/* Primeiro Passo,Estrutura dos dados*/
/* ----------------------------------- */
 
typedef struct No *PtrNo;
typedef struct CabecalhoLista Lista;

struct No{	
	int item;
	PtrNo prox;
	
};

struct CabecalhoLista{
	
	PtrNo primeiro;
	PtrNo ultimo;
	int qtd;	
	
};

/* ----------------------------------- */
/* Segundo Passo, Cria a lista vazia   */
/* ----------------------------------- */


int criarLista(Lista *lista){
	
	if(lista == NULL)
	return 0;
	
	lista->primeiro = NULL;
	lista-> ultimo = NULL;
	lista-> qtd = 0;
	return 1;
		
}


/* ----------------------------------- */
/* Verifica Lista Vazia                 */
/* ----------------------------------- */

int main(){
	
	
	return 0;
}














