#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

Nodo *crearNodo(int dato){
	
	Nodo *nuevo = new Nodo();
	nuevo->dato=dato;
	nuevo->siguiente=NULL;
	return nuevo;
}

void insertarFinal(Nodo *&inicio, int dato){
	Nodo *nuevo = crearNodo(dato);
	Nodo *aux=inicio;
	if(aux == NULL){
		inicio = nuevo;
	}
	else{
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
			aux->siguiente=nuevo;
	}
}

void mostrarLista(Nodo *lista){
	Nodo *aux1 = lista;
	
	while(aux1!=NULL){
		cout<<aux1->dato<<" -> ";
		aux1 = aux1->siguiente;
		
	}
}

void filtro(Nodo *&ListaI,Nodo *&ListaPos,Nodo *&ListaNeg){
	Nodo *auxP=ListaPos;
	Nodo *auxN=ListaNeg;
	
	do{
		if(ListaI->dato>=0){
			insertarFinal(ListaPos,ListaI->dato);
			ListaI=ListaI->siguiente;
		}else{
			insertarFinal(ListaNeg,ListaI->dato);
			ListaI=ListaI->siguiente;
		}
		
		
	}while(ListaI!=NULL);
}

int cantidadLista(Nodo *lista){
	int n=0;
	Nodo *aux=lista;
	while(aux!=NULL){
		n++;
		aux=aux->siguiente;
	}
	return n;
}

void metodoBurbuja(Nodo *&lista){
	Nodo *aux=lista;	
	int auxD;
	
	for(int i=0;i<cantidadLista(lista);i++){
		aux=lista;
		for(int j=0;j<cantidadLista(lista);j++){
			if(aux->siguiente!=NULL){
				if(aux->dato>aux->siguiente->dato){
				auxD=aux->dato;
				aux->dato= aux->siguiente->dato;
				aux->siguiente->dato = auxD;
				}	
			}
			
			aux=aux->siguiente;
		}
	}
}


void metodoSeleccion(Nodo *&lista){
	Nodo *auxi=lista;
	Nodo *auxj=lista;
	Nodo *menor=NULL;	
	int auxD;
	
	for(int i=0;i<cantidadLista(lista);i++){
		
		menor=auxi;
		auxj=auxi->siguiente;
		for(int j=i+1;j<cantidadLista(lista);j++){
			
				if(auxj->dato < menor->dato){
					menor=auxj;
				}
			auxj=auxj->siguiente;
		}
		auxD = auxi->dato;
		auxi->dato = menor->dato;
		menor->dato = auxD;
		
		
		auxi=auxi->siguiente;
		
	}
	
}

Nodo *darmeNodoXPos(Nodo *&lista,int pos){
	Nodo *aux=lista;
	int i=1;
	while(aux!=NULL && pos!=i){
		aux=aux->siguiente;
		i++;
	}
	
	return aux;
	
}

void busquedaBinaria(Nodo *lista){
	int dato;
	int inf=0;
	int sup=cantidadLista(lista);
	int i=0;
	int mitad;
	bool band=false;
	Nodo *mitadN=NULL;	
	
	cout<<"\nDigite que dato quiere encontrar: ";
	cin>>dato;
	
		
	while((darmeNodoXPos(lista,inf+1)->dato<=darmeNodoXPos(lista,sup)->dato)&&(i<cantidadLista(lista))){
		mitad = (inf+sup)/2;
		mitadN = darmeNodoXPos(lista,mitad);
		if(mitadN->dato == dato){
			band=true;
			break;
		}
		if(mitadN->dato > dato){
			sup = mitad;
			mitad = (inf+sup)/2;
			mitadN = darmeNodoXPos(lista,mitad);
		}
		if(mitadN->dato<dato){
			inf = mitad;
			mitad = (inf+sup)/2;
			mitadN = darmeNodoXPos(lista,mitad);
		}
		i++;
	}
	
	if(band){
		cout<<"El numero se encontro en la pos: "<<mitad<<endl;
	}
	else{
		cout<<"El numero NO se encontro";
	}
	
}

int main(){
	
	Nodo *ListaI=NULL,*ListaPos=NULL,*ListaNeg=NULL;
	int valor;
	srand(time(NULL));
	cout<<"\n=========================================================\n";
	cout<<"\tINGRESO DE DATOS\n";
	for(int i=0;i<16;i++){
		valor=rand()%100-50;  //[-100,100] 
		insertarFinal(ListaI,valor);
	}
	mostrarLista(ListaI);
	cout<<"\n=========================================================\n";
	cout<<"\tFILTRO DE DATOS\n";
	filtro(ListaI,ListaPos,ListaNeg);
	cout<<"\nLista 1: ";mostrarLista(ListaI);
	cout<<"\nLista Positiva: ";mostrarLista(ListaPos);
	cout<<"\nLista Negativa: ";mostrarLista(ListaNeg);
	cout<<"\n=========================================================\n";
	cout<<"\tORDENAR LISTA POSITIVA - METODO BURBUJA\n";
	metodoBurbuja(ListaPos);
	cout<<"\nLista Positiva: ";mostrarLista(ListaPos);
	cout<<"\n=========================================================\n";
	cout<<"\tORDENAR LISTA NEGATIVO - METODO SELECCION\n";
	metodoSeleccion(ListaNeg);
	cout<<"\nLista Negativa: ";mostrarLista(ListaNeg);
	cout<<"\n=========================================================\n";
	cout<<"\tBUSQUEDA BINARIA\n";
	cout<<"\nLista Positiva: ";busquedaBinaria(ListaPos);
	cout<<"\nLista Negativa: ";busquedaBinaria(ListaNeg);
	
	getch();
	return 0;
}
