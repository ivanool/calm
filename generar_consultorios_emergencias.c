struct consultorio_emergencia* initialize_consultories_emergencias() {
    struct consultorio_emergencia* head = NULL;
    struct consultorio_emergencia* tail = NULL;
    for (int i = 0; i < NUM_CONSULTORIOS; i++) {
        struct consultorio* new_consultorio = (struct consultorio*)malloc(sizeof(struct consultorio));
        new_consultorio->num_consultorio = i + 1;
        for (int j = 0; j < TAM_ARRAY; j++) {
            new_consultorio->array_bidimensional[j][0] = j + 1; // valores del 1 al 15 en la primer columna
            new_consultorio->array_bidimensional[j][1] = 0;
        }
        new_consultorio->next = NULL;
        new_consultorio->prev = tail;
        if (tail != NULL) {
            tail->next = new_consultorio;
        }
        tail = new_consultorio;
        if (head == NULL) {
            head = new_consultorio;
        }
    }
    return head;
}