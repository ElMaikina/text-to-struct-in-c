# 📚 Texto a _Estructuras de Datos_ en C

## 🔥 Resumen

Serie de programas ligeros hecho en C con el fin de convertir cadenas
grandes de texto en Estructuras de Datos para posteriormente poder ser 
analizadas a gran escala. Mi intencion es poder convertir la informacion
en forma de Matriz para poder compararlas con otras cadenas de texto
y poder extraer informacion relevante.

## 🧠 Implementaciones

De momento los modelos implementados son los siguientes:

1) Tablas de Hashing
2) Arboles Binarios

### 1. Tablas de Hashing

Es sumamente pesado en memoria pero potencialmente puede dar busquedas
muy eficientes en terminos de tiempo. Para el modelo que planteo, para
cada registro en la tabla se necesitan $24$ _bytes_, en donde la tabla
completa tiene una cantidad fija de $10^9 + 9$ de filas totales para
utilizar. Haciendo los calculos, se necesitan al menos $24$ _Gigabytes_
para albergar la tabla completa sin hacer particiones y acceso al
disco.

### 2. Arboles Binarios

Esta implementacion es mucho mas ligera en terminos de memoria, sin
embargo esta sujeta a una busqueda de orden $\log_2 N$. Luego de ver
lo costoso que era una tabla de Hashing, considere el Arbol Binario
ya que el metodo para calcular los indices en el caso anterior se
podia reutilizar.

## ✈️ Rendimiento

Mediciones hechas durante la ejecucion del main en su respectiva
implementacion.

| Estructura | Tiempo | Memoria |
|---|---|---|
| Tabla de Hash | > 30 minutos | 24 _Gigabytes_ |
| Arbol Binario | 1.113 segundos | 1464 _Bytes_ |

## 👾 Instalacion

Como el programa esta hecho en C, hay que instalar algun compilador
compatible. Como solo se usan librerias estandar no es necesario
descargar librerias aparte. Mi configuracion en Windows 10 fue la
siguiente:

 * MinGW: Entorno nativo en Windows para desarrolar en C
    * GCC, stdio.h, stdlib.h, string.h, ctype.h
 * Visual Studio Code: Editor de texto
 * Windows Terminal: Ejecucion
 * Chocolatey: Instalador de paquetes

Recomiendo seguir los pasos a continuacion:

### 1. Instalar Chocolatey
Seguir el siguiente [enlace](https://chocolatey.org/install) para instalar
Chocolatey. Una vez que se hayan seguido los pasos correspondientes, hay
que reinciar el equipo.

### 2. Instalar MinGW
Haciendo uso de Chocolatey, instalamos MinGW ejecutando el sigueinte
comando desde la terminal como _administrador_:

```
choco install mingw -y
```
### 3. Instalar Make
De la misma manera, instalar Make:

```
choco install make -y
```
### 4. Listo
Una vez hecho todo esto, podemos compilar el codigo de las diferentes
implementaciones en el repositorio.