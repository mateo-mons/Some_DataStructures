/*  Implementacion de listas usando librebria 'Listas.h' y
    usando archivos para guardar la lista */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Listas.h"

/*  MENU DE OPERACIONES CON LISTAS   */
void menu() {
    printf("----------MENU DE OPCIONES----------\n");
    printf("1). Insertar elemento al comienzo de la lista\n");
    printf("2). Insertar elemento al final de la lista\n");
    printf("3). Insertar elemento entre dos nodos\n");
    printf("4). Buscar un elemento en la lista\n");
    printf("5). Eliminar la lista\n");
    printf("6). Guardar la lista en un archivo\n");
    printf("7). Salir\n");
    printf("Opcion: ");
}

int main() {
    struct node *head;
    char archi[20];
    head = NULL;

    int option, elem, prevData, newData, target;

    while(option != 7) {
        menu();
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &elem);
                insertAtBeginning(&head, elem);
                printf("\nLista: ");
                printLinkedList(head);
                printf("\n\n");
                break;
                
            case 2:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &elem);
                insertAtEnd(&head, elem);
                printf("\nLista: ");
                printLinkedList(head);
                printf("\n\n");
                break;
            
            case 3:
                printf("Ingrese el dato anterior al nuevo nodo: ");
                scanf("%d", &prevData);
                printf("Ingrese el nuevo dato: ");
                scanf("%d", &newData);
                insertBetween(&head, prevData, newData);
                printf("\nLista: ");
                printLinkedList(head);
                printf("\n\n");
                break;

            case 4:
                printf("Ingrese el elemento a buscar: ");
                scanf("%d", &target);
                struct node* result = searchElement(head, target);
                if (result != NULL) {
                    printf("\n--> El elemento %d se encontró en la lista.\n\n", target);
                } else {
                    printf("\n--> El elemento %d no se encontró en la lista.\n\n", target);
                }
                printLinkedList(head);
                printf("\n\n");
                break;

            case 5:
                deleteLinkedList(head);
                printf("Lista eliminada\n\n");
                printf("\n\n");
                break;
            
            case 6:
                printf("Ingrese el nombre del archivo para guardar la lista: ");
                scanf("%s", archi);
                saveListToFile(head, archi);
                break;

            case 7:
                printf("Hasta pronto!\n");
                break;

            default:
                printf("Opcion invalida. Intente de nuevo\n\n");
        }
    }

    return 0;
}
