// int isConsultorioAvailable(struct consultorio* start_consultorio, int index, int current_hour) {
//     struct consultorio* curr_consultorio = start_consultorio;
//     while (curr_consultorio != NULL) {
//         if (curr_consultorio->num_consultorio == index) {
//             // Consultorio encontrado, revisamos si está disponible
//             int row, col;
//             for (row = 0; row < TAM_ARRAY; row++) {
//                 if (curr_consultorio->array_bidimensional[row][0] == current_hour) {
//                     // Hora coincide
//                     if (curr_consultorio->array_bidimensional[row][1] == 0) {
//                         // Estado es igual a 0, por lo tanto está disponible
//                         return 1;
//                     } else {
//                         // Estado es diferente de 0, por lo tanto no está disponible
//                         return 0;
//                     }
//                 }
//             }
//             // Si llegamos aquí, la hora no se encontró en el array, lo cual significa que el consultorio está disponible
//             return 1;
//         }
//         curr_consultorio = curr_consultorio->next;
//     }
//     // Si llegamos aquí, el consultorio no se encontró en la lista, lo cual significa que está disponible
//     return 1;
// }


int buscar_consultorio_disponible(struct consultorio* ptr_consultorio, int hora) {
    for (int i = 0; i < TAM_ARRAY; i++) {
        if (ptr_consultorio->array_bidimensional[hora][i] == 0) {
            return ptr_consultorio->num_consultorio;
        }
    }
    return -1;
}
