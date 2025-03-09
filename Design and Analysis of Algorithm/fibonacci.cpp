#include<iostream>
using namespace std;
int fibonacci(int n,int &steps){
	int first=0;
	int second=1;
	int temp;
	int i=0;
	while(i<=n){
		steps++;
		temp=first+second;
		first=second;
		second=temp;
		i++;
		cout<<temp<<",";
	}
	return steps;
}
int main(){
	int n,steps=0;
	cout<<"Enter upto which you want fibonacci series"<<endl;
	cin>>n;
	int s=fibonacci(n,steps);
	cout<<"Steps taken:"<<steps;
	return 0;
}
