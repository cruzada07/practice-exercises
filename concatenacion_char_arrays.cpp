#include <iostream>
using namespace std;
int main(){
	char array1[3]={'a','b','c'};
	char array2[3]={'d','e','f'};
	char array3[6];
	cout<<"Primer arreglo: ";
	for(int i=0; i<3; i++){
		cout << array1[i] << " ";
		
		
	}
	cout<<"\nSegundo arreglo: ";
	for(int i=0; i<3; i++){
		cout << array2[i] << " ";
		
		
	}
	
	for(int i=0;i<3;i++){
		array3[i]= array1[i];
	}
	for(int i=0 ;i<3;i++){
		array3[i+3]= array2[i];
	}
	cout<<"\nArreglo final: ";
	for(int i=0; i<6; i++){
		cout << array3[i] << " ";
		
		
	}
	cin.get();
	return 0;
}
