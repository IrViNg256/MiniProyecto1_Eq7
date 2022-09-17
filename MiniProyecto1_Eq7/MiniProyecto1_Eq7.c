#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct contacto
{
    char nombre[80];
    char genero[8];
    long int telefono;
    char email[100];
};

void menu();
void obtener();
void iniciar();
void regresar();
void listar();
void agregar();
void buscar();
void editar();
void borrar();

int main()
{
    iniciar();
    return 0;
}

void menu()
{
    system("cls");
    int opcion;
    printf("DIRECTORIO TELEFONICO\n");
    printf("1. Agregar nuevo\n");
    printf("2. Listar\n");
    printf("3. Editar\n");
    printf("4. Buscar\n");
    printf("5. Borrar\n");
    printf("6. Cerrar\n");
    printf("Elige una opcion: ");
    scanf_s("%d", &opcion);

    switch (opcion)
    {
    case 1:
        agregar();
        break;
    case 2:
        listar();
        break;
    case 3:
        editar();
        break;
    case 4:
        buscar();
        break;
    case 5:
        borrar();
        break;
    case 6:
        exit(0);
    default:
        system("cls");
        menu();
    }
}

void obtener(char* nombre)
{
    int i = 0, j;
    char c, ch;
    do
    {
        c = _getch();
        if (c != 8 && c != 13)
        {
            *(nombre + i) = c;
            _putch(c);
            i++;
        }
        if (c == 8)
        {
            if (i > 0)
            {
                i--;
            }
            for (j = 0; j < i; j++)
            {
                ch = *(nombre + j);
                _putch(ch);
            }
        }
    } while (c != 13);
}

void iniciar()
{
    menu();
}

void regresar()
{

}

void listar()
{
    printf("Listar\n");
}

void agregar()
{
    printf("Agregar\n");
}

void buscar()
{
    printf("Buscar\n");
}

void editar()
{
    printf("Editar\n");
}

void borrar()
{
    printf("Borrar\n");
}