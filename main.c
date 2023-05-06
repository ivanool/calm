#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define NUM_CONSULTORIOS 15
#define TAM_ARRAY 16
#define MAX_STRING_LENGTH 100

struct NodeN {
    char* nombre;
    int numero_cuenta;
    int turno;
    int consultorio;
    struct NodeN* prev;
    struct NodeN* next;
};


struct appointment {
    char patient_name[50];
    char appointment_date[11];
    char appointment_time[6];
    int room_number;
    struct appointment* next;
};



struct patient {
    char name[MAX_STRING_LENGTH];
    int age;
    int account_number;
    char sex[MAX_STRING_LENGTH];
    char birthdate[MAX_STRING_LENGTH];
    struct patient* next;
    struct patient* prev;
};

struct AppointmentNode {
    int account_number;
    int consultory;
    char *name;
    char *date;
    char *time;
    int turno;
    struct AppointmentNode *prev;
    struct AppointmentNode *next;
    struct AppointmentNode *head;
    struct AppointmentNode *tail;
};

// struct Node {
//     int num_consultorio;
//     int citas_hoy;
//     int disponible;
//     int horarios[32][2]; // Array bidimensional para almacenar el estatus y el turno
//     struct Node* next;
//     struct Node* prev;
// };

struct consultorio_emergencia{
    int num_consultorio;
    int array_bidimensional[TAM_ARRAY][2];
    struct consultorio_emergencia* next;
    struct consultorio_emergencia* prev;
};




struct consultorio {
    int num_consultorio;
    int array_bidimensional[TAM_ARRAY][2];
    struct consultorio* next;
    struct consultorio* prev;
};



#include "menu.c"

int main(){
    menu();
}