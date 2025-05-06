#include "binary_tree.h"

int main(int argc, char *argv[]) {
    // Raiz de nuestro arbol de palabras
    Word *root = NULL;

    // Toma texto por entrada estandar
    char *text;

    // Separa el texto por espacios
    text = strtok(argv[1], " ");

    // Cuenta la cantidad de palabras
    int size = sizeof(text) / sizeof(text[0]);

    // Cantidad de inserciones
    int index = 0;

    // Insertar palabras con sus posiciones
    while (text != NULL) {
        root = insert_word(root, text, index);
        text = strtok(NULL, " ");
        index++;
    }

    printf("Arbol ordenado despues de inserciones:\n");
    print_tree(root);

    // Eliminar una palabra
    printf("Eliminando la palabra \"datos\"...\n");
    root = delete_word(root, "datos");

    printf("Arbol despues de eliminar \"datos\":\n");
    print_tree(root);

    // Liberar memoria
    delete_tree(root);
    return 0;
}