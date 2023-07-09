#ifndef LINEA_DE_PINTADO_H_INCLUDED
#define LINEA_DE_PINTADO_H_INCLUDED

#include "Robots.h"
#include "Linea de piezas.h"

typedef struct nodod
{
    Pieza *pieza;
    struct nodod *sig;
    struct nodod *ant;

} Nodod;

typedef struct
{
   Nodod *h, *t;

} Listad;

Listad *crearListaDBE ();
Nodod *crearNodo (Pieza *pieza, Nodod *sig, Nodod *ant);
void insertaralprincipioDBE (Listad *lista, Pieza *pieza);
int listaDBEvacia (Listad lista);
void inicializarlistaDBE (Listad *lista);
void listarDBE (Listad lista);
void pintarnormal (Listad lista);
void pintarinverso (Listad lista);
Pieza *borrarp (Listad *lista);

#endif // LINEA_DE_PINTADO_H_INCLUDED
