#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>


using namespace std;


int main(){
	
	srand(time(NULL));
	
	int matriz[9][2];
	int PosPar[10]={0}; //Positivo Par
	int PosImpar[10]={0}; //Positivo Impar
	int NegPar[10]={0}; //Negativo Impar
	int NegImpar[10]={0}; //Negativo impar
	
	
	for(int i=0;i<9;i++){
		for(int j=0;j<2;j++){
			
			matriz[i][j]=rand() %200 -100; //200 determina que te da de 0-200 --> luego le resta 100 --> -100 a 100
			
		}
	}
	
	for(int j=0;j<2;j++){
		for(int i=0;i<9;i++){
		cout<<matriz[i][j]<<" ";
	
		}
		cout<<"\n";
	}

	
	
	int n=0;
	int m=0;
	int r=0;
	int k=0;
	
	for(int i=0;i<9;i++){
		for(int j=0;j<2;j++){
			
			if(matriz[i][j]%2==0 && matriz[i][j]>=0){ //pares positivos
					PosPar[n]=matriz[i][j];
					n++;
				}else if(matriz[i][j]%2!=0 && matriz[i][j]>=0){//impares positivos
					PosImpar[m]=matriz[i][j];
					m++;
				}else if(matriz[i][j]%2==0 && matriz[i][j]<0){//pares negativos 
					NegPar[r]=matriz[i][j];
					r++;
				}else if(matriz[i][j]%2!=0 && matriz[i][j]<0){//impares negativos
					NegImpar[k]=matriz[i][j];
					k++;
				}
				
				
			
		}
	}
	
	cout<<"----------------------------------"<<"\n";
	int p=0;
	int PPar[n];
	int PImpar[m]; 
	int NPar[r]; 
	int NImpar[k];
	
	for(int i=0;i<n;i++){
		if(PosPar[p]!=0){
			PPar[i]= PosPar[p];
			cout<<PPar[i]<<" ";
			p++;
		}
		
	}
	cout<<"PPAR\n\tPrimero: "<<PPar[0]<<"\tMedio: "<<PPar[n/2]<<"\tUltimo: "<<PPar[n-1];
	p=0;
	for(int i=0;i<n;i++){
		if(PosImpar[p]!=0){
			PImpar[i]= PosImpar[p];
			cout<<PImpar[i]<<" ";
			p++;
		}
		
	}
	cout<<"PIMPAR\n\tPrimero: "<<PImpar[0]<<"\tMedio: "<<PImpar[n/2]<<"\tUltimo: "<<PImpar[n-1];
	p=0;
	for(int i=0;i<n;i++){
		if(NegPar[p]!=0){
			NPar[i]= NegPar[p];
			cout<<NPar[i]<<" ";
			p++;
		}
		
	}
	cout<<"NPAR\n\tPrimero: "<<NPar[0]<<"\tMedio: "<<NPar[n/2]<<"\tUltimo: "<<NPar[n-1];
	p=0;
	for(int i=0;i<n;i++){
		if(NegImpar[p]!=0){
			NImpar[i]= NegImpar[p];
			cout<<NImpar[i]<<" ";
			p++;
		}
		
	}
	cout<<"NIMPAR\n\tPrimero: "<<NImpar[0]<<"\tMedio: "<<NImpar[n/2]<<"\tUltimo: "<<NImpar[n-1];
	
	
	
	
	
//	
//	int p=0;
//	
//	while(PPar[p]!=0){
//		cout<<PPar[p]<<"|";
//		p++;
//	}
//	cout<<"PPAR\n\tPrimero: "<<PPar[0]<<"\tMedio: "<<PPar[n/2]<<"\tUltimo: "<<PPar[n-1];
//	p=0;
//	while(PImpar[p]!=0){
//		cout<<PImpar[p]<<"|";
//		p++;
//	}
//	cout<<"PIMPAR\n\tPrimero: "<<PImpar[0]<<"\tMedio: "<<PImpar[n/2]<<"\tUltimo: "<<PImpar[n-1];
//	p=0;
//	while(NPar[p]!=0){
//		cout<<NPar[p]<<"|";
//		p++;
//	}
//	cout<<"NPAR\n\tPrimero: "<<NPar[0]<<"\tMedio: "<<NPar[n/2]<<"\tUltimo: "<<NPar[n-1];
//	p=0;
//	while(NImpar[p]!=0){
//		cout<<NImpar[p]<<"|";
//		p++;
//	}
//	cout<<"NIMPAR\n\tPrimero: "<<NImpar[0]<<"\tMedio: "<<NImpar[n/2]<<"\tUltimo: "<<NImpar[n-1];
	
	
}
