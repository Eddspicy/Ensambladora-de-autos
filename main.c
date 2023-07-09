
#include "Robots.h"
#include "Linea de piezas.h"
#include "Linea de pintado.h"
#include "Bodega.h"

int main()
{
    srand(time(NULL));

    int capacidad, llenado = 0, sobra, na = 0, nb = 1, nc = 2, nd = 3, ida = 0, idb = 0, idc = 0, idd = 0;

    printf("\n\t\t BIENVENIDO A LA ENSAMBLADORA TOYOTA! \n\n");
    printf("\n%cCual es la capacidad de la bodega de ensamble el dia de hoy?\n", 168);
    scanf("%d", &capacidad);

    Listas *bodega = crearListaSE();

    do
    {
        Cola *lineadepiezas = crearCola();
        Listad *lineadepintado = crearListaDBE();

        int A = rand()%101, B = rand()%101, C = rand()%101, D = rand()%101;

        printf ("\n\t\t-ROBOT A-\n");
        ida = ida +1;
        robotsenfuncion(A, na, ida, lineadepiezas);
        if (A<50){ ida = ida - 1; }
        if (ida == 4){ ida = 0; }
        printf("\n\t%cEste es el estado actual de la l%cnea de piezas:%c\n",     179, 161, 179);
        listarCola(*lineadepiezas);

        printf ("\n\t\t-ROBOT B-\n");
        idb = idb + 1;
        robotsenfuncion(B, nb, idb, lineadepiezas);
        if (B<50){ idb = idb - 1; }
        if (idb == 4){ idb = 0; }
        printf("\n\t%cEste es el estado actual de la l%cnea de piezas:%c\n", 179, 161, 179);
        listarCola(*lineadepiezas);

        printf ("\n\t\t-ROBOT C-\n");
        idc = idc + 1;
        robotsenfuncion(C, nc, idc, lineadepiezas);
        if (C<50){ idc = idc - 1; }
        if (idc == 4){ idc = 0; }
        printf("\n\t%cEste es el estado actual de la l%cnea de piezas:%c\n", 179, 161, 179);
        listarCola(*lineadepiezas);

        printf ("\n\t\t-ROBOT D-\n");
        idd = idd + 1 ;
        robotsenfuncion(D, nd, idd, lineadepiezas);
        if (D<50){ idd = idd - 1 ; }
        if (idd == 4){ idd = 0; }
        printf("\n\t%cEste es el estado actual de la l%cnea de piezas:%c\n", 179, 161, 179);
        listarCola(*lineadepiezas);

        printf ("\n\t\t-BRAZO ROBOTICO-\n");
            while (!colavacia(*lineadepiezas))
            {
                insertaralprincipioDBE(lineadepintado, borrar(lineadepiezas));
                printf("\nEL BRAZO ROBOTICO A ENVIADO LA PIEZA");
                identificarpieza(lineadepintado->h->pieza);
                printf("A LA LINEA DE PINTADO\n");
                printf("\n\t%cEste es el estado actual de la l%cnea de piezas:%c\n", 179, 161, 179);
                listarCola(*lineadepiezas);
                printf("\n\t%cEste es el estado actual de la l%cnea de pintado:%c\n", 179, 161, 179);
                listarDBE(*lineadepintado);
            }

            free(lineadepiezas);
            lineadepiezas = NULL;

        printf ("\n\t\t-ROBOT PINTOR-\n");
            printf("\nCOMENZANDO PRIMERA PASADA DE PINTURA\n");
            pintarnormal(*lineadepintado);
            printf("\nPRIMERA PASADA FINALIZADA\n");
            printf("\nCOMENZANDO SEGUNDA PASADA DE PINTURA\n");
            pintarinverso(*lineadepintado);
            printf("\nSEGUNDA PASADA FINALIZADA\n");

        printf ("\n\t\t-BRAZO ROBOTICO-\n");
            while (!listaDBEvacia(*lineadepintado))
            {
                insertaralfinalSE(bodega, borrarp(lineadepintado));
                llenado++;
                printf("\nEL BRAZO ROBOTICO HA MOVIDO LA PIEZA");
                identificarpieza(bodega->h->pieza);
                printf("DE LA SECCION DE PINTADO A LA BODEGA DE ENSAMBLAJE\n");
                printf("\n\t%cEste es el estado actual de la l%cnea de pintado:%c\n", 179, 161, 179);
                listarDBE(*lineadepintado);
                printf("\n\t%cEste es el estado actual de la bodega de ensamblaje:%c\n", 179, 179);
                listarSE(*bodega);
            }

            free(lineadepintado);
            lineadepintado = NULL;

    } while (llenado<capacidad);

    printf("\n\t\t -ESTOS SON LOS PRODUCTOS EN LA BODEGA DE ENSAMBLAJE:- \n");
    listarSE(*bodega);

    sobra =  llenado - capacidad;

        if((llenado>capacidad)){
            printf("\n\t %cSE CREARON %d PIEZAS MAS DE LAS PREEVISTAS EN BODEGA%c\n", 158, sobra, 158);
        }
    return 0;
}
