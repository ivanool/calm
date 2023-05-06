void imprimir_consultorio(struct consultorio* consultorio) {
    printf("Consultorio %d:\n", consultorio->num_consultorio);
    printf("Turno\tAsignado\n");
    for (int i = 0; i < TAM_ARRAY; i++) {
        printf("%d\t%d\n", consultorio->array_bidimensional[i][0], consultorio->array_bidimensional[i][1]);
    }
    printf("\n");
}
