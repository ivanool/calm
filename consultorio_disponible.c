


int buscar_consultorio_disponible(struct consultorio* ptr_consultorio, int hora) {
    for (int i = 0; i < TAM_ARRAY; i++) {
        if (ptr_consultorio->array_bidimensional[hora][i] == 0) {
            printf("el consultorio disponible es %d \n", i);
            return i+1;
        }
    }
    return -1;
}
