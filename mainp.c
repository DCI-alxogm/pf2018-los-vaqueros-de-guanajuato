#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
float m0, b0, mn, bn, sigmam, sigmab;
int i,delta,n;
FILE*datos;
scanf("f", &m0);
scanf("f", &b0);
scanf("i", &delta);
scanf("f", &sigmam);
scanf("f", &sigmab);
printf("cuantos datos tiene su archivo de lectura?");
scanf("i",n);
float *xobs, *yobs;
xobs=(float*)malloc(10*sizeof(float));
yobs=(float*)malloc(10*sizeof(float));
datos = fopen("datos","r");
for (i=0;i<n;i++){
	fscanf(datos, "f", &xobs[i]);
	fscanf(datos, "f", &yobs[i]);
		}

}
