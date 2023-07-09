#ifndef LINEA_DE_PIEZAS_H_INCLUDED
#define LINEA_DE_PIEZAS_H_INCLUDED
#include "Robots.h"

typedef struct nodo
{
    Pieza *pieza;
    struct nodo *sig;

} Nodo;

typedef struct
{
    Nodo *h, *t;

} Cola;

Cola *crearCola ();
void insertarenCola (Cola *cola, Pieza *piezacreada);
void listarCola (Cola cola);
int colavacia (Cola cola);
void inicializarCola (Cola *cola);
Pieza *borrar (Cola *cola);
void robotsenfuncion (int X, int nc, int idx, Cola *lineadepiezas);

#endif // LINEA_DE_PIEZAS_H_INCLUDED
