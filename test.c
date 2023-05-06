#define TAM_ARRAY 16
#define NUM_CONSULTORIOS 15

#include <stdio.h>
#include <stdlib.h>

struct consultorio
{
    int num_consultorio;
    int array_bidimensional[TAM_ARRAY][2];
    struct consultorio *next;
    struct consultorio *prev;
};

void asignar_turno_previas(int consultorio, int turno, struct consultorio **consultorios)
{
    struct consultorio *current = *consultorios;
    for (int i = 0; i < consultorio; i++)
    {
        current = current->next;
    }
    current->array_bidimensional[turno][1] = 1;
    consultorios = &current;
    // printf("Funciono    ");
    // free(current);
}

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
            new_consultorio->array_bidimensional[j][0] = j + 1; // valores del 1 al 15 en la primer columna
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

void imprimir_consultorio(struct consultorio *consultorio)
{
    printf("Consultorio %d:\n", consultorio->num_consultorio);
    printf("Turno\tAsignado\n");
    for (int i = 0; i < TAM_ARRAY; i++)
    {
        printf("%d\t%d\n", consultorio->array_bidimensional[i][0], consultorio->array_bidimensional[i][1]);
    }
    printf("\n");
}

int main()
{
    struct consultorio *current = initialize_consultories();
    // struct consultorio *current = consultorios;
    // struct consultorio *current2 = current;
    asignar_turno_previas(1 - 1, 1 - 1, &current);
    while (current != NULL)
    {
        imprimir_consultorio(&current);
        current = current->prev;
    }
    return 0;
}