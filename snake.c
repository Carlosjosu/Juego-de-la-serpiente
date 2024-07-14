#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 1
#define DOWN 2
#define V 21
#define H 65
#define N 100

typedef struct
{
    int x, y;
    int Modx, Mody;
    char imagen;
} snk;

typedef struct
{
    int x, y;
} fruta;

snk snake[N];
fruta fruta_actual;

void Inicio_Campo(char campo[V][H])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (i == 0 || i == V - 1 || j == 0 || j == H - 1)
            {
                campo[i][j] = '#';
            }
            else
            {
                campo[i][j] = ' ';
            }
        }
    }
}

void Inicio_Datos(char campo[V][H], int tamaño)
{
    for (int i = 1; i < tamaño; i++)
    {
        snake[i].x = snake[i - 1].x - 1;
        snake[i].y = snake[i - 1].y;

        snake[i].imagen = 'X';
    }

    snake[0].imagen = 'O';

    for (int i = 0; i < tamaño; i++)
    {
        campo[snake[i].y][snake[i].x] = snake[i].imagen;
    }
    campo[fruta_actual.y][fruta_actual.x] = '*';
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

    for (int i = 0; i < *tamaño; i++)
    {
        snake[i].Modx = 1;
        snake[i].Mody = 0;
    }

    Inicio_Campo(campo);
    Inicio_Datos(campo, *tamaño);
}

// Se crea el campo de juego

void dibujar(char campo[V][H])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < H; j++)
        {
            printf("%c", campo[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int tamaño;
    char campo[V][H];

    inicio(&tamaño, campo);
    dibujar(campo);

    system("pause");
    return 0;
}
