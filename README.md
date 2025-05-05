# 📚 Conversion de Texto a Hash

## 🔑 Resumen
Programa ligero hecho en C con el fin de convertir cadenas grandes
de texto en tablas de Hashing para posteriormente poder ser 
analizadas a gran escala. Mi intencion es poder convertir la informacion
en forma de Matriz para poder compararlas con otras cadenas de texto
y poder extraer informacion relevante.

## 🖨️ Salida
### Hashing
Implementacion inicial que toma la informacion basica de cada palabra
```
Texto de entrada: My beloved C, I love you <3. Is it possible to create a simple code in c to create a hash table of words in a given text file the table must use the word as key and store the amount of repetifions of said word
Palabra: My		        Largo: 2		Numero: 0		Indice: 0		Hash: 2804
Palabra: beloved		Largo: 7		Numero: 1		Indice: 3		Hash: 407512705
Palabra: C,		        Largo: 2		Numero: 2		Indice: 11		Hash: 407
Palabra: I		        Largo: 1		Numero: 3		Indice: 14		Hash: 41
...
Palabra: repetifions	Largo: 11		Numero: 42		Indice: 185		Hash: 824174908
Palabra: of		        Largo: 2		Numero: 43		Indice: 197		Hash: 2249
Palabra: said		    Largo: 4		Numero: 44		Indice: 200		Hash: 2098039
Palabra: word		    Largo: 4		Numero: 45		Indice: 205		Hash: 2107126
```