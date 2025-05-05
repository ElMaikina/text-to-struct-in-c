#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constantes para el metodo de Hashing
#define M 1000000009
#define P 31

/*
Resumen: Funcion que convierte un String en un Int de Hashing
Entrada: El puntero de un String
Salida: Un valor Int / Hash
*/
long long word_to_hash(const char *s) {
	// Se usa el metodo de Polynomial Rolling Hash Function
	long long hash_value = 0;
    	long long p_pow = 1;
	int len = strlen(s);

	// Recorre cada letra y la suma a la sumatoria
	for (int i = 0; i < len; i++) {
		// El caracter '!' se usa como offset ya que es 
		// el caracter con menor indice esperado
		int c = s[i] - '!' + 1;
		hash_value = (hash_value + (c * p_pow)) % M;
		p_pow = (p_pow * P) % M;
	}
	return hash_value;
}

int main(int argc, char *argv[]) {
	// Puntero de palabra a iterar
	char * input_char;

	// Numero de la palabra actual
	int word_number = 0;

	// Largo de la palabra actual
	int word_len = 0;

	// Indice de la palabra actual
	int word_index = 0;

	// Valor Hash de la palabra
	long long word_hash = 0;

	// Mostrar por pantalla
	printf("Texto de entrada: %s\n", argv[1]);
	
	// Obtener la primera palabra se obtiene separando
	// el texto hasta el primer espacio
	input_char = strtok(argv[1], " ");

	// Las siguientes palabras se obtienen de la misma manera
	while (input_char != NULL)
	{
		// Largo de la palabra actual
		word_len = strlen(input_char);

		// Valor Hash de la palabra actual
		word_hash = word_to_hash(input_char);

		// Muestra la palabra y sus detalles
		printf("Palabra: %s\t\tLargo: %d\t\tNumero: %d\t\tIndice: %d\t\tHash: %lld\n", input_char, word_len, word_number, word_index, word_hash);

		// La cantidad de caracteres antes de 
		// la palabra indicara su indice
		word_index += word_len;

		// Considera el espacio
		word_index++;

		// Toma la siguiente pantalla
		input_char = strtok(NULL, " ");

		// Aumenta el numero de la palabra
		word_number++;
	}
	return 0;
}
