#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

int size = 0;
int plano = -1;
int escala;

void troca(int *V, int esq, int dir, int aux){
    aux = V[esq]; 
    V[esq] = V[dir];
    V[dir] = aux; 
}

int organiza(int *V, int *Vx, int *Vy, int a, int b){
    
int esq = a, dir = b, pivo = V[a], aux = 0;

    while (esq < dir) { 
        
        while (pivo >= V[esq]){
        esq++;
        } 
        
        while (pivo < V[dir]){
        dir--; 
        }
        
        if(esq < dir) { 
            troca(V, esq, dir, aux);
            troca(Vx, esq, dir, aux);
            troca(Vy, esq, dir, aux);
        }
    }
troca(V, a, dir, pivo);
troca(Vx, a, dir, pivo);
troca(Vy, a, dir, pivo);

return dir;
}

void quickSortm (int *V, int *Vx, int *Vy, int a, int b) {
int pivo;
    if(b > a) {
        pivo = organiza(V, Vx, Vy, a, b); 
        quickSortm (V, Vx, Vy, a, pivo-1); 
        quickSortm (V, Vx, Vy, pivo+1, b);
    }
}

void Valoresaleatorios (int *vetor){
    int i;
    for(i=0 ; i < size ; i++){
        vetor[i] =  rand()%(escala+1);
    }
}
    
void PlanoCartesiano (int *Vx, int *Vy, int Cx, int Cy){

if (plano != -1){
    if (escala>=20){
       escala /= 2;
       escala += 5;
       plano = -escala;
    }
    else{
        plano = -escala;
    }
}    


int i = 0, j = 0, c = 0, p = 0, b = 0;

     for (j=escala; j>= plano; j--){
        for (i=plano; i <= escala; i++){
            for (c=0; c < size; c++){
                if ((Vx[c] == i && Vy[c] == j) && (Vx[c] != 0 || Vy[c] != 0)){
                    for (b= c-1; b>=0; b--){
                            if ((Vx[b] == Vx[c]) && (Vy[b] == Vy[c])){
                                b= size+1; 
                                break;
                            }
                    }
                    if (b != size+1){
                        printf ("|X|");
                        b=0;
                    }       
                    p++;
                }
            }
        if (Cx == i && Cy == j){
            printf ("|O|");   
            p++;
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

void CentroGeometrico (int *Vx, int *Vy, int *Cx , int *Cy){
     int i;
     for(i=0 ; i < size ; i++){
        *Cx += Vx[i] ;
        *Cy += Vy[i];
     }
     *Cx /= size;
     *Cy /= size;
     
}

void TransladarVetores (int *Vx, int *Vy, int Cx, int Cy){
    int i;
    for(i=0 ; i < size ; i++){
        Vx[i] -= Cx;
        Vy[i] -= Cy;
    }
    plano = 1;
}

void ImprimirPontos (int *Vx, int *Vy){
    int i;
    for (i=0 ; i< size ; i++){
        printf("[%i,%i] ",Vx[i], Vy[i]);
    }
    printf ("\n\n");
}

void Angularpontos (int *angulo, int *Vx, int *Vy){
    int i;
    float Hipo, aux;
    
    for (i=0; i<size; i++){
        if (Vx[i]== 0 && Vy[i]==0){
            angulo[i]=0;
            continue;
        }
        Hipo=sqrt(pow(Vx[i],2) + pow(Vy[i],2)); 
        aux = Vx[i]/Hipo;
        aux = acos(aux);
        angulo[i] = floor((aux*180)/M_PI);
        
    }
}

void Ajustarangulos (int *angulo, int *Vx, int *Vy){
    int i;
        for (i=0; i<size; i++){
            if (Vx[i]>= 0){ 
            
                if (Vy[i]<0){
                angulo[i] = 360 - angulo[i];
                }
            }
            else{
                if (Vy[i]<0){
                angulo[i] = 360 - angulo[i];
                }
            }
        }
}    

void Imprimirangulos (int *angulo, int *Vx, int *Vy){
    int i;
    for (i=0; i<size; i++){
         printf ("%dº vetor -> [%d,%d]: %d\n", i+1, Vx[i], Vy[i], angulo[i]);
    }
    printf ("\n\n");
}

void main()
{
    int *Vx, *Vy, *angulo, Cx = 0, Cy = 0, i = 0;

    printf("Digite a escala do grafico (10x10 = 10): ");
    scanf("%i", &escala);
    
    printf("Digite a quantidade de pontos: ");
    scanf("%i", &size);
    
    Vx = malloc(size * sizeof(int));
    Vy = malloc(size * sizeof(int));
    angulo = malloc(size * sizeof(int));
    
    printf("\nintervalo dos números randômicos: [0,%i]\n", escala);
    
    srand((unsigned)time(NULL) );
     
    Valoresaleatorios(Vx);
    Valoresaleatorios(Vy);
    
    printf ("\nVetores: ");
    
    ImprimirPontos(Vx, Vy);
    PlanoCartesiano(Vx,Vy,Cx,Cy);
    Angularpontos (angulo, Vx, Vy);
    
    printf ("\nAngulos dos vetores:\n" );
   
    Imprimirangulos(angulo, Vx, Vy);
    CentroGeometrico (Vx, Vy, &Cx, &Cy);
    
    printf ("\n\nNovo Centro Geometrico: [%d,%d]\n\n", Cx, Cy);
    
    PlanoCartesiano(Vx,Vy,Cx,Cy);
    TransladarVetores (Vx, Vy, Cx, Cy);
    
    printf ("\nVetores Transladados:  \n");
    
    ImprimirPontos(Vx, Vy);
    Angularpontos (angulo, Vx, Vy);
    Ajustarangulos (angulo, Vx, Vy);
    PlanoCartesiano(Vx,Vy,Cx = 0,Cy = 0);
     
    printf ("\nNovos Angulos(ordenados):  \n");
    
    quickSortm(angulo, Vx, Vy, i, size-1);
    Imprimirangulos(angulo, Vx, Vy);
    
    free (Vx);
    free (Vy);
    free (angulo);
}