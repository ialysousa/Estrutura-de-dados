//
//  Pilha.h
//  prova 3 ED
//
//  Created by Ialy Cordeiro de Sousa on 01/10/21.
//


typedef struct nopilha
{
    int dado;
    struct nopilha *prox;
}no;
typedef no* TPilhaEnc;

/* Criar uma pilha vazia */
void CriarPilha(TPilhaEnc *pilha);

/* Verificar se a pilha está vazia */
int PilhaVazia(TPilhaEnc pilha);

/* Tamanho da pilha */
int TamPilha(TPilhaEnc pilha);

/* Empilhar um elemento */
int Empilhar(TPilhaEnc *pilha, int dado);

/* Desempilhar um elemento */
int Desempilhar(TPilhaEnc *pilha, int *dado);

/* Consultar o topo pilha */
int ElemTopo(TPilhaEnc pilha, int *dado);

/* Exibir todos os elementos */
int Exibir (TPilhaEnc pilha);

/*Clonar elementos da pilha origem para a pilha destino */
int clonarPilha (TPilhaEnc *origem, TPilhaEnc *destino);

