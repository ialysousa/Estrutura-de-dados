#include "listadupenc.h"
#include <stdio.h>

int main (void) {
	TListaDupEnc lista;
  TListaDupEnc* lista_auxiliar;

    criarLista( &lista );

    if( listaVazia( lista ) ) printf( "Esta vazia!" );

    inserirElemento( &lista, 1, 10 );
    inserirElemento( &lista, 2, 20 );
    inserirElemento( &lista, 3, 30 );
    inserirElemento( &lista, 4, 40 );
  
    printf( "\nQtd elementos na memoria: %d", tamanhoLista( lista ) );
    


    // e se quem utiliza a biblioteca comete equívocos?
    printf( "\n%s", inserirElemento( &lista, 5000, 50 ) ? 
	    	        "Sucesso" : "Erro na insercao!" );

    imprimir( lista );  printf( "\n" );

    printf( "\nPosicao do elemento 10: %d", posicaoDoElemento( lista, 10 ) );
    printf( "\nPosicao do elemento 20: %d", posicaoDoElemento( lista, 20 ) );
    printf( "\nPosicao do elemento 30: %d", posicaoDoElemento( lista, 30 ) );
    printf( "\nPosicao do elemento 40: %d", posicaoDoElemento( lista, 40 ) );

    

    int retorno = 0;
    elementoNaPosicao( lista, 1, &retorno ) ; 
		printf( "\nElemento na posicao 1: %d", retorno );
    elementoNaPosicao( lista, 2, &retorno ) ;
		printf( "\nElemento na posicao 2: %d", retorno );
    elementoNaPosicao( lista, 3, &retorno ) ;
		printf( "\nElemento na posicao 3: %d", retorno );
    elementoNaPosicao( lista, 4, &retorno ) ;
		printf( "\nElemento na posicao 4: %d", retorno );

    //Procura as ocorrencias

    int numero_aux, resp;
    
   printf("\nDigite o numero a ser procurado as ocorrencias:");
    scanf("%d", &numero_aux);
    getchar();
    resp = ProcurarOcorrencias(lista_auxiliar, numero_aux);
    printf("\tQuantidade de ocorrencias na lista: %d \n", ProcurarOcorrencias(lista_auxiliar, numero_aux));
    getchar();
   
   // Adiciona inicio
   //adcInicio();


    // Adiciona final
    int nv_elemento, elemento, ocorrencia;
    adcFim(lista_auxiliar, 100);
  
    removerElemento( &lista, 2, &retorno ); //20
    printf( "\n\nElemento removido: %d", retorno );
    printf( "\nQtd elementos na memoria: %d", tamanhoLista( lista ) );

    imprimir( lista );
    
    removerElemento( &lista, 3, &retorno );
    printf( "\nElemento removido: %d", retorno ); // 40

    printf( "\nQtd elementos na memoria: %d", tamanhoLista( lista ) ); 
  	imprimir( lista );

    removerElemento( &lista, 1, &retorno );
    printf( "\nElemento removido: %d", retorno ); //10

    printf( "\nQtd elementos na memoria: %d", tamanhoLista( lista ) );
	  imprimir( lista );

    removerElemento( &lista, 1, &retorno );
    printf( "\nElemento removido: %d", retorno ); //30

    printf( "\nQtd elementos na memoria: %d\n", tamanhoLista( lista ) );

	  return 0;
}



/*#include "listadupenc.h"
#include <stdio.h>

int main(void){
  TListaDupEnc lista1, lista2;

  criarLista(&lista1);
  criarLista(&lista2);

  adcInicio(&lista1, 10);
  adcInicio(&lista1, 9);
  adcInicio(&lista1, 9);

  adcInicio(&lista2,25);
  adcInicio(&lista2,7);

  imprimir(lista1);
  imprimir(lista2);  

  return 0;
}

*/

