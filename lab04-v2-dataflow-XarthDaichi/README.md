# Laboratorio #4 - DataFlow

Con base al tema de Data Flow (Archivos de texto y Binarios). Se le solicita lo siguiente:

- Se tiene un archivo de texto de tipo CSV `email.csv` que va a ser la fuente de datos inicial

## Instrucciones

Desarrollar una aplicación en C++ que tenga la siguiente funcionalidad, es necesario desarrollar el UML de la aplicación.

### Método parsear archivo csv

1. Parsear (convertir) el archivo `email.csv` a un sistema en C++ con una estructura similar a la primera fila contenida en el archivo de texto

### Método almacenar estructura en memoria en un archivo binario

1. Los datos que fueron cargados en memoria se deben almacenar en un archivo binario para posteriormente recuperar los datos
2. El nombre del archivo binario es: `basedatos.dat`

### Método recuperar datos del archivo binario

1. Recuperar los datos del archivo binario  `basedatos.dat`

## Evaluación

- Se requiere UML de la aplicación
- Es necesario que se realicen las pruebas de unidad necesarias para evaluar los métodos solicitados
  - Se puede usar Google Test o Catch2
  - Son mínimo tres pruebas de unidad
- Es necesario que se utilice try / catch en los lugares indicados
