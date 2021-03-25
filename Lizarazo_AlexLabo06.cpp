#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string>

using namespace std;

struct Nodo{
	char nombre;
	int peso;
	int dSiguiente;
	Nodo *siguiente;
	Nodo *anterior;
};

Nodo *crearNodo(int dSiguiente,char nombre,int peso){
	
	Nodo *nuevo = new Nodo();
	nuevo->peso=peso;
	nuevo->siguiente=NULL;
	nuevo->anterior=NULL;
	nuevo->nombre=nombre;
	nuevo->dSiguiente=dSiguiente;
	return nuevo;
}

void insertarFinal(Nodo *&inicio,Nodo *&final,int dSiguiente,char nombre, int peso){
	Nodo *nuevo = crearNodo(dSiguiente,nombre,peso);
	
	if(inicio == NULL){
		
		inicio = nuevo;
		final = nuevo;
		final->siguiente=inicio;
		final->anterior=inicio;
	}
	else{
		final->siguiente=nuevo;
		nuevo->siguiente=inicio;
		nuevo->anterior=final;
		final=final->siguiente;
		inicio->anterior=final;
	}
}

void insertarNodoInicio(Nodo *&inicio,Nodo *&final,int dSiguiente,char nombre, int peso){
	Nodo *nuevo = crearNodo(dSiguiente,nombre,peso);
	if(inicio == NULL){
		
		inicio = nuevo;
		final = nuevo;
		final->siguiente=inicio;
		final->anterior=inicio;
	}else{
		
		nuevo->siguiente=inicio;
		inicio=nuevo;
		final->siguiente=inicio;
		inicio->siguiente->anterior=inicio;
		inicio->anterior=final;
	}
}

void eliminarPrimero(Nodo *&inicio){
	Nodo *t = inicio;
	inicio->anterior->siguiente = inicio->siguiente;
	inicio->siguiente->anterior=inicio->anterior;
	t=inicio;
	inicio=inicio->siguiente;
	delete(t);
}

void eliminarUltimo(Nodo *&inicio){
	Nodo *t = inicio;
	inicio->anterior->anterior->siguiente=inicio;
	t=inicio->anterior;
	inicio->anterior=inicio->anterior->anterior;
	delete(t);
}

Nodo *CrearRuta(Nodo *&inicio,Nodo *&final){
	insertarNodoInicio(inicio,final,7,'A',10);
	insertarFinal(inicio,final,10,'B',30);
	insertarFinal(inicio,final,3,'C',20);
	insertarFinal(inicio,final,5,'D',5);
	insertarFinal(inicio,final,16,'E',50);
}

void mostrarRuta(Nodo *inicio,Nodo *final){
	Nodo *aux=inicio;
	int tPeso=0;
	if(aux!=NULL){
		do{
			cout<<"|"<<aux->nombre<<" "<<aux->peso<<"k |"<<"---"<<aux->dSiguiente<<"---";
			tPeso+=aux->peso;
			aux=aux->siguiente;
		}while(aux!=final);
		cout<<"|"<<final->nombre<<" "<<final->peso<<"k |"<<"--"<<endl;
		cout<<"\n";
		cout<<"\\--- 	"<<final->dSiguiente<<"   --- /";
		tPeso+=final->peso;	
		cout<<"\n";	
	}
	
	cout<<"\n\nEl peso total recogido es: "<<tPeso;
	
}

void mostrarRutaEspecifica(Nodo *inicio,Nodo *final){
	Nodo *aux=inicio;
	Nodo *auxF=inicio;
	char estacionI;
	char estacionF;
	int tRecorrido=0;
	
	if(aux!=NULL){
		
		cout<<"Digite el nombre de la Estacion Inicial: ";
		cin>>estacionI;
		cout<<"Digite el nombre de la Estacion Final: ";
		cin>>estacionF;
		while(aux->nombre!=estacionI){
				aux=aux->siguiente;
			}
		while(auxF->nombre!=estacionF){
				auxF=auxF->siguiente;
			}
	
		
		do{
			
			cout<<"|"<<aux->nombre<<" "<<aux->peso<<"k |"<<"---"<<aux->dSiguiente<<"---";
			tRecorrido+=aux->dSiguiente;
			aux=aux->siguiente;
		}while(aux!=auxF);
		cout<<"|"<<auxF->nombre<<" "<<auxF->peso<<"k |"<<"--"<<endl;
		
		cout<<"\n\nRecorrido Total: "<<tRecorrido;	
	}
	
}

void eliminarEstacion(Nodo *&inicio,Nodo *&final){
	
	Nodo *aux=inicio;
	char estacion;
	
	if(aux!=NULL){
		
		cout<<"Digite el nombre de la Estacion a eliminar: ";
		cin>>estacion;
		while(aux->nombre!=estacion){
				aux=aux->siguiente;
			}
		aux->siguiente->anterior=aux->anterior;
		aux->anterior->siguiente=aux->siguiente;
		aux->anterior->dSiguiente+=aux->dSiguiente;
		delete(aux);
				
	}
	
}

void introducirEstacion(Nodo *&inicio,Nodo *&final){
	Nodo *aux=inicio;
	char estacion;
	char estacionAux;
	int dSiguiente;
	int peso;
	
	if(aux!=NULL){
		
		cout<<"Digite el nombre de la Estacion: ";
		cin>>estacion;
		cout<<"Digite el peso de la Estacion: ";
		cin>>peso;
		cout<<"Delante de que estacion estará?:";
		cin>>estacionAux;
		while(aux->nombre!=estacionAux){
				aux=aux->siguiente;
			}
			
		cout<<"\n cual es la distancia de la estacion nueva al siguiente?: ";
		cin>>dSiguiente;
		Nodo *nuevo= crearNodo(8,estacion,peso);
		nuevo->siguiente=aux->siguiente;
		aux->siguiente->anterior=nuevo;
		aux->siguiente=nuevo;
		nuevo->anterior=aux;
		aux->dSiguiente-=nuevo->dSiguiente;	
			
		if(aux==final){
			final=final->siguiente;
		}
		
		
				
	}
}

void mostraRecogerAEA(Nodo *&inicio,Nodo *&final){
	Nodo *aux=inicio;
	int tPeso=0;
	int tRecorrido=0;
	if(aux!=NULL){
		do{
			cout<<"|"<<aux->nombre<<" "<<aux->peso<<"k |"<<"---"<<aux->dSiguiente<<"---";
			tPeso+=aux->peso;
			if(aux->nombre!='E'){
			tRecorrido+=aux->dSiguiente;
			}			
			aux=aux->siguiente;
		}while(aux!=final);
		
		do{
			cout<<"|"<<aux->nombre<<" "<<aux->peso<<"k |"<<"---"<<aux->anterior->dSiguiente<<"---";
			tPeso+=aux->peso;
			if(aux->nombre!='E'){
			tRecorrido+=aux->dSiguiente;
			}
			aux=aux->anterior;
		}while(aux!=inicio);
		cout<<"|"<<inicio->nombre<<" "<<inicio->peso<<"k |"<<"--"<<endl;
		tPeso+=inicio->peso;
		tRecorrido+=inicio->dSiguiente;
		cout<<"\n\nEl peso total recogido es: "<<tPeso;		
		cout<<"\n\nLa distancia total recogido es: "<<tRecorrido;		
	}
	
	
}


int main(){
	int opc;
	Nodo *inicio=NULL,*final=NULL;
	CrearRuta(inicio,final);
	do{
		system("cls");
		cout<<"\n=====================================";
		cout<<"\n        Laboratorio 06               ";
		cout<<"\n=====================================";
		cout<<"\n 1. Mostrar Ruta    	  6. Salir    ";
		cout<<"\n 2. Ruta especifica     		      ";
		cout<<"\n 3. Eliminar Estacion		      	  ";
		cout<<"\n 4. Ingresar Estacion                ";
		cout<<"\n 5. RUTA AEA                         ";
		cout<<"\n=====================================";
		cout<<endl << endl << "Opcion: ";
		cin>>opc;
		switch(opc){
			case 1:
				cout<<"\n\tRUTA\n"<<endl;
				mostrarRuta(inicio,final);
				break;
			case 2:
				cout<<"\n\tRUTA ESPECIFICA\n"<<endl;
				mostrarRutaEspecifica(inicio,final);
				break;	
			case 3:
				cout<<"\n\tELIMINAR ESTACION\n"<<endl;
				eliminarEstacion(inicio,final);
				break;
			case 4:
				cout<<"\n\tINTRODUCIR ESTACION\n"<<endl;
				introducirEstacion(inicio,final);
				break;
			case 5:
				cout<<"\n\tRUTA AEA\n"<<endl;
				mostraRecogerAEA(inicio,final);
				break;
		}
		cout<<"\n";
		system("pause"); 
	}while (opc != 6);
	
	getch();
	return 0;
}
