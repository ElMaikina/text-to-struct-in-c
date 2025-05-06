#include "hash_table.h"

int main(int argc, char *argv[]) {
	// Puntero de palabra a iterar
	char * input_char;

	// Numero de la palabra actual
	int number = 0;

	// Largo de la palabra actual
	int length = 0;

	// Indice de la palabra actual
	int index = 0;

	// Valor Hash de la palabra
	long long hash = 0;
	
	// Obtener la primera palabra se obtiene separando
	// el texto hasta el primer espacio
	input_char = strtok(argv[1], " ");

	// Creacion de la tabla de Hash
	HashTable *hash_table = create_HT();

	// Las siguientes palabras se obtienen de la misma manera
	while (input_char != NULL)
	{
		// Largo de la palabra actual
		length = strlen(input_char);

		// Valor Hash de la palabra actual
		hash = word_to_hash(input_char);

		HashEntry entry;
        entry.word = strdup(input_char);
        entry.length = strlen(input_char);
        entry.hash = word_to_hash(input_char);
        int *single_index = malloc(sizeof(int));
        single_index[0] = index;
        entry.indices = single_index;
        entry.n_of_occur = 1;
        insert_HT(hash_table, &entry);
        free(single_index);

		// Muestra la palabra y sus detalles
		printf("Palabra: \"%s\", Largo: %d, Numero: %d, Indice: %d, Hash: %lld\n", input_char, length, number, index, hash);

		// La cantidad de caracteres antes de 
		// la palabra indicara su indice
		index += length;

		// Considera el espacio
		index++;

		// Toma la siguiente pantalla
		input_char = strtok(NULL, " ");

		// Aumenta el numero de la palabra
		number++;
	}

	// Libera la tabla de Hash
	delete_HT(hash_table);

	return 0;
}
