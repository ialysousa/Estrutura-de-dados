/*************** Área de dados do TAD Lista Duplamente Encadeada *********************/
#include "listadupenc.h"
#include <stdio.h>
#include <stdlib.h>



//----------------------------------------------------------------------

// funções auxiliares que apenas fatoram código comum as sub-rotinas...
TListaDupEnc aloca();
TListaDupEnc *inicio;
TListaDupEnc *fim;
//----------------------------------------------------------------------

//*************** Implementação do TAD Lista Dup. Encadeada ***********//


/* Criar uma lista duplamente encadeada vazia
 * Parâmetros: o ponteiro que representa "a cabeça" da lista 
 * (por referência)
 */
void criarLista( TListaDupEnc *lista ){ *lista = NULL; }



/* Verificar se a lista está (ou não) vazia
 * Parâmetros: o ponteiro que representa "a cabeça" da lista (por valor)
 */
int listaVazia( TListaDupEnc lista ){ return lista == NULL; }


/* Verificar a quantidade de elementos na lista
 * Parâmetros: o ponteiro que representa a cabeça da lista (por valor)
 */
int tamanhoLista( TListaDupEnc lista ){
	int tamanho = 0;
	while( lista != NULL ) {
    	lista = lista->prox;
        tamanho++;
    }
    return tamanho;
}


/*Interseção  */

TListaDupEnc* ListaEncadeada_ObterIntersecao(TListaDupEnc* lst1, TListaDupEnc* lst2) {
	TListaDupEnc* lista_intersecao = ListaEncadeada_Criar();
	no* node_lista_a = TListaDupEnc->prox;
	no* node_lista_b;
	no* node_lista_intersecao;
	short numero_ja_inserido; //boolean

	//Itera pelos elementos da lista 'a:'
	while (node_lista_a != NULL) {
		numero_ja_inserido = 0;
		node_lista_intersecao = lista_intersecao->prox;
		//Verifica se o elemento ja existe na lista de intersecao:
		while (node_lista_intersecao != NULL) {
			if (node_lst1->ant == node_lista_intersecao->ant) {
				numero_ja_inserido = 1;
				break;
			}
			node_lista_intersecao = node_lista_intersecao->prox;
		}

		if (numero_ja_inserido == 0) {
			//Para cada elemento da lista 'a', percorre por todos os elementos da lista 'b':
			node_lista_b = lst2-> prox;
			while (node_lista_b != NULL) {
				if (node_lista_a->ant == node_lista_b->ant) {
					ListaEncadeada_Inserir(lista_intersecao, node_lista_a->ant);
					break; //Para o while que itera a lista 'b' e passa pro proximo da lista 'a'.
				}
				node_lista_b = node_lista_b->prox; //Passa para o proximo elemento da  lista 'b'.
			}
		}
		node_lista_a = node_lista_a->prox; //Passa para o proximo elemento da  lista 'a'.
	}

	return lista_intersecao;
}






/*  Buscar um elemento mediante sua posição na lista
 *  Parâmetros: lista = a lista dup. encadeada
 *              posicao = posição na qual se deseja buscar o elemento
 *              dado = passagem por referência "retornando" o elem. desejado
 *  Retorno: 1 em caso de sucesso ou 0, no caso de posição inválida
 */
int elementoNaPosicao( TListaDupEnc lista, int posicao, int* dado ){
	int posicaoAtual = 1;
	
    // se lista está vazia ou posição inválida
    if ( listaVazia( lista ) || posicao <= 0 
              || posicao > tamanhoLista( lista ) ) return 0;
    
    while ( ( lista != NULL ) && ( posicaoAtual < posicao ) ){
    	lista = lista->prox;
        posicaoAtual++;
    }
    *dado = lista->dado;
    return 1;
}

/* Obter a posição de um elemento na lista dup. encadeada
 * Parâmetros: lista = a lista dup. encadeada
 *             elemento = o dado a ser pesquisado na lista
 * Retorno: a posição do elemento em caso de sucesso ou 0 caso contrário
 */
int posicaoDoElemento( TListaDupEnc lista, int dado ){
    int posicao = 1;

    while ( lista != NULL ) {
    	// testar se o dado � igual ao campo de informação do nó...
    	if ( dado == lista->dado )	return posicao;
    	
    	lista = lista->prox;
    	posicao++;
    }
    return 0;
}

/* Inserir um elemento na lista mediante uma posição
 * Parâmetros: lista = a lista dup. encadeada
 *             elemento = o dado a ser inserido
 *             posicao = posição na qual se deseja inserir o elemento
 * Retorno: 1 em caso de sucesso ou 0, caso contrário
 */
int inserirElemento( TListaDupEnc* lista, int posicao, int dado ){
	TListaDupEnc novo = NULL, aux = NULL;
    int contador = 1;
    
    // inserção em uma lista que está vazia
    if( listaVazia( *lista ) ) {
    	// se a lista está vazia, só é possível inserir na posição 1
        if( posicao != 1 ) return 0;
		// alocar o no e testar pra ver se tudo correu bem
        if( ( novo = aloca() ) == NULL ) return 0;

        novo->dado = dado;
        novo->prox = NULL;
        novo->ant = NULL;
        *lista = novo;
        return 1;
    }

	// inserção na primeira posição em uma lista não vazia
    if( posicao == 1 ){
    	// alocar o no e testar pra ver se tudo correu bem
        if( ( novo = aloca() ) == NULL ) return 0;

        novo->dado = dado;
        novo->prox = *lista; // faz novo nó "conectar-se" ao primeiro
        novo->ant = NULL;
        (*lista)->ant = novo;
        *lista = novo;
        return 1;
    }

    // inserção após a primeira posição e em uma lista não vazia
    aux = *lista;

	// uma estratégia é fazer aux parar uma posição "antes" da real posição
	while( ( contador < posicao -1 ) && ( aux != NULL ) ) {
    	aux = aux->prox;
        contador++;
    }

    // só por garantia, vou testar se posição 
	// foi maior que o esperado (é inválida)
    if( aux == NULL ) return 0;

    // alocar o novo nó
    if( ( novo = aloca() ) == NULL ) return 0;

    novo->dado = dado;
    novo->prox = aux->prox;
    novo->ant = aux;

    // cenário de inserção entre dois elementos existentes
    if( aux->prox != NULL ) aux->prox->ant = novo;

    aux->prox = novo;
    return 1;
}

/* Remover um elemento da lista mediante sua posição
 * Parâmetros: lista = a lista dup. encadeada
 * 			   dado = passagem por referência "retornando" o elem. removido
 *             posicao = posição na qual se deseja remover o elemento
 * Retorno: 1 em caso de sucesso ou 0, caso contrário
 */
int removerElemento( TListaDupEnc* lista, int posicao, int *dado ){
	TListaDupEnc aux = NULL;
    int contador = 1;

    if ( listaVazia( *lista ) ) return 0;

    // faz aux apontar para o primeiro elemento
    aux = *lista;

    // aux deve "parar" sobre o nó a ser removido
    while( ( contador < posicao ) && ( aux != NULL ) ){
    	aux = aux->prox;
        contador++;
    }
    // se a posição foi maior que o esperado
    if ( aux == NULL ) return 0;

 	// guardar o dado antes de "apagar" o nó da memória
    *dado = aux->dado;

    // primeiro nó da lista?
    if( posicao == 1 ){
    	*lista = aux->prox;
        // deve-se testar se há mais de um elemento na lista
        if( aux->prox != NULL )	aux->prox->ant = NULL;
    } else {
    	// se não é o último nó...
        if( aux->prox != NULL ) aux->prox->ant = aux->ant;

        aux->ant->prox = aux->prox;
    }
    // remover, aqui, implica em desalocar memória
    free( aux );
    return 1;
}

/* Exibir todos os elementos da lista
 * Parâmetros: lista = a lista encadeada
 */
void imprimir ( TListaDupEnc lista ){
	printf( "\nLista: ( ");

	for( ;!listaVazia( lista ); lista = lista->prox )
	    printf("%d ", lista->dado );

	printf( ")" );
}

// alocar um novo nó na memória do computador
// função utilitária usada para fatorar código comum
TListaDupEnc aloca(){ return (no*) malloc( sizeof( no ) ); }


/* Numero de ocorrencias */

int ProcurarOcorrencias(TListaDupEnc* listaEncadeada, int n_procurado) {
	no* TListaDupEnc =  TListaDupEnc-> prox;
	int numero_ocorrencias = 0;
	while (TListaDupEnc != NULL) {
		//Verifica se encontrou:
		if (TListaDupEnc ->dado == n_procurado) {
			numero_ocorrencias++;
		}
		TListaDupEnc = TListaDupEnc->prox;
	}
	return numero_ocorrencias;
 }
/* Adiciona no inicio */

int adcInicio(TListaDupEnc * lista, int elemento)
{
  TListaDupEnc nv_elemento = aloca();

  if(listaVazia(*lista))
  {
    nv_elemento -> dado = elemento;
    *lista = nv_elemento;
  } else
  {
    nv_elemento -> dado = elemento;
    nv_elemento -> prox = *lista;
    (*lista) -> ant = nv_elemento;
    *lista = nv_elemento;
  }
  return 0;
}

/* Adiciona no fim */

int adcFim(TListaDupEnc * lista, int elemento)
{
  TListaDupEnc nv_elemento = aloca();
  int ocorrencia = 0;

  if(listaVazia(*lista))
  {
    nv_elemento -> dado = elemento;
    *lista = nv_elemento;
  } else 
  {
    while (lista != NULL)
    {
      if (elemento ==  nv_elemento -> dado)
      {
        ocorrencia++; 
      }
    }
  }
  return 0;
  free(nv_elemento);
}
