

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
    // printf("\n %d", head->turno);
    // printf("Karla");
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






    /*

    karla
    El sistema se inicializa en este orden:

    1.- Leemos el archivo patients.csv y creamos una lista de pacientes.
    2.- Leemos el archivo appointments.csv y creamos una lista de citas.
    3.- Inicializamos los consultorios.
        Ya que tenemos inicializados los consultorios debemos de leer la lista
        que contiene las citas programadas para hoy. Con el verificador vamos a ver
        si la fecha es de hoy, si es de hoy entonces la agregamos a la lista de citas 
        que se van a atender hoy y le asignamos el consultorio correspondiente. Esto
        se ejecuta así:
        3.1-verificador de citas hoy. Aquí verificamos las citas que tenemos programadas
        para hoy. Además de regresar 1 o un 0, pasamos a las funciones de citas_hoy y }
        asignar_turno_citas_previas. 
        3.1.2- Asignar_turno_citas_previas. Aquí asignamos el turno a las citas que se tienen
        que atender hoy.
        3.2-agregar_citas_hoy. Aquí agregamos las citas que se van a atender hoy a una lista

        Una vez eso hemos terminado. Ahora solo establecemos el espacio para las citas de 
        emergencia y esta todo listo.

        Una vez hecho eso podríamos decir que esta inicializado

    */