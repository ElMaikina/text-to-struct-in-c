#include "hash_table.h"

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

	// Creacion de la tabla de Hash
	HashTable *ht;
	create_HT(ht);

	// Las siguientes palabras se obtienen de la misma manera
	while (input_char != NULL)
	{
		// Largo de la palabra actual
		word_len = strlen(input_char);

		// Valor Hash de la palabra actual
		word_hash = word_to_hash(input_char);

		// Muestra la palabra y sus detalles
		printf("Palabra: %s, Largo: %d, Numero: %d, Indice: %d, Hash: %lld\n", input_char, word_len, word_number, word_index, word_hash);

		// Usa los valores para crear el registro
		HashEntry *he = malloc(sizeof(HashEntry));

		/*
		strcpy(he->word, input_char);
		printf("Palabra copiada: %s", he->word);
		he->indices = malloc(sizeof(int));
		he->indices[0] = word_index;
		he->length = word_len;
		he->n_of_occur = word_number;
		he->hash = word_hash;
		*/

		// La inserta en la tabla de Hash
		insert_HT(ht, he);

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

	// Libera la tabla de Hash
	delete_HT(ht);

	return 0;
}
