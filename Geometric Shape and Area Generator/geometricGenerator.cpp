#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

typedef struct ptoXY{
	int x;
	int y;
	float ang;
} stPtoXY;


typedef struct vetPto{
	int n;
	stPtoXY *xyAng;
}stVetPto;



int organiza (stPtoXY* xyAng, int a, int b){
    
int esq = a, dir = b, aux = 0;
float pivo= xyAng[a].ang;

    while (esq < dir) { 
        
        while (pivo >=  xyAng[esq].ang){
        esq++;
        } 
        
        while (pivo < xyAng[dir].ang){
        dir--; 
        }
        
        if(esq < dir) { 
            aux = xyAng[esq].x; 
    		xyAng[esq].x = xyAng[dir].x;
    		xyAng[dir].x = aux; 
    
			aux = xyAng[esq].y; 
    		xyAng[esq].y = xyAng[dir].y;
    		xyAng[dir].y = aux; 
    
			aux = xyAng[esq].ang; 
    		xyAng[esq].ang = xyAng[dir].ang;
    		xyAng[dir].ang = aux; 
        }
    }
    
	aux = xyAng[a].x; 
    xyAng[a].x = xyAng[dir].x;
    xyAng[dir].x = aux; 
    
	aux = xyAng[a].y; 
    xyAng[a].y = xyAng[dir].y;
    xyAng[dir].y = aux; 
    
	aux = xyAng[a].ang; 
    xyAng[a].ang = xyAng[dir].ang;
    xyAng[dir].ang = aux; 	


return dir;
}


void quickSortm (stPtoXY *xyAng, int a, int b) {
int pivo;
    if(b > a) {
        pivo = organiza(xyAng, a, b); 
        quickSortm (xyAng, a, pivo-1); 
        quickSortm (xyAng, pivo+1, b);
    }
}


void translacaoOrigem(int n, stPtoXY *xyAng, stPtoXY* Cxy){
	int i;
	for(i=0; i<n; i++){
		xyAng[i].x -= Cxy->x;
		xyAng[i].y -= Cxy->y;
	}
}


void retranslacaoOrigem(int n, stPtoXY *xyAng, stPtoXY* Cxy){
	int i;
	for(i=0; i<n; i++){
		xyAng[i].x += Cxy->x;
		xyAng[i].y += Cxy->y;
	}
}


void Angularpontos (int n, stPtoXY* xyAng){
    int i;
    float Hipo, aux;
    
    for (i=0; i<n; i++){
        if (xyAng[i].x == 0 && xyAng[i].y ==0){
            xyAng[i].ang=0;
            continue;
        }
        Hipo=sqrt(pow(xyAng[i].x,2) + pow(xyAng[i].y,2)); 
        aux = xyAng[i].x/Hipo;
        aux = acos(aux);
        xyAng[i].ang= floor((aux*180)/M_PI);
        
    }
}


void Ajustarangulos (int n, stPtoXY* xyAng){
    int i;
        for (i=0; i<n; i++){
            if (xyAng[i].x >= 0){ 
            
                if (xyAng[i].y <0){
                xyAng[i].ang = 360 - xyAng[i].ang;
                }
            }
            else{
                if (xyAng[i].y<0){
               xyAng[i].ang = 360 - xyAng[i].ang;
                }
            }
        }
}    


void calculaCentro(int n, stPtoXY *v, stPtoXY *ctro){
	int sx = 0;
	int sy = 0;
	int i;
	for(i=0; i<n; i++) {
		sx += v[i].x;
		sy += v[i].y;
	}
	ctro->x = sx/n;
	ctro->y = sy/n;
}


void geraElemVetor(stVetPto *v){
	int i;
	for(i=0; i<v->n; i++){
		v->xyAng[i].x= rand()%101; 
		v->xyAng[i].y= rand()%101;
		v->xyAng[i].ang = 0.0f;
	}
}


stPtoXY *alocaVetor(int n){
	stPtoXY *v;
	v = (stPtoXY*) malloc(n*sizeof(stPtoXY));
	return(v);
}


void mostrarVetor(stVetPto *v){
	int i;
	for(i=0; i<v->n; i++)
		printf(" (%d, %d, %6.2f), ", v->xyAng[i].x, v->xyAng[i].y, v->xyAng[i].ang);
		
	printf("\n");
}


void CalcArea (int n , stPtoXY* xyAng){
	
	int i;
	float area=0;
	
	for (i=0; i<n-1; i++){
		area += (((xyAng[i].x - xyAng[i+1].x)*(xyAng[i].y + xyAng[i+1].y))/2);
	}
		
	area += (((xyAng[n-1].x - xyAng[0].x)*(xyAng[n-1].y + xyAng[0].y))/2);
		
	printf ("\nArea dessa figura: %.2f metros quadrados\n", area);
	}	
	
void PlanoCartesiano (int n, stPtoXY* xyAng, stPtoXY* ctro){
	
	 int i = 0, j = 0, c = 0, b = 0, p = 0;
	 

	 for (i=0;i<n;i++){
	 	if (xyAng[i].x>25 || xyAng[i].y>25){
	 		c++;
		 }	
	 }
	 for (i=0;i<n;i++){
	 	if (c!=0){
			xyAng[i].x/=4;
	 		xyAng[i].y/=4;
	 	}
	 }
	 
     for (j=25; j>= -1; j--){
        for (i=-1; i <= 25; i++){
            for (c=0; c < n; c++){
                if ((xyAng[c].x == i) && (xyAng[c].y == j)){
                    for (b= c-1; b>=0; b--){
                            if ((xyAng[b].x == xyAng[c].x) && (xyAng[b].y == xyAng[c].y)){
                                b= n+1; 
                                break;
                            }
                    }
                    if (b != n+1){
                        printf ("|X|");
                        b=0;
                    }       
                    p++;
                }
            }
        if (p==0){
            if (i == 0 | j == 0){
                printf ("|=|");
                }
            else {
                printf("   ");
            }
        }
        p = 0;
        }
        printf("\n");
     }
}
    

int main() {

	stVetPto vetPts;  
	stPtoXY Cxy;		
	int m, e, i;
	
	for(;;){
	printf("\n Escolha :\n Digitar os pontos (1)\n Gerar automaticamente (2)\n Encerrar(3)\n ");
	scanf("%d", &e);
	if (e==3){
		break;
	}
	printf("\n Digite a quantidade de pontos: ");
	scanf("%d", &m);
	
	vetPts.n = m;
	vetPts.xyAng = alocaVetor(m);
	
	switch (e){
		case 1:
			printf ("\n Digite os pontos (x,y):\n");
			for(i=0;i<m;i++){
				scanf("%d,%d",&vetPts.xyAng[i].x,&vetPts.xyAng[i].y);
			}
		break;
		
		default:
			srand(time(NULL));
			geraElemVetor(&vetPts);	 
	}
	
	Angularpontos(vetPts.n, vetPts.xyAng);
	
	printf("\n Vetores Gerados:\n");
	
	mostrarVetor(&vetPts);

	calculaCentro(vetPts.n, vetPts.xyAng, &Cxy);

	printf("\n Centro Calculado: (%d, %d) \n", Cxy.x, Cxy.y);
		
	translacaoOrigem(vetPts.n, vetPts.xyAng, &Cxy);
	
	Angularpontos(vetPts.n, vetPts.xyAng);
	
	Ajustarangulos(vetPts.n, vetPts.xyAng);
	
	quickSortm (vetPts.xyAng, i, m-1);
	
	printf("\n Vetores Transladados e Angulos:\n");
	
	mostrarVetor(&vetPts); 
	
	retranslacaoOrigem(vetPts.n, vetPts.xyAng, &Cxy);
	
	Angularpontos(vetPts.n, vetPts.xyAng);
	
	printf("\n Vetores em Ordem:\n");
	
	mostrarVetor(&vetPts); 
	
	CalcArea (vetPts.n, vetPts.xyAng);
	
	PlanoCartesiano (vetPts.n, vetPts.xyAng, &Cxy);
	
	free (vetPts.xyAng); 
	}
	printf("\n Finalizando o programa...\n");
}

