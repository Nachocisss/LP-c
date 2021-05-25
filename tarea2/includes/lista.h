#ifndef _LISTA_H_
#define _LISTA_H_



typedef struct nodo{
	void *tcarta;
	struct nodo *siguiente;
}tnodo;

typedef struct list{
	tnodo *head;
	tnodo *tail;
	tnodo *curr;
	unsigned int listSize;
	unsigned int pos;
}tlist;


tlist* inicializar();
void append(tlist *,tnodo *);
int getvalueExpon(tlist *);
int getvalueCoef(tlist *);
void clear(tlist *);
void moveToStart(tlist *);
void next(tlist *);
int length(tlist *);


#endif // _LISTA_H_