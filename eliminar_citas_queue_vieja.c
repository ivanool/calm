int remove_old_appointments(struct Appointment *queue) {
    int current_hour = get_current_hour(); // Obtener la hora actual
    
    // Recorrer la cola
    // struct Appointment *current = queue->head;
    while (queue != NULL) {
        // Verificar si la hora de la cita es menor a la hora actual
        if (queue->hour < current_hour) {
            // Eliminar el nodo de la cola
            return 1;
        }
        else {
            // Si no se cumple la condición, avanzar al siguiente nodo
            // current = current->next;
            return 0;
        }
    }
}
