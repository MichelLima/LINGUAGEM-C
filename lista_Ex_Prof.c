/* ----------------------------------- */
/* Programa Exemplo de Estrutura de    */
/* Dados do Tipo Lista Encadeada       */
/* Disciplina: AED                     */
/* Prof.     : Alessandro M. Lima      */
/* ----------------------------------- */

//#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>

/* ----------------------------------- */
/* Definicao dos tipos de Dados        */
/* ----------------------------------- */
typedef struct No *PtrNo;
typedef struct CabecalhoLista Lista;
 
struct No {
  int item;
  PtrNo prox;
};

struct CabecalhoLista {
    PtrNo prim;
    PtrNo ult;
    int qtd;
};

/* ----------------------------------- */
/* Cria a lista vazia                  */
/* ----------------------------------- */

int crialista(Lista *lista){
 
   if (lista==NULL)
      return 0;
      
   lista->prim=NULL;
   lista->ult=NULL;
   lista->qtd=0;
   
   return 1;
}

/* ----------------------------------- */
/* Verifica se a lista e' vazia        */
/* ----------------------------------- */

int eVazia(Lista lista){ 
 return (lista.prim  == lista.ult);
}

/* ----------------------------------- */
/* Verifica se e o último no da lista  */
/* ----------------------------------- */

int eUltimo(PtrNo p){
 return  (p->prox == NULL);
}

/* -------------------------------------- */
/* Retorna referência elemento encontrado */ 
/* na lista                               */
/* Retorna:                               */
/*   Endereço - Endereço do elemento      */
/*   NULL - Nao conseguiu encontrar       */
/* -------------------------------------- */

PtrNo buscar(int x, Lista lista){
  PtrNo p;
  p=lista.prim->prox;
  while ((p!=NULL) && (p->item!=x))        
      p=p->prox; 
  return p;  
 } 
 
/* --------------------------------------- */
/* Encontre elemento anterior.             */
/* Assume existencia de Header             */
/* Retorna:                                */
/*   Null - Caso nao encontre              */
/*   Endereço do elemento anterior - caso encontre  */
/* --------------------------------------- */

PtrNo encontreAnterior(int x, Lista *lista){
  PtrNo p;
  p=lista->prim;
  if (p==NULL) 
     return NULL;
     
  while ((p->prox!=NULL) 
          && (p->prox->item!=x))        
      p=p->prox; 
   
  return p;  
 }  
 
/* -------------------------------------- */
/* Encontre elemento anterior             */
/* Assume existencia de Header            */
/* Retorna:                               */
/*   Endereço - Endereço do elemento      */
/*   NULL - Nao conseguiu encontrar       */
/* -------------------------------------- */

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
 
/* ------------------------------------- */
/* Inclui um elemento na lista em uma    */
/* posição                               */
/* Retorna:                              */
/*   1 - Inclusao com sucesso            */
/*   0 - Erro!! Nao conseguiu incluir    */
/* ------------------------------------- */
int inserir (int x, int posicao, Lista *lista){
   PtrNo p, tmp, aux;
   
   //Checa possibilidade de insercao
   if (posicao>lista->qtd+1){
   	return 0;
   }
   
   /* aloca e preenche espaço do elemento */
   tmp = malloc (sizeof(struct No));
   if (tmp==NULL)
      return 0;
   tmp->item=x;
   tmp->prox=NULL;
   
   if (posicao==1){
   	   aux=lista->prim;
   	   lista->prim=tmp;
	   tmp->prox=aux; 
	   if (lista->qtd==0)
   	     lista->ult=tmp;
	   lista->qtd++; 
   	   return 1;
   }
   
   p=encontreAnteriorIndice(posicao,lista);
   
   if (p==NULL){
   	return 0;
   }
 
   tmp->prox=p->prox;
   p->prox=tmp;
   lista->qtd++; 
      
   return 1;
}

/* ------------------------------------- */
/* Inclui um elemento no final da lista  */
/* Retorna:                              */
/*   1 - Inclusao com sucesso            */
/*   0 - Erro!! Nao conseguiu incluir    */
/* ------------------------------------- */
int inserirNoFinal (int x, Lista *lista){
   PtrNo tmp;
   
   /* aloca e preenche espaço do elemento */
   tmp = malloc (sizeof(struct No));
   if (tmp==NULL)
      return 0;
   tmp->item=x;
   tmp->prox=NULL;
     
   lista->ult->prox=tmp;
   lista->ult=tmp;  
        
   return 1;
}

/* ------------------------------------- */
/* Remove um elemento da lista           */
/* Retorna:                              */
/*   1 - Removeu com sucesso             */
/*   0 - Erro!! Nao conseguiu Remover    */
/* ------------------------------------- */
int remover(int x, Lista *lista){
   PtrNo p,tmp;

   if (x>lista->qtd)
      return 0;
    
   if (x==1){
   	   tmp=lista->prim;
   	   lista->prim=NULL; 
   	   lista->ult=NULL; 
	   lista->qtd--; 
	  
	   free (tmp);
   	   return 1;
   }
    
   p=encontreAnteriorIndice(x,lista);
   if (p==NULL)
       return 0;
   
   
   
   tmp=p->prox;
   p->prox=tmp->prox; 
   if (lista->ult==tmp)
      lista->ult=p;     
   lista->qtd--;     
	     
   free (tmp);
   
   return 1;
}

/* ----------------------------------- */
/* Imprime os Elementos da Lista       */
/* ----------------------------------- */
void imprimeLista (Lista lista){
  PtrNo p;
  p=lista.prim;
  while (p!=NULL){
      printf("Valor: %d \n", p->item);
      p=p->prox;
  }
 }

/* ----------------------------------- */
/* Programa Principal                  */
/* ----------------------------------- */
int main(){
      char c;
      int elemento;
      Lista lista;

      /* Limpa a tela
      clrscr();       */

      /* Criando a Pilha vazia */
      crialista(&lista);      
 
      /* Incluindo um elemento */
      elemento=1;
      inserir(elemento,1,&lista);
      printf("\nlista qtd: %d\n", lista.qtd);

      /* Incluindo um elemento */
      elemento=3;
      inserir(elemento,2,&lista);
        printf("\nlista qtd: %d \n", lista.qtd);

      /* Incluindo um elemento */
      elemento=2;
      inserir(elemento,3,&lista);  
        printf("\nlista qtd: %d \n", lista.qtd);
      
      /* Incluindo um elemento */
      //elemento=21;
      //inserirNoFinal(elemento,&lista);             

      /* Imprimindo a Pilha */
      printf("Imprimindo 1a Parte: \n");
      imprimeLista(lista);

      printf("\nRemovendo \n");
      /* Retirando o elemento*/
      remover(2,&lista);
       
      /* Imprimindo a Pilha */
      printf("\n\nImprimindo 2a Parte: \n");
      imprimeLista(lista);  

      system("PAUSE");
}


