#include "hash_table.h"

/*
Resumen: Hashea un String y lo convierte en un Int
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

/*
Resumen: Pide memoria y crea una tabla de Hash vacia
        en el destino del puntero indicado
Entrada: El puntero de una tabla de Hash
Salida: Nada
*/
void create_HT(HashTable *ht) {
    ht = malloc(sizeof(HashTable));
    ht->rows = malloc(sizeof(HashEntry) * M);
    /*
    for (long long i = 0; i < M; i++) {
        ht->rows[i].word = NULL;
        ht->rows[i].indices = NULL;
        ht->rows[i].n_of_occur = 0;
        ht->rows[i].length = 0;
        ht->rows[i].hash = 0;
    }*/
}

/*
Resumen: Libera la memoria de una tabla de Hash en
        el destino del puntero indicado
Entrada: El puntero de una tabla de Hash
Salida: Nada
*/
void delete_HT(HashTable *ht) {
    free(ht);
}

/*
Resumen: Inserta una entrada en la tabla de Hash
        si hay colisiones esta entrada nueva se
        omite
Entrada: El puntero de una tabla de Hash
Salida: Nada
*/
void insert_HT(HashTable *ht, HashEntry *e) {
    // Indice de la nueva fila a insertar
    long long i = e->hash;

    // Si la fila no existe se usa la entrada directamente
    if (ht->rows[i].word == NULL) {
        ht->rows[i] = *e;
        return;
    }

    // Si la fila existe, habra que ver si son la
    // palabra a insertar
    int diff = strcmp(ht->rows[i].word, e->word);

    // Misma palabra
    if (!diff) {
        int old_len = ht->rows[i].n_of_occur;
        int new_len = old_len + 1;
        int *new_ind;
        new_ind = malloc(sizeof(int) * new_len);
        for (int l = 0; l < old_len; l++) {
            new_ind[l] = ht->rows[i].indices[l];
        }
        new_ind[new_len] = e->indices[0];
        ht->rows[i].indices = new_ind;
        ht->rows[i].n_of_occur = new_len;
        return;
    }

    // Diferente palabra
    else {
        free(e);
        return;
    }
}

/*
Resumen: Imprime por pantalla la tabla de Hash
Entrada: El puntero de una tabla de Hash
Salida: Nada
*/
void print_HT(HashTable *ht) {
    for (long long i = 0; i < M; i++) {
        // String de la palabra
        char *w;
        strcpy(w, ht->rows[i].word);
        
        // Numero de ocurrencias
        int o = ht->rows[i].n_of_occur;

        // Arreglo con los indices
        int *in;
        in = malloc(sizeof(int) * o);
        for (int l = 0; l < o; l++) {
            in[l] = ht->rows[i].indices[l];
        }

        // Largo de la palabra
        int l = ht->rows[i].length;

        // Hash de la palabra
        long long h = ht->rows[i].hash;

        // Muestra por pantalla
        printf("Palabra: %s, Largo: %d, Numero: %d, Indice: %d, Hash: %lld\n", w, l, o, i, h);
    }
}
