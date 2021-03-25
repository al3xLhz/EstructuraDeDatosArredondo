//Crear y completar un vector con N datos enteros positivos (pares e impares) de forma aleatoria.

#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<math.h>

using namespace std;

void mostrarVector(int evector[],int longitud);
void mostrarVectorT(int evector[],int longitud);

int main(){
	
	srand(time(NULL));
	int tPar=0,tImpar=0;
	int vector[100],parVector[100],imparVector[100],nDatos;
	float promePar=0,promeImpar=0;
	
	nDatos=10;//=rand()%20+5; //Cantidad de valores que tendrá el vector desde 5 a 25
	
	cout<<"=====================================================================================================\n";
	
	for(int i=0;i<nDatos;i++){
		vector[i]=rand()%100;
		
		if(vector[i]%2==0){
			parVector[tPar]=vector[i];
			tPar++;
		}else{
			imparVector[tImpar]=vector[i];
			tImpar++;
		}
		
	}
	
	cout<<"LISTA GENERAL\n";
	
	mostrarVector(vector,nDatos);
	
	cout<<"\tCantidad Total = "<<nDatos<<"\n=====================================================================================================\n";
	
	cout<<"Lista Par\n";
	
	mostrarVector(parVector,tPar);
	
	cout<<"\t Cantidad de Pares = "<<tPar;
	cout<<"\nLista Impar\n";	
	
	mostrarVector(imparVector,tImpar);
	
	cout<<"\t Cantidad de Impares = "<<tImpar;
	cout<<"\n=====================================================================================================\n";
	
	cout<<"Lista Impar\n";
	
	mostrarVectorT(parVector,tPar);
	
	cout<<"\nLista Par\n";	
	
	mostrarVectorT(imparVector,tImpar);
	
	cout<<"\n=====================================================================================================\n";
	
	for(int i=0;i<tPar;i++){
		promePar+=parVector[i];
	}
	promePar/=tPar;
	parVector[tPar]=round(promePar);
	
	for(int i=0;i<tImpar;i++){
		promeImpar+=imparVector[i];
	}
	promeImpar/=tImpar;
	imparVector[tImpar]=round(promeImpar);
	
	cout<<"\nPromedio Lista Par: \t"<<promePar<<"\t";
	
	mostrarVector(parVector,tPar);
	
	cout<<"\n\nPromedio Lista Impar: \t"<<promeImpar<<"\t";
	mostrarVector(imparVector,tImpar);
	
	cout<<"\n=====================================================================================================\n";
	
	cout<<"\nUNION DE LAS LISTAS\n";
	
	for(int i=0;i<(tPar+1);i++){
		vector[i]=parVector[i];
	}
	for(int j=0;j<(tImpar+1);j++){
		vector[tPar+1+j]=imparVector[j];
	}
	
	mostrarVector(vector,(tPar+tImpar+2));
	
	cout<<"\n=====================================================================================================\n";
	
	getch();
	return 0;
	
	
}


void mostrarVector(int evector[],int longitud){
	
	for(int i=0;i<longitud;i++){
		cout<<"|"<<evector[i]<<"|";
	}
	
}

void mostrarVectorT(int evector[],int longitud){
	
	for(int i=0;i<longitud;i++){
		cout<<"|"<<evector[i]+1<<"|";
	}
	
}
