
#include "Robots.h"

Pieza *crearPieza ()
{
    Pieza *nuevapieza = (Pieza*) malloc (sizeof(Pieza));
        if (nuevapieza == NULL){
            printf("\nError: no se ha podido crear la pieza\n");
        return NULL;
        }

    nuevapieza->idn = 0;

    nuevapieza->idr = (char*) calloc (MAX, sizeof(char));
        if (nuevapieza->idr == NULL){
            printf("\nError: no se ha podido crear el apartado de la pieza\n");
        return NULL;
        }

    nuevapieza->color = (char*) calloc (MAX, sizeof(char));
        if (nuevapieza->color == NULL){
            printf("\nError: no se ha podido crear el apartado de la pieza\n");
        return NULL;
        }

    nuevapieza->descripcion = (char*) calloc (MAX, sizeof(char));
        if (nuevapieza->descripcion == NULL){
            printf("\nError: no se ha podido crear el apartado de la pieza\n");
        return NULL;
        }

    return nuevapieza;
}



void llenarpieza (Pieza *pieza, int id, int nc)
{
    char robot [4][MAX] = {"A", "B", "C", "D"};
    char piezas [4][MAX] = {"Puertas", "Cofre", "Toldo", "Cochera"};
    char colores [4][MAX] = {"Negro piano", "Azul marino", "Gris Plata", "Carmesi"};

        if ((nc == 0)){
            strcpy (pieza->idr, robot[nc]);
            pieza->idn = id;
            strcpy (pieza->descripcion, piezas[nc]);
            strcpy (pieza->color, colores[id-1]);
        }

        if ((nc == 1)){
            strcpy (pieza->idr, robot[nc]);
            pieza->idn = id;
            strcpy (pieza->descripcion, piezas[nc]);
            strcpy (pieza->color, colores[id-1]);
        }

        if ((nc == 2)){
            strcpy (pieza->idr, robot[nc]);
            pieza->idn = id;
            strcpy (pieza->descripcion, piezas[nc]);
            strcpy (pieza->color, colores[id-1]);
        }

        if ((nc == 3)){
            strcpy (pieza->idr, robot[nc]);
            pieza->idn = id;
            strcpy (pieza->descripcion, piezas[nc]);
            strcpy (pieza->color, colores[id-1]);
        }
}

void listarpieza (Pieza *pieza)
{
    printf("\n\t-Datos de la pieza:-\n");
    printf("\nLa id de la pieza es: %s-%d\n", pieza->idr, pieza->idn);
    printf("El color de la pieza es: %s\n", pieza->color);
    printf("El tipo de pieza es: %s\n", pieza->descripcion);
    fflush(stdout);
}

void identificarpieza (Pieza *pieza)
{
    printf(" %s-%d ", pieza->idr, pieza->idn);
    fflush(stdout);
}

void liberarpieza (Pieza *pieza)
{
    pieza->idn = 0;
    free (pieza->idr);
        pieza->idr = NULL;
    free (pieza->descripcion);
        pieza->descripcion = NULL;
    free(pieza->color);
        pieza->color = NULL;
    free(pieza);
        pieza = NULL;
}
