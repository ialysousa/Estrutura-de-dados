//
//  main.c
//  prova 3 ED
//
//  Created by Ialy Cordeiro de Sousa on 01/10/21.
//

#include "Pilha.h"
#include <stdio.h>

int main (void) {
    
    // Cria a variável pilha
  TPilhaEnc Pilha1;
  TPilhaEnc Pilha2;

  // Criar a pilha
  CriarPilha(&Pilha1);
  CriarPilha(&Pilha2);

  // Solicita o tamanho da pilha ao usuário
  int qntdElemPilha;

  printf("\n--- Informe a quantidade de elementos da pilha 1: --- ");
  scanf("%d",&qntdElemPilha);


  // Solicita os dados ao usuário
  int elemento_temp;
  for(int i = 0; i < qntdElemPilha;i++){

    printf("--- Informe o %d° elemento da pilha: --- ",i+1);
    scanf("%d",&elemento_temp);

    //Adicionando os elementos na pilha
    Empilhar(&Pilha1, elemento_temp);
  }

  //Imprimindo a primeira pilha
  printf("\n---- Exibindo a pilha 1: ----\n");
  Exibir(Pilha1);


  // Clonando a 1° pilha
  int dado;
  clonarPilha (&Pilha1, &Pilha2);

  //Exibindo a primeira pilha
  printf("\n---- Exibindo a pilha 2: ----\n");
  Exibir(Pilha2);

  // Verifica o topo da primeira pilha
  printf("\n");
    int topo_pilha;
    ElemTopo(Pilha1, &topo_pilha);
  printf("\n--- O elemento no topo da pilha é: --- %d\n", topo_pilha);

return 0;
}
