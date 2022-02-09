#include <stdio.h>
#include <stdlib.h>

// -- meu header ------
typedef 
  struct Elem {
	int inf;
	struct Elem *prox;
  } 
stElem;

typedef struct List 
{
	int  n;
	stElem *noFirst;
} stList;
// ------------------

void liberaLista(stList *Lst){
	stElem *no= (stElem*)malloc(sizeof(stElem)) ;
	while(Lst->noFirst!=NULL) {
		 no = Lst->noFirst;
	     free(Lst->noFirst);
	     Lst->noFirst = no->prox;	 	
	}	
}

void mostraLista(stList *Lst){
	stElem *no;
	printf("\n Lista \n");

	no = Lst->noFirst;
	while (no != NULL) {
		printf("\n %d ", no->inf);
		no = no->prox;
	}
	printf("\n");
}
	
void buscaNaLista(stList *Lst){
	stElem *no;
	int n, count=0;
	
	printf("\n Escreva o elemento que deseja buscar na lista: \n");
	scanf("%d", &n);
	
	no = Lst->noFirst;
	while (no != NULL && count==0) {
		if (no->inf==n){
			count++;
		}
		no = no->prox;
	}
	if(count>0){
		printf("\n O elemento %d existe na lista", n);
	}else{
		printf("\n Não foi encontrado nenhum elemento %d na lista", n);
	}
}

void buscaQtdLista(stList *Lst){
	stElem *no;
	int n,count=0;
	
	printf("\n Escreva o elemento que deseja buscar na lista: \n");
	scanf("%d", &n);
	
	no = Lst->noFirst;
	while (no != NULL) {
		if (no->inf==n){
			count++;
		}
		no = no->prox;
	}
	if(count>0){
		printf("\n Foram encontrados %d elementos %d na lista\n",count, n);
	}else{
		printf("\n Não foi encontrado nenhum elemento %d na lista\n", n);
	}
}

void insereNaPosicao(stList *Lst) {
	int pos, m, count;
	stElem *no = (stElem*)malloc(sizeof(stElem)) ;
	stElem *noAtual = (stElem*)malloc(sizeof(stElem)) ;
	stElem *noAnt = (stElem*)malloc(sizeof(stElem)) ;
	noAnt= NULL;
	noAtual= Lst->noFirst;
	
	
	printf("\n Escreva o elemento que deseja inserir na lista: \n");
	scanf("%d", &m);
	
	printf("\n Digite a posicao de insercao do elemento: \n");
	scanf("%d", &pos);
	
	no->inf = m;
	
	for (count=0; noAtual != NULL; count++){
		if(count == pos-1){
			if(noAnt == NULL){
				no->prox = Lst->noFirst;
				Lst->noFirst = no;
			} else {
				no->prox= noAtual;
				noAnt->prox = no;
			}
		Lst->n += 1;
		break;
		}else {
			noAnt = noAtual;
			noAtual = noAtual->prox;
		}		
	}
	
	
}
	
/*void insereNaLista(int m, stList *Lst) {
	int n;
	if (m==0){
		printf("\n Escreva o elemento que deseja inserir na lista: \n");
		scanf("%d", &n);
	}
	
	stElem *no = (stElem*)malloc(sizeof(stElem)) ;
	if (m==0){
	no->inf = n;
	}else{
	no->inf = m;
	}
	no->prox = Lst->noFirst;
	Lst->noFirst = no;
	Lst->n += 1;
}
*/

void insereNaLista(int n, stList *Lst) {
	
	stElem *no = (stElem*)malloc(sizeof(stElem)) ;
	no->inf = n;
	no->prox = Lst->noFirst;
	Lst->noFirst = no;
	Lst->n += 1;
}



void geraLista(stList *Lst) {
	int m;
	Lst->n = 0;
	Lst->noFirst = NULL;
	
	printf("\n Escreva um digito diferente de 0 (digite 0 para parar): \n");
	scanf("%d", &m);

	while(m!=0) {
		insereNaLista(m, Lst);
		printf("\n Escreva um digito diferente de 0: \n");
		scanf("%d", &m);
		Lst->n++;		
	}
}

void EliminaUmElemento(stList *Lst) {
	int m;
	stElem *no = Lst->noFirst;
	stElem *noAnt = NULL;
	
	printf("\n\n Digite um elemento para eliminar\n");
	scanf("%d", &m);
	while(no != NULL){
		if(no->inf == m) {
			if(noAnt == NULL){
				Lst->noFirst = no->prox;
			} else {
				noAnt->prox = no->prox;	
			}
			free(no);
			Lst->n -= 1;
			break;
		}
		else {
			noAnt = no;
			no = no->prox;
		}		
	}
}

int main() {
	int e, n=0;
	stList meuLst; 
	
	for(;;){
	if (n==0){
		printf("\n Gerar uma nova lista (1) \n Eliminar um elemento da lista (2)\n Buscar existencia de um elemento na lista (3)\n Buscar existencia e quantidade de um elemento na lista (4)\n Inserir novo elemento na lista (5)\n Inserir novo elemento na lista na posicao especificada (6)\n Mostrar a lista(7)\n Liberar a lista(8)\n Encerrar(9)\n");	
	}
	printf("\n Escolha: ");
	scanf("%d", &e);
	
	switch (e){
		case 1:
			geraLista(&meuLst);
			mostraLista(&meuLst);
		break;
		
		case 2:
			EliminaUmElemento(&meuLst);
			mostraLista(&meuLst);
		break;
		
		case 3:
			buscaNaLista(&meuLst);
		break;
		
		case 4:
			buscaQtdLista(&meuLst);
		break;
		
		case 5:
			printf("\n Escreva o elemento que deseja inserir na lista: \n");
			scanf("%d", &n);
			insereNaLista(n, &meuLst);
			mostraLista(&meuLst);
		break;
		
		case 6:
			insereNaPosicao(&meuLst);
			mostraLista(&meuLst);
		break;
		
		case 7:
			mostraLista(&meuLst);
		break;
		
		case 8:
			liberaLista(&meuLst);
			printf("\n Lista Esvaziada\n");
		break;
		
		default:
			printf("\n Finalizando Programa...\n");
		exit(0);	 
	} 
	
	n++;
	}
}


