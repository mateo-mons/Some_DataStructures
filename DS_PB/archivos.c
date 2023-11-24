#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// #69.1
/*
void main(void) {
    long letra[27];
    short caracter;
    long suma = 0;
    short int i;
    FILE *archivo;
    for(i = 0 ; i < 26 ; i++)
        letra[i] = 0;

    archivo = fopen("./quijote.txt", "r");
    if(archivo == NULL) {
        printf("No se ha podido abrir el archivo.\n");
        printf("Pulse una tecla para finalizar... ");
        getchar();
    }
    while((caracter = fgetc(archivo)) != EOF) {
        if(isalpha(caracter)) {
            i = (short)tolower(caracter) - (short)'a';
            if(i >= 0 && i < 26)
                letra[i]++;
        }
    }
    fclose(archivo);
    for(i = 0 ; i < 26 ; i++)
        suma += letra[i];

    for(i = 0 ; i < 26 ; i++) {
        printf("[ %c ]= %10ld\t",(char)(i+ 'A'),letra[i]);
        printf("%7.2lf\n",((float)letra[i]/suma)*100);
    }
    printf("\n\nTotal letras ... %ld",suma);
}
*/


// #69.2
/*
void main(void) {
    long letra[27];
    short caracter;
    long suma = 0;
    short int i;
    FILE *archivo;
    for(i = 0 ; i < 27 ; i++)
        letra[i] = 0;

    archivo = fopen("./quijote.txt", "r");
    if(archivo == NULL) {
        printf("No se ha podido abrir el archivo.\n");
        printf("Pulse una tecla para finalizar... ");
        getchar();
        exit(1);
    }

    while((caracter = fgetc(archivo)) != EOF) {
        if(caracter == 209 || caracter == 241)
            letra[26]++; // letras � y �
        else if(caracter == 225 || caracter == 193)
            letra['a' - 'a']++; // letras � y �
        else if(caracter == 233 || caracter == 201)
            letra['e' - 'a']++; // letras � y �
        else if(caracter == 237 || caracter == 205)
            letra['i' - 'a']++; // letras � e �
        else if(caracter == 243 || caracter == 211)
            letra['o' - 'a']++; // letras � y �
        else if(caracter == 250 || caracter == 218)
            letra['u' - 'a']++; // letras � y �
        else if(caracter == 252 || caracter == 220)
            letra['u' - 'a']++; // letras � y �
        else if(isalpha(caracter)) {
            i = (short)tolower(caracter) - (short)'a';
            if(i >= 0 && i < 26) letra[i]++;
        }
    }
    fclose(archivo);
    for(i = 0 ; i < 27 ; i++)
        suma += letra[i];

    for(i = 0 ; i < 26 ; i++) {
        printf("[ %c ]= %10ld\t",(char)(i+'A'),letra[i]);
        printf("%7.2lf%\n",((float)letra[i]/suma)*100);
    }
    printf("[ %c ] = %10ld\t", 165,letra[26]);
    printf("%7.2lf\n",((float)letra[26] / suma) * 100);
    printf("\n\nTotal letras ... %ld",suma);
}
*/

// #70

typedef struct
{
	unsigned long clave;
	char descr[50];
	double cred;
}asignatura;

short mostrar_opciones(void);
void error(void);
short anyadir(char*);
short pantalla(char*);
short impresora(char*);

int main()
{
char nombre_archivo[80];
short opcion;
short oK;

printf("Nombre del archivo de asignaturas ... ");
gets(nombre_archivo);
do
	{
	opcion = mostrar_opciones();
	switch(opcion)
		{
		case '1': oK = anyadir(nombre_archivo);
				if(oK) 
					error();
		break;
		case '2': oK = pantalla(nombre_archivo);
				if(oK) 
					error();
		break;
		case '3': oK = impresora(nombre_archivo);
				if(oK) 
					error();
		break;
		case '4': 
				exit(1);
		}
}while(1);
return 0;
}

short mostrar_opciones(void)
{
char opcion;
system("cls");
	printf("\n\n\t\tOpciones y Tareas");
	printf("\n\n\t1. A�adir nueva asignatura.");
	printf("\n\t2. Mostrar listado por pantalla.");
	printf("\n\t3. Mostrar listado en archivo.");
	printf("\n\t4. Salir del programa.");
	printf("\n\n\t\t\tElegir opcion ... ");
do 
opcion = getchar();
while(opcion <'0'&&opcion >'4');
	return opcion;
}

void error(void)
{
printf("Error en la operacion de acceso disco.\n");
printf("Pulse una tecla para terminar ... \n");
getchar();
exit(1);
}

short anyadir(char archivo[])
{
	FILE *ARCH;
	asignatura asig;
	printf("\n\n\nDATOS DE LA NUEVA ASIGNATURA.\n\n");
	printf("clave de la asignatura ... ");
	fflush(stdin);
	scanf("%lu",&asig.clave);
	printf("\nDescripcion ... ");
	fflush(stdin);
	gets(asig.descr);
	printf("\nCreditos ...... ");
	fflush(stdin);
	scanf("%lf",&asig.cred);
	ARCH = fopen(archivo,"ab");
	fwrite(&asig,sizeof(asig),1,ARCH);
	printf("\n\n\tPulsar una tecla para continuar ... ");
	getchar();
	if(ferror(ARCH)) 
		return 1;
	fclose(ARCH);
	return 0;
}

short pantalla(char archivo[])
{
FILE *ARCH;
asignatura asig;
ARCH = fopen(archivo,"a+b");
rewind(ARCH);
while(fread(&asig,sizeof(asig),1,ARCH) == 1)
{
	printf("\n\nClave ......... %lu",asig.clave);
	printf("\nDescripcion ... %s",asig.descr);
	printf("\nCreditos ...... %6.1lf",asig.cred);
}
printf("\n\n\tPulsar una tecla para continuar ... ");
getchar();
	if(ferror(ARCH)) return 1;
	fclose(ARCH);
return 0;
}

short impresora(char archivo[])
{
FILE *ARCH1, *ARCH2;
asignatura asig;
ARCH1 = fopen(archivo,"rb");
ARCH2 = fopen("impresora.txt","w");
while(fread(&asig,sizeof(asig),1,ARCH1) == 1)
{
	fprintf(ARCH2,"\n\nClave\t%lu", asig.clave);
	fprintf(ARCH2,"\nDescripcion \t%s", asig.descr);
	fprintf(ARCH2,"\nCreditos\t%6.1lf", asig.cred);
}
printf("\n\n\tPulsar una tecla para continuar ... ");
getchar();
if(ferror(ARCH1)) return 1;
	fclose(ARCH1);
	fclose(ARCH2);
return 0;
}