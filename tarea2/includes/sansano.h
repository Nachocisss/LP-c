#ifndef _SANSANO_H_
#define _SANSANO_H_

typedef struct Sansano{
    char * nombre;
    int prioridad;
    void * mazo;
}jugador;

jugador inicializarju(char *, void *);
void mostrarvida(jugador , jugador);

#endif