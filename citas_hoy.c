

struct NodeN* today_appointments(char* nombre, int numero_cuenta, int turno, int consultorio) {
    static struct NodeN* head = NULL;
    struct NodeN* new_node_ptr = new_node(nombre, numero_cuenta, turno, consultorio);
    if (head == NULL) {
        head = new_node_ptr;
    } else {
        struct NodeN* node = head;
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = new_node_ptr;
        new_node_ptr->prev = node;
    }
    return head;
}

// int main() {
//     struct NodeN* head = NULL;

//     // Agregar nuevas citas
//     head = today_appointments("Juan", 12345, 1, 1);
//     head = today_appointments("Maria", 67890, 2, 2);
//     head = today_appointments("Pedro", 24680, 1, 3);

//     // Imprimir la lista completa de citas
//     printf("Nombre\tNumero de cuenta\tTurno\tConsultorio\n");
//     struct NodeN* node = head;
//     while (node != NULL) {
//         printf("%s\t%d\t\t%d\t%d\n", node->nombre, node->numero_cuenta, node->turno, node->consultorio);
//         node = node->next;
//     }

//     return 0;
// }
