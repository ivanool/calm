#include "leer_csv.c"
#include "leer_citas.c"
#include "newNode.c"
#include "citas_hoy.c"
#include "generar_consultorios.c"
#include "generar_consultorios_emergencias.c"
#include "mismo_dia.c"
#include "agregar_citas_hoy.c"
#include "asignar_turno_citas_previas.c"
// #include "verificar_existencia_cita_lista.c"
#include "verificador_agregar_hoy.c"
#include "imprimir_consultorios.c"
#include "verificar_existencia_cita_lista.c"
#include "ciclar_consultorios.c"
#include "zhora.c"
#include "find_patient.c"
#include "add_appointment.c"
#include "verificar_fecha_valida.c"
#include "buscar_paciente.c"




int menu(){

    //set up

    struct patient* patients = read_patient_info_from_csv("datos.csv");
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

    struct consultorio* consultorios_emergencias = initialize_consultories_emergencias();
    if (consultorios_emergencias == NULL) {
        printf("Error al crear la lista de consultorios de emergencias.\n");
        return -1;
    }
    struct AppointmentNode *head2 = head;
    
    struct NodeN *citas = NULL;
    int option = -1;
    
    //end set up


    //asignation begings

    while(head2 != NULL){
        option = -1;
        option = verificar_fecha_hora(&head2);

        if(option == 1){

            char *nombre;
            int account_number = 0;
            int turno = 0;
            int consultorio = 0;

            consultorio = head2->consultory;
            turno = head2->turno;
            nombre = head2->name;
            account_number = head2->account_number;
            citas = agregar_citas_hoy(consultorio, turno, nombre, account_number);
            asignar_turno_previas(consultorio -1, turno-1, &consultorios);

        }
        head2=head2->next;
    }
    //asignation ends

    // Crear una lista de citas de ejemplo
    // struct AppointmentNode *head = createAppointmentList("citas.csv");
    // imprimir_consultorio(consultorios);
    struct AppointmentNode *head3 = head;
    int consultorioas = 3;    int turno = 3;
    char fecha[11] = "2023-7-15";
    int disponible = verificar_disponibilidad_cita(head3, consultorioas, turno, fecha);
    printf("\n prueba");
    // Mostrar el resultado
    if (disponible == 1)
    {
        printf("El consultorio %d está disponible para la fecha %s y el turno %d.\n", consultorioas, fecha, turno);
    }
    else
    {
        printf("El consultorio %d NO está disponible para la fecha %s y el turno %d.\n", consultorioas, fecha, turno);
    }
    printf("\n prueba");
    printf("\n prueba");

    addAppointment(head, 112343, 1, "Prueba","2023-6-25", "9", 3, "datos.csv");

    //menu begins

    //Dale al usuario las siguientes opciones; añadir cita, eliminar cita, modificar cita, cita de emergencia, cita hoy, mostrar citas, cancelar cita por no llegar
    //0 para salir. Si el usuario ingresa una opción inválida, imprima un mensaje de error y vuelva a mostrar el menú.

    // while(option != 0){
    //     printf("Bienvenido al sistema de citas del hospital\n");
    //     printf("1. Agregar cita\n");
    //     printf("2. Eliminar cita\n");
    //     printf("3. Modificar cita\n");
    //     printf("4. Cita de emergencia\n");
    //     printf("5. Cita para hoy\n");
    //     printf("6. Mostrar citas\n");
    //     printf("7. Cancelar cita por no llegar\n");
    //     printf("0. Salir\n");
    //     printf("Ingrese una opción: ");
    //     scanf("%d", &option);

    //     if(option == 1){
    //     }

    //agregar_logica
    // int fecha_option = 0;
    // int ask_account = 0;
    // printf("Ingrese el numero de cuenta del paciente: \n");
    // scanf("%d", &ask_account);
    
    // struct patient* acc = NULL;
    // // printf("\n\n%d\n\n", ask_account);
    // int encontrado = 0;
    // encontrado  = search_patient_by_account_number(patients, ask_account);
    // printf("%d", encontrado);
    // acc = find_patient_by_account_number(patients, ask_account);
    
    // printf("\n\nd\n\n", ask_account);
    // printf("Por favor, ingrese la fecha de la cita empezando por el año, mes y al final el día\n ");
    // printf("Si la fecha tiene un solo digito en mes o día, NO ponga 0 antes de el mes. \n Ejemplo: 2024-5-31\n");
    // char fechas[11];
    // scanf("%s", fechas);
    // fecha_option = es_fecha_valida(fechas);
    // int turno_option = 0;
    
    // if(fecha_option == 1){
    //     printf("\n\n Ingrese la hora de la cita, tiene que ser en formato de 24 horas sin minutos\n ejemplo 22 ó 10\n: \n");
    //     scanf("%d", &turno_option);
    //     turno_option = get_hour_slot(turno_option);
    //     if(turno_option == 0){
    //         printf("La hora ingresada no es valida, por favor ingrese una hora entre 7 y 22\n");
    //         scanf("%d", &turno_option);
    //         turno_option = get_hour_slot(turno_option);
    //     }
    //     // printf("La hora ingresada es: %d\n", turno_option);
    //     int assigned_consultory = ciclo_consultorio(consultorios, turno_option);
    //     printf("El consultorio que se le asigno es el numero: %d\n", assigned_consultory);
    //     addAppointment(head,acc->account_number,assigned_consultory, acc->name, fechas, turno_option+6,turno_option);
    //     return 1; 
    // }else{
    //     return 0;
    // }

}
