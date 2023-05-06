struct AppointmentNode *createAppointmentList(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("No se puede abrir el archivo.\n");
        return NULL;
    }

    struct AppointmentNode *head = NULL;
    struct AppointmentNode *tail = NULL;
    struct AppointmentNode *newNode = NULL;
    int turno, account_number, consultory;
    char  name[50], date[20], time[20];

    while (fscanf(fp, "%d,%d,%[^,],%[^,],%[^,],%d\n", &account_number, &consultory, name, date, time, &turno) == 6) {
        
        newNode = (struct AppointmentNode*)malloc(sizeof(struct AppointmentNode));
        newNode->account_number = account_number;

        newNode->consultory = consultory;
        newNode->name = (char*)malloc(50*sizeof(char));
        newNode->date = (char*)malloc(20*sizeof(char));
        newNode->time = (char*)malloc(20*sizeof(char));
        newNode->turno = turno;
        
        newNode->prev = NULL;
        newNode->next = NULL;
        newNode->head = NULL;
        newNode->tail = NULL;
        strcpy(newNode->name, name);
        strcpy(newNode->date, date);
        strcpy(newNode->time, time);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            head->head = head;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    tail->tail = tail;
    fclose(fp);
    return head;
}