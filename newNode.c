
struct NodeN* new_node(char* nombre, int numero_cuenta, int turno, int consultorio) {
    struct NodeN* node = malloc(sizeof(struct NodeN));
    node->nombre = nombre;
    node->numero_cuenta = numero_cuenta;
    node->turno = turno;
    node->consultorio = consultorio;
    node->prev = NULL;
    node->next = NULL;
    return node;
}