# Estrutura-de-dados

<div align="center">
  <h1>Estrutura de Dados em <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg"  alt="c" height=30/></h1>
  
  #### Repositório de estudos de Estruturas de Dados na linguagem C.
  
</div>

---
<h2 id="conteudos">Conteúdos</h2>

** Listas:**
- [Lista Sequencial](./estrutura_de_dados/ListaSequencial)
- [Lista Simplesmente Encadeada](./estrutura_de_dados/ListaSimpEncad)
- [Lista Duplamente Encadeada](./Estrutura-de-dados/listaDEncadeada)
- [Lista Encadeada Circular](./estrutura_de_dados/ListaCircular)
<hr>
Questao 1: Considere uma aplicação gráfica que define dois tipos estruturados identificados pelos nomes Ponto e Circulo. O
tipo estruturado Ponto representa o objeto ponto em duas dimensões, que é composto por duas coordenadas tipo float. O tipo
estruturado Circulo representa o objeto círculo composto por um nome (que nunca contém mais do que 10 caracteres, p.ex.
Circulo015), por um ponto que define o seu centro e por um raio com a precisão de um float. Escreva um programa completo (com includes, structs, funções e a main), em um único arquivo .c, que implementa e testa as
seguintes funções:
● criaCirculo() – que cria um novo círculo. Esta função recebe um nome, as coordenadas x e y do centro e o raio para
este novo círculo, e retorna um ponteiro para Circulo.
● contem() – que testa se um determinado círculo contém outro círculo dado. Esta função recebe dois ponteiros para o
tipo estruturado Circulo e retorna 0 se o primeiro círculo não contém o segundo círculo e diferente de zero se contém.


Questao 2: Crie uma função que receba como parâmetros dois vetores de inteiros, v1 e v2, e as suas respectivas quantidades
de elementos, n1 e n2. A função deverá retornar um ponteiro para um terceiro vetor, v3, com capacidade para (n1 + n2)
elementos, alocado dinamicamente, contendo a união de v1 e v2. Por exemplo, se v1 = {11, 13, 45, 7} e v2 = {24, 4, 16, 81,
10, 12}, v3 irá conter {11, 13, 45, 7, 24, 4, 16, 81, 10, 12}.
O cabeçalho dessa função deverá ser o seguinte:

                            int* uniao(int *v1, int n1, int *v2, int n2);
                            
Em seguida, crie a função principal do programa para chamar a função uniao passando dois vetores informados pelo usuário
(ou declarados estaticamente). Em seguida, o programa deve exibir na tela os elementos do vetor resultante. Não esqueça de
liberar a memória alocada dinamicamente
