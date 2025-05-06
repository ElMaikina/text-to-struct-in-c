#include "binary_tree.h"

long long text_to_hash(const char *s) {
    long long hash = 0;
    long long p_pow = 1;

    for (int i = 0; s[i] != '\0'; i++) {
        hash = (hash + (s[i] - '!' + 1) * p_pow) % M;
        p_pow = (p_pow * P) % M;
    }
    return hash;
}
// --- TREE FUNCTIONS ---

// Crea un nuevo nodo Word
Word* create_word_node(const char *text, int index) {
    Word *new_node = (Word*)malloc(sizeof(Word));
    new_node->length = strlen(text);
    new_node->word = strdup(text);
    new_node->indices = (int*)malloc(sizeof(int));
    new_node->indices[0] = index;
    new_node->n_of_occur = 1;
    new_node->hash = text_to_hash(text);
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Agrega una palabra al árbol, o actualiza si ya existe
Word* insert_word(Word *root, const char *text, int index) {
    long long h = text_to_hash(text);

    if (root == NULL) {
        return create_word_node(text, index);
    }

    if (h == root->hash && strcmp(text, root->word) == 0) {
        // Palabra ya existe, agregar índice
        root->indices = realloc(root->indices, sizeof(int) * (root->n_of_occur + 1));
        root->indices[root->n_of_occur++] = index;
        return root;
    } else if (h < root->hash) {
        root->left = insert_word(root->left, text, index);
    } else {
        root->right = insert_word(root->right, text, index);
    }

    return root;
}

// Encuentra el nodo mínimo (usado para borrar)
Word* find_min(Word *node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

// Borra una palabra específica del árbol
Word* delete_word(Word *root, const char *text) {
    if (!root) return NULL;

    long long h = text_to_hash(text);

    if (h < root->hash) {
        root->left = delete_word(root->left, text);
    } else if (h > root->hash) {
        root->right = delete_word(root->right, text);
    } else if (strcmp(root->word, text) == 0) {
        // Nodo encontrado
        if (!root->left) {
            Word *temp = root->right;
            free(root->word);
            free(root->indices);
            free(root);
            return temp;
        } else if (!root->right) {
            Word *temp = root->left;
            free(root->word);
            free(root->indices);
            free(root);
            return temp;
        } else {
            Word *temp = find_min(root->right);
            free(root->word);
            free(root->indices);
            root->word = strdup(temp->word);
            root->length = temp->length;
            root->n_of_occur = temp->n_of_occur;
            root->indices = malloc(sizeof(int) * temp->n_of_occur);
            memcpy(root->indices, temp->indices, sizeof(int) * temp->n_of_occur);
            root->hash = temp->hash;
            root->right = delete_word(root->right, temp->word);
        }
    }
    return root;
}

// Borra todo el árbol
void delete_tree(Word *root) {
    if (!root) return;
    delete_tree(root->left);
    delete_tree(root->right);
    free(root->word);
    free(root->indices);
    free(root);
}

// (Opcional) Imprimir el árbol en orden (útil para debug)
void print_tree(Word *root) {
    if (!root) return;
    print_tree(root->left);
    printf("Palabra: \"%s\":", root->word);
    printf(", Ocurrencias: %d", root->n_of_occur);
    printf(", Hash: %lld", root->hash);
    printf(", Indices: [");
    for (int i = 0; i < root->n_of_occur; i++) {
        printf("%d", root->indices[i]);
        if (i < root->n_of_occur - 1) {
            printf(",");
        }
    } printf("]\n");
    print_tree(root->right);
}