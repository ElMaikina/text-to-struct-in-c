#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constantes para el metodo de Hashing
#define M 1000000009
#define P 31

typedef struct Word {
    char *word;
    int *indices;
    int length;
    int n_of_occur;
    long long hash;
    struct Word *left;
    struct Word *right;
} Word;

long long text_to_hash(const char *s);
Word* create_word_node(const char *text, int index);
Word* insert_word(Word *root, const char *text, int index);
Word* find_min(Word *node);
Word* delete_word(Word *root, const char *text);
void delete_tree(Word *root);
void print_tree(Word *root);