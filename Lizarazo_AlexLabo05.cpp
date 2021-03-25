#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
	int piso;
	int entran;
	int salen;
	int quedan;
	Nodo *siguiente;
	Nodo *anterior;
};

Nodo *crearNodo(int piso){
	Nodo *q= new Nodo();
	q->piso=piso;
	q->entran=0;
	q->salen=0;
	q->quedan=0;
	q->siguiente=NULL;
	q->anterior=NULL;
	return q;
}

void insertarInicio(Nodo *&inicio,int piso){
	Nodo *n=NULL;
	n=crearNodo(piso);
	if(inicio==NULL){
		inicio=n;
	}else{
		n->siguiente=inicio;
		inicio->anterior=n;
		inicio=n;	
	}
	
}

void insertarFinal(Nodo *&inicio,int piso){
	Nodo *n = NULL;
	Nodo *p = inicio;
	n=crearNodo(piso);
	while(p->siguiente!=NULL){
		p=p->siguiente;
	}
	p->siguiente=n;
	n->anterior=p;
	
}

void insertarPos(Nodo *&inicio,int dato,int pos){
	Nodo *n = NULL;
	Nodo *p = inicio;
	n=crearNodo(dato);
	int x=1;
	while(p->siguiente!=NULL && x!=pos){
		p=p->siguiente;
		x++;
	}
	if(x==pos){
	n->siguiente=p->anterior->siguiente;
	n->anterior=p->anterior;
	p->anterior->siguiente=n;
	p->anterior=n;	
	}
	
}

void eliminarInicio(Nodo *lista){
	Nodo *aux=lista;
	lista=lista->siguiente;
	lista->anterior=NULL;
	delete(aux);
}

void eliminarFinal(Nodo *&lista){
	Nodo *aux=lista;
	while(aux->siguiente!=NULL){
		aux=aux->siguiente;
	}
	aux->anterior->siguiente=NULL;
	delete(aux);
}

void eliminarPos(Nodo *&lista,int pos){
	Nodo *aux=lista;
	int x=1;
	while(aux!=NULL && x!=1){
		aux=aux->siguiente;
		x++;
	}
	aux->anterior->siguiente=aux->siguiente;
	aux->siguiente->anterior=aux->siguiente;
	delete(aux);
}

void mostrarLista(Nodo *&lista){
	Nodo *aux=lista,*aux1=NULL;
	int i=1;
	while(aux!=NULL){
		//cout<<aux->piso<<" - ";
		aux1=aux;
		aux=aux->siguiente;
	}
	aux=aux1;
	
	while(aux!=NULL){
		cout<<aux->piso<<"\tEntran: "<<aux->entran<<"\tSalen: "<<aux->salen<<"\tQuedan: "<<aux->quedan<<endl;
		aux=aux->anterior;
	}
}

void crearPisos(Nodo *&edificio){
	
	insertarInicio(edificio,1);
	insertarFinal(edificio,2);
	insertarFinal(edificio,3);
	insertarFinal(edificio,4);
	insertarFinal(edificio,5);
	insertarFinal(edificio,6);
	insertarFinal(edificio,7);
	insertarFinal(edificio,8);
	
	
}

void modificacionPorPisoSubida(Nodo *&edificio,int piso){
	Nodo *aux=edificio;
	int entran=0,salen=0;
	int x=1;
	while(aux!=NULL && x!=piso){
		aux=aux->siguiente;
		x++;
	}
	
	
	if(x==1){
		cout<<"Piso "<<x<<endl;
		cout<<"Cuantos ingresan?: ";
		cin>>entran;
		aux->entran+=entran;
		aux->salen+=salen;
		aux->quedan=(aux->entran)-(aux->salen);
		
	}else if(x>1 && x<8){
		cout<<"Piso "<<x<<endl;
		do{
			cout<<"Cuantos ingresan?: ";
			cin>>entran;
			cout<<"Cuantos salen?: ";
			cin>>salen;
			aux->entran=entran;
			aux->salen=salen;
			aux->quedan=(aux->anterior->quedan)+(aux->entran)-(aux->salen);	
			if(aux->quedan>=20 && aux->quedan<0){
				cout<<"\nSupera la cantidad de 20 o es negativo\n";
			}
			
		}while(aux->quedan>=20 && aux->quedan<0);
		
		if(aux->siguiente!=NULL || aux->anterior!=NULL){	
			aux->anterior->quedan=0;
			aux->siguiente->quedan=0;
			aux->anterior->salen=0;
			aux->siguiente->salen=0;
			aux->anterior->entran=0;
			aux->siguiente->entran=0;
				
		}
		
		
	}else if(x==8){
		cout<<"Piso "<<x<<endl;
		salen=aux->anterior->quedan;
		cout<<"Salieron "<<salen<<endl;
		cout<<"Cuantos ingresan?: ";
		cin>>entran;
		aux->entran=entran;
		aux->salen=salen;
		if(aux->anterior!=NULL){
			aux->quedan=(aux->anterior->quedan)+(aux->entran)-(aux->salen);	
			aux->anterior->quedan=0;
			aux->anterior->salen=0;
			aux->anterior->entran=0;
				
		}
		
	}
	
}

void modificacionPorPisoBajada(Nodo *&edificio,int piso){
	Nodo *aux=edificio;
	int entran=0,salen=0;
	int x=1;
	while(aux!=NULL && x!=piso){
		aux=aux->siguiente;
		x++;
	}
	
	
	if(x==1){
		cout<<"Piso "<<x<<endl;
		salen=aux->siguiente->quedan;
		cout<<"Salieron "<<salen<<endl;
		//cout<<"Cuantos ingresan?: ";
	//	cin>>entran;
		aux->entran=entran;
		aux->salen=salen;
		
		if(aux->siguiente!=NULL){
			aux->quedan=(aux->siguiente->quedan)+(aux->entran)-(aux->salen);	
			aux->siguiente->quedan=0;
			aux->siguiente->salen=0;
			aux->siguiente->entran=0;
		}
		
	}else if(x>1 && x<8){
		cout<<"Piso "<<x<<endl;
		do{
			cout<<"Cuantos ingresan?: ";
			cin>>entran;
			cout<<"Cuantos salen?: ";
			cin>>salen;
			aux->entran=entran;
			aux->salen=salen;
			aux->quedan=(aux->siguiente->quedan)+(aux->entran)-(aux->salen);
			if(aux->quedan>=20 && aux->quedan<0){
				cout<<"\nSupera la cantidad de 20 o es negativo\n";
			}
			
		}while(aux->quedan>=20 && aux->quedan<0);
		
		if(aux->siguiente!=NULL || aux->anterior!=NULL){	
			aux->anterior->quedan=0;
			aux->siguiente->quedan=0;
			aux->anterior->salen=0;
			aux->siguiente->salen=0;
			aux->anterior->entran=0;
			aux->siguiente->entran=0;
		}
	
		
	}else if(x==8){
		cout<<"Piso "<<x<<endl;
		salen=aux->anterior->quedan;
		cout<<"Salieron "<<salen<<endl;
		cout<<"Cuantos ingresan?: ";
		cin>>entran;
		aux->entran=entran;
		aux->salen=salen;
		if(aux->anterior!=NULL){
			aux->quedan=(aux->anterior->quedan)+(aux->entran)-(aux->salen);	
			aux->anterior->quedan=0;
			aux->anterior->salen=0;
			aux->anterior->entran=0;
				
		}
		
	}
	
}

void trayectoria(Nodo *&edificio){
	for(int i=1;i<=8;i++){
		modificacionPorPisoSubida(edificio,i);
		mostrarLista(edificio);
		
	}
	for(int i=7;i>0;i--){
		modificacionPorPisoBajada(edificio,i);
		mostrarLista(edificio);
		
	}
}

int main(){
	
	Nodo *edificio=NULL;
	int x=1;
	crearPisos(edificio);
	
	trayectoria(edificio);
	
	system("pause");
	
	getch();
	return 0;
	
}
