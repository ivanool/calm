void free_appointment_list(struct AppointmentNode* head) {
    struct AppointmentNode* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->name);
        free(temp->date);
        free(temp->time);
        free(temp);
    }
}
