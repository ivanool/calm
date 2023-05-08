void enqueue(struct Appointment** front, struct Appointment** rear, char* name, char* date, char* time, int hour, int account_number) {
    struct Appointment* newAppointment = (struct Appointment*) malloc(sizeof(struct Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    newAppointment->hour = hour;
    newAppointment->account_number = account_number;
    newAppointment->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newAppointment;
        return;
    }
    (*rear)->next = newAppointment;
    *rear = newAppointment;
}