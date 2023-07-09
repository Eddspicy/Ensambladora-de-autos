#include "Robots.h"
#include "Linea de piezas.h"
#include "Linea de pintado.h"
#include "Bodega.h"

Listas *crearListaSE ()
{
    Listas *nuevalista = (Listas *) calloc (1,sizeof(Listas));
        if (nuevalista == NULL){
         printf("\nError: Espacio insuficiente para crear la lista...");
        return NULL;
        }

    return nuevalista;
}

void insertaralfinalSE (Listas *lista, Pieza *pieza)
{
    Nodos *nuevoNodo = (Nodos *) malloc (1 * sizeof(Nodos));
        if (nuevoNodo == NULL){
            printf("\nError: Espacio insuficiente para crear el nodo...");
        return;
        }

    nuevoNodo->pieza = crearPieza();
        strcpy (nuevoNodo->pieza->idr, pieza->idr);
        nuevoNodo->pieza->idn = pieza->idn;
        strcpy (nuevoNodo->pieza->color, pieza->color);
        strcpy (nuevoNodo->pieza->descripcion, pieza->descripcion);
    nuevoNodo->sig = NULL;

    if (lista->t == NULL)
        lista->h = lista->t = nuevoNodo;
        else {
            lista->t->sig = nuevoNodo;
            lista->t = nuevoNodo;
        }
}

void listarSE (Listas lista)
{
    Nodos *q = lista.h;
    if (listavaciaSE(lista)){
        printf("\nNo hay piezas dentro de la bodega de ensamblaje...");
    return;
    }

    while (q!=NULL)
    {
        listarpieza(q->pieza);
            q = q->sig;
    }
    printf("\n");
}

int listavaciaSE (Listas lista)
{
    return lista.h==NULL;
}

void inicializarSE (Listas *lista)
{
    Nodos *q = lista->h;
    if (!listavaciaSE(*lista)){
        while (q!=NULL)
        {
            lista->h = lista->h->sig;
                free(q);
            q = lista->h;
        }
        lista->h=lista->t=NULL;
    }
    printf("Lista vacía...");
}
