
#include <stdio.h>    
#include <stdlib.h>   
#include <memory.h>		
#include <string.h>	



int verTamAquivo(char *nome) {
	FILE *ptrFile;
	int cont = 0;
	
	ptrFile = fopen(nome,"r");
    if(!ptrFile){
		printf("\n Nao foi possivel abrir a File %s  !\n", nome);
		exit(1);
	}
	while(!feof(ptrFile)){ 
		cont++;
		fgetc(ptrFile);
	}
	fclose(ptrFile);
	printf("%d\n",cont);
	return(cont);
}

void regVetores(int n, int *vTam, char** vNom, char *nome) {
	int tam,i;
	
	tam = verTamAquivo(nome);
	
	if (n==0){
		i=0;
	}
	else{
		i=n-1;
	}
	

	while (i>=0){
		if (vTam[i] > tam){
			vTam[i+1] = vTam[i];
			strcpy(vNom[i+1],vNom[i]);
			if(i==0){
			vTam[i]= tam;
			strcpy(vNom[i],nome);	
			}
			i--;
		}
		else{
			if (n==0){
				vTam[i]= tam;
				strcpy(vNom[i],nome);
			}
			else{
			strcpy(vNom[i+1], nome); 
			vTam[i+1] = tam;
		    }	
		    break;
		}
	}

}

void mostraVetores(int nArq,int *vTamArq,char **vNomArq){
    int i;
    for(i=0;i<nArq;i++){
        printf("%d|| Arquivo: %s\nTamanho: %d caracteres\n\n", i+1,vNomArq[i], vTamArq[i]);
    }
}

void main(void) {
	int nArq = 5, i, *vTamArq;
	char nome[30], **vNomArq;
	char *vNomNomes[13] = {"arqText01.txt", 
	                       "arqText02.txt", 
	                       "arqText03.txt", 
	                       "arqText04.txt", 
	                       "arqText05.txt"};
	
	vNomArq = (char**) malloc(nArq*sizeof(char*));  

	for(i=0; i<nArq; i++){
		vNomArq[i] = (char*) malloc(16*sizeof(char));  
	}

	
		
	vTamArq = (int*) malloc(nArq*sizeof(int));
	
	for(i=0;i<nArq; i++){
		vTamArq[i]= 0;
	}
	
	for (i=0; i<nArq; i++){
		strcpy(nome, "arquivos/");   
		strcat(nome, vNomNomes[i]);
		regVetores(i, vTamArq, vNomArq, nome);  
	}
	
	mostraVetores(nArq, vTamArq, vNomArq);
	
	free(vTamArq);
	for(i=0; i<nArq; i++){
		free(vNomArq[i]);
	}
	free(vNomArq);	 
}


