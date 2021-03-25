#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
	int peso;
	char tipo; //NP=N || PE=P
	Nodo *siguiente;
};

Nodo *frente = NULL;
Nodo *fin = NULL;
/*
void insertarLista(Nodo *&lista, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while((aux1!=NULL) &&(aux1->dato<n)){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	
	if(lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->siguiente=nuevo_nodo;
	}
	
	nuevo_nodo->siguiente =aux1;
	
}
*/

bool cola_vacia(){
	return (frente == NULL)? true : false;
}

void mostrarLista(Nodo *&Lista){
	Nodo *t;
	
	t=Lista;
	
	while(t!=NULL){
		cout<<t->peso<<"-"<<t->tipo<<"->";
		t=t->siguiente;
	}
	
}

void insertarCola(Nodo *&cola){
	int valor;
	char tipo;
	Nodo *nuevo_nodo = new Nodo();
	do{
		cout<<"Digite el valor: ";
		cin>>valor;	
	}while(valor>50);
	cout<<"Digite el tipo (n/p): ";
	cin>>tipo;
	nuevo_nodo->peso=valor;
	nuevo_nodo->tipo=tipo;
	nuevo_nodo->siguiente=NULL;
	
	if(cola_vacia()){
		frente = nuevo_nodo;
	}else{
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
	cola = frente;
	
}

void agregarPila(Nodo *&pila,int peso,char tipo){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->peso=peso;
	nuevo_nodo->tipo=tipo;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
}

void sacarPila(Nodo *&pila){
	Nodo *aux = pila;
	pila = aux->siguiente;
	delete aux;
	
}

int sumaLista(Nodo *&l){ //para usar tanto pila como cola
	int suma=0;
	Nodo *aux=l;
	while(aux!=NULL){
		suma+=aux->peso;
	}
	return suma;
}

void transferirContenedor(Nodo *&cola,Nodo *&c1,Nodo *&c2){
	Nodo *aux=cola;
	if(aux->tipo=='p'){
		agregarPila(c1,aux->peso,aux->tipo);
	}
	if(aux->tipo=='n'){
		agregarPila(c2,aux->peso,aux->tipo);
		
	}
	
	cola=cola->siguiente;
	
}
/*
void transferirCamion(Nodo *&c,Nodo *&camion){ //por terminar
	Nodo *aux=c;
	insertarLista(camion,)
	sacarPila(c1);
}
*/
void menu(){
    cout<<"\n\t.:DISTRIBUIDORA:.\n\n";
    cout<<"[1]: Llenar Cola "<<endl;
    cout<<"[2]: Mostrar Cola "<<endl;
    cout<<"[3]: Transferir a Contenedores (por caja)"<<endl;
    cout<<"[4]: Transferir a Camiones o Furgoneta (por caja)"<<endl;
    cout<<"[5]: Mostrar contenedor Perecible "<<endl;
    cout<<"[6]: Mostrar contenedor No Perecible "<<endl;
    cout<<"[0]: SALIR"<<endl;
    cout<<"Opcion: ";
    
}

int main(){
	
	Nodo *cola=NULL, *c1=NULL,*c2=NULL,*camion=NULL,*furgoneta=NULL;
	int opc;
	do{
        menu();
        cin>>opc;
        switch(opc){
            case 1:	insertarCola(cola);
					break;
            case 2: mostrarLista(cola);
            		cout<<"\n";
                	break;
            case 3: if((sumaLista(c1)<=500) && (sumaLista(c2)<=500)){
            		transferirContenedor(cola,c1,c2);
            		}else{
            			cout<<"\nAlgun contenedor supera la maxima capacidad\n\n";
					}
                	break;
            case 4:	cout<<"\nContenedor Perecible\n";
					mostrarLista(c1);
					cout<<"\nContenedor No Perecible\n";
					mostrarLista(c2);
					cout<<"\n";
					transferirCamion(c1);
					transferirCamion(c2);
                	break;
        	case 5:	mostrarLista(c1);
            		cout<<"\n";
                	break;
            case 6:	mostrarLista(c2);
            		cout<<"\n";
                	break;
               
        }
        system("pause");
        system("cls"); 
    }while(opc!=0);
    
    getch();
    return 0; 
	
	
}
