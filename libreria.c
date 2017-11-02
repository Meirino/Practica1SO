#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include <string.h>

int head(int n) {
	
	char buffer[1024];
	int i;

	while((i < n) && (fgets(buffer, 1024, stdin) != NULL)) {
		printf("%s", buffer);
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

        i = 0;
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

        for(j = 0; j < n; j++) {
                printf("indice %d: %s", j,lineas[j]);
                free(lineas[j]);
        }

        free(lineas);
}

int longlines(int n) {
	char **lista;
        char buffer[1024];
        int i;
        int j;

        lista = (char **) malloc(n*sizeof(char *));
        for(i = 0; i < n; i++) { /* Inicializar lista a NULL */
                lista[i] = NULL;
        }

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

        for(i = 0; i < n; i++) {
                printf("%s", lista[i]);
        }
        return 0;
}
