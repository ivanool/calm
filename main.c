#include <stdio.h>
#include <assert.h>

int suma(int a, int b) {
    return a + b;
}

int main() {
    // Prueba 1: Verificar si la suma de 2 y 3 es igual a 5
    int resultado1 = suma(2, 3);
    assert(resultado1 == 5);
    printf("Prueba 1 aprobada\n");

    // Prueba 2: Verificar si la suma de -2 y 2 es igual a 0
    int resultado2 = suma(-2, 2);
    assert(resultado2 == 0);
    printf("Prueba 2 aprobada\n");

    // Prueba 3: Verificar si la suma de 0 y 0 es igual a 0
    int resultado3 = suma(0, 0);
    assert(resultado3 == 0);
    printf("Prueba 3 aprobada\n");

    printf("Todas las pruebas han sido aprobadas\n");
    return 0;
}

