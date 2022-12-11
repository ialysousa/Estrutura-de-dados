//*************** Implementação da área de dados do TAD ***************//

// definição da estrutura lista duplamente encadeada
typedef struct nolista {
	int dado;  			   // campo que guarda a informação
    struct nolista *prox;  // guarda o endereço para prox nó
    struct nolista *ant;   // guarda o endereço para nó anterior
}no;

typedef no* TListaDupEnc;


// 2 listas que serao encadeadas
typedef struct Lista_Dividida {
	Lista_Encadeada* lst1;
	Lista_Encadeada* lst2;
} ListaDividida;

//************ A interface de uso do TAD Lista Dup. Encadeada *********//

/* Procedimento para criar uma lista vazia */
void criarLista( TListaDupEnc *lista );


/* Função para verificar se a lista está vazia ou nó */
int listaVazia( TListaDupEnc lista );

/* Função para verificar a quantidade de elementos na lista */
int tamanhoLista( TListaDupEnc lista );

/* Função para buscar um elemento mediante sua posição dentro da lista */
int elementoNaPosicao( TListaDupEnc lista, int posicao, int* dado );

/* Função para buscar a posição de um elemento na lista */
int posicaoDoElemento( TListaDupEnc lista, int dado );

/* Função para inserir um elemento na lista mediante sua posição */
int inserirElemento( TListaDupEnc* lista, int posicao, int dado );

/* Função para remover um elemento da lista mediante sua posição */
int removerElemento( TListaDupEnc* lista, int posicao, int *dado );

/* Procedimento para exibir todos os elementos da lista */
void imprimir ( TListaDupEnc lista );


/* Função para verificar a quantidade de elementos na lista */
int ProcurarOcorrencias(TListaDupEnc* lista, int n_procurado);

/* Função adiciona elemento no inicio da lista */
int adcInicio(TListaDupEnc * lista, int dado);

/* Função adiciona elemento no fim da lista */
int adcFim(TListaDupEnc * lista, int elemento);

/* interseção das listas */
TListaDupEnc* ObterIntersecao(TListaDupEnc* lst1, TListaDupEnc* lst2);