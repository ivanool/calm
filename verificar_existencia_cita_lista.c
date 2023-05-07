int verificar_disponibilidad_cita(struct AppointmentNode *head, int consultorio, int turno, char *fecha){
    printf("Funcion llamada\n");
    while(head != NULL){
        printf("%s", head->date);
        printf("%d", head->consultory);
        printf("%d", head->turno);
        if(strcmp(head->date, fecha) == 0 && head->consultory == consultorio && head->turno == turno){
            // printf("%s", head->date);
            // printf("%d", head->consultory);
            return 0; // no está disponible
        }
        head = head->next;
    }
    return 1; // está disponible
}