int search_patient_by_account_number(struct patient* head, int account_number) {
    struct patient* current = head;
    while (current != NULL) {
        if (current->account_number == account_number) {
            return 1;  // Se encontró el elemento en la lista
        }
        current = current->next;
    }
    return -1;  // No se encontró el elemento en la lista
}
