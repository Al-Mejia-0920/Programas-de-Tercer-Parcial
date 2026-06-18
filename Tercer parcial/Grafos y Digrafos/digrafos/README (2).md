                 MANUAL DE USUARIO - SISTEMA DE DIGRAFOS


Este archivo contiene las instrucciones necesarias para configurar, ejecutar
y utilizar correctamente el programa de gestión de rutas y logística óptima.

1. CONFIGURACIÓN PREVIA REQUERIDA

El programa funciona de manera desacoplada utilizando un archivo de 
configuración externa llamado 'red.xml'. Este archivo dicta qué nodos y 
aristas son válidos en el universo del sistema.

Antes de arrancar el programa, asegúrate de colocar el archivo 'red.xml'
en las siguientes ubicaciones para evitar errores de lectura en disco:

A) En la carpeta raíz de tu proyecto (donde están tus archivos .cpp y .h).
B) En la carpeta de depuración ejecutable (dentro de /bin/Debug/ junto 
   al archivo .exe generado por el compilador).

El formato interno del archivo 'red.xml' debe ser estrictamente el siguiente:

<?xml version="1.0" encoding="UTF-8"?>
<configuracion>
    <nodo id="A"/>
    <nodo id="B"/>
    <nodo id="C"/>
    <nodo id="D"/>
    <nodo id="E"/>
    <nodo id="F"/>
    <arista id="a"/>
    <arista id="b"/>
    <arista id="c"/>
    <arista id="d"/>
    <arista id="e"/>
    <arista id="f"/>
    <arista id="g"/>
</configuracion>

2. INSTRUCCIONES DE USO 
PASO 1: Inicio del Sistema
Al ejecutar el programa, lo primero que verás en la consola es el mensaje 
de carga exitosa: "[OK] Catalogos maestros leidos desde el XML con exito."
Si te aparece un mensaje de error, revisa el punto 3 de este manual.

PASO 2: Creación Dinámica de Rutas (Conexión de Nodos)
El sistema te pedirá interactivamente que armes tu mapa de conexiones:
- Ingrese Nodo Origen: Teclea una letra de la A a la F (Ej. A). El sistema 
  acepta minúsculas pero las convierte automáticamente a mayúsculas.
- Ingrese Nodo Destino: Teclea la letra del nodo final (Ej. B).
- Ingrese identificador de Arista: Teclea el nombre de la arista según el 
  catálogo aprobado en el archivo XML (Ej. a).
- Ingrese el Peso: Digita el valor numérico del costo o distancia (Ej. 4).

PASO 3: Validación en Tiempo Real
Si intentas conectar un nodo que no existe en el XML, o utilizas una 
arista no autorizada (por ejemplo, una arista 'z'), el programa emitirá 
un mensaje de advertencia en la pantalla y rechazará el registro en la 
memoria dinámica para evitar datos corruptos.

PASO 4: Continuidad del Flujo
Al terminar de meter una conexión, la consola te preguntará: 
"¿Desea agregar otra conexion dirigida? (S/N)". Presiona 'S' para seguir 
armando el mapa por teclado o 'N' para avanzar al módulo de cálculo.

PASO 5: Visualización de la Estructura
Al presionar 'N', el programa desplegará la lista de adyacencia de la 
memoria RAM para que verifiques visualmente cómo quedaron tus conexiones 
unidireccionales y sus respectivos pesos.

PASO 6: Búsqueda del Camino Más Corto (Algoritmo de Dijkstra)
Finalmente, accederás al módulo de logística. La consola te solicitará:
- Punto de Partida (Nodo inicial): Digita tu origen (Ej. A).
- Punto de Destino (Nodo final): Digita tu destino (Ej. D).

El algoritmo procesará los punteros dinámicos respetando el sentido único 
de las flechas y te arrojará en pantalla la secuencia exacta de las 
aristas que debes tomar y el peso total acumulado del viaje óptimo.

3. RESOLUCIÓN DE PROBLEMAS COMUNES (TROUBLESHOOTING)

* PROBLEMA: El programa dice "[!] Error: No se pudo abrir el archivo XML."
  - SOLUCIÓN: Verifica que el archivo se llame exactamente 'red.xml' (en 
    minúsculas) y que esté físicamente dentro de la carpeta /bin/Debug/ 
    al lado del archivo ejecutable .exe del proyecto.

* PROBLEMA: El programa dice "No existe ninguna ruta dirigida transitable."
  - SOLUCIÓN: Recuerda que la estructura es un DÍGRAFO (un grafo dirigido). 
    Si creaste una ruta de A hacia B, el algoritmo no puede regresar de 
    B hacia A a menos que en el paso 2 hayas creado explícitamente otra 
    conexión de vuelta.

* PROBLEMA: El programa arroja un error extraño de asignación.
  - SOLUCIÓN: Asegúrate de no dejar espacios en blanco al teclear los 
    nombres de las aristas y verifica que el peso introducido sea un 
    número entero positivo válido antes de presionar Enter.