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

    