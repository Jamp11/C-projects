#include <iostream>
using std::cout;
using std::cin;
using std::endl;
 
#include <cstring>
using std::string;
 
#include <cstdlib>   // system("clear")
 
//----------------------- PROTOTIPO FUNCIONES --------------------------//
 
void menu();                                       // Muestra el menu principal
void Ingresar(struct Datos Persona[],int,int);     // Ingreso de contactos
 
// Funciones para mostrar la info de los contactos
void Mostrar(struct Datos Persona[],int);           // Muestra todos los contactos
void ImprFicha(struct Datos Persona[],int,int);     // Imprime la informacion de los contactos
 
// Funciones de Busqueda
void Buscar(struct Datos Persona[],int);          // Busqueda con menu
void BuscaFicha(struct Datos Persona[],int);      // Buscar por # Ficha
void BuscaNombre(struct Datos Persona[],int);     // Buscar por Nombre
void BuscaTel(struct Datos Persona[],int);       // Buscar por Telefono
 
// Funcion Modificar
void Modificar(struct Datos Persona[],int);
 
//----------------------- ESTRUCTURAS ----------------------------------//
struct Cumpleanos
{
    string Nacimiento;
};
 
struct Datos
{
    string Nombre;
    string Direccion;
    string Telefono;
 
    Cumpleanos Fecha;
};
 
//------------------------ FUNCION PRINCIPAL ----------------------------//
int main()
{
    const int LEN = 2;   // Cantidad de Contactos a guardar
 
    Datos Persona[LEN];  // Defino la variable Persona del tipo Datos (estructura)
 
    int index = 0;  // Variable para el Indice cada contacto
    int opcion;     // Opcion Menu principal
    bool salir;     // Variable Para salir del menu principal
 
    do
    {
        menu();  // Llamada funcion menu();
 
        cout << "\n\t Elija la opcion: ";
        cin >> opcion;
        cin.ignore();
 
        switch (opcion)    // Menu principal
        {
            case 1:
                    system("clear");
                    Ingresar(Persona,index,LEN); // Llamo funcion Ingresar();
                    index++;
                    break;
            case 2:
                    system("clear");
                    Mostrar(Persona,index);  // Llamo funcion Mostrar();
                    break;
            case 3:
                    system("clear");
                    Buscar(Persona,index);  // LLamo funcion Buscar();
                    break;
            case 4:
                    system("clear");
                    Modificar(Persona,index);
                    break;
            case 6:
                    salir = true;
                    break;
            default:
                    system("clear");
                    cout << "Ingrese Opcion valida\n\n";
                    break;
        }
    }while(salir == false);
 
    return 0;
}
 
//--------------------- FUNCIONES ---------------------------//
 
/// FUNCION MENU ///
void menu()
{
    cout << "\t AGENDA INFORMATIVA \n\n";
 
    cout << "\t 1. Ingresar." << endl;
    cout << "\t 2. Mostrar todos." << endl;
    cout << "\t 3. Buscar contacto." << endl;
    cout << "\t 4. Modificar." << endl;
    cout << "\t 5. Eliminar." << endl;
    cout << "\t 6. SALIR." << endl;
}
 
/// FUNCION INGRESAR ///
 
void Ingresar(struct Datos Persona[], int numero, int TAM)  // Paso como parametros la estructura,index y LEN
{
    if(numero < TAM)  // Comparo el numero de contactos con la cantidad que se pueden guardar
    {
        cout << "\t Igresar Datos Ficha: #" << numero << endl << endl;
 
        cout << " Nombre: ";
        getline(cin,Persona[numero].Nombre);
        cout << " Direccion: ";
        getline(cin,Persona[numero].Direccion);
        cout << " Telefono: ";
        getline(cin,Persona[numero].Telefono);
        cout << " Fecha Nacimiento (DD/MM/AAAA): ";
        getline(cin, Persona[numero].Fecha.Nacimiento);
        cout << endl << endl;
    }
    else
        cout << "LLEGO AL LIMITE DE CONTACTOS PERMITIDOS" << endl << endl;
}
 
/// FUNCION IMPRFICHA ///
void ImprFicha(struct Datos Persona[], int x) // x ==> paso parametro iterador i  // Funcion Imprimir info
{
    cout << "\t Informacion ficha: #" << x << endl << endl;
    cout << " Nombre: " << Persona[x].Nombre << endl;
    cout << " Direccion: " << Persona[x].Direccion << endl;
    cout << " Telefono: " << Persona[x].Telefono << endl;
    cout << " Fecha Nacimiento (DD/MM/AAAA): " << Persona[x].Fecha.Nacimiento;
    cout << endl << endl;
}
 
/// FUNCION MOSTRAR ///
void Mostrar(struct Datos Persona[], int numero)
{
    for(int i=0 ; i<numero ; i++)
    {
        ImprFicha(Persona,i);     // Llamada Funcion para imprimir la info
    }
    cin.get();        // Pausa
    system("clear");  // Lipmpia
}
 
/// FUNCION BUSCAR ///
void Buscar(struct Datos Persona[], int numero)
{
    bool exit;  // variable para salir del menu Busqueda
    do
    {   // Menu de Busqueda
        cout << "\t BUSQUEDA: \n\n";
        cout << " 1. # Ficha" << endl;
        cout << " 2. Nombre" << endl;
        cout << " 3. Telefono" << endl;
        cout << " 4. SALIR" << endl << endl;
 
        unsigned int op;
        cout << " Indique Opcion: ";
        cin >> op;
        cin.ignore();
        cout << endl;
 
        switch(op)  // Opciones Menu de Busqueda
        {
            case 1:
                system("clear");
                BuscaFicha(Persona,numero);  // Llamada funcion BuscaFicha(); ==> Busca por # de Ficha
                break;
            case 2:
                system("clear");
                BuscaNombre(Persona,numero); // Llamada funcion BuscaNombre(); ==> Busca por Nombre
                break;
            case 3:
                system("clear");
                BuscaTel(Persona,numero); // Llamada funcion BuscaTel(); ==> Busca por Telefono
                break;
            case 4:
                exit = true;
                break;
 
            default:
                cout << "ERROR, DIGITE OPCION CORRECTA\n";
                break;
        }
    }while(exit == false);
 
    system("clear");     // Limpiar
}
 
/// FUNCION BUSCAFICHA ///
void BuscaFicha(struct Datos Persona[], int numero)
{
    cout << "\t Busqueda por ficha: \n\n";
 
    unsigned int Ficha;
    cout << " Digite # Ficha: ";
    cin >> Ficha;
    cin.ignore();
    cout << endl;
 
    for(int i=0 ; i<numero ; i++)
    {
        if(Ficha == i)
        {
            ImprFicha(Persona,i);
        }
    }
    cin.get();        // Pausa
    system("clear");  // Limpia
}
 
/// FUNCION BUSCANOMBRE ///
void BuscaNombre(struct Datos Persona[], int numero)
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
            ImprFicha(Persona,i);
        }
    }
    cin.get();
    system("clear");
}
 
/// FUNCION BUSCAFECHA ///
void BuscaTel(struct Datos Persona[], int numero)
{
    cout << "\t Busqueda por Telefono: \n\n";
 
    string tel;
    cout << "Digite Telefono: ";
    getline(cin,tel);
    cout << endl;
 
    for(int i=0 ; i<numero ; i++)
    {
        if(tel == Persona[i].Telefono)
        {
            ImprFicha(Persona,i);
        }
    }
    cin.get();
    system("clear");
}
 
/// FUNCION MODIFICAR ///
void Modificar(struct Datos Persona[], int numero)
{
    cout << " Modificar o Editar la informacion: \n\n";
 
    string tel;
    cout << "Digite Telefono: ";
    getline(cin,tel);
    cout << endl;
 
    for(int i=0 ; i<numero ; i++)
    {
        if(tel == Persona[i].Telefono)
        {
            ImprFicha(Persona,i);
 
            cout << " Nombre: ";
            getline(cin,Persona[i].Nombre);
            cout << " Direccion: ";
            getline(cin,Persona[i].Direccion);
            cout << " Telefono: ";
            getline(cin,Persona[i].Telefono);
            cout << " Fecha Nacimiento (DD/MM/AAAA): ";
            getline(cin, Persona[i].Fecha.Nacimiento);
            cout << endl << endl;
        }
    }
}
