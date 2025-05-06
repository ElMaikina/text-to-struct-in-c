#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constantes para el metodo de Hashing
#define M 1000000009
#define P 31

// Estructura que almacena una fila de la tabla de Hash
typedef struct {
    char *word;     // Palabra original
    int *indices;   // Indices de ocurrencia
    int length;     // Largo de la palabra
    int n_of_occur; // Numero de ocurrencias
    long long hash; // ID de Hashing
} HashEntry;

// Estructura que almacena las filas de la tabla de Hash
typedef struct {
    HashEntry *rows;
} HashTable;

long long word_to_hash(const char *s);
HashTable *create_HT();
void delete_HT(HashTable *ht);
void insert_HT(HashTable *ht, HashEntry *e);
void print_HT(HashTable *ht);