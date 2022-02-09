#include <stdio.h>
#include <stdlib.h>

typedef struct charCont{
	int freq;
	char c;
	struct charCont* arqProxChar;
}stCharCont;

int main(){
	stCharCont *aa = (stCharCont*)malloc(sizeof(stCharCont)) ;
	scanf("%c", &aa->c);
	printf("%c", aa->c);
return 0;}

