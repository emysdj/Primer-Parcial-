#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const char *nombre_archivo = "archivo.dat";
const char *nombre2 = "temporal.dat";

struct Empleado{

	int codigo;
	char nombres[50];
	char apellidos[50];
	char puesto[50];
	int sueldo;
	int boni;
};
void ingresar();
void menu();
void abrir();
void buscar_id();
void eliminar();
void modificar_empleado();
main(){
    	system("title Emily Juarez Carne: 3590-20-4067");
	menu();
}

void menu(){
    system("cls");
    int opc;
    do{
        cout<<"\n\t\t Empleados \n\n"<<endl;
        cout<<"\n1. Ingresar."<<endl;
        cout<<"2. Ver Empleados."<<endl;
        cout<<"3. Buscar Empleado."<<endl;
        cout<<"4. Eliminar."<<endl;
        cout<<"5. Editar Dato."<<endl;
        cout<<"6. Salir."<<endl;
        cout<<"Digite una opcion: ";
        cin>>opc;

        switch(opc){
            case 1: ingresar(); break;
            case 2: abrir(); break;
            case 3: buscar_id(); break;
            case 4: eliminar(); break;
            case 5: modificar_empleado(); break;
            case 6: exit(1); break;
        }

    }while(opc !=6);

}

void ingresar(){
    system("cls");
	char continuar;
    cout<<"\n\t\t\t Agregando Empleados\n\n"<<endl;

	FILE* archivo = fopen(nombre_archivo,"ab");
	Empleado empleado;
	string nombre,apellido,puesto;
	do{
		fflush(stdin);
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
		cin.ignore();
		
		cout<<"Ingrese los Nombres: ";
		getline(cin,nombre);
		strcpy(empleado.nombres,nombre.c_str());

		cout<<"Ingrese los Apellidos: ";
		getline(cin,apellido);
		strcpy(empleado.apellidos,apellido.c_str());

		cout<<"Ingrese el Puesto: ";
		getline(cin,puesto);
		strcpy(empleado.puesto,puesto.c_str());

		cout<<"Ingrese el Sueldo:";
		cin>>empleado.sueldo;		
		cout<<"Ingrese la bonificacion:";
		cin>>empleado.boni;
		fwrite(&empleado,sizeof(Empleado),1,archivo);
		
		cout<<"Desea ingresar otro dato (s/n):";
		cin>>continuar;

	} while (continuar=='s' || continuar=='S');

	fclose(archivo);
	cout<<"\n\n\t\t\tGuardado con Exito\n\n";
    system("pause");
    menu();

}

void abrir(){
	system("cls");
    cout<<"\n\t\t\t Registros\n\n"<<endl;
	FILE* archivo = fopen(nombre_archivo,"rb");

	if (!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}

	Empleado empleado;
	int sueldo_total=0;
	sueldo_total=empleado.sueldo+empleado.boni;
	int id= 0;

	fread(&empleado,sizeof(Empleado),1,archivo);
	cout<<"id |"<<"Codigo |"<<"Nombres   |"<<"Apellidos   |"<<"Puesto |"<<"Sueldo"<<"Bonificacion |"<<"Sueldo total |"<<endl;

	do{
	cout<<id<<" |"<<empleado.codigo<<" |"<<empleado.nombres<<"  |"<<empleado.apellidos<<"  |"<<empleado.puesto<<" |"<<empleado.sueldo<<" |"<<empleado.boni<<" |"<<(empleado.sueldo+empleado.boni)<<" |"<<endl;
	fread(&empleado,sizeof(Empleado),1,archivo);
		id+=1;
	} while(feof(archivo) ==0);

	fclose(archivo);

    cout<<"\n\n";
    system("pause");
    menu();

}

void buscar_id(){
	
system("cls");
cout<<"\n\t\t\t Buscar Empleado \n\n"<<endl;
	FILE* archivo = fopen(nombre_archivo,"rb");	

	int id;

	cout<<"\n\nIngrese el ID que desea ver: ";

	cin>>id;

	fseek(archivo,id*sizeof(Empleado),SEEK_SET);

	Empleado empleado;

	fread(&empleado,sizeof(Empleado),1,archivo);

	cout<<"Codigo: "<<empleado.codigo<<endl;
	cout<<"Nombres: "<<empleado.nombres<<endl;
	cout<<"Apellidos: "<<empleado.apellidos<<endl;
	cout<<"Puesto: "<<empleado.puesto<<endl;
	cout<<"Sueldo: "<<empleado.sueldo<<endl;
	cout<<"Bonificacion: "<<empleado.boni<<endl;
	cout<<"Sueldo Total: "<<empleado.sueldo+empleado.boni<<endl;
	fclose(archivo);
	system("pause");
    menu();
}


void modificar_empleado(){	
	system("cls");
	cout<<"\n\t\t\t Modificar Empleado \n\n"<<endl;
	FILE* archivo = fopen(nombre_archivo, "r+b");	
		int id;
		string nombre,apellido,puesto;	
    	Empleado empleado;
        
		cout <<"\n\nIngrese el ID que desea Modificar: ";
    	cin >> id;
    	fseek ( archivo, id * sizeof(Empleado), SEEK_SET );  // esto es lo que permite modificar en la pocision
	
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese los Nombres: ";
		getline(cin,nombre);
		strcpy(empleado.nombres,nombre.c_str());

		cout<<"Ingrese los Apellidos: ";
		getline(cin,apellido);
		strcpy(empleado.apellidos,apellido.c_str());
		
		cout<<"Ingrese el Puesto: ";
		getline(cin,puesto);
		strcpy(empleado.puesto,puesto.c_str());
		cout<<"Ingrese el Sueldo:";
		cin>>empleado.sueldo;			
		cout<<"Ingrese la bonificacion:";
		cin>>empleado.boni;
					
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
	fclose(archivo);
	system("PAUSE");
}

void eliminar(){
    system("cls");
    cout<<"\n\t\t Eliminar Empleado\n"<<endl;
	FILE* archivo = fopen(nombre_archivo,"rb");
    FILE* archivo2 = fopen(nombre2,"w+b");
	if (!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	int id= 0, codigo;
    string nombre,apellido,puesto;

	cout<<"Ingrese el Codigo para eliminar: ";
	cin>>codigo;

	Empleado empleado;
	fread(&empleado,sizeof(Empleado),1,archivo);
	do{       
		if(empleado.codigo == codigo){
            cout<<"Datos eliminados..\n\n"<<endl;
            system("pause");
            fread(&empleado,sizeof(Empleado),1,archivo);
        }

        else{
            
            fwrite(&empleado,sizeof(Empleado),1,archivo2);
            fread(&empleado,sizeof(Empleado),1,archivo);
            id+=1;
        }

	} while (feof(archivo)==0);

	fclose(archivo);
    fclose(archivo2);
    remove("archivo.dat");
    rename("temporal.dat","archivo.dat");

    cout<<"\n\n";
    system("pause");
    menu();
    

}
