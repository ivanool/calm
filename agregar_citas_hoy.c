struct NodeN* agregar_citas_hoy(int consultorio, int turno, char *nombre, int numero_cuenta) {
    struct NodeN* current0 = NULL;
    current0 = today_appointments(nombre, numero_cuenta, turno, consultorio);
    return current0;
}
