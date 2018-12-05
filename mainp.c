#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include "perce.h"
// se llman las librerias usadas y la libreria creada: "perce.h"

int main() { //declaracion de variables, siendo la pendiente, la interseccion en y
	float m0, b0, mn, bn; 
	double px0, pxn=0, pxn2=0, px02, ale;
	int delta;
	int i,j,n=10; 
	
	FILE*resultados; 
//ingreso de datos variables por le usuario
	printf("Ingrese el valor de la pendiente y el valor de las ordenadas iniciales\n"); 
	scanf("%f",&m0); 
	scanf("%f", &b0); 
	printf("Ingrese el número deveces que quiere que el programa seejecute\n");
	scanf("%i", &delta);


	
	
	//apertura del acrhivo de resultados
	resultados=fopen("resultados","w"); 

		
		// se ejectuc la evaluacion de datos "delta" veces
		
		for(j=0;j<delta;j++){
		

			//genera numeros aleatoriso en un rango datos como nuevas pendientes se incluyen lines como comentarios para evaluar cada paso			
			mn=m0-(1)+(2)*(rand()/(double)RAND_MAX);
			bn=b0-(1)+(2)*(rand()/(double)RAND_MAX);
			//printf("%f %f\n",mn,bn);
			//uso de funciones de likelihood
			px0=percentx(m0,b0);
			pxn=percentx(mn,bn);
			//px02=percenty(m0,b0);
			pxn2=percenty(mn,bn);
			//printf("%.30f %.30f\n",px02 ,pxn2);			
			//se evalua la primera condicion del sistema metropolis al comparar 2 likelihoods.			
			if(px0<pxn){
				//printf("%.30f\n",pxn);
			m0=mn;
			b0=bn;
			//fprintf(resultados,"%f %f \n", m0, b0);
			}
				
			//en caso de que lo anterior sea falso se evalua la segunda condicion con un nuevo valor aleatorio
			else{
				//printf("%.30f\n",px0);
				ale= rand()/(double)RAND_MAX;
				if (ale<pxn2){ 
				m0=mn; 
				b0=bn;
				//fprintf(resultados,"%f %f \n", m0, b0);
				}
			//si ningun caso se cumple no se sustituyen los valores anteriores y se imprimen de nuevo.
			}
			//se imprimen resultados del proces o anterios
			fprintf(resultados,"%f %f \n", m0, b0); 
			
		
		}
		
fclose(resultados);
return 0;
}

