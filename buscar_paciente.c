struct patient* find_patient_by_account_number(struct patient* head, int account_number) {
    struct patient* current = head;
    while (current != NULL) {
        if (current->account_number == account_number) {
            return current;
        }
        current = current->next;
    }
    return 0; 
}
