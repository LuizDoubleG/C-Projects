#include <stdio.h>
#include <stdlib.h>


//dava pra informar ainda quantidade de quebra de linhas e numero de caracteres diferentes no texto == n
typedef struct charCont{
	int freq;
	char c;
	struct charCont* arqProxChar;
}stCharCont;

typedef struct charList{
	int n;
	stCharCont* arqFirstChar;
}stCharList;

int verificaFreq(FILE* arq, char c) {
	int count = 0;
	while(!feof(arq)){ 
		if (c == fgetc(arq)){
			count++;
		}
	}
	return(count);
}

void insereNaLista(char c, stCharList *Lst) {
	FILE* arq;
	stCharCont *cha = (stCharCont*)malloc(sizeof(stCharCont)) ;
	arq = fopen ("texto.txt", "r");
	
	cha->c = c;
	cha->freq = verificaFreq(arq,c); //verifica a frequencia
	cha->arqProxChar = Lst->arqFirstChar;
	Lst->arqFirstChar = cha;
	Lst->n += 1;
	fclose(arq);
}

int verificaRep(char c, stCharList *Lst){
	int count=0;
	stCharCont *cha;
	cha = Lst->arqFirstChar;
	while (count != 1 && cha != NULL) { //caso já tenha um igual na lista o contador indica à geraLista que nao precisa registrar dnv
		if (cha->c==c){
		   count++;
		}
		cha = cha->arqProxChar;
	}
	return (count);
}


void geraLista(stCharList *Lst) {
	FILE* arq;
	char c;
	arq = fopen ("texto.txt", "r");
	
	if (!arq){
		printf("\n Nao foi possivel abrir a File!\n");
		exit(1);
	}
	
	Lst->n = 0;
	Lst->arqFirstChar = NULL;

	while(!feof(arq)){ 
		c = fgetc(arq);
		
		if (c==-1 || c==10){ //eliminar quebra de linha /n e caractere /0
			continue;
		}
		if (verificaRep(c,Lst)>=1){ //caso haja repetição (count==1) nao isere na lista novamente
			continue;
		}
		insereNaLista(c,Lst);//pode usar com else tambem	
		
	}
	fclose(arq);
}

void mostraLista(stCharList *Lst){
	stCharCont *cha;
	
	cha = Lst->arqFirstChar;
	
	printf("\n Lista \n");
	
	while (cha != NULL) {
		printf("\n Caractere: %c Numero: %d Frequencia: %d \n", cha->c, cha->c, cha->freq);
		cha = cha->arqProxChar;
	}
}

int main() {
	stCharList charList;
	geraLista (&charList);
	mostraLista (&charList);
}
