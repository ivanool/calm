// #include <stdio.h>
// #include <stdlib.h>

// #define NUM_CONSULTORIOS 15
// #define TAM_ARRAY 16

// struct consultorio {
//     int num_consultorio;
//     int array_bidimensional[TAM_ARRAY][2];
//     struct consultorio* next;
//     struct consultorio* prev;
// };


// void asignar_turno_previas(int consultorio, int turno, struct consultorio* consultorios){
//     int contador = 0;
//     struct consultorio* current = consultorios;
//     for(int i = 0; i<consultorio; i++){
//         current = current->next;
//     }
//     current->array_bidimensional[turno][1] = 1;
//     // return 0;
// }



struct consultorio* initialize_consultories() {
    struct consultorio* head = NULL;
    struct consultorio* tail = NULL;
    for (int i = 0; i < NUM_CONSULTORIOS; i++) {
        struct consultorio* new_consultorio = (struct consultorio*)malloc(sizeof(struct consultorio));
        new_consultorio->num_consultorio = i + 1;
        for (int j = 0; j < TAM_ARRAY; j++) {
            new_consultorio->array_bidimensional[j][0] = j + 1; // valores del 1 al 15 en la primer columna
            new_consultorio->array_bidimensional[j][1] = 0;
        }
        new_consultorio->next = NULL;
        new_consultorio->prev = tail;
        if (tail != NULL) {
            tail->next = new_consultorio;
        }
        tail = new_consultorio;
        if (head == NULL) {
            head = new_consultorio;
        }
    }
    return head;
}


// int main() {
//     //haz que la función llene el array bidimensional de cada consultorio con valores del 1 al 16
//     struct consultorio* consultorios = initialize_consultories();
//     struct consultorio* current = consultorios;

//     //con la ayuda de la función asignar_turno_previas, asigna turnos a las citas previas llena los turnos, 3,6,9 de todos los consultorios

//     for (int i = 0; i < NUM_CONSULTORIOS; i++) {
//         for (int j = 0; j < TAM_ARRAY; j++) {
//             // printf("%d ", current->array_bidimensional[j][0]);
//             current->array_bidimensional[j][1] = j;
//             printf("%d ", current->array_bidimensional[j][1]);
//         }
//         printf("\n");
//         current = current->next;
//     }


// }

// Este main utiliza la función initialize_consultories() modificada para inicializar una lista de consultorios con un array bidimensional de dimensiones 16x16. Luego, accede al array bidimensional del primer consultorio para imprimirlo por pantalla. Finalmente, libera la memoria de los consultorios utilizando un bucle while y la función free().








