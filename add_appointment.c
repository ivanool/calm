void addAppointment(struct AppointmentNode **head_ref, int account_number, int consultory, char *name, char *date, char *time, int turno, char *filename) {
    struct AppointmentNode *new_node = (struct AppointmentNode *) malloc(sizeof(struct AppointmentNode));
    new_node->account_number = account_number;
    new_node->consultory = consultory;
    new_node->name = (char *) malloc(strlen(name) + 1);
    strcpy(new_node->name, name);
    new_node->date = (char *) malloc(strlen(date) + 1);
    strcpy(new_node->date, date);
    new_node->time = (char *) malloc(strlen(time) + 1);
    strcpy(new_node->time, time);
    new_node->turno = turno;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    new_node->head = (*head_ref);
    new_node->tail = NULL;
    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;

    // Actualizar archivo CSV
    FILE *fp;
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error al abrir el archivo %s\n", filename);
        return;
    }
    fprintf(fp, "%d,%d,%s,%s,%s,%d\n", account_number, consultory, name, date, time, turno);
    printf("Agregado con exito\n");
    fclose(fp);
}
