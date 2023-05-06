void verificar_fecha_hora(struct AppointmentNode **head, struct consultorio **consultorios, struct NodeN **citas){
    
    int resultado_fecha = 0;

    char *fecha = (*head)->date;
    resultado_fecha = is_same_day(fecha);
    if(resultado_fecha == 1){
        agregar_citas_hoy(&head, &citas);
        asignar_turno_previas((*head)->consultory, (*head)->turno, &consultorios);
    }
}
