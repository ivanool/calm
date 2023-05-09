int verificar_disponibilidad_cita(struct AppointmentNode *head, int consultorio, int turno, char *fecha){
    if(head == NULL) {
        printf("La lista de citas está vacía\n");
        return 1; 
    }
    while(head != NULL){

        if(strcmp(head->date, fecha) == 0 && head->consultory == consultorio && head->turno == turno){

            return 0; 
        }
        head = head->next;
    }
    return 1; 
}
