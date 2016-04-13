#include "librerias.h"
typedef struct tCell{
	int payload;
	struct tCell *next;
} Cell;

Cell agrega(Cell *base, int entrada){
	Cell *reg;
	reg=(Cell*)malloc(sizeof(Cell));
	reg->payload=entrada;
	Cell *cursor = base;
	while(cursor->next !=NULL){
		cursor=(Cell*)cursor->next;
	}
	cursor->next=reg;
	return *base;
}

void imprime(Cell *raiz){
	printf("%d",raiz->payload);
	while((raiz=(Cell*)raiz->next) !=NULL){
		printf("%d ->",raiz->payload);
	}
}

Cell pop(Cell *ruta){
	Cell *cursor=ruta;
	while(cursor->next !=NULL){
		cursor=(Cell*)cursor->next;
	}
	free(cursor);
	cursor->next=NULL;
	return *ruta;
}

Cell erase(Cell *celda){
	while(celda->next!=NULL)
		pop(celda);
	return *celda;
}

Cell opciones(Cell *base){
	int opcion=0;
	bool ev=false;
	int num;
	//Cell *root = base;
	while(ev==false){
		printf("Dame una opción: \n0 - Agrega nodo\n1 - Borra último nodo\n2 - Imprime lista\n3 - Salir\n");
		scanf("%d", &opcion);
		if(opcion==0){
			printf("Dame un numero\n");
			scanf("%d", &num);	
			agrega(base, num);
			//printf("%d", ((Cell*)base->next)->payload);
			//imprime(root); 
		} else if(opcion==1){
			pop(base);
			printf("Último elemento borrado\n");
		} else if(opcion==2){
			printf("imprimiendo la lista\n");
			imprime(base);
		} else if(opcion==3){
			erase(base);
			ev=true;
		} else {
			printf("Error, ingresa una opción válida\n");
		}
	}
	return *base;
}

int main(int argc, char* argv[]) {
	Cell *root;
	root = (Cell*)malloc(sizeof(Cell));
	root->next=NULL;
	root->payload = -1;
	opciones(root);
	return 0;
}
