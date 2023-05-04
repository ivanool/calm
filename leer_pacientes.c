//lee la información del archivo csv y lo almacena en una lista
#include <stdint.h>


struct node{
    char* nombre;
    uint8_t edad;
    char* fecha_nacimiento;
    uint8_t sexo;
    int num_cuenta;
    struct node* prev;
    struct node* next;
}