# Proyecto #1

**Universidad Nacional de Costa Rica**

ESCUELA DE INFORMÁTICA

EIF 204 PROGRAMACIÓN II

---

FECHA DE ENTREGA: SEMANA 9 (Domingo 15 de Mayo)

PUNTAJE TOTAL: 100 Puntos

PORCENTAJE: Corresponde a un 15% de la nota final del curso

---

## CONDICIONES DEL PROYECTO

El Proyecto de Aprendizaje del curso EIF 204 Programación II pretende que el estudiante ponga en práctica los siguientes temas: 

- Principios de Diseño

- Jerarquías de Clases

- Relaciones entre Clases

Se presenta un problema que el estudiante debe implementar en el IDE seleccionado por el profesor para desarrollar un proyecto en C + +, y posteriormente subirlo al aula virtual en la sección que el profesor habilite para esto. El ejercicio se trabaja en grupos de máximo dos personas. Cualquier plagio se calificará con 0, como lo establece el artículo 24 del Reglamento General sobre los procesos de Enseñanza y Aprendizaje de la Universidad Nacional.

Recuerde que además, como es de esperar los proyectos tienen una naturaleza de investigación por cuanto, es importante que usted como parte del proyecto aplique los conocimientos adquiridos e investigue en el proceso de desarrollo y solución del proyecto.

### TEMAS EVALUADOS:

- Mejores prácticas de programación
- Programación Orientada a Objetos (POO)
- Relaciones entre clases
- Manejo de excepciones
- Programación Genérica

## ENUNCIADO DEL PROBLEMA

La empresa de buses BusCar Costa Rica S.A., se encarga de brindar el servicio de transporte a destinos turísticos de Costa Rica.

Durante la pandemia por el COVID-19 y a raíz de las restricciones sanitarias impulsadas por el Ministerio de Salud para minimizar el riesgo de contagio del virus, instruye que todas las empresas de transporte tienen como **<u>requisito temporal</u>** que los buses puedan brindar el servicio de transporte a un 80% de su capacidad total, este requerimiento crea un problema de asignación de espacios al momento de emitir un boleto. Los siguientes datos indican las unidades disponibles de la empresa y la capacidad de transporte al 100%.

**Tipos de buses:**

- Buseta: Hasta 40 pasajeros 
  - Placa: BUS001
  - Placa: BUS002
  - Placa: BUS003
- Coaster: Hasta 21-27 pasajeros
  - Placa: COA001
  - Placa: COA002
- Hiace: Hasta 12 pasajeros
- Placa: HIA001
- Placa: HIA002
- Placa: HIA003
- Placa: HIA004
- H1: Hasta 6 pasajeros
  - Placa: HON001
  - Placa: HON002

**Rutas de viajes:**

- Volcán Arenal, San Carlos
- Río celeste, San Carlos
- Tamarindo, Guanacaste
- Puerto Viejo, Limón
- Cóbano, Puntarenas
- Volcán Irazú, Cartago

Se solicita desarrollar un sistema que permita gestionar los buses, las rutas, y la reserva de tiquetes, considerando las restricciones adicionales impuestas por el ministerio de salud.

Para solucionar este problema, la empresa ha contactado a los estudiantes del curso de Programación II, para hacer un sistema en C + + con el fin de:

1. Asignar uno o varios tipos de bus a una ruta de viaje
2. Permitir reservar boletos por viaje, considerando las restricciones de capacidad máxima por unidad de transporte.
3. Las rutas de viaje podrían tener uno o más buses asignados. Si un bus llega a su máxima capacidad de pasajeros, el sistema automáticamente lo asigna al siguiente bus.

### Requerimientos Específicos

1. Construya una interfaz llamada Object, esta es la superclase por excelencia de todo el proyecto así que todas las clases heredan de ella. 
   1. Debe tener como métodos virtuales puros
      1. Método toString que retorna un string con la representación del objeto
   2. Configuración de la flota de transporte
     1. Tipos de buses: 
           1. Permitir la carga de distintos tipos de buses
     2. Rutas de viaje
           1. Permitir la carga de las rutas de viaje
               2. Tener la opción de asignar los buses a las rutas de viaje, por ejemplo: la ruta al Volcán Arenal podría tener dos tipos de buses asignados: una Buseta y un H1. 
   3. Reserva de tiquetes
     1. Reserva de tiquetes
           1. Permitir reservar y emitir un tiquete de viaje, el mismo debe llevar el número de asiento y el bus correspondiente.
   4. Reportes
     1. Mostrar todos los tiquetes emitidos indicando la ruta y el bus
     2. Mostrar la disponibilidad de pasajeros por ruta de viaje
   5. Pruebas de Unidad
     1. Esta sección de la aplicación maneja toda la interacción con el usuario
     2. Se evalúan los procesos y la interacción de los resultados mediante las pruebas de unidad 

### Distribución de pasajeros
El sistema debe tener la capacidad de distribuir eficientemente los pasajeros entre los buses que tiene disponible la empresa.

Técnicamente se debe buscar un algoritmo de distribución (ejemplo: bin packing problem).

### Anotaciones

Usted debe aplicar los siguientes conceptos para cumplir con los requerimientos y obtener la puntuación asignada:

1. Utilización de la delegación
2. Los contenedores deben utilizar programación genérica 
3. Las excepciones deben estar incluidas.
4. El sistema debe incluir persistencia de datos mediante la utilización de archivos (csv).

## Diseño del Menú

<img src="pngFIles/Menú%20Principal.png" style="zoom:50%;" />

<img src="pngFIles/Menú%20Configuración.png" alt="Menú Configuración" style="zoom:50%;" />

<img src="pngFIles/Tipos%20de%20Buses.png" style="zoom:50%;" />

<img src="pngFIles/Restricciones%20Sanitarias.png" style="zoom:50%;" />

<img src="pngFIles/Rutas%20de%20Viaje.png" alt="Rutas de Viaje" style="zoom:50%;" />

<img src="pngFIles/Reserva%20de%20tiquetes.png" alt="Reserva de tiquetes" style="zoom:50%;" />

<img src="pngFIles/Reserva%20de%20tiquetes%20impresión-1.png" alt="Reserva de tiquetes impresión-1" style="zoom:50%;" />

<img src="pngFIles/Menú%20Reportes.png" alt="Menú Reportes" style="zoom:50%;" />

<img src="pngFIles/Reserva%20de%20tiquetes%20impresión-1.png" alt="Reserva de tiquetes impresión-1" style="zoom:50%;" />

<img src="pngFIles/Mostrar%20la%20disponibilidad%20de%20pasajeros%20por%20ruta%20de%20viaje.png" alt="Mostrar la disponibilidad de pasajeros por ruta de viaje" style="zoom:50%;" />

## Evaluación

| Detalle                                                      | Puntaje |
| ------------------------------------------------------------ | ------- |
| [ESTÁNDARES] Código fuente ordenado siguiendo los estándares definidos para los nombres de las variables, documentación del código y estructura de las clases. | 5       |
| [UML] Diagrama de clases completo.                           | 10      |
| [POO] Uso correcto de las técnicas de Programación Orientada a Objetos [Herencia, Encapsulamiento y Polimorfismo] (5 puntos cada tema) | 15      |
| [RELACIONES DE CLASES] Implementación de relaciones de clases. | 10      |
| [ABSTRACCIÓN E INTERFACES] Utilizar de forma correcta la abstracción y las interfaces. (5 puntos cada tema) | 10      |
| [PRINCIPIOS DE DISEÑO] Diseñar e implementar utilizando al menos tres principios de SOLID. (5 puntos cada tema) | 15      |
| [PRUEBAS DE UNIDAD] Definición de las pruebas de unidad para los métodos más importantes en su sistema. | 20      |
| [MANEJO DE EXCEPCIONES] Implementar las excepciones en los lugares adecuados. | 15      |

