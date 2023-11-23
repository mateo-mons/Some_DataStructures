#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Grafo;

void InicializarGrafo(Grafo *grafo, int num_vertices) {
    grafo->num_vertices = num_vertices;

    // Inicializar la matriz de adyacencia con 0 (sin aristas)
    for(int i = 0; i < num_vertices; i++) {
        for(int j = 0; j < num_vertices; j++) {
            grafo->vertices[i][j] = 0;
        }
    }
}

void AgregarArista(Grafo *grafo, int origen, int destino, int peso) {
    grafo->vertices[origen][destino] = peso;
    grafo->vertices[destino][origen] = peso; // Grafo no dirigido
}

void ImprimirGrafo(Grafo *grafo) {
    printf("G = {V = {");
    for(int i = 0; i < grafo->num_vertices; i++) {
        printf("%d", i + 1);
        if(i < grafo->num_vertices - 1) {
            printf(", ");
        }
    }
    printf("}, A = {");
    for(int i = 0; i < grafo->num_vertices; i++) {
        for(int j = i; j < grafo->num_vertices; j++) {
            if(grafo->vertices[i][j] > 0) {
                printf("(%d, %d, %d),", i + 1, j + 1, grafo->vertices[i][j]);                
                if(j < grafo->num_vertices - 1) {
                    printf(" ");
                }
            }
        }
    }
    printf("}}\n");
}

void RecorridoAnchura(Grafo *grafo, int inicio) {
    printf("\nRecorrido en Anchura (BFS): ");

    int visitados[MAX_VERTICES] = {0};
    int cola[MAX_VERTICES];
    int frente = 0, fin = 0;
    int nivel = 1;

    visitados[inicio] = 1;
    cola[fin++] = inicio;

    while(frente < fin) {
        printf("\n");
        int elementosNivel = fin - frente;
        printf("Nivel %d: ", nivel++);

        while(elementosNivel > 0) {
            int actual = cola[frente++];
            printf("%d ", actual + 1);

            for(int i = 0; i < grafo->num_vertices; i++) {
                if(grafo->vertices[actual][i] > 0 && !visitados[i]) {
                    visitados[i] = 1;
                    cola[fin++] = i;
                }
            }

            elementosNivel--;
        }
    }

    printf("\n");
}

void RecorridoProfundidadRecursivo(Grafo *grafo, int vertice, int visitados[]) {
    visitados[vertice] = 1;
    printf("%d . ", vertice + 1);

    for(int i = 0; i < grafo->num_vertices; i++) {
        if(grafo->vertices[vertice][i] > 0 && !visitados[i]) {
            RecorridoProfundidadRecursivo(grafo, i, visitados);
        }
    }
}

void RecorridoProfundidad(Grafo *grafo, int inicio, int visitados[]) {
    printf("\nRecorrido en Profundidad (DFS): ");
    RecorridoProfundidadRecursivo(grafo, inicio, visitados);
    printf("\n\n");
}

void Dijkstra(Grafo *grafo, int inicio) {
    int distancia[MAX_VERTICES];
    int visitados[MAX_VERTICES] = {0};

    for(int i = 0; i < grafo->num_vertices; i++) {
        distancia[i] = INT_MAX;
    }

    distancia[inicio] = 0;

    for(int count = 0; count < grafo->num_vertices - 1; count++) {
        int min = INT_MAX, min_index;

        for(int v = 0; v < grafo->num_vertices; v++) {
            if(!visitados[v] && distancia[v] <= min) {
                min = distancia[v];
                min_index = v;
            }
        }

        visitados[min_index] = 1;

        for(int v = 0; v < grafo->num_vertices; v++) {
            if(!visitados[v] && grafo->vertices[min_index][v] &&
                distancia[min_index] != INT_MAX &&
                distancia[min_index] + grafo->vertices[min_index][v] < distancia[v]) {
                distancia[v] = distancia[min_index] + grafo->vertices[min_index][v];
            }
        }
    }

    printf("Distancias más cortas desde el vértice %d:\n", inicio + 1);
    for(int i = 0; i < grafo->num_vertices; i++) {
        printf("(%d, %d): %d\n", i + 1, i + 1, distancia[i]);
    }
}

int main() {
    Grafo grafo;
    int num_vertices, origen, destino, peso, inicio;

    printf("Ingrese el numero de vertices: ");
    scanf("%d", &num_vertices);

    InicializarGrafo(&grafo, num_vertices);

    printf("Ingrese las relaciones entre vertices (origen destino peso), finalice con 0 0 0:\n");
    while(1) {
        scanf("%d %d %d", &origen, &destino, &peso);
        if(origen == 0 || destino == 0 || peso == 0) {
            break;
        }
        AgregarArista(&grafo, origen - 1, destino - 1, peso);
    }

    printf("Ingrese el vertice de inicio para los recorridos: ");
    scanf("%d", &inicio);
    inicio--; // Ajustar a índice base 0

    ImprimirGrafo(&grafo);

    RecorridoAnchura(&grafo, inicio);

    int visitados[MAX_VERTICES] = {0};
    RecorridoProfundidad(&grafo, inicio, visitados);

    Dijkstra(&grafo, inicio);

    return 0;
}
