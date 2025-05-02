#include <stdio.h>
int a[101],n,x,d,b,r,g;
double p;
int main(){
	scanf("%lf%d",&p,&n);
	while(n--){
		char c;
		scanf("%d %c",&x,&c);
		d=c=='L'?-1:1;
		for(int i=x+d;1<=i&&i<=100;i+=d) a[i]++;
	}
	for(int i=1;i<=100;i++)(a[i]%3==0?b:a[i]%3==1?r:g)++;
	printf("%.2f\n%.2f\n%.2f",p*b/100,p*r/100,p*g/100);
}
