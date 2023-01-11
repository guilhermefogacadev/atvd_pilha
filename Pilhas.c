
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int TipoElemento;

typedef struct no {
  TipoElemento dado;
  struct no *prox;
} No;

typedef struct pilha {
  No *topo;
  int qtde;
} Pilha;

Pilha *criaPilha() {
  Pilha *pi = (Pilha *)malloc(sizeof(Pilha));
  pi->qtde = 0;
  pi->topo = NULL;
  return pi;
}
Pilha *empilha(Pilha *pi, int valor) {
  No *novoElemento = (No *)malloc(sizeof(No));
  novoElemento->dado = valor;
  novoElemento->prox = NULL;
  int i;
  if (pi->topo == NULL) {
    pi->topo = novoElemento;
    pi->qtde++;
  } else {
    No *aux = pi->topo;
    for (i = 0; i < pi->qtde; i++) {
      if (aux->prox == NULL) {
        aux->prox = novoElemento;
        pi->qtde++;
      } else {
        aux = aux->prox;
      }
    }
  }
  return pi;
}

int* desempilha(Pilha *pi, int* valor) {
  if (pi->topo != NULL) {
    No *topo = pi->topo;
    valor=&pi->topo->dado;
    pi->topo=pi->topo->prox;
    free(topo);
   // pi->topo=ant;
    return valor;    
    //valor=&topo->dado;
  }
  return valor;  
}

void printa(Pilha *pi) {
  int i;
  No *aux = pi->topo;
  if (aux == NULL) {
    printf("Ta vazia");
  } else {
    for (i = 0; i < pi->qtde; i++) {
      printf("[%d]", aux->dado);
      aux = aux->prox;
    }
  }
}

int tamanho(Pilha *pi) { return pi->qtde; }
int topo(Pilha *pi) {
  if (pi->topo != NULL) {
    return pi->topo->dado;
  } else {
    printf("Topo esta NULO");
  }
}

int main(void) {
  Pilha *pi = criaPilha();
  empilha(pi, 10);
  empilha(pi, 20);
  int * valor;
  desempilha(pi,&valor);
  //printa(pi);
}
