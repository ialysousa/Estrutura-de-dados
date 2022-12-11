//
//  Pilha.c
//  prova 3 ED
//
//  Created by Ialy Cordeiro de Sousa on 01/10/21.
//

#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

/* Criar uma pilha vazia */
void CriarPilha(TPilhaEnc *pilha)
{
    *pilha = NULL;
}

/* Verificar se a pilha está vazia */
int PilhaVazia(TPilhaEnc pilha)
{
    return pilha == NULL;
}

/* Tamanho da pilha */
int TamPilha(TPilhaEnc pilha)
{
    int tam = 0;
    while(pilha != NULL)
    {
        pilha = pilha->prox;
        tam++;
    }
    return tam;
}

/* Empilhar */
int Empilhar(TPilhaEnc *pilha, int dado)
{
    TPilhaEnc novo;

    // aloca o nó e testa
    if((novo = (no*) malloc(sizeof(no))) == NULL) return 0;

    novo->dado = dado;
    novo->prox = *pilha;
    *pilha = novo;
    return 1;
}

/* Desempilhar */
int Desempilhar(TPilhaEnc *pilha, int *dado)
{
    // Pilha está vazia
       if (PilhaVazia(*pilha)) return 0;

    TPilhaEnc aux;

    aux = *pilha;
    *dado = aux->dado;
    *pilha = (*pilha)->prox;
    
    // Liberar memória do nó desempilhado
    free(aux);

    return 1;
}


/* Consultar o topo pilha */
int ElemTopo(TPilhaEnc pilha, int *dado)
{
    if(PilhaVazia(pilha)) return 0;

    *dado = pilha->dado;
    return 1;
}

/* Exibir todos os elementos */
int Exibir (TPilhaEnc pilha)
{
    // Pilha está vazia
       if (PilhaVazia(pilha)) return 0;

    printf(" = [ ");

    // Varredura dos elementos
    while(!PilhaVazia(pilha))
    {
        printf("%d ", pilha->dado);
        pilha = pilha->prox;
    }

    printf("]");
     return 1;
}



//Clone da pilha origem para uma de destino

int clonarPilha (TPilhaEnc *origem, TPilhaEnc *destino){
  TPilhaEnc pilha_temp;
  CriarPilha(&pilha_temp);

  TPilhaEnc aux1 = *origem, aux2 = *destino;
  int elemento_temp;

  if(PilhaVazia(aux1))
  {
    printf("A pilha de origem está vazia, não pode fazer o clone!");
    return 0;
  }

  else{
    while(!PilhaVazia(aux1))
    {
      elemento_temp = aux1 -> dado;
          Empilhar(&pilha_temp, elemento_temp);
          aux1 = aux1 -> prox;
      }
      
    if(!PilhaVazia(aux2))
    {
      printf("A pilha de destino já possui elementos, não pode fazer o clone!");
      return 0;
    }
      
    else{
      while(!PilhaVazia(pilha_temp))
      {
      elemento_temp = pilha_temp -> dado;
          Empilhar(&aux2,elemento_temp);
          pilha_temp = pilha_temp -> prox;
        }
    }
  
  *destino = aux2;
  printf("\n\n--- O clone foi feito com sucesso! ---- \n");
  }

  return 1;
  free(aux1);
  free(aux2);
  free(pilha_temp);
}
