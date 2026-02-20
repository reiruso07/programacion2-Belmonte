#include <iostream>
#include <fstream> // Libreria para manejar archivos
#include <string> // Para usar strings
using namespace std;
struct Producto
{
    int id;
    string codigo;
    string nombre;
    string descripcion;
    int idProveedor;
    float precio;
    int stock;
    string fecharegistro;
};

int main(){
    int x=0;
    int y=0;
    int z;
    int idmayyor=0,preciomayor=0;
    int stockmayor,iddtockmayor=0;
    ifstream archivo("csv_productos.csv");
    if(archivo.is_open()){
        Producto* productos=new Producto[63];
        string linea;
        while(getline(archivo,linea)){
            if(x>0){
                for(int i=0;i<linea.size();i++){
                if(linea[i]==','&&y==0){
                    productos[x-1].id=stoi(linea.substr(z,i));
                    cout<<"Id: "<<stoi(linea.substr(z,i))<<endl;
                    y++;
                    z=i;
                }
                else if(linea[i]==','&&y==1){
                    productos[x-1].codigo=linea.substr(z+1,i-3);
                    cout<<"Codigo: "<<linea.substr(z+1,i)<<endl;
                    y++;
                    z=i;
                }
                else if(linea[i]==','&&y==2){
                    productos[x-1].nombre=linea.substr(z+1,i-1);
                    cout<<"nombre: "<<linea.substr(z+1,i)<<endl;
                    y++;
                    z=i;
                }
                else if(linea[i]==','&&y==3){
                    cout<<"i: "<<i<<endl;
                    productos[x-1].descripcion=linea.substr(z+1,i);
                    cout<<"descripcion: "<<linea.substr(z+1,i)<<endl;
                    y++;
                    z=i;
                }
                else if(linea[i]==','&&y==4){
                    productos[x-1].idProveedor=stoi(linea.substr(z+1,i-1));
                    cout<<"idProveedor: "<<stoi(linea.substr(z+1,i))<<endl;
                    y++;
                    z=i;
                }
                else if(linea[i]==','&&y==5){
                    productos[x-1].precio=stof(linea.substr(z+1,i-1));
                    cout<<"precio: "<<stof(linea.substr(z+1,i))<<endl;
                    y++;
                    z=i;
                }
                else if(linea[i]==','&&y==6){
                    productos[x-1].stock=stoi(linea.substr(z+1,i-1));
                    cout<<"stock: "<<stoi(linea.substr(z+1,i))<<endl;
                    y++;
                    z=i;
                }
                else if(y==7){
                    productos[x-1].fecharegistro=(linea.substr(z+1,linea.size()));
                    cout<<"fecharegistro: "<<(linea.substr(z+1,i))<<endl;
                    y++;
                    z=i;
                }
            }
            y=0;
            
            z=0;
            }
            x++;
        }
        cout<<x;
        for(int i=0;i<x-1;i++){
            if(productos[i].precio>preciomayor){
                preciomayor=productos[i].precio;
                idmayyor=productos[i].id;
            }
            if(productos[i].stock>stockmayor){
                iddtockmayor=productos[i].id;
                stockmayor=productos[i].stock;
            }
                cout<<"id: "<<productos[i].id<<endl;
                cout<<"codigo: "<<productos[i].codigo<<endl;
                cout<<"nombre: "<<productos[i].nombre<<endl;
                cout<<"descripcion: "<<productos[i].descripcion<<endl;
                cout<<"idProveedor: "<<productos[i].idProveedor<<endl;
                cout<<"precio: "<<productos[i].precio<<endl;
                cout<<"stock: "<<productos[i].stock<<endl;
                cout<<"fecharegistro: "<<productos[i].fecharegistro<<endl;
            }
        cout<<"El producto con mayor precio es el id: "<<idmayyor<<" con un precio de: "<<preciomayor<<endl;
        cout<<"El producto con mayor stock es el id: "<<iddtockmayor<<" con un stock de: "<<stockmayor<<endl;
        delete[] productos;
    }
}