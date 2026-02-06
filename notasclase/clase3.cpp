#include <iostream>
using namespace std;
int* crearreglo(int tamanio){
    int* arreglo= new int[tamanio];
    return arreglo; 
}
void llenararreglo(int* arreglo,int* tamanio){
    for(int i=0;i<*tamanio;i++){
            cout<<"introduce el valor "<<i+1<<": "<<endl;
            cin>>arreglo[i];
        }
        cout<<"Valores introducidos con exito"<<endl;
}
int* extenerarr(int* arreglo,int* tamanio){
    *tamanio=(*tamanio)*2;
    int* arreglonew=new int[*tamanio];
    for(int i=0;i<*tamanio/2;i++){
        arreglonew[i]=arreglo[i];
    }
    delete[] arreglo;
    arreglo=nullptr;
    return arreglonew;
}
void mostrar(int* arreglo,int* tamanio){
    for(int i=0;i<*tamanio;i++){
        cout<<"El valor del array en el espacio "<<i+1<<": "<<*(arreglo+i)<<endl;
    }
}
int main(){
    int* arreglo;
    int* tamanio= new int(5);
    arreglo=crearreglo(*tamanio);
    llenararreglo(arreglo,tamanio);
    mostrar(arreglo,tamanio);
    arreglo=extenerarr(arreglo,tamanio);
    arreglo[6]=2;
    cout<<*(arreglo+6);
    return 0;
}