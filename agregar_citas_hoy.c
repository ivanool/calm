// void agregar_citas_hoy(struct AppointmentNode *head0, struct NodeN *head){
//     // struct NodeN *current = NULL;
//     struct AppointmentNode *current0 = head0;
//     head = today_appointments(current0->nombre, current0->numero_cuenta, current0->turno, current0->consultorio);
// }


struct NodeN* agregar_citas_hoy(int consultorio, int turno, char *nombre, int numero_cuenta) {
    struct NodeN* current0 = NULL;
    current0 = today_appointments(nombre, numero_cuenta, turno, consultorio);
    // printf("%d", cabeza->turno);
    
    // printf("caca");
    return current0;
}


// struct nodeN* agregar_citas_hoy(struct AppointmentNode* cabeza){
//     struct AppointmentNode* current = cabeza;
//     struct nodeN* headN = NULL;
//     while(current != NULL){
//         struct nodeN* new_node = today_appointments(current->name, current->account_number, current->turno, current->consultory);
//         if(new_node != NULL){
//             // Agregar el nuevo nodo a la lista de nodos de citas de hoy
//             new_node->next = headN;
//             headN = new_node;
//         }
//         current = current->next;
//     }
//     return headN;
// }

// struct nodeN* agregar_citas_hoy(struct AppointmentNode* cabeza){
//     struct AppointmentNode* current = cabeza;
//     struct nodeN* headN = NULL;
//     while(current != NULL){
//         struct NodeN* new_node = today_appointments(current->name, current->account_number, current->turno, current->consultory);
//         if(new_node != NULL){
//             // Agregar el nuevo nodo a la lista de nodos de citas de hoy
//             new_node->next = headN;
//             if (headN != NULL) {
//                 headN->prev = new_node;
//             }
//             headN = new_node;
//         }
//         current = current->next;
//     }
//     return headN;
// }
