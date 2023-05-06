// void asignar_turno_previas(int consultorio, int turno, struct consultorio* consultorios){
//     int contador = 0;
//     // struct consultorio* current = consultorios;
//     for(int i = 0; i<consultorio; i++){
//         current = current->next;
//     }
//     current->array_bidimensional[turno][1] = 1;
//     free(current);
// }


void asignar_turno_previas(int consultorio, int turno, struct consultorio** consultorios){
    struct consultorio* current = *consultorios;
    for(int i = 0; i<consultorio; i++){
        current = current->next;
    }
    current->array_bidimensional[turno][1] = 1;
    consultorios = &current;
    free(current);
}
