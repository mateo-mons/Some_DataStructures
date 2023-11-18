#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
#include<time.h>

#include "Arboles.h"

/* Menu de operaciones */
void Menu() {
  printf("\n\n--- Operaciones basicas con un arbol binario ---\n");
  printf("1.LLenar un arbol de forma aleatoria\n");
  printf("2.LLenar un arbol de forma manual\n");
  printf("3.Ingresar un elemento al arbol\n");
  printf("4.Buscar un dato de forma recursiva\n");
  printf("5.Buscar un dato de forma iterativa\n");
  printf("6.Buscar minimo y maximo\n");
  printf("7.Contar nodos del arbol\n");
  printf("8.Contar hojas del arbol\n");
  printf("9.Ver arbol\n");
  printf("10.Ver recorridos\n");
  printf("11.Altura del arbol\n");
  printf("12.Eliminar un dato\n");
  printf("13.Eliminar arbol\n");
  printf("14.Salir\n");
  printf("Opcion: ");
}

/* Programa principal */
int main() {
  int n, i, option, dato, contH=0;
  arbol *p = NULL; /* Arbol vacio */


  while(option != 14) {
    Menu();
    scanf("%d", &option);

    switch(option) {
      case 1:
        printf("Numero de nodos del arbol: ");
        scanf("%d", &n);
        n = abs(n); /* Solo n positivo */
        srand(time(NULL)); /* Numero aleatorio en base al tiempo */

        for(i=0; i<n; i++) {
          printf("\nElemento %d: ", i+1);
          dato = rand()%200;
          printf("%d", dato);
          p = Insertar(dato, p);
        }
      break;

      case 2:
        printf("Numero de nodos del arbol: ");
        scanf("%d", &n);
        n = abs(n);
        printf("\n");
        for(i=0; i<n; i++) {
          printf("Elemento %d: ", i+1);
          scanf("%d", &dato);
          p = Insertar(dato, p);
        }
      break;

      case 3:
        printf("Elemento a insertar: ");
        scanf("%d", &dato);
        Insertar(dato, p);
        printf("Elemento %d insertado!\n", dato);
      break;

      case 4:
        printf("Dato a buscar: ");
        scanf("%d", &dato);
        printf("\n");
        if(BuscarRec(p, dato) != 0)
          printf("Dato %d encontrado!", dato);
        else
          printf("No se pudo en contrar el dato %d\n", dato);
      break;

      case 5:
        printf("Dato a buscar: ");
        scanf("%d", &dato);
        printf("\n");
        if(BuscarIter(p, dato) != 0)
          printf("Dato %d encontrado!", dato);
        else
          printf("No se pudo en contrar el dato %d\n", dato);
      break;

      case 6:
        printf("\n");
        printf("Minimo: %d\n", BuscarMin(p));
        printf("Maximo: %d\n", BuscarMax(p));
      break;

      case 7:
        printf("\n");
        printf("Numero de nodos: %d\n", NumNodos(p));
      break;

      case 8:
        printf("\n");
        printf("Numero de hojas: ");
        ContarHojas(p, &contH);
        printf("%d", contH);
        printf("\n");
      break;

      case 9:
        printf("Arbol Binario\n");
        Ver(0, p);
      break;

      case 10:
        printf("\n");
        printf("Pre-Orden");
        PreOrden(p);
        printf("\n");
        printf("En-Orden");
        EnOrden(p);
        printf("\n");
        printf("Post-Orden");
        PostOrden(p);
        printf("\n");
      break;

      case 11:
        printf("\n");
        int altura = Altura(p);
        printf("Altura: %d", altura);
        printf("\n");
      break;

      case 12:
        printf("\n");
        printf("Dato a eliminar: ");
        scanf("%d", &dato);
        Suprimir(p, dato);
      break;

      case 13:
        printf("\n");
        EliminarArbol(p);
      break;

      case 14:
        printf("Hasta pronto!\n");
      break;

      default:
        printf("Intente de nuevo\n");
      break;
    }
  }

  return 0;
}