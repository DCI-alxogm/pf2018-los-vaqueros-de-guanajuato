#makefile del prorama, pone make ne consola para compilar
mainp: func.c mainp.c libs
	
	gcc func.c mainp.c -o mainp.out -lm -I ./libs
	
clean:
	rm mainp.out
