#include <stdlib.h>
#include <string.h>
#include "iostream"
 using namespace std;
 
//----------------------- PROTOTIPO DE LAS FUNCIONES
 
void Ingresar(struct Alumnos Persona[],int numero,int tam);     // Ingreso de alumnos
 
// Funciones para mostrar la informacion de los contactos
void Mostrar(struct Alumnos Persona[],int numero);           // Muestra todos los alumnos
void ImprAlumno(struct Alumnos Persona[],int x);     // Imprime la informacion de alumno requerido alumnos
 
// Funciones de Busqueda
void Buscar(struct Alumnos Persona[],int numero);         // Menu de busqueda
void BuscaNu(struct Alumnos Persona[], int numero);       // Buscar por # de alumno
void BuscaNombre(struct Alumnos Persona[],int numero);     // Buscar por Nombre
void BuscaGra(struct Alumnos Persona[],int numero);       // Buscar por Grado
 
//----------------------- ESTRUCTURA
 
struct Alumnos{
    string Nombre;
    string Grupo;
    string Grado;
    string Promedio;
};
 
//------------------------ PROGRAMA
int main()
{
    int con = 1000;   // Cantidad de alumnos a guardar
 
    Alumnos Persona[con];  // Defino la variable Persona del tipo Datos (estructura)
 
    int ind = 1;  // Variable para el Indice cada alumno
    int opcion;     // Opcion Menu principal
    bool salir;     // Variable Para salir del menu principal (ciclo)
    cout << "\tHola y bienvenido a la lista de alumnos"<<endl;
    cout << "\tBy Antonio Milanes"<<endl;
 
    do
    {
    	    cout << endl;
            cout << "\t 1. Ingresar Alumno." << endl;
            cout << "\t 2. Mostrar todos los Alumnos." << endl;
            cout << "\t 3. Buscar Alumnos." << endl;
            cout << "\t 4. SALIR." << endl;
 
        cout << "\n\t Elija la opcion: ";
        cin >> opcion;
        cin.ignore();
 
        switch (opcion)    // Menu principal
        {
            case 1:
                    system("cls");
                    Ingresar(Persona,ind,con); // Llamo funcion Ingresar();
                    ind++;
                    break;
            case 2:
                    system("cls");
                    Mostrar(Persona,ind);  // Llamo funcion Mostrar();
                    break;
            case 3:
                    system("cls");
                    Buscar(Persona,ind);  // LLamo funcion Buscar();
                    break;
            case 4:
                    salir = true; // Se cierra el ciclo
                    break;
            default:
                    system("cls");
                    cout << " -Ingrese Opcion valida-"<<endl<<endl;
                    break;
        }
    }while(salir == false);
 
    return 0;
}
 
//----------------------------- DEFINICIONES DE LAS FUNCIONES
 
// FUNCION INGRESAR //
 
void Ingresar(struct Alumnos Persona[], int numero, int Tam)  // Paso como parametros la estructura,ind y con
{
    if(numero < Tam)  // Comparo el numero de alumnos con la cantidad que se pueden guardar
    {
        cout << "\t Igresar Datos del alumno: #" << numero << endl << endl;
 
        cout << " Nombre: ";
        getline(cin,Persona[numero].Nombre);
        cout << " Grupo: ";
        getline(cin,Persona[numero].Grupo);
        cout << " Grado: ";
        getline(cin,Persona[numero].Grado);
        cout << " Promedio: ";
        getline(cin, Persona[numero].Promedio);
        cout << endl << endl;
    }
    else
        cout << "LLEGO AL LIMITE DE ALUMNOS PERMITIDOS" << endl << endl;
}

// FUNCION MOSTRAR //
void Mostrar(struct Alumnos Persona[], int numero)
{
    for(int i=1 ; i<numero ; i++)
    {
        ImprAlumno(Persona,i);     // Llamada Funcion para imprimir la info
    }
    cin.get();        // Pausa
    system("cls");  // Limpia
}
 
// FUNCION IMPRALU //
void ImprAlumno(struct Alumnos Persona[], int x) // x --> paso parametro iterador i  // Funcion Imprimir info
{
    cout << "\t Informacion alumno: #" << x << endl << endl;
    cout << " Nombre: " << Persona[x].Nombre << endl;
    cout << " Grupo: " << Persona[x].Grupo << endl;
    cout << " Grado: " << Persona[x].Grado << endl;
    cout << " Promedio: " << Persona[x].Promedio;
    cout << endl << endl;
}
 
// FUNCION BUSCAR //
void Buscar(struct Alumnos Persona[], int numero)
{
    bool exit;  // variable para salir del menu Busqueda
    do
    {   // Menu de Busqueda
        cout << "\t BUSQUEDA: \n\n";
        cout << " 1. # de alumno" << endl;
        cout << " 2. Nombre" << endl;
        cout << " 3. Grado" << endl;
        cout << " 4. SALIR" << endl << endl;
 
        int op;
        cout << " Indique Opcion: ";
        cin >> op;
        cin.ignore();
        cout << endl;
 
        switch(op)  // Opciones Menu de Busqueda
        {
            case 1:
                system("cls");
                BuscaNu(Persona,numero);  // Llamada funcion BuscaNu --> Busca por # de alumno
                break;
            case 2:
                system("cls");
                BuscaNombre(Persona,numero); // Llamada funcion BuscaNombre --> Busca por Nombre
                break;
            case 3:
                system("cls");
                BuscaGra(Persona,numero); // Llamada funcion BuscaGra --> Busca por el grado
                break;
            case 4:
                exit = true;
                break;
 
            default:
                cout << "-Ingrese opcion valida-"<<endl;
                break;
        }
    }while(exit == false);
 
    system("cls");    // Limpiar
}
 
// FUNCION BUSCANU //
void BuscaNu(struct Alumnos Persona[], int numero)
{
    cout << "\t Busqueda por numero de alumno: \n\n";
 
    int alumno;
    cout << " Digite # de alumno: ";
    cin >> alumno;
    cin.ignore();
    cout << endl;
 
    for(int i=1 ; i<numero ; i++)
    {
        if(alumno == i)
        {
            ImprAlumno(Persona,i);
        }
    }
    cin.get();        // Pausa
    system("cls");  // Limpia
}
 
// FUNCION BUSCANOMBRE //
void BuscaNombre(struct Alumnos Persona[], int numero)
{
    cout << "\t Busqueda por nombre: \n\n";
 
    string nomb;
    cout << " Digite el nombre: ";
    getline(cin,nomb);
    cout <<  endl;
 
    for(int i=0 ; i<numero ; i++)
    {
        if(nomb == Persona[i].Nombre)
        {
            ImprAlumno(Persona,i);
        }
    }
    cin.get();
    system("cls");
}
 
// FUNCION BUSCAGRADO //
void BuscaGra(struct Alumnos Persona[], int numero)
{
    cout << "\t Busqueda por Grado: \n\n";
 
    string Gra;
    cout << "Grado: ";
    getline(cin,Gra);
    cout << endl;
 
    for(int i=0 ; i<numero ; i++)
    {
        if(Gra == Persona[i].Grado)
        {
            ImprAlumno(Persona,i);
        }
    }
    cin.get();
    system("cls");
}
