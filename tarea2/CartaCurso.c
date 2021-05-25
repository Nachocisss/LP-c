#include "includes/CartaCurso.h"
#include "includes/lista.h"
#include <time.h>

/******** Funcion: crearcartacurso ********************
Descripcion: crear la carta correspondiente al numero aleatorio entregado
Parametros:
int test
card *gg
Retorno: no tiene retorno
************************************************/

void crearcartacurso(int test, card *gg){
	
	if (test == 0){
       	gg->nombre ="matematica";
       	gg->descripcion ="Ataca 550/Cura 200 puntos de prioridad.";
       	gg->ataque=550;
       	gg->defensa=200;
        gg->reprobar = &reprobar;
        gg->aprobar = &aprobar;
    }

    if (test == 1){
       	gg->nombre="fisica";
       	gg->descripcion ="Ataca 450/Cura 150 puntos de prioridad.";
       	gg->ataque=450;
       	gg->defensa=150;
        gg->reprobar = &reprobar;
        gg->aprobar = &aprobar;
    }

    if (test == 2){
       	gg->nombre="LP";
       	gg->descripcion ="Ataca 510/Cura 180 puntos de prioridad.";
       	gg->ataque=510;
       	gg->defensa=180;
        gg->reprobar = &reprobar;
        gg->aprobar = &aprobar;
    }
    if (test == 3){
       	gg->nombre="programacion";
       	gg->descripcion ="Ataca 110/Cura 300 puntos de prioridad.";
       	gg->ataque=110;
       	gg->defensa=300;
        gg->reprobar = &reprobar;
        gg->aprobar = &aprobar;
    }
    if (test == 4){
       	gg->nombre="ED";
       	gg->descripcion ="Ataca 470/Cura 160 puntos de prioridad.";
       	gg->ataque=470;
       	gg->defensa=160;
        gg->reprobar = &reprobar;
        gg->aprobar = &aprobar;
    }
    if (test == 5){
       	gg->nombre="EDD";
       	gg->descripcion ="Ataca 430/Cura 120 puntos de prioridad.";
       	gg->ataque=430;
       	gg->defensa=120;
        gg->reprobar = &reprobar;
        gg->aprobar = &aprobar;
    }
   
}

/******** Funcion: inicializarMazo ********************
Descripcion: inicializa lista enlazada que representa el mazo de los jugadores, con 
ayuda de funcion crearcartacurso crea mazo aleatorio
Parametros:
void* mazo
Retorno: puntero hacia lista que representa mazo
************************************************/

void * inicializarMazo(void* mazo){
	tlist* mm;
	mm = mazo;
	int mat = 1,fis=4,lp=2,pro=6,ed=3,edd=4;
    int contador=0;
     while(contador < 20){
    	int t = rand() % 6;
    	if (t==0 && mat !=0){
    		tnodo* no = (tnodo*)malloc(sizeof(tnodo));
    		card *m = (card*)malloc(sizeof(card));
    		crearcartacurso(t,m);
    		(no->tcarta) = m; 
    		append(mm, no);
    		contador++;
    		mat--;
    	}
    	if (t==1 && fis !=0){
    		tnodo* no = (tnodo*)malloc(sizeof(tnodo));
    		card *f = (card*)malloc(sizeof(card));
    		crearcartacurso(t,f);
    		(no->tcarta) = f;
    		
    		append(mm, no);
    		contador++;
    		fis--;
    	}
    	if (t==2 && lp !=0){
    		tnodo* no = (tnodo*)malloc(sizeof(tnodo));
    		card *l = (card*)malloc(sizeof(card));
    		crearcartacurso(t,l);
    		(no->tcarta) = l; 
    	
    		append(mm, no);
    		contador++;
    		lp--;
    	}
    	if (t==3 && pro !=0){
    		tnodo* no = (tnodo*)malloc(sizeof(tnodo));
    		card *p = (card*)malloc(sizeof(card));
    		crearcartacurso(t,p);
    		(no->tcarta) = p;
    		
    		append(mm, no);
    		contador++;
    		pro--;
    	}
    	if (t==4 && ed !=0){
    		tnodo* no = (tnodo*)malloc(sizeof(tnodo));
    		card *e = (card*)malloc(sizeof(card));
    		crearcartacurso(t,e);
    		(no->tcarta) = e; 
    		
    		append(mm, no);
    		contador++;
    		ed--;
    	}
    	if (t==5 && edd !=0){
    		tnodo* no = (tnodo*)malloc(sizeof(tnodo));
    		card *d = (card*)malloc(sizeof(card));
    		crearcartacurso(t,d);
    		(no->tcarta) = d; 
    
    		append(mm, no);
    		contador++;
    		edd--;
    	}
    }
	return mm;
         
}    
/******** Funcion: reprobar ********************
Descripcion: resta a la prioridad del oponente el ataque de la carta disponible para jugar
Parametros:
void *carta
void *ju
Retorno: no tiene retorno
************************************************/

void reprobar(void *carta, void *ju){
    card *c = carta;
    jugador *j = ju;
    int aux;
    aux = j->prioridad - c->ataque;
    if (aux < 0){
        j->prioridad = 0;
        return;
    }
    j->prioridad = aux;
    return;

}

/******** Funcion: reprobar ********************
Descripcion: suma a la prioridad propia los puntos de defensa de la carta disponible para jugar
Parametros:
void *carta
void *ju
Retorno: no tiene retorno
************************************************/

void aprobar(void *carta, void *ju){
    card *c = carta;
    jugador *j = ju;
    int aux;
    aux = j->prioridad + c->defensa;
    if (aux > 3000){
        j->prioridad = 3000;
        return;
    }
    j->prioridad = aux;
    return;
    
}