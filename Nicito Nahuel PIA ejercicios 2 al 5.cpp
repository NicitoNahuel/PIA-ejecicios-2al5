//2) Decir que devuelve el siguiente programa, comentar cada instrucción.
//muestra a donde
#include <stdio.h>
int main() {
	int x, *y;//declara las variables 
	x=10;//declara que x = 10
	y=&x;//guarda en y la direccion de memoria de x 
    printf("%d %d %d",y,*y,&y ); //muestra a donde apunta y (que contiene la direccion de memoria de x)
	                             //muestra a donde apunta la direccion guardada en y (x)
								 //muestra la direccion de memoria de y
	return 0;//Fin                    
}

//3) //Decir que devuelve el siguiente programa, mencionar si hay algo extraño en el mismo y comentar cada instrucción.
// pide 5 numeros y los muestra en vertical y horizontal
#include <stdio.h>
void carga (int n, int Vector[]); //declara las variables para la funcion "carga"
void imprimir (int n, int Vector[]); //declara las variables para la funcion "imprimir"
 
int main()
{
int n=5;
           	int V[n]; 
carga (n,V); //llama la funcion carga
	       	imprimir (n,V); // llama la funcion imprimir
           	printf("\n"); //deja un espacio
           	for (int i=0; i<n; i++){
    	                   	printf("%5d",V[i]); //imprime los numeros uno al lado del otro en un espacio de 5 caracteres
	       	}
	       	return 0; //Fin
}
void carga (int n, int Vector[]){ //funcion "carga" (pregunta y guarda los valores del vector)
           	 int i;
           	 for (i=0; i<n; i++){
    	                   	printf("ingrese el valor de la posicion %d: ",i);
    	                   	scanf("%d",&Vector[i]); //pregunta el valor de la posicion y lo guarda en el vector
           	  }
}
void imprimir (int n, int Vector[]){ //funcion "imprimir" (muestra los numeros uno debajo del otro)
           	 for (int i=0; i<n; i++){
  	                     	 printf("\n %5d",Vector[i]);//imprime lo que hay en el vector, dando un salto de renglon entre cada uno
	       	}
           	 printf("\n");
}
//si alguno de los numeros ingresados tiene mas de 5 caracteres se amontona al anterior numero ya que "%5d" da un lugar de 5 caracteres, se arreglaria poniendo un %c, 32
//las funciones estan antes del main en el cual se usa lo cual puede generar errores
//ademas no hay verificacion, por lo que si ingresas una letra se bugea todo

//4) Decir que devuelve el siguiente programa, mencionar si hay algo extraño en el mismo y comentar cada instrucción.
//el programa pide 5 numeros y los devuelve ordenados de mayor a menor, en vertical y horizontal
#include <stdio.h>
void carga (int n, int Vector[]); //declara la funcion "carga"
void imprimir (int n, int Vector[]); //declara la funcion "imprimir"
void ordenar (int n, int Vector[]); //declara la funcion "ordenar"
int main()
{
int n=5;
int V[n];
carga (n,V); //llama la funcion "carga"
imprimir (n,V); //llama la funcion "imprimir"
ordenar (n,V); //llama la funcion "ordenar"
imprimir (n,V); //vuelve a llamar la funcion "imprimir" con el vector ya ordenado
 
           	printf("\n");
           	for (int i=0; i<n; i++){
    	                   	printf("%5d",V[i]);
	       	}
	       	return 0;
}
void carga (int n, int Vector[]){ //funcion "carga" (pregunta y guarda los valores del vector)
           	for (int i=0; i<n; i++){
    	                   	printf("ingrese el valor de la posicion %d: ",i);
    	                   	scanf("%d",&Vector[i]);
           	  }
}
void imprimir (int n, int Vector[]){ //funcion "imprimir" (muestra los numeros del vector uno debajo del otro)
           	for (int i=0; i<n; i++){
  	                     	 printf("\n %5d",Vector[i]);
	       	}
           	 printf("\n");
}
void ordenar (int n, int Vector[]){ //funcion "ordenar" (ordena los numeros del mayor al menor)
           	int aux; //declara un aux para poder mover los numeros
           	for (int i=0; i<n; i++){ //for de i para hacerlo con cada numero
           	    for (int j=0; j<n; j++){ 
           	        if (Vector[i]>Vector[j]){ //compara si "i" es mayor que j, si lo es:
           	           aux=Vector[i]; //guarda el valor de "vector[i]" en "aux"
           	           Vector[i]=Vector[j]; //guarda el valor "vector[j]" en "vector[i]"
           	           Vector[j]=aux; //guarda el valor de aux en "vector[j]" (basicamente intercambio el valor de "vector[i]" a por el de "vector[j]")
           	        }   //se podria usar una comparacion de i-1 en vez de j
           	        	//las funciones estan antes del main en el cual se usa lo cual puede generar errores
           	        	//si alguno de los numeros ingresados tiene mas de 5 caracteres se amontona al anterior numero ya que "%5d" da un lugar de 5 caracteres, se arreglaria poniendo un %c, 32
						//ademas no hay verificacion, por lo que si ingresas una letra se bugea
 	      	}
           	}
           	 printf("\n");
}

//5 Decir que devuelve el siguiente programa, mencionar si hay algo extraño en el mismo y comentar cada instrucción.
#define N 10
#include <stdio.h>
//el programa multiplica dos matrices A x B
void leer_matriz(int A[N][N], int filas, int columnas); //declara para la funcion "leer matriz"
void escribir_matriz(int A[N][N], int filas, int columnas); //declara para la funcion "escribir matriz"
void multiplicar(int A[N][N], int B[N][N], int C[N][N], int m, int n, int p); //declara para la funcion "multiplicar"
int main ()  { //main
 int m, n, p; 
 int A[N][N], B[N][N], C[N][N];
           	printf("\n Datos de la Matriz A: \n"); 
printf("Filas: ");                           	scanf("%d", &m); 
           	printf("Columnas: "); 	scanf("%d", &n);           //pregunta el tamaño de la matriz A (esto se podria hacer dentro de la funcion leer matriz)
leer_matriz(A, m, n); 
           	printf("\n Datos de la Matriz B: \n");            //pregunta los datos de la matriz B
printf("Columnas: ");	          	scanf("%d", &p);   //pregunta solo las columnas porque para poder multiplicar matrices: la cantidad de columnas de A deben ser igual a la cantidad de filas de B
leer_matriz(B, n, p); //llama a la funcion "leer matriz"
printf("\n Matriz A:\n");  escribir_matriz(A, m, n); // muestra la matriz A con la funcion "escribir matriz"
    	printf("\n Matriz B: \n");  escribir_matriz(B, n, p); // muestra la matriz B con la funcion "escribir matriz"
    	multiplicar(A, B, C, m, n, p); //Llama a la funcion "multiplicar" que multiplica las matrices A y B y las guarda en C
    	printf("\n Matriz AxB: \n");   escribir_matriz(C, m, p); //usa la funcion "escribir matriz" para mostrar el resultado, almacenado en C
}
void leer_matriz(int A[N][N], int filas, int columnas) { //declara la funcion y sus variables
           	int i, j;
 for (i=0; i<filas; i++)  {
                           	for (j=0; j<columnas; j++)  {
                                           	printf("Ingresa la entrada [%d][%d]: ", i+1, j+1);  //pide todos los datos de la matriz 
                                           	scanf("%d", &A[i][j]);
                           	}
           	}
}
void escribir_matriz(int A[N][N], int filas, int columnas)
{
 int i, j;
 for (i=0; i< filas; i++)  {
                           	for (j=0; j<columnas; j++)   {
                                           	printf("\t%d", A[i][j]); //Imprime todos los elementos de la matriz
                           	 }
                           	printf("\n");
 }
}
void multiplicar (int A[N][N], int B[N][N], int C[N][N], int m, int n, int p) {
           	int i, j, k;
 //limpiar o inicializar matriz C
           	for(i=0; i< m; i++) 
                           	for(k=0; k< p; k++)
                                           	C[i][k]=0; //se "crea" la matriz C llenandola de 0, esta tiene la cantidad de filas de A y la cantidad de Columnas de B
  
                           	for (i=0; i< m; i++)
                                           	for (j=0; j< n; j++)
                                                          	 for (k=0; k< p; k++)
                                                                          	 C[i][k] = C[i][k] + A[i][j]*B[j][k]; //se multiplica la matriz A por B y se guarda en C
}

