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
void obtener(char* nombre);
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
    int i = 0;
    char c;
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
            printf("\b \b");
        }
    } while (c != 13);
    *(nombre + i) = '\0';
}

void iniciar()
{
    menu();
}

void regresar()
{
    iniciar();
}

void listar()
{
    struct contacto c;
    FILE* f;
    f = fopen_s(&f, "proyecto", "rb");

    if (f == NULL)
    {
        printf("Error al abrir archivo de guardado");
        exit(1);
    }

    while (fread(&c, sizeof(c), 1, f) == 1)
    {
        printf("\n\n\nLos contactos almacenados son\n\n");
        printf("\nNombre: %s \nGenero: %s \nTelefono: %s \nCorreo electronico: \n", c.nombre, c.genero, c.telefono, c.email);
        _getch();
        system("cls");
    }

    fclose(f);
    printf("\nPresiona cualquier tecla para continuar");
    getch();
    system("cls");
    menu();
}

void agregar()
{
    system("cls");
    FILE* f;
    struct contacto c;

    f = fopen_s(&f ,"proyecto", "ab+");
    printf("Ingresa nombre: ");
    obtener(c.nombre);
    printf("\nIngresa genero: ");
    obtener(c.genero);
    printf("\nIngresa numero de telefono: ");
    obtener(c.telefono);
    printf("\nIngresa correo electronico: ");
    obtener(c.email);
    fwrite(&c, sizeof(c), 1, f);

    fflush(stdin);
    printf("\n\nContacto guardado");
    fclose(f);
    
    printf("\n\nPresiona cualquier tecla para continuar");
    _getch();
    system("cls");
    menu();
}

void buscar()
{
    struct contacto c;
    FILE* f;
    char nombre[100];
    
    fopen_s(&f, "proyecto", "rb");
    if (f == NULL)
    {
        printf("Error al abrir archivo de guardado");
        exit(1);
    }

    printf("\nIngresa del nombre de la persona a buscar: ");
    obtener(nombre);
    while (fread(&c, sizeof(c), 1, f) == 1)
    {
        if (strcmp(c.nombre, nombre) == 0)
        {
            printf("\nInformación de %s", nombre);
            printf("\nNombre: %s \nGenero: %s \nTelefono: %s \nCorreo electronico: \n", c.nombre, c.genero, c.telefono, c.email);
        }
        else
        {
            printf("Contacto no encontrado");
        }
    }

    fclose(f);
    printf("\nPresiona cualquier tecla para continuar");
    _getch();
    system("cls");
    menu();
}

void editar()
{
    printf("Editar\n");
}

void borrar()
{
    printf("Borrar\n");
}