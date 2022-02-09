#include <stdio.h>
#include <stdlib.h>

// -- meu header ------
typedef struct Elem {
	int inf;
	struct Elem *prox;
} stElem;

typedef struct List 
{
	int  n;
	stElem *noFirst;
} stList;
// ------------------

void mostraLista(stList *Lst){
	stElem *no;
	printf("\n --- Lista  \n");

	no = Lst->noFirst;
	while (no != NULL) {
		printf("\n %d ", no->inf);
		no = no->prox;
	}
}
	
void insereNaLista(int m, stList *Lst) {
	stElem *no = (stElem*)malloc(sizeof(stElem)) ;
	no->inf = m;
	no->prox = Lst->noFirst;
	Lst->noFirst = no;
	Lst->n += 1;
}

void geraLista(stList *Lst) {
	int m;
	printf("Digite digite um diferente de 0 ");
	scanf("%d", &m);
	Lst->n = 0;
	Lst->noFirst = NULL;
	while(m!=0) {
		insereNaLista(m, Lst);
		printf("Digite digite um diferente de 0 ");
		scanf("%d", &m);		
	}
}

void main(void) {
	// definir os dados
	stList meuLst;
	geraLista(&meuLst);
	mostraLista(&meuLst);
	liberaLista(); // free
}
