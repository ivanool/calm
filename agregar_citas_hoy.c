// void agregar_citas_hoy(struct AppointmentNode *head0, struct NodeN *head){
//     // struct NodeN *current = NULL;
//     struct AppointmentNode *current0 = head0;
//     head = today_appointments(current0->nombre, current0->numero_cuenta, current0->turno, current0->consultorio);
// }


void agregar_citas_hoy(struct AppointmentNode *head0, struct NodeN **head){
    struct AppointmentNode *current0 = head0;
    while(current0 != NULL){
        head = today_appointments(current0->name, current0->account_number, current0->turno, current0->consultory);
        current0 = current0->next;
    }
    // head = today_appointments(current0->name, current0->account_number, current0->turno, current0->consultory);
}
