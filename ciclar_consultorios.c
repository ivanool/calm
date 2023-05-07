int ciclo_consultorio(struct consultorio* inicio, int turno) {
    // Recorremos la lista doblemente ligada desde el inicio
    struct consultorio* actual = inicio;
    while (actual != NULL) {
        // Ciclamos en el array bidimensional correspondiente al turno actual
        int i;
        for (i = 0; i < TAM_ARRAY; i++) {
            int index = actual->array_bidimensional[i][0];
            int value = actual->array_bidimensional[i][1];
            if (index == turno && value == 0) {
                return actual->num_consultorio;  // Retornamos el número de consultorio del primer consultorio disponible
            }
        }
        // Avanzamos al siguiente nodo de la lista
        actual = actual->next;
    }
    return -1;  // Si no hay consultorios disponibles, retornamos -1
}
