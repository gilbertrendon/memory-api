# Memory API # 

En este laboratorio ganará algún grado de familiaridad con la asignación de memoria (memory allocation). Para el caso, ustedd escribirá algunos programas con bugs. Luego, usará algunas herramientas para localizar los bugs que usted ha insertado. De este modo se familiarizará con algunas de estas herramientas para un uso futuro. Estas herramientas son: el debuger (**gdb**) y el memory-bug detector (**valgrind**).

## Questions ##

1. Escriba un programa simple llamado ```null.c``` que cree un puntero a un entero, llevelo a null y entonces intente desreferenciarlo (esto es, asignarle un valor). Compile este programa llamado ```null```. ¿Qué pasa cuando usted ejecuta este programa?

Cuando se ejecuta el programa sale un mensaje que dice: "Segmentation fault".

2. Compile el programa del ejercicio anterior usando información de simbolos (con la flag -g). Al hacer esto se esta poniendo mas informacion en el ejecutable para permitir al debugger acceder a informacion util sobre los nombres de las variables y cosas similares. Ejecute el programa bajo el debugger digitando en consola (para el caso) ```gdb null``` y entonces una vez el ```gdb``` este corriendo ejecute ```run```. ¿Qué muestra gdb?

R/ Muestra que hay problemas de segmentación como se puede apreciar en la carpeta de los pantallazos:

![enlace](https://raw.githubusercontent.com/gilbertrendon/memory-api/master/Pantallazos/Figura1.png)

Al compilar el programa con la flag -g hubieron inconvenientes con la creación de una tabla como se puede observar en la siguiente imagen:
![enlace](https://raw.githubusercontent.com/gilbertrendon/memory-api/master/Pantallazos/Figura3.1.png)

3. Haga uso de la herramienta ```valgrind``` en el programa empleado en los puntos anteriores. Se usará la herramienta ```memcheck``` que es parte de ```valgrind``` para analizar lo que pasa: ``` valgrind --leak-check=yes null```. ¿Qué pasa cuando corre esto?, Â¿Puede usted interpretar la salida de la herramienta anterior?

R/ Al usar este comando se aprecia más detalladamente en que consiste el error que apreciamos en los puntos anteriores, mostrándo un error relacionado con el mapeo, problemas de que no hay el espacio requerido para hacer dicha operación que se solicita y otros detalles respecto al problema de segmentación como se puede apreciar en la siguiente figura:

![enlace](https://raw.githubusercontent.com/gilbertrendon/memory-api/master/Pantallazos/Figura4.1.png)

4. Escriba un programa sencillo que asigne memoria usando ```malloc()``` pero olvide liberarla antes de que el programa termina. ¿Qué pasa cuando este programa se ejecuta?, ¿Puede usted usar gdb para encontrar problemas como este?, ¿Que dice acerca de Valgrind (de nuevo use este con la bandera ```--leak check=yes```)?

Teniendo en cuenta que el problema descrito en este punto se asoció con una de las anomalías más comunes cuando se gestiona la memoria de forma explícita es lo que se conoce como “fuga de memoria”. Esta situación ocurre cuando un programa obtiene memoria dinámica, 
y el valor del puntero que devuelve el sistema, por error, se pierde. En tal caso, ya no es posible invocar a la función free con ese puntero, y la porción de memoria se queda reservada por lo que resta de ejecución. Como ejemplo de fuga de memoria analicemos el siguiente fragmento de código.

Si se pudo usar gdb, pero debido a que el programa ejecutado no era muy complejo no se pudieron apreciar grandes diferencias en cuanto a la memoria usada u otros factores.
Al usar valgrind se muestra lo relacionado con el programa más detalladamente.


5. Escriba un programa que cree un array de enteros llamado data de un tamaño de 100 usando ```malloc```; entonces, lleve el ```data[100]``` a ```0```. ¿Qué pasa cuando este programa se ejecuta?, ¿Qué pasa cuando se corre el programa usando ```valgrind```?, ¿El programa es correcto?

Hay un error de escritura, debido a que normalmente se toman las posiciones desde la cero hasta la n-1 donde n es el tamaño del vector:

![enlace](https://raw.githubusercontent.com/gilbertrendon/memory-api/master/Pantallazos/Figura5.png)

Como se puede ver en la imagen también hay un error porque solo se permite la ejecución del código para un tipo de arquitectura.

6. Codifique un programa que asigne un array de enteros (como arriba), luego lo libere, y entonces intente imprimir el valor de un elemento del array. ¿El programa corre?, ¿Que pasa cuando hace uso de ```valgrind```?

![enlace](https://raw.githubusercontent.com/gilbertrendon/memory-api/master/Pantallazos/Figura6.png)

7. Ahora pase un **funny value** para liberar (e.g. un puntero en la mitad del array que usted ha asignado) ¿Qué pasa?, ¿Ústed necesita herramientas para encontrar este tipo de problemas?

Como se puede ver en la siguiente imagen:

![enlace](https://raw.githubusercontent.com/gilbertrendon/memory-api/master/Pantallazos/Figura7.2.png)

Hay problemas, y estos problemas más detalladamente consisten en que hay problemas de inicialización de un valor, problemas relacionados con el espacio en la memoria.

8. Intente usar alguna de las otras interfaces para asignacion de memoria. Por ejemplo, cree una estructura de datos simple similar a un vector y que use rutinas que usen realloc para manejar el vector. Use un array para almacenar los elementos del vector; cuando un usuario agregue una entrada al vector, use realloc para asignar un espacio mas a este. ¿Que tan bien funciona el vector asi?, ¿Como se compara con una lista enlazada?, utilice ```valgrind``` para ayudarse en la busqueda de errores.

9. Gaste mas tiempo y lea sobre el uso de gdb y valgrind. Conocer estas herramientas es critico; gaste el tiempo y aprenda como volverse un experto debugger en UNIX y C enviroment.

### Valgrind ###

1. http://valgrind.org/docs/manual/quick-start.html
2. http://www.st.ewi.tudelft.nl/koen/ti2725-c/valgrind.pdf
3. http://pages.cs.wisc.edu/~bart/537/valgrind.html
4. http://web.mit.edu/amcp/drg/valgrind-howto.pdf

### GDB ###

1. http://www.lsi.us.es/~javierj/ssoo_ficheros/GuiaGDB.htm
2. https://www.gdb-tutorial.net/
3. https://web.eecs.umich.edu/~sugih/pointers/summary.html
4. https://www.cs.umd.edu/~srhuang/teaching/cmsc212/gdb-tutorial-handout.pdf
5. https://lihuen.linti.unlp.edu.ar/index.php/C%C3%B3mo_usar_GDB
6. https://www.cs.cmu.edu/~gilpin/tutorial/
7. http://pages.di.unipi.it/bodei/CORSO_FP_17/FP/Lezioni/gdb-commands.pdf
8. https://cs.brown.edu/courses/cs033/docs/guides/gdb.pdf
9. https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf
10. http://users.ece.utexas.edu/~adnan/gdb-refcard.pdf
