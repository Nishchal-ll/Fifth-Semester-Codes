#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
    int total_points,points_inside_circle=0;
    double x,y,pi_estimate;
    cout<<"Enter the total number of points:";
    cin>>total_points;
    srand(time(NULL));
    for(int i=0;i<total_points;i++){
        x=(double)rand()/RAND_MAX;
        y=(double)rand()/RAND_MAX;
        
        if(x*x+y*y<=1.0){
            points_inside_circle++;
        }
    }
    pi_estimate=4.0*points_inside_circle/total_points;
    cout<<"Enstimated value of pi is"<<pi_estimate;
    return 0;
}
