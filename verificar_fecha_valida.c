// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>

// #include <stdio.h>
// #include <time.h>
// #include <string.h>

int es_fecha_valida(char* fecha) {
    time_t tiempo_actual = time(NULL);
    struct tm *tm_actual = localtime(&tiempo_actual);
    int anio_actual = tm_actual->tm_year + 1900;
    int mes_actual = tm_actual->tm_mon + 1;
    int dia_actual = tm_actual->tm_mday;
    int anio, mes, dia;
    sscanf(fecha, "%d-%d-%d", &anio, &mes, &dia);
    
    if (anio > anio_actual || (anio == anio_actual && mes > mes_actual) || (anio == anio_actual && mes == mes_actual && dia > dia_actual)) {
        if(mes > 12 || mes < 1){
            return 0;
        }
        if (mes == 2) {
            if (dia > 29 || dia < 1) {
                return 0;
            }
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            if (dia > 30 || dia < 1) {
                return 0;
            }
        } else {
            if (dia > 31 || dia < 1) {
                return 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
}



// int main() {
//     char fecha[11];
//     printf("Ingresa una fecha en formato YYYY-MM-DD: ");
//     scanf("%s", fecha);
    
//     if (es_fecha_valida(fecha)) {
//         printf("La fecha proporcionada es mayor que la fecha actual.\n");
//     } else {
//         printf("La fecha proporcionada no es mayor que la fecha actual.\n");
//     }
    
//     return 0;
// }



