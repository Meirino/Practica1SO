#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libreria.h>

char *strdup(const char *str);

int head(int n) {
	
	char buffer[1024];
	int i = 0;

	/* Mientras no se alcance el límite de palabras, o no se lea un caracter nulo por la entrada estandar, mostrar la entrada */

	while((i < n) && (fgets(buffer, 1024, stdin) != NULL)) {
		printf("%d - %s", i+1, buffer);
		i++;
	}

	return 0;
}

int tail(int n) {
	int i;
	int j;
        int aux;
        char ** lineas;
        char buffer[1024];

        lineas = (char **) malloc(n*sizeof(char*));
	
	/* Si la memoria estuviese llena, cesa la ejecución */
	if(lineas == NULL) return 1;

        i = 0;

	/* Mientras no se lea un caracter nulo por la entrada estandar
	 * si el "array" esta lleno, entonces se desplaza todas las posiciones a la izquierda y se añade por el final
	 * si no, solo se añade en orden */

        while(fgets(buffer, 1024, stdin) != NULL) {
                if(i >= n) {
                        for(aux = 1; aux < n; aux++) {
                                lineas[aux-1] = lineas[aux];
                        }
                        lineas[n-1] = strdup(buffer);
                } else {
                        lineas[i] = strdup(buffer);
                }
                i++;
        }

	/* Escribo y libero memoria */

        for(j = 0; j < n; j++) {
                if(lineas[j] != NULL) printf("%d - %s", j+1, lineas[j]);
                free(lineas[j]);
        }

        free(lineas);
	return 0;
}

int longlines(int n) {
	char **lista;
        char buffer[1024];
        int i;
        int j;

        lista = (char **) malloc(n*sizeof(char *));

	/* Si la memoria estuviese llena, cesa la ejecución */
	if(lista == NULL) return 1;

	/* Inicializar la lista a NULL para evitar posibles valores basura */

        for(i = 0; i < n; i++) {
                lista[i] = NULL;
        }

	/* Mientras no se lea un caracter nulo por la entrada estandar 
	 * recorro con while toda la lista, y si la posicion actual esta vacia o su contenido es menor a lo leido
	 * entonces muevo el contenido a la derecha e inserto  */

        while(fgets(buffer, 1024, stdin) != NULL) {
                i = 0;
                while(i < n) {
                        if (lista[i] == NULL || strlen(lista[i]) <= strlen(buffer)) {
                                for(j = n; j >= i; j--) {
                                        lista[j] = lista[j-1];
                                }
                                lista[i] = strdup(buffer);
                                i = n;
                        }
                i++;
                }
        }

	/* Escribo y libero memoria */

        for(i = 0; i < n; i++) {
		if(lista[i] != NULL) printf("%d - %s", i+1, lista[i]);
		free(lista[i]);
        }

        return 0;
}

/* Redefino strdup para evitar problemas de compatibilidad de usar funciones POSIX con el estandar ANSI C */

char *strdup(const char *str) {
	char *d = malloc((strlen(str) * sizeof(char)) + 1);
	if (d == NULL) return NULL;
	strcpy(d, str);
	return d;
}
