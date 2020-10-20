#include <stdio.h>

int val (void){
	int a = 0;
	
	while(a <= 0){
		printf("Type a positive integer: ");
		scanf("%d",&a);
	}
	printf("You typed %d.\n", a);
	return a;
}

int factor (int value){
	int i = 0;
	printf("\n\nFactors for %d are: ", value);
	for (i = 1; i <= value; i++){
		if (value % i == 0){
			printf(" %d ", i);
		}
	}
}

int prime (int num){
	int count = 1;
	while(count < num){
		count = count + 1;
		if (num%count == 0){
			printf(" %d ", count);
			num = num/count;
			count = count - 1; 
		}
	}
}

int gcf(int valueA, int valueB){
	int num = valueA;
	while(valueA%num != 0 || valueB%num != 0){
		num = num - 1;
	}
	printf("\nGCF for values is: %d", num);
}

int lcm(int valueA, int valueB){
	int num = valueA;
	while(num%valueA != 0 || num%valueB != 0){
		num = num + 1;
	}
	printf("\nLCM for values is: %d", num);
}


void main (void){
	int valA, valB = 0;
	printf("Debug\n\n");
	valA = val();
	valB = val();
	printf("%d and %d.\n\n", valA, valB);
	factor(valA);
	factor(valB);
	printf("\nPrimes for first value are: ");
	prime(valA);
	printf("\nPrimes for second value are: ");
	prime(valB);
	gcf(valA, valB);
	lcm(valA, valB);
}
