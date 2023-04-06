#include<iostream>
#include<array>
using namespace std;

void matchnumbers(int target, int array_of_numbers[],int size){
	int y=0;
	int z;
	while(y<(size-1)){
		z=y+1;
		while(z<size){
			if((array_of_numbers[y]+array_of_numbers[z])==target){
				cout<<y;
			    cout<<z;
			}
			z++;
		}
		y++;
	}
}

int main() {
	int size;
	int array_of_numbers[105];
	int target;
	cout<<"Define the size of the array";
	cin>>size;
	cout<<"Enter the numbers in the array";
	for (int i=0;i<size;i++){
		cin>>array_of_numbers[i];
	}
	cout<<"Enter the target number";
 	cin>>target;
 	matchnumbers(target,array_of_numbers,size);
}








