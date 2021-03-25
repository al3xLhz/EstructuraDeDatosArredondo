#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>


//AVANCE HASTA punto 2


using namespace std;

struct ListaPar{
	int dato1;
	ListaPar *siguiente;
}*p1 = NULL, *p2=NULL, *aux1=NULL;

struct ListaImpar{
	int dato2;
	ListaImpar *siguiente1;
}*cab1 = NULL, *aux2=NULL, *aux3=NULL;

typedef struct nodo *Tlista;

//Funciones
void Insertar(int vector[100], int filas);
void MostrarListaPar(void);
void MostrarListaImpar(void);
void ParImpar();
void ImparPar();

int main(){
	
	srand(time(NULL));
	int filas;
	int vector[100];
			
	filas=10;
	
	for(int i=0;i<filas;i++){
		vector[i]=rand()% 100;
	}
	
	cout<<"Lista inicial: ";
	for(int i=0;i<filas;i++){
		cout<<vector[i]<<" ";
	}
	cout<<"\n";
	cout<<"======================================================\n";
	Insertar(vector, filas);
	cout<<"Lista Par: ";
	MostrarListaPar();
	cout<<"\n";
	cout<<"Lista Impar: ";
	MostrarListaImpar();
	cout<<"\n======================================================\n";
	ParImpar();
	ImparPar();
	cout<<"Lista Par: ";
	MostrarListaPar();
	cout<<"\n";
	cout<<"Lista Impar: ";
	MostrarListaImpar();
	
	getch();
	return 0;
}

void Insertar(int vector[100], int filas){
	for(int i=0;i<filas;i++){
		if(vector[i]%2==0 ){
			p2 = new ListaPar;
			p2->dato1 = vector[i];
		
			p2->siguiente = NULL;
		
			if(p1 == NULL){
				p1 = p2;
			}
			else{
				aux1->siguiente = p2;
			}
			aux1=p2;}
		else{
			aux2 = new ListaImpar;
			aux2->dato2 = vector[i];
		
			aux2->siguiente1 = NULL;
		
			if(cab1 == NULL){
				cab1 = aux2;
			}
			else{
				aux3->siguiente1 = aux2;
			}
			aux3=aux2;
		}
	}
}

void MostrarListaPar(){
	int cont1=0;
	if(p1!=NULL){
		for(p2 = p1; p2!= NULL; p2=p2->siguiente){
			cout<<p2->dato1<<" ";
			cont1++;
		}	
	cout<<"\nTotal Pares: "<<cont1;
	}
	
}
void MostrarListaImpar(){
	int cont2=0;
	if(cab1!=NULL){
		for(aux2 = cab1; aux2!= NULL; aux2=aux2->siguiente1){
			cout<<aux2->dato2<<" ";
			cont2++;
		}
	cout<<"\nTotal Impares: "<<cont2;	
	}
}

void ParImpar(){
	if(p1!= NULL){
		for(p2 = p1; p2!= NULL; p2=p2->siguiente){
			p1->dato1 = p1->dato1+1;
		}	
	}
}

void ImparPar(){
	if(p1!= NULL){
		for(p2 = p1; p2!= NULL; p2=p2->siguiente){
			p1->dato1 = p1->dato1+1;
		}	
	}
}






