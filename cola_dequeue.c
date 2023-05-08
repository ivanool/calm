
void dequeue(struct Appointment** front, struct Appointment** rear) {
    if (*front == NULL) {
        return;
    }
    struct Appointment* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
}