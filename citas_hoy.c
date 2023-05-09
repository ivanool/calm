

// struct NodeN today_appointments(char* nombre, int numero_cuenta, int turno, int consultorio) {
//     static struct NodeN* head = NULL;
//     struct NodeN* new_node_ptr = new_node(nombre, numero_cuenta, turno, consultorio);
//     if (head == NULL) {
//         head = new_node_ptr;
//     } else {
//         struct NodeN* node = head;
//         while (node->next != NULL) {
//             node = node->next;
//         }
//         node->next = new_node_ptr;
//         new_node_ptr->prev = node;
//     }
//     return *head;
// }

struct NodeN* today_appointments(char* nombre, int numero_cuenta, int turno, int consultorio) {
    struct NodeN* new_node_ptr = new_node(nombre, numero_cuenta, turno, consultorio);
    if (new_node_ptr == NULL) {
        return NULL;
    }
    static struct NodeN* head = NULL;
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
