#include <stdio.h>
#include <libreria.h>

int main() {

	char opcion;
	int n;

	while(opcion != 'q') {
		puts("Escriba la función a ejecutar:\n h - Head\n t - Tail\n l- Longest");
		scanf(" %c", &opcion);

		switch(opcion) {
			case 'h':
				puts("Escriba el número de líneas a leer: ");
				scanf(" %d",&n);
				head(n);
				break;
			case 't': 
                                puts("Escriba el número de líneas a leer: ");
                                scanf(" %d", &n);
                                tail(n);
                                break;
			case 'l': 
                                puts("Escriba el número de líneas a escribir: ");
                                scanf(" %d", &n);
                                longest(n);
                                break;
			case 'q':
				break; 
		}
	}
	
	return 0;
}
