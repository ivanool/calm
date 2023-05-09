int ciclo_consultorio(struct consultorio* inicio, int turno) {
    struct consultorio* actual = inicio;
    while (actual != NULL) {
        int i;
        for (i = 0; i < TAM_ARRAY; i++) {
            int index = actual->array_bidimensional[i][0];
            int value = actual->array_bidimensional[i][1];
            if (index == turno && value == 0) {
                return actual->num_consultorio; 
            }
        }
        actual = actual->next;
    }
    return -1;
}
