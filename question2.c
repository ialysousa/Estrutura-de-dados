/* Questão 2 - Estrutura de dados */

#include  <stdio.h>
#include <stdlib.h>

int * uniao( int * v1, int * v2, int n1, int n2, int * utam);


int main(void)
{ 
  int n1, n2;

  printf("Digite a quantidade de elementos n1:");
  scanf("%d", &n1);

  printf("Digite a quantidade de elementos n2:");
  scanf("%d", &n2);
  
  int v1[n1], v2[n2];
	for(int i=0; i<n1; i++){
		printf("Digite os valores para o vetor 1: ");
		scanf("%d", &v1[i]);
	}

	for(int i=0; i<n2; i++){
		printf("Digite os valores para o vetor 2: ");
		scanf("%d", &v2[i]);
	}              
  
  int utam= 0; 
  int * uv=  uniao( v1, v2, n1, n2, (& utam)); 
  
  /* imprimir */
  for (int u= 0; u < utam; ++u) printf(" %d", (* (uv + u)));
  
  /* liberar memória */
  free(uv);
  return 0;
}


int * search( const int * v, int tamanho, int elemento)
{ int * vet= ((void *)(v + tamanho)); 
  while (vet --> v && (* v) != elemento){/*  */};
  return vet; 
}


int * copy(int * dv, const int * ov, int dtamanho)
{ 
  for (int el= 0; el < dtamanho; ++el) dv [el]= ov [el]; 
  return dv; 
}


int * uniao(int * v1, int * v2, int n1, int n2, int * utam)
{ 
  int uv [n1 + n2];
  
  copy(uv, v1, n1);
  (* utam)= n1;
  
  for (int b= 0; b < n2; ++b)
    if (uv > search(uv, (* utam),v2 [b])) 
    {uv [(* utam)++]= v2 [b];}
    
 
  int * rv= malloc(sizeof (int [(* utam)]));
  if ((rv == NULL) || (utam == 0))
  {printf("Sem memória."); 
    
    return ((* utam)= 0, NULL);
  } /*  */
  copy(rv, uv, (* utam));
  return (rv); /* retorna o ponteiro */
}
