void free_patient_list(struct patient* head) {
    struct patient* current = head;
    while (current != NULL) {
        struct patient* temp = current;
        current = current->next;
        free(temp);
    }
}
