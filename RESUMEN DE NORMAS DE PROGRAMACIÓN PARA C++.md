# RESUMEN DE NORMAS DE PROGRAMACIÓN PARA C++.
## Estructura de programas.
Aislar el código de la función principal en un solo fichero y organizar el resto de
funciones/clases en otros ficheros. La organización en distintos ficheros responderá a una agrupación funcional. Para cada agrupación funcional se establecerá un fichero de cabecera que puede servir de enlace para uno o varios ficheros de código en caso de que un solo fichero de código sea excesivamente grande y que exista la posibilidad de diferenciar operaciones según alguna característica. En C++ se utilizará un fichero de cabecera y un fichero de código específico para cada una de las clases definidas.

### Ejemplo: programa que opera con números complejos y con matrices.
Una estructura posible sería la siguiente:

* Principal.c : Fichero que contiene el main
* Matrices.cpp : Fichero con la implementación de la clase matriz.
* Matrices.h : Fichero de definición de la clase matriz
* Complejos.cpp : Fichero con la implementación de la clase complejo.
* Complejos.h : Fichero de definición de la clase complejo.


## Variables globales.
Su uso queda restringido a la transmisión de estados, comunicación de errores o al ahorro de memoria, nunca debe servir como medio de comunicación entre funciones o instancias.

## Estructura interna de los archivos en C++.

### Estructura de un archivo de código fuente en C++.
1. Cajetín archivo fuente (Se explica en el apartado de comentarios).
2. Inclusión de los archivos de encabezamiento de las bibliotecas standard ('#include')
3. Archivos de encabezamiento de otras bibliotecas usadas.
4. Archivos de encabezamiento del propio del proyecto.
5. Constantes definidas exclusivamente para este archivo en orden alfabético (#define).
6. Macros definidas exclusivamente para este archivo en orden alfabético.
7. Inicialización de las variables estáticas de la clase.
8. Implementación de los métodos inline no definidos en el fichero de cabecera.
9. Implementación de los métodos de la clase. Cada método estará precedido de un cajetín con información sobre ella (Se explica en el apartado de comentarios).
10. Implementación de las funciones amigas de la clase.

### Estructura de un archivo de cabecera en C++.
1. Cajetín del archivo de encabezamiento.
2. Directivas de exclusividad (explicado a continuación)
3. Archivos de encabezamiento standard.
4. Archivos de encabezamiento de otras bibliotecas.
5. Archivos de encabezamiento de este proyecto.
6. Definición de constantes .
7. Definición de estructuras.
8. Definición de Macros.
9. Variables externas (si no se han incluido en otro archivo de encabezamiento)
10. Definición de la clase.
11. `#endif` necesario para cerrar el punto 2.

## Identificadores

### Tipos definidos por el usuario: clases, estructuras, enumeraciones.
* Comenzarán con letra mayúscula.
* Si están formados por varias palabras, la primera letra de cada palabra se
pondrá en mayúsculas.
* No se utilizarán números ni _.
* Se tenderá a utilizar sustantivos y adjetivos.
* Ejemplos: MatrizAvanzada, Complejo, DialogoCalculadora.

### Variables o atributos.
* Comenzarán con letra minúscula.
* Si están formados por varias palabras, la primera letra de cada palabra se
pondrá en mayúsculas excepto la primera.
* Los identificadores de una letra, normalmente i,j,k,l, están reservados para
contadores. El resto de identificadores se recomienda que sean más
extensos.
* No se utilizarán números ni ‘_’.
* Se tenderá a utilizar sustantivos y adjetivos.
* Ejemplos: estadoPrograma, minimo, maximo, colorFrontal, valorMax.

### Macros y constantes.
* Se escribirán enteramente en mayúsculas
* Si están formadas por varias palabras, estas se separarán por medio de ‘_’
* Las macros tendrán los argumentos y el resultado con paréntesis en la evaluación de la
expresión.
* Ejemplo: #define CUADRADO(x) ((x)*(x)) #define DIMENSION_MAX 10

### Funciones y metodos.
* Comenzarán con letra minúscula.
* Si están formados por varias palabras, la primera letra de cada palabra se
pondrá en mayúsculas.
* No se utilizarán números ni ‘_’.
* Se tenderá a utilizar la estructura verbo-sustantivo.
* Las funciones de interfaz de atributos de una clase utilizarán la notación
inglesa get y set.
* Se utilizarán identificadores de los argumentos en los prototipos que
faciliten la identificación del parámetro.
* Ejemplos: getColor, imprimirMatriz, calcularSolucion, etc.

## Otras normas.
* Después de cada signo de puntuación, "," o ";" se debe dejar un espacio.
* Al escribir un comentario debe dejarse un espacio entre el * de apertura y el texto, y otro entre el texto y el * de cierre.
```
/* Esto es un comentario. */
// Esto es un comentario
```
* No debe dejarse un espacio después de abrir un paréntesis ni antes de cerrarlo.
* Delimitacion de bloques: las llaves "{" que abren el cuerpo de un bucle, se situarán debajo de la sentencia y con un sangrado adicional. La llave que cierra el bloque se situará en la línea siguiente a la última línea del bloque y con un nivel de sangrado igual al de las sentencias que encierra.
```
if(valor==5)
  {
  printf(“Correcto”);
  valor=valor*10;
  }
```
* Debe haber una línea blanca entre la definición de variables locales y el cuerpo de un procedimiento.
* El código del procedimiento debe comenzar a escribirse al mismo nivel de sangrado que la llave de
apertura, que se escribirá al mismo nivel de sangrado que el nombre del procedimiento.
* Se recomienda usar secciones en el código de un procedimiento, para separar partes de un
procedimiento que realicen labores distintas. La primera línea de cada sección debería ser un comentario explicando el por qué de esa sección.
