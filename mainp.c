#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 

int i,j,n=10; 
float percentx(float m0,float b0); 
float percenty(float m0,float b0); 

int main() { 
	float m0, b0, mn, bn; 
	double px0, pxn=0, pxn2=0, px02, ale;
	int delta;

	FILE*resultados; 

	printf("Ingrese el valor de la pendiente y el valor de las ordenadas iniciales\n"); 
	scanf("%f",&m0); 
	scanf("%f", &b0); 
	printf("Ingrese el número deveces que quiere que el programa seejecute\n");
	scanf("%i", &delta);


	
	

	resultados=fopen("resultados","w"); 

		
		
		
		for(j=0;j<delta;j++){
		

			
			mn=m0-(1)+(2)*(rand()/(double)RAND_MAX);
			bn=b0-(1)+(2)*(rand()/(double)RAND_MAX);
			//printf("%f %f\n",mn,bn);
			px0=percentx(m0,b0);
			pxn=percentx(mn,bn);
			//px02=percenty(m0,b0);
			pxn2=percenty(mn,bn);
			//printf("%.30f %.30f\n",px02 ,pxn2);			
			if(px0<pxn){
				//printf("%.30f\n",pxn);
			m0=mn;
			b0=bn;
			//fprintf(resultados,"%f %f \n", m0, b0);
			}
				

			else{
				//printf("%.30f\n",px0);
				ale= rand()/(double)RAND_MAX;
				if (ale<pxn2){ 
				m0=mn; 
				b0=bn;
				//fprintf(resultados,"%f %f \n", m0, b0);
				}
			}

			fprintf(resultados,"%f %f \n", m0, b0); 
			
		
		}
		
fclose(resultados);
return 0;
}
float percentx(float m0,float b0){
	FILE*datos; 
	float result[10], suma=0, res2;
	float *xobs, *yobs, *sigmam, *sigmab;
	xobs=(float*)malloc(10*sizeof(float));
	yobs=(float*)malloc(10*sizeof(float)); 
	sigmam=(float*)malloc(10*sizeof(float));
	sigmab=(float*)malloc(10*sizeof(float));
	
	datos = fopen("datos","r");
	 
		for (i=0;i<n;i++){ 

			fscanf(datos,"%f", &xobs[i]); 
			fscanf(datos,"%f", &yobs[i]); 	
			fscanf(datos,"%f", &sigmam[i]); 	   
			fscanf(datos,"%f", &sigmab[i]); 

		} 

	fclose(datos); 
	for (i=0;i<10;i++){

	result[i]= yobs[i]-(xobs[i]*(m0))+b0;
	result[i]= pow(result[i],2)-(sigmam[i]*sigmam[i]);
	suma+=result[i];
	}
	suma*=-0.5;
	res2= pow(2.718282,suma);
	return res2;
}
float percenty(float m0,float b0){
	FILE*datos; 
	float result[10], suma=0, res2;
	float *xobs, *yobs, *sigmam, *sigmab;
	xobs=(float*)malloc(10*sizeof(float));
	yobs=(float*)malloc(10*sizeof(float)); 
	sigmam=(float*)malloc(10*sizeof(float));
	sigmab=(float*)malloc(10*sizeof(float));
	
	datos = fopen("datos","r");
	 
		for (i=0;i<n;i++){ 

			fscanf(datos,"%f", &xobs[i]); 
			fscanf(datos,"%f", &yobs[i]); 	
			fscanf(datos,"%f", &sigmam[i]); 	   
			fscanf(datos,"%f", &sigmab[i]); 

		} 

	fclose(datos); 
	for (i=0;i<10;i++){

	result[i]= yobs[i]-(xobs[i]*(m0)+b0);
	result[i]= pow(result[i],2)-(sigmam[i]*sigmam[i]);
	suma+=result[i];
	}
	suma*=-0.5;
	res2= suma;
	return res2;
}

