#include "leer_csv.c"
#include "leer_citas.c"
#include "newNode.c"
#include "citas_hoy.c"
#include "generar_consultorios.c"
#include "generar_consultorios_emergencias.c"
#include "mismo_dia.c"
#include "agregar_citas_hoy.c"
#include "asignar_turno_citas_previas.c"
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
            // printf("turno: %d\n", turno);
            nombre = head2->name;
            account_number = head2->account_number;
            citas = agregar_citas_hoy(consultorio, turno, nombre, account_number);
            asignar_turno_previas(consultorio -1, turno-1, &consultorios);

        }
        head2=head2->next;
    }
    //asignation ends



while(1){
        
        printf("Bienvenido al sistema de citas del hospital\n");
        printf("1. Agregar cita\n");
        printf("2. Eliminar cita\n");
        printf("3. Sacar turno cita\n");
        printf("4. Mostrar citas programadas para hoy\n");
        printf("5. Mostrar lista de espera\n");
        printf("0. Salir\n");
        printf("9. Limpiar terminal\n ");
        printf("Ingrese una opción: ");
        scanf("%d", &option);
        int remove_succeded = 0;
        int hora_actual = 0;
        remove_succeded = remove_old_appointments(front, hora_actual);

        if(remove_succeded==1){
            dequeue(&front, &rear);
        }

        int success = 0;
        while(option==1){
            int account_number_option1 = 0;
            printf("Ingrese el numero de cuenta del paciente: \n");
            scanf("%d", &account_number_option1);

            int encontrado = 0;
            encontrado = search_patient_by_account_number(patients, account_number_option1);

            if (encontrado == 1) {
                struct patient* acc = NULL;
                acc = find_patient_by_account_number(patients, account_number_option1);
                char date[11];
                printf("Ingrese la fecha de la cita: \n");
                scanf("%s", date);
                printf("La fecha ingresada es: %s\n", date);
                int valid_date = 0;
                valid_date = es_fecha_valida(date);

                if (valid_date == 1) {
                    int hour = 0;
                    printf("Ingrese la hora de la cita: \n");
                    scanf("%d", &hour);
                    int valid_hour = 0;
                    valid_hour = get_hour_slot(hour);

                    if (hour >= 7 && hour <= 22) {
                        printf("vuelva a ingresar la hora de la cita para confirmar: \n");
                        char hora_confirmacion[3];
                        scanf("%s", &hora_confirmacion);
                        int add_turno = hour - 6;
                        struct consultorio *temporal_consultorios = consultorios;
                        int consultorio_dd = ciclo_consultorio(temporal_consultorios, valid_hour);
                        struct AppointmentNode *temporal = head;
                        

                        int disponible = 0;
                        disponible = verificar_disponibilidad_cita(temporal, consultorio_dd, add_turno, date);
                   

                        if (disponible == 1) {
                            printf("%s", date);
                            // printf("%d", hora_confirmacion);
                            // printf("%d", add_turno);
                            addAppointment(&head, account_number_option1, consultorio_dd, acc->name, date, hora_confirmacion, add_turno, "citas.csv");
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
            hora_actual= 0;
            int encontrado = 0;
            encontrado = search_patient_by_account_number(patients, account_number_option1);

            if(encontrado ==1){
                printf("Ingrese la hora actual:");
                scanf("%d", &hora_actual);
                if(hora_actual <7 || hora_actual>22){
                    printf("Hora invalida.\n");
                    option = -1;
                    break;
                }
                int activador = 0;
                struct consultorio *temporal_consultorios = consultorios;
                for(int i=0; i<15;i++){

                    hora_actual = get_hour_slot(hora_actual);
                    activador = buscar_consultorio_disponible(consultorios, hora_actual);
                    if(activador != -1){                        
                        printf("\nEl consultorio %d está disponible. Por favor, pase\n", activador-1);
                        asignar_turno_previas(activador-2, hora_actual-1, &consultorios);
                        option = -1;
                        free(temporal_consultorios);

                        break;

                    }
                    if(activador ==-1){
                        printf("No hay consultorios disponibles para la hora %d\n", hora_actual);
                        printf("Será agregado a la lista de espera\n");
                        printf("Ingrese su nombre: \n");
                        char name[50];
                        scanf("%s", name);
                        enqueue(&front, &rear, name, "Hoy", hora_actual, hora_actual, 0000);
                        option = -1;
                        free(temporal_consultorios);
                        break;
                    }
                    temporal_consultorios = temporal_consultorios->next;

                }
                int consultorio_dd = ciclo_consultorio(consultorios, hora_actual);
                free(temporal_consultorios);
            }
            else{
                printf("El paciente no existe\n");
                option = -1;
                break;
            }
        }
        while(option == 4){
            struct nodeN *temporal2 = citas;
            printAppointments(temporal2);
            option = -1;
            break;
        }
        while(option == 5){
            display(front);
            option =-1;
            break;

        }
        while(option == 0){
            free(patients);
            free(head);
            free(front);
            free(consultorios);
            free(head2);
            terminateProgram();
            break;
        }
        while(option == 9){
            system("clear");
            option = -1;
        }

    }

}
