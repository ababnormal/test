#include<stdio.h>
#include<math.h>

int main(){
	int inter;
	int i=1;int t=0;
	scanf("%d",&inter);
	while(inter>0)
	{
		if(inter%10%2==i%2)
		{
			t+=pow(2,(i-1));	
		}
		inter=inter/10;
		i++;
	}
	printf("%d",t);
	
	return 0;
}
