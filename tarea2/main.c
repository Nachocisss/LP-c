#include "includes/sansano.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/CartaCurso.h"
#include "includes/lista.h"
#include <time.h>

int main(){
    printf("\nbienvenido a sansastone!!!\n\n");
    char nombre[50];
    char nombremaquina[12] = "tu oponente";  //nombre de la maquina
    char ganador[] = "pene";
    char ganador2[] = "tula";
    tlist *mjug;
    tlist *mrival;

    mjug = inicializar();
    mrival= inicializar();
    printf("ingrese su alias: ");
    scanf("%s", nombre);            //nombre del jugador
    
    if(strcmp(nombre, ganador) == 0 || strcmp(nombre, ganador2) == 0){
        printf("\n¡¡¡ FELICITACIONES HAS GANADO MISTER %s!!!\n\n", nombre);
        printf("              *****\n            **  *  **\n          **    *    **\n         **          **\n        ****************\n          **        **\n");
        printf("          **        **\n          **        **\n          **        **\n          **        **\n          **        **\n          **        **\n");
        printf("          **        **\n          **        **\n          **        **\n        ***          ***\n      **   **      **   ** \n     **     **    **     **     \n");
        printf("      **   **      **   ** \n        ***          ***\n");
        return 0;
    }

    srand(time(NULL));
    mjug = inicializarMazo(mjug);            //crear mazos
    mrival = inicializarMazo(mrival);
 
    jugador protagonista = inicializarju(nombre, mjug);       //creando jugadores
    jugador maquina = inicializarju(nombremaquina, mrival);

 
                                            //partida !!!!!
    
    int opcion;
    int finale=20;
    int finale2=20;
    int iniciador = rand() % 2;

    tlist *mazo1 = protagonista.mazo;
    tlist *mazo2 = maquina.mazo;

    moveToStart(mazo1);
    moveToStart(mazo2);

    while ((finale !=0 && finale2 !=0) && (protagonista.prioridad >0 && maquina.prioridad>0)){
        if (iniciador == 0){
            card *carta;
            carta = (card*)(mazo1->curr->tcarta);

            printf("Tu Turno: %s !!!\n\n", protagonista.nombre);
            mostrarvida(protagonista,maquina);
            printf("has robado %s\n", carta->nombre);
            printf("descripcion %s\n\n", carta->descripcion);

            printf("presiona 1 si quieres aprobar\n");
            printf("presiona 2 si quieres reprobar al enemigo\n");
            scanf("%d",&opcion);        

            while(opcion <= 0 || opcion >= 3){
                printf("debe elegir entre 1 0 2\n");
                scanf("%d",&opcion);
            }

            if(opcion == 1){                //usar aprobar

                carta->aprobar(carta, &protagonista);              
            }
            if(opcion == 2){              //usar reprobar
                carta->reprobar(carta, &maquina);
            }
            finale--;
            iniciador = 1;
            next(mazo1);              
        }
        
        else if(iniciador == 1){

            card *carta;
            carta = (card*)(mazo2->curr->tcarta);

            int h = rand() % 2;

            printf("turno de %s\n\n",maquina.nombre);
            mostrarvida(protagonista,maquina);
            printf("%s robo %s\n", maquina.nombre, carta->nombre);
            printf("esta carta %s\n\n", carta->descripcion);

            if(h == 0){

                carta->aprobar(carta, &maquina);    
                printf("tu rival utilizo aprobar\n\n");
            }
            else if(h == 1){
                carta->reprobar(carta, &protagonista); 
                printf("tu rival utilizo reprobar\n\n");   
            }
            finale2--;
            iniciador = 0;
            next(mazo2);
        }
    }
mostrarvida(protagonista,maquina);
if (finale ==0 || finale2 ==0){
    if(protagonista.prioridad < maquina.prioridad){
        printf("el juego ha terminado! tu rival tiene mas prioridad, Has perdido\n");
    }
    if(protagonista.prioridad > maquina.prioridad){
        printf("el juego ha terminado! tienes mas prioridad, Has ganado %s!!!\n",nombre);
    }
    if(protagonista.prioridad == maquina.prioridad){
       printf("el juego ha terminado y han empatado\n");
    }
}

if (protagonista.prioridad == 0){
    printf("Has perdido!\n");
}
if (maquina.prioridad == 0){
    printf("Felicidades %s!!, has ganado\n",nombre);
}
    clear(protagonista.mazo);
    clear(maquina.mazo);
    return 0;    
}