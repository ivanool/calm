int verificar_fecha_hora(struct AppointmentNode **head){
    

    struct nodeN *citas;
    int resultado_fecha = 0;
    char *fecha = (*head)->date;
    resultado_fecha = is_same_day(fecha);
    // printf("%d\n", resultado_fecha);

    if(resultado_fecha == 1){
        return 1;
    }
    else{
        return 0;
    }

}
