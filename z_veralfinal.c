void assign_consultory_appointments(struct Node* head, int appointments[][32], char* filename) {

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }


    char line[1024];
    while (fgets(line, 1024, fp)) {

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


        time_t now = time(NULL);
        struct tm* tm_struct = localtime(&now);
        char* today = asctime(tm_struct);
        today[strlen(today) - 1] = '\0'; 

        if (strcmp(fecha, today) == 0) {

            int hour = atoi(hora);
            if (hour >= 7 && hour <= 22) { 
          
                int index = (hour - 7) * 2; 
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
