#ifndef _CARTACURSO_H_
#define _CARTACURSO_H_

typedef struct CartaCurso{
    char * nombre, * descripcion;
    int ataque, defensa;
    void (*reprobar)(void *, void *); //Los parametros son la carta y el enemigo
    void (*aprobar)(void *, void *); //Los parametros son la carta y el jugador
}card;

void crearcartacurso( int, card*);
void *inicializarMazo(void *);

void reprobar(void *, void *);

void aprobar(void *, void *);





#endif