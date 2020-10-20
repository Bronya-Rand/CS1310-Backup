#include <stdio.h>

void main(void){
	int a,b = 0;
	printf("Type a positive integer: ");
	scanf("%d",&a);
	printf("Type a positive integer: ");
	scanf("%d",&b);
	int num = a;
	while(a%num != 0 || b%num != 0){
		num = num - 1;
	}
	printf("\n\n%d", num);
}
