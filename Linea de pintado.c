#include "Robots.h"
#include "Linea de piezas.h"
#include "Linea de pintado.h"


Listad *crearListaDBE ()
{
    Listad *nuevaLista = (Listad * ) calloc (1, sizeof(Listad));
    if (nuevaLista==NULL){
        printf("Error: Espacio insuficiente...");
    return NULL;
    }

    return nuevaLista;
}

Nodod *crearNodo (Pieza *pieza, Nodod *sig, Nodod *ant)
{
    Nodod *nuevoNodo= (Nodod *) malloc (1 * sizeof (Nodod));
    if (nuevoNodo == NULL){
       printf("Error: memoria insuficiente...");
    return NULL;
    }

    nuevoNodo->pieza = crearPieza();
        strcpy (nuevoNodo->pieza->idr, pieza->idr);
        nuevoNodo->pieza->idn = pieza->idn;
        strcpy (nuevoNodo->pieza->color, pieza->color);
        strcpy (nuevoNodo->pieza->descripcion, pieza->descripcion);
    nuevoNodo->sig = sig;
    nuevoNodo->ant = ant;

    return nuevoNodo;
}

void insertaralprincipioDBE (Listad *lista, Pieza *pieza)
{
    Nodod *nuevoNodo = crearNodo (pieza,lista->h,NULL);

    if (lista->h == NULL) {
        lista->h = nuevoNodo;
        lista->t = nuevoNodo;
    }
        else {
        lista->h->ant = nuevoNodo;
        lista->h = nuevoNodo;
        }
}

int listaDBEvacia (Listad lista)
{
    return lista.h==NULL;
}

void listarDBE (Listad lista)
{
    Nodod *q;
    if (listaDBEvacia(lista))
        printf("\nNo hay piezas en la l%cnea de pintado...\n", 161);
    else{
        q = lista.h;
        while (q!=NULL)
        {
            listarpieza(q->pieza);
                q = q->sig;
        }
    }
}

void pintarnormal (Listad lista)
{
    Nodod *q;
    if (listaDBEvacia(lista))
        printf("\nNo hay nada que pintar...\n");
    else{
        q = lista.h;
        while (q!=NULL)
        {
            printf("\nLa pieza:");
            identificarpieza(q->pieza);
            printf("esta siendo pintada de \"%s\"\n", q->pieza->color);
                q = q->sig;
        }
    }
}

void pintarinverso (Listad lista)
{
    Nodod *q;
    if (listaDBEvacia(lista))
        printf("\nNo hay nada que pintar...\n");
    else{
        q = lista.t;
        while (q!=NULL)
        {
            printf("\nLa pieza:");
            identificarpieza(q->pieza);
            printf("esta siendo pintada de \"%s\"\n", q->pieza->color);
                q = q->ant;
        }
    }
}

void inicializarlistaDBE (Listad *lista)
{
    Nodod *q;
    if (listaDBEvacia(*lista))
        printf("\n\tNo hay piezas en la l%cnea de pintado...\n", 161);
        else{
        q = lista->h;
            while (q!=NULL)
            {
                lista->h = lista->h->sig;
                free(q);
                q = lista->h;
            }
        }
    lista->h= lista->t = NULL;
    printf("\nLa l%cnea de pintado se ha incializado\n", 161 );
}

Pieza *borrarp (Listad *lista)
{
    Pieza *pasodepieza = (Pieza*) calloc (1, sizeof(Pieza));
        if (pasodepieza == NULL){
            printf("\nEspacio de memoria insuficiente...\n");
        return NULL;
        }

        pasodepieza = crearPieza();

        if (!listaDBEvacia(*lista)){
            Nodod *q = lista->h;
            lista->h = lista->h->sig;
            pasodepieza = q->pieza;
                free(q);
                q = NULL;
        }
    return pasodepieza;
}
