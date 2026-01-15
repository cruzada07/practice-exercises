#include <iostream>
using namespace std;
int main(){
	int a, b;
	
	cout<<"Ingrese el numero de filas: "; cin>>a;
	cout<<"Ingrese el numero de columnas: "; cin>>b;
	
	int matriz[a][b];
	
	for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			cout<<"Digite el elemento ["<<i+1<<"]["<<j+1<<"]: "; cin>>matriz[i][j];
		}
	}
	
	cout<<"Matriz: "<<endl;
	for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			cout<<matriz[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cin.get();
	return 0;
}
