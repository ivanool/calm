#include "leer_csv.c"
#include "leer_citas.c"
#include "newNode.c"
#include "citas_hoy.c"
#include "consultorios.c"
#include "generar_consultorios_emergencias.c"
#include "mismo_dia.c"
#include "agregar_citas_hoy.c"
#include "asignar_turno_citas_previas.c"
#include "verificador_agregar_hoy.c"




int menu(){
    /*
    El sistema se inicializa en este orden:

    1.- Leemos el archivo patients.csv y creamos una lista de pacientes.
    2.- Leemos el archivo appointments.csv y creamos una lista de citas.
    3.- Inicializamos los consultorios.
        Ya que tenemos inicializados los consultorios debemos de leer la lista
        que contiene las citas programadas para hoy. Con el verificador vamos a ver
        si la fecha es de hoy, si es de hoy entonces la agregamos a la lista de citas 
        que se van a atender hoy y le asignamos el consultorio correspondiente. Esto
        se ejecuta así:
        3.1-verificador de citas hoy. Aquí verificamos las citas que tenemos programadas
        para hoy. Además de regresar 1 o un 0, pasamos a las funciones de citas_hoy y }
        asignar_turno_citas_previas. 
        3.1.2- Asignar_turno_citas_previas. Aquí asignamos el turno a las citas que se tienen
        que atender hoy.
        3.2-agregar_citas_hoy. Aquí agregamos las citas que se van a atender hoy a una lista

        Una vez eso hemos terminado. Ahora solo establecemos el espacio para las citas de 
        emergencia y esta todo listo.


    */
    struct patient* patients = read_patient_info_from_csv("pacientes.csv");
    if (patients == NULL){
        printf("Error reading patient info from CSV file\n");
        return 1;
    }

    struct AppointmentNode *head = createAppointmentList("citas.txt");
    if (head == NULL) {
        printf("Error al crear la lista de citas.\n");
        return -1;
    }

    struct consultorio *consultorios =initialize_consultories();
    if (consultorios == NULL) {
        printf("Error al crear la lista de consultorios.\n");
        return -1;
    }

    struct consultorio *consultorios_emergencias = initialize_consultories_emergencias();
    if (consultorios_emergencias == NULL) {
        printf("Error al crear la lista de consultorios de emergencias.\n");
        return -1;
    }

    struct nodeN *headN = NULL; 

    verificar_fecha_hora(&head, &consultorios, &headN);




    return 0;
}