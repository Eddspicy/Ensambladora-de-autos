#ifndef BODEGA_H_INCLUDED
#define BODEGA_H_INCLUDED

#include "Robots.h"
#include "Linea de piezas.h"
#include "Linea de pintado.h"

typedef struct nodos
{
    Pieza *pieza;
    struct nodos *sig;

} Nodos;

typedef struct
{
    Nodos *h, *t;

} Listas;

Listas *crearListaSE ();
void insertaralfinalSE (Listas *listas, Pieza *pieza);
void listarSE (Listas lista);
int listavaciaSE (Listas lista);
void inicializarSE (Listas *lista);

#endif // BODEGA_H_INCLUDED
