#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include "perce.h"
//calcula e likelihood en base a parametros leidos de "datos" contra una pendiente y puntos dados
float percentx(float m0,float b0){
	int i,j,n=10; 
//lectura de datos y almacenamiento en arreglos
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
//calculo de likelihoo por metodo metropolis ne base a datos anteriores
	for (i=0;i<10;i++){

	result[i]= yobs[i]-(xobs[i]*(m0))+b0;
	result[i]= pow(result[i],2)-(sigmam[i]*sigmam[i]);
	suma+=result[i];
	}
	suma*=-0.5;
//ñogaritmos de likelihood
	res2= pow(2.718282,suma);
	return res2;
}
//identica a la anterior exepto por el paso marcado
float percenty(float m0,float b0){
	int i,j,n=10; 
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
//omite el logaritmo que se usa en la funcion anterior
	res2= suma;
	return res2;
}

