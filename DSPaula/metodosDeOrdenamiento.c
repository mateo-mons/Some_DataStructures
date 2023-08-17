/*PRACTICA METODOS DE ORDENAMIENTO Y BUSQUEDA.
El siguiente programa presenta los metodos de ordenamiento y busqueda 
para ordenar elementos en un array de N elementos enteros*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>  //libreria para setlocale
#define N 10

//PROTOTIPOS DE LAS FUNCIONES
int leer(int lista[]);
void busqueda_secuencial(int lista[]);
void busqueda_binaria(int lista[]);
void insercion(int lista[]);
void seleccion(int lista[]);
void intercambio(int lista[]);
void mostrar(int lista[]);

int main()
	{
	setlocale(LC_ALL, "");   //Funcion para incluir tildes y �, �  ...
	int lista[N], opc=0, ok=0;
	while(opc<=5)
	{
	 printf("\n****BUSQUEDA Y ORDENAMIENTO EN VECTORES****\n");
	 printf("\n1. Leer");
	 printf("\n2. Mostrar"); 
	 printf("\n3. Busqueda secuencial");
	 printf("\n4. Busqueda binaria");
	 printf("\n5. Inserci�n"); 
	 printf("\n6. Selecci�n"); 
	 printf("\n7. Intercambio"); 
	 printf("\n0. Salir");	  
	 printf("\n\nOpci�n: "); 
	 do
	  	 scanf("%d", &opc);
		while (opc<0 || opc>7);
		switch(opc)
		{
		 	case 0: opc=8;
		 	 		break;
			case 1: ok=leer(lista);
		 	 		break;
		 	case 2: mostrar(lista);
		 	 		break;	
		 	case 3: busqueda_secuencial(lista);
		 	 		break;	
			case 4: busqueda_binaria(lista);
		 	 		break;		
		 	case 5: insercion(lista);
		 	 		break;
		 	case 6: seleccion(lista);
		 	 		break;		
		 	case 7: intercambio(lista);
		 	 		break;
				  		
		}			 
	}
}	

/********************* GUARDAR *************************/

int leer(int lista[])
{
system ("cls");  //funcion para limpiar pantalla
printf("\n****INGRESE LOS VALORES PARA EL VECTOR****\n");
for (int i=0; i<N; i++)
		scanf("%d", &lista[i]);
return 1;	
}	

/********************* IMPRIMIR *************************/
		
void mostrar(int lista[])
{
system ("cls");
for (int i=0; i<N; i++)
		printf("%d ", lista[i]);
		printf("\n"); 
}		

/*********************BUSQUEDA SECUENCIAL*************************/
void busqueda_secuencial(int a[])
{
	int dato, i, encontrado;
	printf("Ingrese el n�mero que desea buscar en el vector: ");
	//leemos el dato a buscar
	scanf("%i",&dato);
	// busqueda secuencial
	i = 0 ;
	encontrado = 0 ; // marcador: toma valor cierto(1) o falso(0)
	while((i<N)&&(!encontrado))
	{
		if (a[i]==dato)
			encontrado = 1 ;
		else
		i++;
	}
// escribimos los resultados
system ("cls");
mostrar(a);
if (encontrado)
{ //a[i]==dato
	printf ("%s", "\nEl dato buscado esta en la posici�n :");
	printf ("%d", i+1);
}
else {
	printf ("%s", "\nEl dato buscado no esta en el vector");
	}
}

/*********************BUSQUEDA BINARIA*************************/
void busqueda_binaria(int a[])
{    
	//Se ordena el vector por el metodo de insercion para realizar busqueda binaria
    insercion(a);  
	int dato, dcha, medio, izq, encontrado, posicion;
	posicion=-1;
	printf("Ingrese el n�mero que desea buscar en el vector\n");
	//leemos el dato a buscar
	scanf("%i",&dato);
	//inicializamos los valores
	izq = 0; //L�mite inferior/izqda (actual) de b�squeda.
	dcha = N-1; //L�mite superior/drcha (actual) de b�squeda.
	encontrado = 0;
	medio=(izq+dcha)/2;
	//b�squeda. Se va comparando a[m] con el dato buscado.
	while ((izq<=dcha) && (!encontrado))
	{
		if (a[medio] == dato)
			{
			encontrado=1;
			posicion=medio;
			}
		else
		{
			if (a[medio] < dato)
				//Si a[medio] es menor, el nuevo extremo izdo es m+1
				izq = medio + 1;
			else
				//Si a[medio] es mayor, el nuevo extremo dcho es m-1
				dcha = medio - 1;
			medio= (izq+dcha)/2;
		}
	}
// escribimos los resultados
    system ("cls");
    mostrar(a);
	if (encontrado){
			printf ("Valor %d encontrado en �ndice %d\n", dato, posicion+1);
			}
	else
			{
				printf ("El dato %d no esta en el vector\n", dato);
			}
}

/********************* ORDENAMIENTO POR INSERCION *************************/

void insercion(int a[])
{
int aux;
// durante N-1 iteraciones
for(int i=1; i<=N-1; i++)
	{//Coge los N-i primeros elementos y los compara cada uno de ellos con el inmediatamente posterior.
	for(int j=0; j < N-i; j++)
		{
		//si est�n desordenados se intercambian usando una variable auxiliar.
			if(a[j]>a[j+1])
			{
				aux=a[j];
				a[j]=a[j+1];
				a[j+1]=aux;
			}
		}
	}
printf("\n***ORDENADO POR METODO DE INSERCION***\n"); 
mostrar(a);
}

/********************* ORDENAMIENTO POR SELECCION *************************/

void seleccion(int a[])
{
	for(int i=0;i<N-1;i++)
 	{ //en cada iteraci�n inicializamos el m�nimo al primero desordenado
		int min = a[i];
		int jmin = i;
		for(int j=i+1; j<N; j++)
		{ //comparo cada elemento con el siguiente y voy quedandome con el menor
			if (a[j] < min)
			{
				min = a[j];
				jmin = j;
			}
		}	
		//pongo el primero desordenado a[i] donde estaba el menor
		a[jmin] = a[i];
		//y el menor min donde estaba el primero desordenado
		a[i] = min;
	}
printf("\n***ORDENADO POR METODO DE SELECCION***\n"); 
mostrar(a);
}

/********************* METODO DE ORDENAMIENTO POR INTERCAMBIO ********************/

void intercambio(int a[])
{
int dato, i , j;
for (i=1; i<N; i++)
	{//N-1 iteraciones
		dato=a[i]; //Dato a colocar en la sublista ordenada de i elementos.
		j=i-1; //�ndice del �ltimo elemento de la sublista.
		while ( (j>=0) && (a[j]>dato) )
		{
			a[j+1]=a[j];
			j= j-1;	
		}
		a[j+1]=dato; //Se coloca el elemento en la posici�n correcta.
	}
printf("\n***ORDENADO POR METODO DE INTERCAMBIO***\n"); 
mostrar(a);	
}
