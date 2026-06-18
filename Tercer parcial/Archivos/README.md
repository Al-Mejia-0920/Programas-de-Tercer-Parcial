# Trabajo 3er Parcial--Archivos

Este proyecto es una herramienta interactiva diseñada en **C++** para automatizar la ejecución de los ejercicios de programación. El sistema se encarga de compilar el código al instante, capturar los resultados de la consola y exportarlos a formatos estructurados de datos (JSON, XML, CSV, TXT) utilizando principios de **Programación Orientada a Objetos (POO)**.

---
## Características Principales

* **Menú Interactivo:** Navegación sencilla para elegir entre los ejercicios del 1er o 2do parcial.
* **Captura de Salida:** Usa `PowerShell Transcript` para grabar exactamente lo que el programa imprime en la consola, limpiando metadatos innecesarios.
* **Exportación a tipo de datos:** Una vez terminada la ejecución de un ejercicio, puedes guardar el resultado en el formato que prefieras:
    **TXT:** Archivo de texto plano estético y fácil de leer
    **JSON:** Formato de pares clave-valor ideal para web 
    **CSV:** Archivo separado por comas, perfecto para abrir en Excel
    **XML:** Formato jerárquico basado en etiquetas


# 📂 Estructura del Proyecto
Para que el programa encuentre correctamente tus ejercicios, el proyecto está organizado de la siguiente manera:

```text
📁 Proyecto-Principal/
│
├── 📁 1er Parcial/               # Contiene los ejercicios del primer parcial
│   ├── 1-ejercicio.cpp
│   ├── 2-ejercicio.cpp
│   └── ...
│
├── 📁 2do Parcial/               # Contiene las ejercicios del segundo parcial
│   ├── 📁 pila-arreglo/          
│   ├── 📁 cola-puntero/
│   └── 📁 lista-libreria/
│
├── main.cpp                      # Archivo principal con el menú del programa
├── convertidor.h                 # Interfaz y clases abstractas/concretas
├── txt.cpp                       # Lógica para exportar a TXT
├── json.cpp                      # Lógica para exportar a JSON
├── xml.cpp                       # Lógica para exportar a XML
├── csv.cpp                       # Lógica para exportar a CSV


1.Ejecución del Proyecto

Tener instalado el IDE **Code::Blocks**.

1. Descarga y descomprime el archivo `.zip` en tu computadora.
2. Abre la carpeta y busca el archivo llamado **`convertidor.cbp`** (el que tiene el icono de Code::Blocks).
3. Haz doble clic sobre él para abrir el proyecto completo en el IDE.
4. Dentro de Code::Blocks, presiona  **Build and Run** para compilar y ejecutar el programa automáticamente.


2. Uso:

Sigue las instrucciones del menú para entrar al parcial deseado.

Escribe el número o nombre exacto del ejercicio que quieres probar.

Cuando termine la ejecución, elige el formato de salida y ponle un nombre al archivo.(Lo encontrarás guardado en la carpeta del proyecto)

Arquitectura de Código

Este proyecto es un gran ejemplo de Polimorfismo y Herencia en C++:

Utiliza una interfaz abstracta (IConvertidor) que obliga a todas las clases hijas a tener un método generar_texto() y guardar().

Las clases hijas (ConvertidorJSON, ConvertidorCSV, etc.) heredan de una clase base y aplican su propia lógica para estructurar el texto antes de guardarlo en el disco duro.
