#include<stdio.h>
#include<stdlib.h>

#define pi 3.1416

// 1)
/*
void captura(int *e, float *es, float *p) {

    printf("Introduzca edad: ");
    scanf("%d", e);
    printf("Introduzca estatura: ");
    scanf("%f", es);
    printf("Introduzca peso: ");
    scanf("%f", p);
}

void imprimir(int e, float es, float p) {

    printf("\nEdad: %d", e);
    printf("\nEstatura: %.2f", es);
    printf("\nPeso: %.2f\n", p);
}

int main() {

    int edad;
    float estatura, peso;

    printf("Programa que lee la edad, estatura y peso de una persona\n");
    captura(&edad, &estatura, &peso); //Paso de parametros por referencia
    imprimir(edad, estatura, peso); //Paso de parametros por valor
    
    return 0;
}
*/

// 2)
/*
void calcula(float area, float *radio) {

    area = pi * (*radio) * (*radio);
    printf("\nEl area del circulo es: %f", area);
    printf("\nDesea calcular nuevamente el area?(s/n)");
    fflush(stdin);
}

int main() {

    float a, r;
    char respuesta = 's';
    printf("Programa que calcula el area de un circulo\n");

    do {
        printf("Radio: ");
        scanf("%f", &r);
        calcula(a, &r);
        scanf("%s", &respuesta);
    } while(respuesta == 's');

    printf("\nGracias por participar\n");

    return 0;
}
*/


// 3)
/*
float calcula(float *radio) {

    float area;
    area = pi * (*radio) * (*radio);
    return(area);
}

int main() {

    float a, r;
    char respuesta = 's';
    printf("Programa que calcula el area de un circulo");

    do {
        printf("Radio: ");
        scanf("%f", &r);
        a = calcula(&r);
        printf("\nEl area del circulo es: %f", a);
        printf("\nDesea calcular nuevamente el area?(s/n)");
        fflush(stdin);
        scanf("%s", &respuesta);
    } while(respuesta =='s');

    return 0;
}
*/


// 4)
/*
struct d_circulo
{
    float a, r;
};

float calcula(float *radio) {

    float area;
    area = pi * (*radio) * (*radio);
}

int main() {

    struct d_circulo circulo;
    char respuesta = 's';
    do {
        printf("Radio: ");
        scanf("%f", &circulo.r);
        circulo.a = calcula(&circulo.r);
        printf("\nEl area del circulo es: %f", circulo.a);
        printf("\nDesea calcular nuevamente el area?(s/n)");
        fflush(stdin);
        scanf("%s", &respuesta);
    } while(respuesta =='s');

    return 0;
}
*/


// 5)
/*
struct d_circulo
{
    float a, r;
};

void calcula(struct d_circulo *c) {

    c->a = pi * (c->r) * (c->r);
    printf("\nEl area del circulo es: %f", c->a);
    printf("\nDesea calcular nuevamente el area?(s/n)");
    fflush(stdin);
}

int main() {

    struct d_circulo circulo;
    char respuesta = 's';
    do {
        printf("Radio: ");
        scanf("%f", &circulo.r);
        calcula(&circulo);
        scanf("%s", &respuesta);
    } while(respuesta =='s');

    return 0;
}
*/


// 6)
/*
struct fecha {

    unsigned int dd;
    unsigned int mm;
    unsigned int aa;
};

void leer(unsigned int *dia) {

    printf("Introduce el dia: ");
    scanf("%u", dia);
}

int main() {

    struct fecha hoy; //hoy: Variable tipo estructura
    printf("Introduce fecha: ");
    leer(&hoy.dd);
    printf("Introduce mes y año (mm-aa): ");
    scanf("%u-%u", &hoy.mm, &hoy.aa);
    printf("\n\n Dia %u del mes %u del año %u \n", hoy.dd, hoy.mm, hoy.aa);

    return 0;
}
*/


// 7
/*
struct fecha {

    unsigned int dd;
    unsigned int mm;
    unsigned int aa;
};

int main() {

    struct fecha *hoy; // Puntero a una estructura
    //Asignacion de memoria para la estructura
    hoy = (struct fecha *) malloc(sizeof(struct fecha));
    printf("Introduce fecha (dd-mm-aa): ");
    scanf("%u-%u-%u", &hoy->dd, &hoy->mm, &hoy->aa);

    return 0;
}
*/


// 8)
/*
struct fecha {

    unsigned int dd;
    unsigned int mm;
    unsigned int aa;
};

void escribir(struct fecha *f) {

    printf("Dia %u del mes %u del año %u", f->dd, f->mm, f->aa);
}

int main() {

    struct fecha *hoy; // Puntero a una estructura
    //Asignacion de memoria para la estructura
    hoy = (struct fecha *) malloc(sizeof(struct fecha));
    printf("Introduce fecha (dd-mm-aa): ");
    scanf("%u-%u-%u", &hoy->dd, &hoy->mm, &hoy->aa);
    escribir(hoy);

    return 0;
}
*/


// 9)
/*
struct direccion {
    
    int numero_ext, num_int;
    char calle[25], colonia[25];
    char ciudad[25], estado[25];
};

struct datos {

    char nombre[20], apellidop[20], apellidom[20];
    struct direccion particular;
};

void leer_datos(struct datos *al) {

    printf("Se capturan los datos personales del alumno\n\n");
    printf("Nombre: ");
    scanf(al->nombre);
    printf("Apellido paterno: ");
    scanf(al->apellidop);
    printf("Apellido materno: ");
    scanf(al->apellidom);
    printf("\n\n Domicilio particular");
    printf("\n\tNumero externo: ");
    scanf("%d", &al->particular.numero_ext);
    printf("\n\tNumero interno: ");
    scanf("%d", &al->particular.num_int);
    fflush(stdin);
    printf("\n\tCalle: ");
    scanf(al->particular.calle);
    printf("\n\tColonia: ");
    scanf(al->particular.colonia);
    printf("\n\tCiudad: ");
    scanf(al->particular.ciudad);
    printf("\n\tEstado: ");
    scanf(al->particular.estado);
}

void imprimir_datos(struct datos *al) {

    printf("Datos personales del alumno\n");
    printf("Nombre: "); puts(al->nombre);
    printf("Apellido paterno: "); puts(al->apellidop);
    printf("Apellido materno: "); puts(al->apellidom);
    printf("\n\nDomicilio particular");
    printf("\n\tNumero externo: "); printf("%d", al->particular.numero_ext);
    printf("\n\tNumero interno: "); printf("%d", al->particular.num_int);
    printf("\n\tCalle: "); puts(al->particular.calle);
    printf("\n\tColonia: "); puts(al->particular.colonia);
    printf("\n\tCiudad: "); puts(al->particular.ciudad);
    printf("\n\tEstado: "); puts(al->particular.estado);
}

void main() {

    struct datos alumno;
    system("cls");
    leer_datos(&alumno);
    imprimir_datos(&alumno);

    return 0;
}
*/



// 10)
/*
void captura(int *e, float *es, float *p) {

    printf("Edad: ");
    scanf("%d", e);
    printf("Estatura: ");
    scanf("%f", es);
    printf("Peso: ");
    scanf("%f", p);
}

void imprimir(int *e, float *es, float *p) {

    printf("\nEdad: %d", *e);
    printf("\nEstatura: %.2f", *es);
    printf("\nPeso: %.2f", *p);
}

int main() {

    int edad;
    float estatura, peso;
    printf("Programa que lee edad, estatura y peso de una persona\n");
    captura(&edad, &estatura, &peso);

    return 0;
}
*/


// 11)
/*
void main() {

    int var;
    var = 10;
    int *pt1 = &var;
    int **pt2 = &pt1;

    printf("\nvar: %d", var);
    printf("\nvar: %d", &var);
    printf("\npt1: %d", pt1);
    printf("\n*pt1: %d", *pt1);
    printf("\npt1: %d", &pt1);
    printf("\npt2: %d", pt2);
    printf("\n*pt2: %d", *pt2);
    printf("\n**pt2: %d", **pt2);
    printf("\npt2: %d", &pt2);

    //return 0;
}
*/