void deleteAppointment(struct AppointmentNode **head_ref, int account_number, char *filename) {
    struct AppointmentNode *temp = *head_ref;
    while (temp != NULL && temp->account_number != account_number) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("La cita con el número de cuenta %d no se encuentra en la lista\n", account_number);
        return;
    }
    if (temp == *head_ref) {
        *head_ref = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);

    // Eliminar la cita del archivo CSV
    FILE *fp, *temp_file;
    char buffer[MAX_LINE_LENGTH];
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error al abrir el archivo %s\n", filename);
        return;
    }
    temp_file = fopen("temp.csv", "w");
    if (temp_file == NULL) {
        printf("Error al crear archivo temporal\n");
        return;
    }
    while (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL) {
        int current_account_number;
        sscanf(buffer, "%d", &current_account_number);
        if (current_account_number != account_number) {
            fputs(buffer, temp_file);
        }
    }
    fclose(fp);
    fclose(temp_file);
    remove(filename);
    rename("temp.csv", filename);
    printf("Cita con el número de cuenta %d eliminada exitosamente\n", account_number);
}
