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
        que luego en su salida devuele por puntero
Entrada: Nada
Salida: Un puntero a una tabla de Hash
*/
HashTable *create_HT() {    
    HashTable *ht = malloc(sizeof(HashTable));
    
    if (!ht) {
        return NULL;
    }
    ht->rows = calloc(M, sizeof(HashEntry)); 
    if (!ht->rows) {
        free(ht);
        return NULL;
    }
    for (long long i = 0; i < M; i++) {
        ht->rows[i].word = NULL;
        ht->rows[i].indices = NULL;
        ht->rows[i].length = 0;
        ht->rows[i].n_of_occur = 0;
        ht->rows[i].hash = 0;
    }
    return ht;
}

/*
Resumen: Libera la memoria de una tabla de Hash en
        el destino del puntero indicado
Entrada: El puntero de una tabla de Hash
Salida: Nada
*/
void delete_HT(HashTable *ht) {
    for (long long i = 0; i < M; i++) {
        if (ht->rows[i].word != NULL) {
            free(ht->rows[i].word);
            free(ht->rows[i].indices);
        }
    }
    free(ht->rows);
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
    long long i = e->hash;
    if (ht->rows[i].word != NULL) {
        if (strcmp(ht->rows[i].word, e->word) == 0) {
            ht->rows[i].indices = realloc(ht->rows[i].indices, sizeof(int) * (ht->rows[i].n_of_occur + 1));
            ht->rows[i].indices[ht->rows[i].n_of_occur++] = e->indices[0];
            return;
        }
    }
    // New entry
    ht->rows[i].word = strdup(e->word);
    ht->rows[i].length = e->length;
    ht->rows[i].n_of_occur = 1;
    ht->rows[i].indices = malloc(sizeof(int));
    ht->rows[i].indices[0] = e->indices[0];
    ht->rows[i].hash = e->hash;
    return;
}
