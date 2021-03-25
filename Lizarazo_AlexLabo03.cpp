#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

bool lista_vacia(Nodo *Lista){
	return (Lista==NULL)? true : false;
}

void insertarFinal(Nodo *&Lista,int valor){
	
	Nodo *nuevo_nodo = new Nodo();	//nodo a colocar
	Nodo *aux;						//Para moverte en la lista
	nuevo_nodo->dato=valor;
	nuevo_nodo->siguiente=NULL;
	
	if(Lista==NULL){
		Lista = nuevo_nodo;
	}
	else{
		aux=Lista;
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=nuevo_nodo;
	}
}

void mostrarLista(Nodo *&Lista){
	Nodo *t;
	
	t=Lista;
	
	while(t!=NULL){
		cout<<t->dato<<" ";
		t=t->siguiente;
	}
	
}

int devolverUltimo(Nodo *&Lista){
	Nodo *t;
	int valor;
	t=Lista;
	valor = t->dato;
	while(t!=NULL){
		
		t=t->siguiente;
		if(t!=NULL){
			valor = t->dato;	
		}
		
	}
	
	return valor;
	
}

void eliminarPosicion(Nodo *&Lista,int pos){

	Nodo *a=Lista;
	Nodo *s=NULL;
	int n=1;
	
	while(a->siguiente != NULL && n!= pos){
		s=a;
		a=a->siguiente;
		n++;
	}
	
	if(pos==n){
		if(pos>1){
		s->siguiente = a->siguiente;	
		}else{
			Lista=Lista->siguiente;	
		}
	}
		

}

void sumaInsertar(Nodo *&Lista){
	Nodo *aux;
	aux = Lista;
	int v1,v2;
	while(aux->siguiente!=NULL){
		v1 = aux->dato;
		v2 = aux->siguiente->dato;
		aux=aux->siguiente;
	}
	
	insertarFinal(Lista,(v1+v2));
}

float promedioLista(Nodo *&Lista){
	Nodo *aux;
	aux = Lista;
	float promedio=0;
	int n=0;
	while(aux!=NULL){
		promedio+=aux->dato;
		n++;
		aux=aux->siguiente;
	}
	promedio=(promedio/n);	
	return promedio;
}

int devolverPosMenoresPromedio(Nodo *&lista,int promedio){
	Nodo *aux = lista;
	int n=0;
	while(aux!=NULL){
		if(aux->dato<promedio){
			n++;
			return n;
		}
		aux= aux->siguiente;
	}
	return n;
}

int devolverPosMayoresPromedio(Nodo *&lista,int promedio){
	Nodo *aux = lista;
	int n=1;
	if(!lista_vacia(lista)){
		while((aux!=NULL)){
			if(!(aux->dato>promedio)){
				n++;
				aux= aux->siguiente;	
			}else{
				return n;
			}
			
		}	
	}else{
		return 0;
	}
	
	
}

void transferir(Nodo *&L1, Nodo *&L2, int pos){
	Nodo *aux,*aux2,*aux3,*aux4;
	aux=L1;
	aux2=aux;
	aux3=L2;
	int n=1;
	while((aux!=NULL) && (pos!=n)){
		n++;
		aux2=aux;
		aux = aux->siguiente;
	}
	aux4=aux;
	aux = aux->siguiente;
	if(aux!=NULL && pos==n){//lista1 tenga +1 valor || //lista tenga +0 valor
		while(aux3->siguiente!=NULL){
			aux3=aux3->siguiente;
		}
		if(pos==1){
			L1=L1->siguiente;
		}
		aux2->siguiente=aux; //oe aux2->siguiente ahora apunta lo que apunta aux
		aux3->siguiente = aux4;
		aux4->siguiente = NULL;
		
	}else{
		cout<<"\nNo existe el la posicion indicada\n";
	}
	
	
	
}


int main(){
	
	Nodo *Lista1=NULL;
	Nodo *Lista2=NULL;
	
	int n;
	char opc;
	int promedio1=0;
	int promedio2=0;
	
	do{
		
	cout<<"Digite un valor a guardar: ";
	cin>>n;
	insertarFinal(Lista1,n);
	cout<<"Desea continuar (s/n): ";
	cin>>opc;
	system("cls");
	}while(opc=='s' || opc =='S');
	cout<<"LISTA 1\n";
	mostrarLista(Lista1);
	cout<<"\n\n==================================================================\n";
	cout<<"LISTA 1\n";
	sumaInsertar(Lista1);
	sumaInsertar(Lista1);
	mostrarLista(Lista1);
	cout<<"\n\n==================================================================\n";
	cout<<"LISTA 2\n";
	insertarFinal(Lista2,round(promedioLista(Lista1)));
	promedio1=round(promedioLista(Lista1));
	mostrarLista(Lista2);
	cout<<"\n\n==================================================================\n";
	while(devolverPosMenoresPromedio(Lista1,promedio1)!=0){
		transferir(Lista1,Lista2,devolverPosMenoresPromedio(Lista1,promedio1));
	}
	cout<<"\nLISTA 1\n";
	mostrarLista(Lista1);
	cout<<"\nLISTA 2\n";
	mostrarLista(Lista2);
	cout<<"\n\n==================================================================\n";
	promedio1=round(promedioLista(Lista1));
	promedio2=round(promedioLista(Lista2));
	cout<<"\nPromedio Lista 1: "<<promedio1<<endl;
	cout<<"\nPromedio Lista 2: "<<promedio2<<endl;
	cout<<"\n\n==================================================================\n";
	while(devolverPosMayoresPromedio(Lista2,promedio2)!=0){
		eliminarPosicion(Lista2,devolverPosMayoresPromedio(Lista2,promedio2));
	}
	cout<<"\nLISTA 2\n";
	mostrarLista(Lista2);
}



