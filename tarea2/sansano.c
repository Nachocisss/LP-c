#include "includes/sansano.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/CartaCurso.h"
#include "includes/lista.h"


/******** Funcion: inicializarju ********************
Descripcion: inicializa struct con los datos de cada jugador 
Parametros:
char* name
void *m
Retorno: struct "jugador" con datos de cada jugador
************************************************/

jugador inicializarju(char* name, void *m){
    jugador yo;
    yo.nombre=name;
    yo.prioridad=3000;
    yo.mazo = m;
    return yo;
}

/******** Funcion: mostrarvida ********************
Descripcion: imprime en pantalla la prioridad de cada jugador luego de cada turno
Parametros:
jugador jug
jugador riv
Retorno: no tiene retorno
************************************************/

void mostrarvida(jugador jug, jugador riv){
	printf(" ----------------------------------------------\n");
    printf("   tu prioridad %s es: %d\n   la prioridad de %s es: %d\n" ,jug.nombre, jug.prioridad, riv.nombre, riv.prioridad);
    printf(" ----------------------------------------------\n\n");
}


