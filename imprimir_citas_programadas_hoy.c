void printAppointments(struct NodeN* head) {
    if (head == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }
    struct NodeN* current = head;
    while (current != NULL) {
        printf("Nombre: %s\n", current->nombre);
        printf("Numero de cuenta: %d\n", current->numero_cuenta);
        printf("Turno: %d\n", current->turno);
        printf("Consultorio: %d\n", current->consultorio);
        printf("\n");
        current = current->next;
    }
}
