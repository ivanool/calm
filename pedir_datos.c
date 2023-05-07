int pedir_datos(int cuenta, int turno){
    int option = -1;

    printf("Por favor, ingrese la fecha de la cita empezando por el año, mes y al final el día\n ");
    printf("Si la fecha tiene un solo digito en mes o día, NO ponga 0 antes de el mes. \n Ejemplo: 2024-5-31\n");
    char *fecha;
    scanf("%s", fecha);
    option = es_validar_fecha(fecha);
    int turno_option = 0;
    if(option == 1){
        printf("\n\n Ingrese la hora de la cita, tiene que ser en formato de 24 horas sin minutos\n ejemplo 22 ó 10\n: \n");
        scanf("%d", &turno_option);
        get_hour_slot(turno_option);
        if(turno_option == 0){
            printf("La hora ingresada no es valida, por favor ingrese una hora entre 7 y 22\n");
            scanf("%d", &turno_option);
        }
        
        printf("El consultorio que se le asigno es el numero: %d\n", ciclo_consultorio(consultorios, turno_option));
        return 1; 
    }else{
        return 0;
    }

    
}