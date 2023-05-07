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
#include "free_patient_list.c"
#include "eliminar_cita.c"
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
    printf("Prueba\n");
    struct patient* patients = read_patient_info_from_csv("datos.csv");
    if (patients == NULL){
        printf("Error reading patient info from CSV file\n");
        return 1;
    }
    printf("Prueba3\n");
    struct AppointmentNode *head = createAppointmentList("citas.csv");
    if (head == NULL) {
        printf("Error al crear la lista de citas.\n");
        return -1;
    }
    printf("Prueba\n");
    struct consultorio *consultorios =initialize_consultories();
    if (consultorios == NULL) {
        printf("Error al crear la lista de consultorios.\n");
        return -1;
    }
    printf("Prueba\n");
    struct consultorio* consultorios_emergencias = initialize_consultories_emergencias();
    if (consultorios_emergencias == NULL) {
        printf("Error al crear la lista de consultorios de emergencias.\n");
        return -1;
    }
    printf("Prueba\n");
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
    printf("\n prueba");
    printf("\n prueba");

    // addAppointment(&head, 1123, 1, "Prueba","2023-6-25", "9", 3, "citas.csv");
    deleteAppointment(&head, 1234, "citas.csv");

    //menu begins

    //Dale al usuario las siguientes opciones; añadir cita, eliminar cita, modificar cita, cita de emergencia, cita hoy, mostrar citas, cancelar cita por no llegar
    //0 para salir. Si el usuario ingresa una opción inválida, imprima un mensaje de error y vuelva a mostrar el menú.

    while(1){
        printf("Bienvenido al sistema de citas del hospital\n");
        printf("1. Agregar cita\n");
        printf("2. Eliminar cita\n");
        printf("3. Modificar cita\n");
        printf("4. Cita de emergencia\n");
        printf("5. Cita para hoy\n");
        printf("6. Mostrar citas\n");
        printf("7. Cancelar cita por no llegar\n");
        printf("0. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &option);

        int success = 0;
        while(option==1){
            //clean the terminal and ask the user for the account nummber
            // system("clear");

            int account_number_option1 = 0;
            printf("Ingrese el numero de cuenta del paciente: \n");
            scanf("%d", &account_number_option1);

            //search the patient by account number
            int encontrado = 0;
            encontrado = search_patient_by_account_number(patients, account_number_option1);

            if (encontrado == 1) {
                struct patient* acc = NULL;
                acc = find_patient_by_account_number(patients, account_number_option1);

                //ask for the date
                char date[11];
                printf("Ingrese la fecha de la cita: \n");
                scanf("%s", date);

                //verify if the date is valid
                int valid_date = 0;
                valid_date = es_fecha_valida(date);

                if (valid_date == 1) {
                    int hour = 0;
                    printf("Ingrese la hora de la cita: \n");
                    scanf("%d", &hour);

                    //verify if the hour is valid
                    int valid_hour = 0;
                    valid_hour = get_hour_slot(hour);

                    if (hour >= 7 && hour <= 22) {
                        int add_turno = hour - 6;
                        int consultorio_add = 3;
                        struct AppointmentNode *temporal = head;

                        int disponible = 0;
                        disponible = verificar_disponibilidad_cita(temporal, consultorio_add, add_turno, date);

                        if (disponible == 1) {
                            char *str;
                            sprintf(str, "%d", hour);
                            addAppointment(&head, account_number_option1, consultorio_add, acc->name, date, str, add_turno, "citas.csv");
                            free_patient_list(temporal);
                            option =-1;
                            break;
                            // success = 1;
                        }
                        else{
                            printf("El consultorio %d NO está disponible para la fecha %s y el turno %d.\n", consultorio_add, date, add_turno);
                            break;
                        }
                    }
                    else{
                        printf("La hora ingresada no es válida\n");
                        break;
                    }
                }
                else{
                    printf("La fecha ingresada no es válida\n");
                    break;
                }
            }
            else {
                printf("El paciente no existe\n");
                break;
            }
        }

}
}