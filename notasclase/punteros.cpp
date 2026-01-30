#include <iostream>
using namespace std;
void modificarvalorporpuntero(int *ola){
    *ola+=1;
}
int main(){
    int numero=42,arreglo[]={1,2,3,4,5};
    int *ptr=&numero,*ptrarr=arreglo;
    cout<<"valor de numero: "<<numero<<endl;
    cout<<"Valor del puntero: "<<*ptr<<endl;
    cout<<"direccion del puntero: "<<ptr<<endl;
    cout<<"direccion del valor: "<<&numero<<endl;
    int *arreglodinamico= new int[5];
    for(int i=0;i<5;i++){
        cout<<"puntero que apunta al arreglo: "<<*ptrarr+i<<endl;
        cout<<"EL arreglo: "<<arreglo[i]<<endl;
        cout<<"dirreccion del arreglo que tiene el puntero que apunta al arreglo: "<<ptrarr+i<<endl;
        cout<<"direccion de EL arreglo: "<<&arreglo[i]<<endl;
    }
    delete[] arreglodinamico;
    arreglodinamico=nullptr;
    int* punterodinamico= new int;
    *punterodinamico=500;// o int* punterodinamico= new int(500);
    cout<<"El valor del puntero dinamico: "<<*punterodinamico<<endl;
    delete punterodinamico;
    punterodinamico=nullptr;
    cout<<"El valor del puntero dinamico: "<<punterodinamico<<endl; //no se puede imprimir debido a que su valo es null
    modificarvalorporpuntero(ptr);
    cout<<"El valor se cambio gracias a la funcion modificarvalorporpuntero: "<<numero<<endl;
    return 0;
}
