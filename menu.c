#include "leer_csv.c"
#include "leer_citas.c"
#include "newNode.c"
#include "citas_hoy.c"
#include "generar_consultorios.c"
#include "generar_consultorios_emergencias.c"
#include "mismo_dia.c"
#include "agregar_citas_hoy.c"
#include "asignar_turno_citas_previas.c"
#include "verificador_agregar_hoy.c"
#include "imprimir_consultorios.c"




int menu(){

    //set up

    struct patient* patients = read_patient_info_from_csv("pacientes.csv");
    if (patients == NULL){
        printf("Error reading patient info from CSV file\n");
        return 1;
    }

    struct AppointmentNode *head = createAppointmentList("citas.csv");
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
    
    struct NodeN *citas = NULL;
    int option = -1;
    
    //end set up


    //asignation begings

    while(head != NULL){
        option = -1;
        option = verificar_fecha_hora(&head);

        if(option == 1){

            char *nombre;
            int account_number = 0;
            int turno = 0;
            int consultorio = 0;

            consultorio = head->consultory;
            turno = head->turno;
            nombre = head->name;
            account_number = head->account_number;
            citas = agregar_citas_hoy(consultorio, turno, nombre, account_number);
            asignar_turno_previas(consultorio -1, turno-1, &consultorios);

        }
        head=head->next;
    }
    //asignation ends

    //menu begins

    //Dale al usuario las siguientes opciones; añadir cita, eliminar cita, modificar cita, cita de emergencia, cita hoy, mostrar citas, cancelar cita por no llegar

    while(option != 0){
        printf("Bienvenido al sistema de citas del hospital\n");
        printf("Por favor seleccione una de las siguientes opciones:\n");
        printf("1. Agregar cita\n");
        printf("2. Eliminar cita\n");
        printf("3. Modificar cita\n");
        printf("4. Cita de emergencia\n");
        printf("5. Cita hoy\n");
        printf("6. Mostrar citas\n");
        printf("7. Cancelar cita por no llegar\n");
        printf("0. Salir\n");
        scanf("%d", &option);

        if(option == 1){
            //agregar cita
            int account_number = 0;
            int consultorio = 0;
            int turno = 0;
            char *nombre;
            int dia = 0;
            int mes = 0;
            int anio = 0;
            int hora = 0;
            int minuto = 0;
            int emergencia = 0;
            int emergencia_consultorio = 0;
            int emergencia_turno = 0;
            int emergencia_hora = 0;
            int emergencia_minuto = 0;
            int emergencia_dia = 0;
            int emergencia_mes = 0;
            int emergencia_anio = 0;
            int emergencia_account_number = 0;
            int emergencia_consultorio_emergencias = 0;
            int emergencia_turno_emergencias = 0;
            int emergencia_hora_emergencias = 0;
            int emergencia_minuto_emergencias = 0;
            int emergencia_dia_emergencias = 0;
            int emergencia_mes_emergencias = 0;
            int emergencia_anio_emergencias = 0;
            int emergencia_account_number_emergencias = 0;
            int emergencia_consultorio_emergencias2 = 0;
            int emergencia_turno_emergencias2 = 0;
            int emergencia_hora_emergencias2 = 0;
            int emergencia_minuto_emergencias2 = 0;
            int emergencia_dia_emergencias2 = 0;
            int emergencia_mes_emergencias2 = 0;
            int emergencia_anio_emergencias2 = 0;
            int emerg

    return 0;
}