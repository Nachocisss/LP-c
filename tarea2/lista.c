#include "includes/sansano.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/CartaCurso.h"
#include "includes/lista.h"

/******** Funcion: inicializar ********************
Descripcion: inicializa struct correspondiente a lista enlazada para mazo 
Parametros:
Retorno: struct tlist que es una lista enlazada para mazo 
************************************************/


tlist* inicializar(){
	tlist *lista = (tlist*)malloc(sizeof(tlist));
	lista->head = NULL;
	lista->tail = NULL;
	lista->curr = NULL;
	lista->listSize = 0;;
	lista->pos = 0;
	return lista;
}

/******** Funcion: append ********************
Descripcion: agrega al mazo un nodo con una carta y puntero a carta siguiente
Parametros:
tlist *lista
tnodo* n
Retorno:no tiene retorno 
************************************************/


void append(tlist *lista,tnodo* n){
	if(lista->head == NULL){
		lista->head = lista->tail = lista->curr = n;
        
	}
	n->siguiente = NULL;
	lista->tail->siguiente = n;
	lista->tail = n;
	lista->listSize++;

}

/******** Funcion:clear ********************
Descripcion: libera memoria de lsita mazo
Parametros:
tlist *l
Retorno: no tiene retorno
************************************************/

void clear(tlist *l){
	while (l->listSize > 0){
		tnodo *borrador;
		borrador = l->head;
		l->head = l->head->siguiente;
		if (l->listSize == 1)
			l->tail = NULL;
		free((void *)borrador);
		l->listSize--;
	}
	free((void*)l);
}

/******** Funcion: moveToStart ********************
Descripcion: mueve la posicion actual de la lista al comienzo de esta
Parametros:
tlist *l
Retorno: no tiene retorno
************************************************/

void moveToStart(tlist *l){
	(l->curr) = (l->head);
	(l->pos) = 0;
}

/******** Funcion: next ********************
Descripcion: mueve la posicion actual de la lista a la siguiente posicion
Parametros:
tlist *l
Retorno: no tiene retorno
************************************************/


void next(tlist *l){
	l->curr = l->curr->siguiente;
}
/******** Funcion: length ********************
Descripcion: entrega la cantidad de elementos en la lista
Parametros:
tlist *l
Retorno: int que representa largo de lista
************************************************/
int length(tlist *l){
	return l->listSize;
}