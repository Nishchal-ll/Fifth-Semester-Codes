#include<stdio.h>
int main(){
	int j=0;	
	float I,Y,T,C,G,YNeg,Cprev;
	YNeg=80;
	float g[] = {20, 25, 30, 35, 40};
	float diff;
	 printf("Year\tG\t\tY\t\t\tI\t\tC\t\tGrowth\n");
    printf("-----------------------------------------------\n");
	for(j=0;j<5;j++){
		I=2+0.1*YNeg;
		Y=45.45+2.27*(I+g[j]);
		T=0.2*Y;
		C=20+0.7*(Y-T);
		Cprev=C - (20 + 0.7 * (YNeg - 0.2 * YNeg));
		printf("%d\t\t%.2f\t%.2f\t\t%.2f\t%.2f\t%.2f\n",j+1, g[j], Y, I, C,Cprev);
		YNeg=Y;
	}
	return 0;
}
