#include <stdio.h>

int main(){
	int i;
	char s[100];
	printf("Enter number: ");
	scanf("%d", &i);
	printf("The number is: %d\n", i);
	getchar();
	fgets(s, 100, stdin);
	printf("%s", s);
}
