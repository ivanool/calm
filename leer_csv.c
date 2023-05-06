

struct patient* read_patient_info_from_csv(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    struct patient* head = NULL;
    struct patient* tail = NULL;
    char line[MAX_STRING_LENGTH];
    while (fgets(line, MAX_STRING_LENGTH, fp)) {
        struct patient* new_patient = malloc(sizeof(struct patient));
        if (new_patient == NULL) {
            printf("Error allocating memory for new patient\n");
            fclose(fp);
            return NULL;
        }

        char* token = strtok(line, ",");
        strncpy(new_patient->name, token, MAX_STRING_LENGTH);
        token = strtok(NULL, ",");
        new_patient->age = atoi(token);
        token = strtok(NULL, ",");
        new_patient->account_number = atoi(token);
        token = strtok(NULL, ",");
        strncpy(new_patient->sex, token, MAX_STRING_LENGTH);
        token = strtok(NULL, ",");
        strncpy(new_patient->birthdate, token, MAX_STRING_LENGTH);
        new_patient->next = NULL;
        new_patient->prev = NULL;

        if (head == NULL) {
            head = new_patient;
            tail = new_patient;
        } else {
            tail->next = new_patient;
            new_patient->prev = tail;
            tail = new_patient;
        }
    }

    fclose(fp);
    return head;
}

// int main() {
//     struct patient* patients = read_patient_info_from_csv("pacientes.csv");
//     if (patients == NULL){
//         printf("Error reading patient info from CSV file\n");
//         return 1;
//     }

//     struct patient* current_patient = patients;
//     while (current_patient != NULL) {
//         printf("Name: %s\n", current_patient->name);
//         printf("Age: %d\n", current_patient->age);
//         printf("Account number: %d\n", current_patient->account_number);
//         printf("Sex: %s\n", current_patient->sex);
//         printf("Birthdate: %s\n", current_patient->birthdate);
//         printf("\n");
//         current_patient = current_patient->next;
//     }

//     return 0;
// }
