

struct consultorio *initialize_consultories()
{
    struct consultorio *head = NULL;
    struct consultorio *tail = NULL;
    for (int i = 0; i < NUM_CONSULTORIOS; i++)
    {
        struct consultorio *new_consultorio = (struct consultorio *)malloc(sizeof(struct consultorio));
        new_consultorio->num_consultorio = i + 1;
        for (int j = 0; j < TAM_ARRAY; j++)
        {
            new_consultorio->array_bidimensional[j][0] = j + 1; 
            new_consultorio->array_bidimensional[j][1] = 0;
        }
        new_consultorio->next = NULL;
        new_consultorio->prev = tail;
        if (tail != NULL)
        {
            tail->next = new_consultorio;
        }
        tail = new_consultorio;
        if (head == NULL)
        {
            head = new_consultorio;
        }
    }
    return head;
}




