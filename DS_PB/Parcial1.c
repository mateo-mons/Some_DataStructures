#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// Estructura definida para el programa
struct datosCliente {
    int numCta;
    char nombre[10];
    char apellido[20];
    double saldo;
};

// Definición de la estructura de un nodo para la lista enlazada
struct Node {
    struct datosCliente data;
    struct Node* next;
};

// Crear un nuevo nodo
struct Node* newNode(struct datosCliente data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Insertar datos
void insert(struct Node **head, struct datosCliente data) {
    struct Node* newData = newNode(data);
    newData->next = *head;
    *head = newData;
}

// Imprimir datos
void printList(struct Node *head) {
    struct Node *actual = head;
    printf("Numero de cuenta: %d\n", actual->data.numCta);
    printf("Nombre: %s\n", actual->data.nombre);
    printf("Apellido: %s\n", actual->data.apellido);
    printf("Saldo: %.3lf\n", actual->data.saldo);
    while(actual != NULL) {
        
        actual = actual->next;
    }
}

// Guardar en un archivo
void GuardarArchivo(struct Node *head, const char *filename) {
    FILE* file = fopen(filename, "w");
    if(file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    struct Node *actual = head;
    while(actual != NULL) {
        fprintf(file, "Numero de cuenta: %d\n", actual->data.numCta);
        fprintf(file, "Nombre: %s\n", actual->data.nombre);
        fprintf(file, "Apellido: %s\n", actual->data.apellido);
        fprintf(file, "Saldo: %.3lf\n", actual->data.saldo);
        actual = actual->next;
    }

    fclose(file);
    printf("Lista guardada en el archivo '%s'.\n\n", filename);
}

void menu() {
    printf("--- PARCIAL I ---\n");
    printf("1.Cargar datos\n");
    printf("2.Listado de alumnos ingresados\n");
    printf("3.Guardar en un archivo\n");
    printf("4.Salir\n");
    printf("Opcion: ");
}


int main() {

    int option;
    char archi[20];

    struct Node *head = NULL;

    while(option != 4){
        menu();
        scanf("%d", &option);

        switch(option) {

        case 1:
            struct datosCliente cliente;
            printf("ingrese numero de cuenta: ");
            scanf("%d", &cliente.numCta);
            printf("ingrese el nombre: ");
            scanf("%s", cliente.nombre);
            printf("ingrese apellido: ");
            scanf("%s", cliente.apellido);
            printf("ingrese el saldo: ");
            scanf("%lf", &cliente.saldo);
            insert(&head, cliente);
            printf("\n\n");
            break;

        case 2:
            printf("\n");
            printList(head);
            printf("\n\n");
            break;

        case 3:
            printf("Ingrese el nombre del archivo para guardar la lista: ");
            scanf("%s", archi);
            GuardarArchivo(head, archi);
            break;

        case 4:
            printf("hasta pronto!\n");
            break;

        default:
            printf("intente de nuevo\n");
            
        }
    }

    return 0;
}