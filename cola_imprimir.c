void display(struct Appointment* front) {
    if (front == NULL) {
        printf("La cola esta vacia\n");
        return;
    }
    struct Appointment* temp = front;
    while (temp != NULL) {
        printf("Nombre: %s\n", temp->name);
        printf("Fecha: %s\n", temp->date);
        printf("Hora: %s\n", temp->time);
        printf("Numero de cuenta: %d\n", temp->account_number);
        temp = temp->next;
    }
}