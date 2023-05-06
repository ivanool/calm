void assign_consultory_appointments(struct Node* head, int appointments[][32], char* filename) {
    // Abrir el archivo de citas
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    // Leer las citas del archivo y actualizar el estado del array
    char line[1024];
    while (fgets(line, 1024, fp)) {
        // Leer los datos de la cita
        char* token = strtok(line, ",");
        int num_cuenta = atoi(token);

        token = strtok(NULL, ",");
        int num_consultorio = atoi(token);

        token = strtok(NULL, ",");
        char* nombre = strdup(token);

        token = strtok(NULL, ",");
        char* fecha = strdup(token);

        token = strtok(NULL, ",");
        char* hora = strdup(token);

        // Verificar si la fecha es la actual
        time_t now = time(NULL);
        struct tm* tm_struct = localtime(&now);
        char* today = asctime(tm_struct);
        today[strlen(today) - 1] = '\0'; // Eliminar el salto de línea

        if (strcmp(fecha, today) == 0) {
            // Verificar la hora de la cita
            int hour = atoi(hora);
            if (hour >= 7 && hour <= 22) { // Las horas permitidas van desde las 7:00 hasta las 22:00
                // Actualizar el estado del espacio correspondiente del array
                int index = (hour - 7) * 2; // Calcular el índice correspondiente en el array
                if (appointments[num_consultorio - 1][index] == 0) {
                    appointments[num_consultorio - 1][index] = num_cuenta;
                    appointments[num_consultorio - 1][index + 1] = 1;
                }
                else if (appointments[num_consultorio - 1][index + 1] == 0) {
                    appointments[num_consultorio - 1][index + 1] = num_cuenta;
                    appointments[num_consultorio - 1][index] = 1;
                }
                else {
                    printf("Error: el consultorio %d en la hora %d:00 ya tiene dos citas programadas\n", num_consultorio, hour);
                }
            }
        }

        free(nombre);
        free(fecha);
        free(hora);
    }

    fclose(fp);
}
