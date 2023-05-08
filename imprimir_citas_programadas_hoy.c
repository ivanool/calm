void printList(struct AppointmentNode *head) {
    if (head == NULL) {
        printf("La lista esta vacia\n");
        return;
    }
    struct AppointmentNode *current = head;
    while (current != NULL) {
        printf("Nombre: %s\n", current->name);
        printf("Fecha: %s\n", current->date);
        printf("Hora: %s\n", current->time);
        printf("Número de cuenta: %d\n", current->account_number);
        printf("Consultorio: %d\n", current->consultory);
        printf("Turno: %d\n", current->turno);
        printf("\n");
        current = current->next;
    }
}
