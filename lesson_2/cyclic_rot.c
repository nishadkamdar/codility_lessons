#include <stdio.h>
#include <stdlib.h>

struct Results {
	int *A;
	int N;
};

struct Results solution(int A[], int N, int K);

struct Results solution(int A[], int N, int K)
{
	int i, j, temp_0;

	for (i = 0; i < K; i++)
	{
		temp_0 = A[0];
		A[0] = A[N-1];

		for (j = N-1; j > 1; j--)
		{
			A[j] = A[j-1];
		}

		A[j] = temp_0;
	}
}

int main(void)
{
	struct Results r1;

	r1.A = malloc(5*sizeof(int));
	r1.N = 5;
	r1.A[0] = 0;
	r1.A[1] = 1;
	r1.A[2] = 2;
	r1.A[3] = 3;
	r1.A[4] = 4;

	solution(r1.A, r1.N, 1);
	printf("r1.A[0] = %d\nr1.A[1] = %d\nr1.A[2] = %d\nr1.A[3] = %d\nr1.A[4] = %d\n", r1.A[0], r1.A[1], r1.A[2], r1.A[3], r1.A[4]);
	solution(r1.A, r1.N, 1);
	printf("r1.A[0] = %d\nr1.A[1] = %d\nr1.A[2] = %d\nr1.A[3] = %d\nr1.A[4] = %d\n", r1.A[0], r1.A[1], r1.A[2], r1.A[3], r1.A[4]);
	solution(r1.A, r1.N, 1);
	printf("r1.A[0] = %d\nr1.A[1] = %d\nr1.A[2] = %d\nr1.A[3] = %d\nr1.A[4] = %d\n", r1.A[0], r1.A[1], r1.A[2], r1.A[3], r1.A[4]);
	solution(r1.A, r1.N, 1);
	printf("r1.A[0] = %d\nr1.A[1] = %d\nr1.A[2] = %d\nr1.A[3] = %d\nr1.A[4] = %d\n", r1.A[0], r1.A[1], r1.A[2], r1.A[3], r1.A[4]);
	solution(r1.A, r1.N, 1);
	printf("r1.A[0] = %d\nr1.A[1] = %d\nr1.A[2] = %d\nr1.A[3] = %d\nr1.A[4] = %d\n", r1.A[0], r1.A[1], r1.A[2], r1.A[3], r1.A[4]);
}
