#ifndef ROBOTS_H_INCLUDED
#define ROBOTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 30

typedef struct
{
    int idn;
    char *idr;
    char *color;
    char *descripcion;

} Pieza;

Pieza *crearPieza ();
void llenarpieza (Pieza *pieza, int id, int nc);
void listarpieza (Pieza *pieza);
void identificarpieza (Pieza *pieza);
void liberarpieza (Pieza *pieza);

#endif // ROBOTS_H_INCLUDED
