#include <stdio.h>
#include<stack>
#include<string>


int main()
{
	int A, B = 0;
	int T = 0;
	int i = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d + %d = %d\n", i++, A, B, A + B);

	}

	return 0;
}