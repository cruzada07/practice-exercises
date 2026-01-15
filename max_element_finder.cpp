#include <iostream>
using namespace std;
int main(){
	
	cout<<"Elementos con sus indices: "<<endl;
	int n;
	cout<<"Ingrese el numero de elementos: "; cin>>n;
	int array[n];
	for(int i=0; i<n; i++){
		cout<<"Escriba el elemento "<<i+1<<": "; cin>>array[i];
	}
	int mayor=array[0];
	for(int i=0; i<n; i++){
		if(array[i]<array[i+1]){
			mayor=array[i+1];
		}
	}
	cout<<"El mayor elemento es: "<<mayor;
	
	cin.get();
	return 0;
}
