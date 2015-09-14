#include<stdio.h>
#include<stdlib.h>


typedef struct No *PtrNo;
typedef struct cabecalhoLista Lista;

struct cabecalhoLista{
	
	PtrNo prim , ult;
	int qtd;
	
	
};

struct No{
	
	char modelo[20];
	int ano;
	PtrNo prox;	
	
};

int CriarLista(Lista *lista){
	
	if(lista==NULL)
	return 0;
	
	
	lista->prim=NULL;
	lista->ult = NULL;
	lista->qtd = 0;
	
	return 1;
	
}

PtrNo encontreAnteriorIndice(int posicao, Lista *lista){
  PtrNo aux;
  int j;
  aux=lista->prim;  
  j=2; 
  while ((j<posicao) && (aux!=NULL)){        
      aux=aux->prox; 
      j++;         
  } 
   //printf("\n\nImprimindo anterior: %d\n", aux->item);
  return aux;
 }  
 /*
 
 			Metodo que insere intens na lista
 
 */
int inserir(char modelo, int ano, int posicao, Lista *lista){
	
	
	PtrNo p, tmp, aux;
	
	if(posicao> lista->qtd+1){
		return 0;
	}
	
	tmp = malloc(sizeof(struct No));
	if(tmp==NULL)
		return 0;
	//	strcpy(tmp->modelo, modelo);
		//tmp->modelo= modelo;
		tmp->ano = ano;
		tmp->prox = NULL;
	
	if(posicao == 1){
		
		aux=lista->prim ;
		lista->prim = tmp;
		tmp->prox = aux;
			if(lista->qtd)
				lista->ult = tmp;
				lista->qtd++;
				
				return 1;
	}
	
	p=encontreAnteriorIndice(posicao, lista);
		if(p==NULL){
			return 0;
		}
		tmp->prox = p->prox;
		lista->qtd++;
		return 1;
	
}
void imprimeLista (Lista lista){
  PtrNo p;
  int qtd = 1;
  p=lista.prim;
  while (p!=NULL){
  	  printf("\n Quantidade: %d", lista.qtd );
      printf("\n Modelo: %d", p->modelo );
      printf("\n Modelo: %d ", p->ano );
      qtd++;
	  p=p->prox;
      
  }
}
	
	int main(){
		char modelo;
		int ano;
		Lista lista;
		
		//cria a lista vazia
		CriarLista(&lista);
		
		//Incluindo Elementos na lista
		//modelo="fiat";
		ano = 1990;
		inserir(modelo,ano,1,&lista);
		
		
		//Incluindo Elementos na lista
		//modelo="fiat";
		ano = 2010;
		inserir(modelo,ano,1,&lista);
		
		
		
		//Incluindo Elementos na lista
		//modelo="fiat";
		ano = 2015;
		inserir(modelo,ano,1,&lista);
	
		
		printf("\n imprimindo lista: \n");
		imprimeLista(lista);
	
	system("pause");
		
		
	}
	
	

