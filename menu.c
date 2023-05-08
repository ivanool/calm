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
// #include "asignar_turno_citas_previas.c"
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
#include "free_citas.c"
// #include "cita_cola.c
#include "cola_dequeue.c"
#include "cola_enqueue.c"
#include "cola_imprimir.c"

#include "imprimir_citas_programadas_hoy.c"
#include "consultorio_disponible.c"
#include "current_hout.c"
#include "eliminar_citas_queue_vieja.c"
#include "finish.c"







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
    struct AppointmentNode *head2 = head;
    
    struct NodeN *citas = NULL;
    int option = -1;

    struct Appointment* front = NULL;
    struct Appointment* rear = NULL;
    
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

    //pruebas de inicio

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
        printf("3. Sacar turno cita\n");
        printf("4. Mostrar citas programadas para hoy\n");
        printf("5. Mostrar lista de espera\n");
        printf("0. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &option);
        int remove_succeded = 0;
        remove_succeded = remove_old_appointments(front);

        if(remove_succeded==1){
            dequeue(&front, &rear);
        }

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
                        printf("vuelva a ingresar la hora de la cita para confirmar: \n");
                        int hora_confirmacion = 0;
                        scanf("%d", &hora_confirmacion);
                        int add_turno = hour - 6;
                        struct consultorio *temporal_consultorios = consultorios;
                        int consultorio_dd = ciclo_consultorio(temporal_consultorios, valid_hour);
                        struct AppointmentNode *temporal = head;

                        int disponible = 0;
                        disponible = verificar_disponibilidad_cita(temporal, consultorio_dd, add_turno, date);

                        if (disponible == 1) {
                            char *str;
                            sprintf(str, "%d", hour);
                            addAppointment(&head, account_number_option1, consultorio_dd, acc->name, date, str, add_turno, "citas.csv");
                            free_patient_list(temporal);
                            free(temporal_consultorios  );
                            free(acc);
                            option =-1;
                            break;
                        }
                        else{
                            printf("El consultorio %d NO está disponible para la fecha %s y el turno %d.\n", consultorio_dd, date, add_turno);
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
        while(option ==2){
            printf("Ingrese el numero de cuenta del paciente: \n");
            int account_number_option2 = 0;
            scanf("%d", &account_number_option2);
            int encontrado = 0;
            encontrado = search_patient_by_account_number(patients, account_number_option2);

            if(encontrado == 1){
                deleteAppointment(&head, account_number_option2, "citas.csv");
                option = -1;
            }
            else{
                printf("El paciente no existe\n");
                break;
            }
        }

        while(option == 3){
            int account_number_option1 = 0;
            printf("Ingrese el numero de cuenta del paciente: \n");
            scanf("%d", &account_number_option1);
            int hora_actual= 0;
            //search the patient by account number
            int encontrado = 0;
            encontrado = search_patient_by_account_number(patients, account_number_option1);

            if(encontrado ==1){
                
                hora_actual = get_current_hour();
                int activador = 0;

                for(int i=0; i<15;i++){
                    activador = buscar_consultorio_disponible(head, hora_actual);
                    hora_actual = get_hour_slot(hora_actual);
                    if(activador != 1){
                        printf("El consultorio %d está disponible para la hora %d\n", i, hora_actual);
                        asignar_turno_previas(activador, hora_actual, hora_actual);
                        option = -1;
                        break;

                    }
                    if(activador ==-1){
                        printf("No hay consultorios disponibles para la hora %d\n", hora_actual);
                        printf("Será agregado a la lista de espera\n");
                        printf("Ingrese su nomnre: \n");
                        char name[50];
                        scanf("%s", name);
                        enqueue(&front, &rear, name, "Hoy", get_current_hour, hora_actual, 0000);

                        break;
                    }

                }
                int consultorio_dd = ciclo_consultorio(consultorios, hora_actual);

            }
            else{
                printf("El paciente no existe\n");
                break;
            }
        }
        while(option == 4){
            printList(head);
            option = -1;
            break;
        }
        while(option == 5){
            display(front);

        }
        while(option == 0){
            free(patients);
            free(head);
            free(front);
            free(consultorios);
            // free(temporal_consultorios);
            free(head2);
            terminateProgram();
            break;
        }

    }

}
