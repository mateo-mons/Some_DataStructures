#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar un cliente
struct Cliente {
    int codigoCliente;
    char nombre[50];
    char correo[50];
    struct Cliente *izquierda;
    struct Cliente *derecha;
};

// Función para crear un nuevo cliente
struct Cliente *CrearCliente(int codigo, const char *nombre, const char *correo) {
    
    struct Cliente *nuevoCliente = (struct Cliente *) malloc(sizeof(struct Cliente));
    nuevoCliente->codigoCliente = codigo;
    strcpy(nuevoCliente->nombre, nombre);
    strcpy(nuevoCliente->correo, correo);
    nuevoCliente->izquierda = nuevoCliente->derecha = NULL;
    return nuevoCliente;
}

// Función para insertar un cliente en el árbol
struct Cliente *InsertarCliente(struct Cliente *raiz, int codigo, const char *nombre, const char *correo) {
    if(raiz == NULL) 
        return CrearCliente(codigo, nombre, correo);
    
    if(strcmp(correo, raiz->correo) < 0) {
        raiz->izquierda = InsertarCliente(raiz->izquierda, codigo, nombre, correo);
    } else if(strcmp(correo, raiz->correo) > 0) {
        raiz->derecha = InsertarCliente(raiz->derecha, codigo, nombre, correo);
    }
    return raiz;
}

// Función para realizar un recorrido ordenado por correo electrónico
void InOrden(struct Cliente *raiz) {
    if(raiz != NULL) {
        InOrden(raiz->izquierda);
        printf("Codigo: %d \nNombre: %s \nCorreo: %s\n\n", raiz->codigoCliente, raiz->nombre, raiz->correo);
        InOrden(raiz->derecha);
    }
}

// Función para buscar un cliente por nombre
struct Cliente *BuscarPorNombre(struct Cliente *raiz, const char *nombre) {
    if(raiz == NULL || strcmp(nombre, raiz->nombre) == 0) 
        return raiz;
    
    if(strcmp(nombre, raiz->nombre) < 0) 
        return BuscarPorNombre(raiz->izquierda, nombre);
    
    return BuscarPorNombre(raiz->derecha, nombre);
}

// Función para guardar la información de la agenda en un archivo
void GuardarEnArchivo(struct Cliente *raiz, FILE *archivo) {
    if(raiz != NULL) {
        GuardarEnArchivo(raiz->izquierda, archivo);
        fprintf(archivo, "Codigo: %d \nNombre: %s \nCorreo: %s\n\n", raiz->codigoCliente, raiz->nombre, raiz->correo);
        GuardarEnArchivo(raiz->derecha, archivo);
    }
}

// Menu de opciones
void Menu() {
	printf("--- Agenda Empresa Solarix ---\n");
    printf("1.Insertar cliente\n");
    printf("2.Leer informacion ordenada por correo\n");
    printf("3.Buscar cliente por nombre\n");
    printf("4.Guardar agenda en archivo\n");
    printf("5.Salir\n");
    printf("Opcion: ");
}

int main() {
    struct Cliente *raiz = NULL;
    int option, codigo;
    char nombre[50], correo[50];

    while(option != 5) {
    	Menu();
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Ingrese codigo del cliente: ");
                scanf("%d", &codigo);
                printf("Ingrese nombre del cliente: ");
                scanf("%s", nombre);
                printf("Ingrese correo del cliente: ");
                scanf("%s", correo);
                raiz = InsertarCliente(raiz, codigo, nombre, correo);
            break;

            case 2:
                printf("Informacion de la agenda ordenada por correo:\n");
                InOrden(raiz);
            break;

            case 3:
                printf("Ingrese nombre del cliente a buscar: ");
                scanf("%s", nombre);
                struct Cliente *nombreC = BuscarPorNombre(raiz, nombre);
                if(nombreC != NULL) {
                    printf("Cliente encontrado! \nCodigo: %d \nCorreo: %s\n", nombreC->codigoCliente, nombreC->correo);
                } else {
                    printf("Cliente %s no fue encontrado\n", nombre);
                }
            break;

            case 4:
                printf("Guardando agenda en archivo...\n");
                FILE *archivo = fopen("agenda.txt", "w");
                if(archivo != NULL) {
                    GuardarEnArchivo(raiz, archivo);
                    fclose(archivo);
                    printf("Agenda guardada en el archivo 'agenda.txt'.\n");
                } else {
                    printf("Error al abrir el archivo.\n");
                }
            break;

            case 5:
                printf("Hasta pronto!\n");
            break;
                
            default:
                printf("Por favor intente de nuevo\n");
        }
    }

    return 0;
}