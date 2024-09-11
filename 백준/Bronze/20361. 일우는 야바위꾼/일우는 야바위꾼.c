#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, X, K;
	scanf("%d %d %d", &N, &X, &K);
	int A, B;
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d", &A, &B);
		if (A == X)
			X = B;
		else if (B == X)
			X = A;
	}
	printf("%d", X);

	return 0;
}