
#include "Robots.h"
#include "Linea de piezas.h"

Cola *crearCola ()
{
    Cola *nuevacola = (Cola *) calloc (1,sizeof(Cola));
        if (nuevacola== NULL){
            printf("\nError: Espacio insuficiente para crear la lista...");
        return NULL;
        }

    return nuevacola;
}

void insertarenCola (Cola *cola, Pieza *piezacreada)
{
    Nodo *nuevoNodo = (Nodo *) malloc (sizeof(Nodo));
        if (nuevoNodo == NULL){
            printf("\nError: Espacio insuficiente para crear el nodo...");
        return;
        }

    nuevoNodo->pieza = crearPieza();
        strcpy (nuevoNodo->pieza->idr, piezacreada->idr);
        nuevoNodo->pieza->idn = piezacreada->idn;
        strcpy (nuevoNodo->pieza->color, piezacreada->color);
        strcpy (nuevoNodo->pieza->descripcion, piezacreada->descripcion);
    nuevoNodo->sig = NULL;

    if (cola->t == NULL)
        cola->h = cola->t = nuevoNodo;
            else{
            cola->t->sig = nuevoNodo;
            cola->t = nuevoNodo;
    }
}

void listarCola (Cola cola)
{
    Nodo *q = cola.h;

    if (colavacia(cola)){
        printf("\nNo hay piezas dentro de la l%cnea de piezas...\n", 161);
    return;
    }

    while (q!=NULL)
    {
        listarpieza (q->pieza);
         q = q->sig;
    }

    printf("\n");
}

Pieza *borrar (Cola *cola)
{
    Pieza *pasodepieza = (Pieza*) calloc (1, sizeof(Pieza));
        if (pasodepieza == NULL){
            printf("\nEspacio de memoria insuficiente...\n");
        return NULL;
        }

    if (!colavacia(*cola)){
        Nodo *q = cola->h;
        cola->h = cola->h->sig;
        pasodepieza = q->pieza;
            free(q);
            q = NULL;
    }

    return pasodepieza;
}

int colavacia(Cola cola)
{
    return cola.h==NULL;
}

void inicializar(Cola *cola)
{
    if (!colavacia(*cola)){
        Nodo *q=cola->h;
        while (q!=NULL)
        {
            cola->h = cola->h->sig;
            free(q);
            q = cola->h;
        }
        cola->h = cola->t = NULL;
    }
    printf("\nLa l%cnea de piezas se ha inicializado\n", 161);
}

void robotsenfuncion (int X, int nc, int idx, Cola *lineadepiezas)
{
    if (X>50)
    {
        Pieza *X = crearPieza();
        llenarpieza (X, idx, nc);
            insertarenCola(lineadepiezas, X);
            printf("\nEl robot a creado una pieza y la ha pasado a la l%cnea de piezas\n", 161);
            listarpieza(X);
            liberarpieza(X);
                free(X);
                X = NULL;
    }
        else if (X<50)
            printf("\nEl robot no ha terminado de generar la pieza\n");
}
