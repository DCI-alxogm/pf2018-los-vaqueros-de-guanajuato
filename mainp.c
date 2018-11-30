#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int i;
float percentx(float *yobs,float *xobs,float m0,float b0);
int main()
{
float m0, b0, mn, bn, px0, pxn;
int delta,n=10, sigmam, sigmab;
FILE*datos;
printf("Ingrese el valor de la pendiente y el valor de las ordenadas iniciales\n");
scanf("%f", &m0);
scanf("%f", &b0);
printf("Ingrese el número de veces que quiere que el programa se ejecute\n");
scanf("%i", &delta);
printf("Ingrese el error de la pendiente y el error de las ordenadas iniciales\n");
scanf("%i", &sigmam);
scanf("%i", &sigmab);
float *xobs, *yobs;
xobs=(float*)malloc(10*sizeof(float));
yobs=(float*)malloc(10*sizeof(float));
datos = fopen("datos","r");
for (i=0;i<n;i++){
	fscanf(datos, "%f", &xobs[i]);
	fscanf(datos, "%f", &yobs[i]);
		}
mn=m0 +rand() % (sigmam*2)+1-(sigmam)+1;
bn=b0 +rand() % (sigmab*2)+1-(sigmab)+1;

for (i=0;i<delta;i++){
	px0=percentx(yobs,xobs,m0,b0);
	pxn=percentx(yobs,xobs,mn,bn);
	if(px0>pxn){
			printf("%.30f\n",px0);
			}
	else{
	 printf("%.30f\n",pxn);
	}
}


return 0;
}
float percentx(float *yobs,float *xobs,float m0,float b0){
	float result[10], suma=0, res2;
	for (i=0;i<10;i++){

	result[i]= *yobs-(*xobs*(m0)+b0);
	suma+=result[i];
	}
	suma*=-0.5;
	res2= pow(2.71828,suma);
	return res2;
}
