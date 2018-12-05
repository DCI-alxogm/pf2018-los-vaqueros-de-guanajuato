#makefile del prorama, se escribe "make" en consola y se compilan los programas y archivos que son parte del mismo
mainp: func.c mainp.c libs
	
	gcc func.c mainp.c -o mainp.out -lm -I ./libs
	
clean:
	rm mainp.out
