int is_same_day(char *date_str) {
    //verifica si la fecha es la misma que la actual. Regresa 1 si es la misma, 0 si es diferente.
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    int current_year = tm_now->tm_year + 1900;
    int current_month = tm_now->tm_mon + 1;
    int current_day = tm_now->tm_mday;

    int input_year, input_month, input_day;
    sscanf(date_str, "%d-%d-%d", &input_year, &input_month, &input_day);

    char current_date[11];
    sprintf(current_date, "%d-%d-%d", current_year, current_month, current_day);

    if (input_year == current_year && input_month == current_month && input_day == current_day) {
        return 1;
    } else {
        return 0;
    }
}
// int main() {
//     char input_date[11];
//     printf("Ingrese una fecha en formato yyyy-mm-dd: ");
//     fgets(input_date, 11, stdin);

//     int result = is_same_day(input_date);
//     if (result == 1) {
//         printf("La fecha ingresada es el mismo día que hoy.\n");
//     } else {
//         printf("La fecha ingresada no es el mismo día que hoy.\n");
//     }

//     return 0;
// }
