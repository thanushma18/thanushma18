#include <stdio.h>
int main(){
	int n,i;
	int a=0, b=1 ,next;
	printf("enter number of terms:");
	scanf("%d",&n);
	printf("fibonacci series:\n");
	for(i=0;i<n;i++){
		printf("%d",a);
		next=a+b;
		a=b;
		b=next;
			}
			return 0;
}
