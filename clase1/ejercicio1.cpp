#include <iostream>
#include <locale>
#include <iomanip>
using namespace std;

// Función para crear un arreglo dinámico
int* crearArreglo(int tamanio) {
    
    if(tamanio>0){
        int* arreglo=new int[tamanio];
        return arreglo;
    }
    else{
        cout<<"valor no valido intentelo otra vez"<<endl;
    return nullptr; // Placeholder
    }
}

// Función para llenar el arreglo con valores del usuario
void llenarArreglo(int* arreglo, int tamanio) {
    if(arreglo!=nullptr){
        for(int i=0;i<tamanio;i++){
            cout<<"introduce el valor "<<i+1<<": "<<endl;
            cin>>arreglo[i];
        }
        cout<<"Valores introducidos con exito"<<endl;
    }
    else{
        cout<<"el arreglo no ha sido creado aun"<<endl;
    }
}

// Función para mostrar todos los elementos del arreglo
void mostrarArreglo(int* arreglo, int tamanio) {
    if(arreglo!=nullptr){
        cout<<"Los elementos del arreglos son:"<<endl;
        for(int i=0;i<tamanio;i++){
            cout<<"el valor del arreglo en el espacio "<<i+1<<"es: "<<*(arreglo+i)<<endl;
        }
        
    }
    else{
            cout<<"el arreglo esta vacio"<<endl;
        }
}

// Función para encontrar el número mayor
int encontrarMayor(int* arreglo, int tamanio) {
    int *mayor=new int(0);
    if(arreglo!=nullptr){
        for(int i=0;i<tamanio;i++){
            if(*mayor<(*arreglo+i)){
                mayor=arreglo+i;
            }
        }
       
        return *mayor; // Placeholder
    }
    else{
        cout<<"el arreglo esta vacio";
        return 0; 
    }
    
}

// Función para calcular el promedio
float calcularPromedio(int* arreglo, int tamanio) {
    float promedio=0;
    if(arreglo!=nullptr&&tamanio>0){
        for(int i=0;i<tamanio;i++){
            promedio+=*(arreglo+i);
        }
        promedio=(promedio/tamanio);
        return promedio;
    }
    else{
         return 0.0f;
    }
    // Placeholder
}

// Función para liberar la memoria del arreglo
void liberarArreglo(int*& arreglo) {
    if (arreglo!=nullptr)
    {
        delete[] arreglo;
        arreglo=nullptr;
    }
    else{
        cout<<"El arreglo ya es nulltpr";
    }
    
}

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n=== GESTIÓN DE ARREGLOS DINÁMICOS ===" << endl;
    cout << "1. Crear y llenar arreglo" << endl;
    cout << "2. Mostrar arreglo" << endl;
    cout << "3. Encontrar número mayor" << endl;
    cout << "4. Calcular promedio" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    setlocale(LC_ALL, "spanish");
    
    // Variables principales
    int* arreglo = nullptr;
    int tamanio = 0;
    
    cout << "=== GESTIÓN DE ARREGLOS DINÁMICOS ===" << endl;
    cout << "Implemente las funciones marcadas con TODO para completar el ejercicio." << endl;
    
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1: {
                // Crear y llenar arreglo
                cout << "Ingrese el tamaño del arreglo: ";
                cin >> tamanio;
                
                arreglo = crearArreglo(tamanio);
                if (arreglo != nullptr) {
                    llenarArreglo(arreglo, tamanio);
                    cout << "Arreglo creado y llenado correctamente." << endl;
                } else {
                    cout << "Error al crear el arreglo." << endl;
                }
                break;
            }
            
            case 2: {
                // Mostrar arreglo
                if (arreglo != nullptr) {
                    mostrarArreglo(arreglo, tamanio);
                } else {
                    cout << "No hay arreglo creado. Use la opción 1 primero." << endl;
                }
                break;
            }
            
            case 3: {
                // Encontrar número mayor
                if (arreglo != nullptr && tamanio > 0) {
                    int mayor = encontrarMayor(arreglo, tamanio);
                    cout << "El número mayor es: " << mayor << endl;
                } else {
                    cout << "No hay arreglo creado o está vacío." << endl;
                }
                break;
            }
            
            case 4: {
                // Calcular promedio
                if (arreglo != nullptr && tamanio > 0) {
                    float promedio = calcularPromedio(arreglo, tamanio);
                    cout << "El promedio es: " << fixed << setprecision(2) << promedio << endl;
                } else {
                    cout << "No hay arreglo creado o está vacío." << endl;
                }
                break;
            }
            
            case 5: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            
            default: {
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
            }
        }
    } while (opcion != 5);
    
    // Liberar memoria antes de salir
    liberarArreglo(arreglo);
    
    cout << "Programa finalizado. Memoria liberada." << endl;
    return 0;
}