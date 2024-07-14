#include <stdio.h>
#include <time.h>
#define V 21
#define H 65
#define N 100

typedef struct
{
    int x, y;
    int Modx, Mody;
    char imagen;
} serpiente;

typedef struct
{
    int x, y;
} fruta;

serpiente snake[N];

fruta fruta_actual;

int main()
{
    int tamaño;
    char campo[V][H];

    inicio(&tamaño, campo);

    return 0;
}

void inicio(int *tamaño, char campo[V][H])
{
    // Cabeza de la serpiente
    snake[0].x = 32;
    snake[0].y = 10;

    // Tamaño de la serpiente
    *tamaño = 4;

    // Coordenas aleatorias de la fruta
    srand(time(NULL));

    fruta_actual.x = rand() % (H - 1);
    fruta_actual.y = rand() % (V - 1);

    while (fruta_actual.x == 0)
    {
        fruta_actual.x = rand() % (H - 1);
    }

    while (fruta_actual.y == 0)
    {
        fruta_actual.y = rand() % (V - 1);
    }
}