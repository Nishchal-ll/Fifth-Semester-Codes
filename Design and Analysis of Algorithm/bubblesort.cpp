#include<iostream>
using namespace std;
int main(){
	int n,steps=0;
	cout<<"Enter the number of elements:"<<endl;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cout<<"Enter a["<<i<<"]: ";
		cin>>arr[i];
		cout<<endl;
	}
	for(int i=0;i<n;i++){
		for(int j=n-i-1;j<n;j++){
			steps++;
			if (arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	cout<<"Elements are: ";
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Steps taken:"<<steps<<endl;
	return 0;
}
