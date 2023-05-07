# GESTOR DE CITAS HOSPITAL

## Instrucciones de uso

- Inicie el programa

## Funciones y descripción breve
- Leer citas: Lee las citas que se tienen almacenadas en el archivo csv
- Leer csv: Lee el archivo csv en el que tenemos almacenados los pacientes
- Generar consultorios: Generamos un espacio de 15 consultorios normales.
- Verificador_citas_hoy: Tenemos que pasar solamente la lista citas. Verificamos sí es el mismo día que el actual. Sí es así, regresamos un 1. Aquí el camino se bifurca en dos pasos para la primera opción positiva: Nos va a dar agregar a citas hoy y luego nos va a mandar asignar a citas previas. 
- asignar_citas_previas_hoy: Simplemente cambia el estado de los turnos en los consultorios en los que se le da la indicación.
- Agregar_citas_hoy: Para que funcione debímos de haber definidoa nuestra estructura en la función menu, pasarla y luego lo que haríamos sería simplemente llamar a la función today appoitments la cual automaticamente va a crear un nuevo nodo y va a regresar la cabeza


Una vez hecho eso podemos decir que hemos terminado con el set up. De hecho en el código se pone la etiquepa por si se necesita diferencias cuando se termina todo eso
    


# Funciones que despues del set up:

## Añadir:

Esta función agrega a la lista de citas una cita. Primero tiene que verificar si la cita es para el día de hoy. Si es para el día de hoy pasa a la opción de darle un turno para la fila de espera. Si resulta que no es para el mismo día que la que se ejecuta en el programa se procede a hacer los siguientes pasos (cada paso esta en una función distinta).

- buscar_paciente: Si encuentra al paciente por el cual se esta buscando se regresa un puntero hacía el nodo en el que se encuentra. Si no se encuentra, regresa 0.

- Ya que encontro a el usuario que se requiere necesitamos pedirle al usuario los datos; fecha, turno y consultorio. Si todos los datos dan correcto pasamos a la función final de esta funcionalidad:

- Añadimos el elemento a la lista y luego, con otra función modificamos el csv para que quede registrado y no se borre.

En total esto va a necesitar 6 funciones, además de buscar; pedir datos, verificar cada uno, añadir y modificar csv con la nueva adición.

