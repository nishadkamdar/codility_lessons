#include <stdio.h>
#include <stdlib.h>

struct Results {
	int *C;
	int L;
};

#define N_min	1
#define N_max	100000
#define M_min	1
#define M_max	100000
#define Val_min	1

void increase(int arr[], int element)
{
	arr[element] = arr[element] + 1;
}

void max_counter(int arr[], int len)
{
	int i = 0;
	int max_val = 0;
	
	for(i = 0; i < len; i++)
	{
		if (max_val < arr[i])
			max_val = arr[i];
	}

	for (i = 0; i < len; i++)
	{
		arr[i] = max_val;
	}
}

struct Results solution(int N, int A[], int M)
{
	int i = 0;
	int j = 0;
	struct Results res;

	res.C = (int *)calloc(N, sizeof(N));
	res.L = N;

	for(i = 0; i < M; i++)
	{
		if (A[i] <= N)
			increase(res.C, A[i]-1);
		else if (A[i] == N+1)
			max_counter(res.C, N);
	
		/*for(j = 0; j < res.L; j++)
		{
			printf("res[%d] = %d\n", j, res.C[j]);
		}

		printf("\n");*/
	}

	return res;
}

int main()
{
	int A[7] = {3,4,4,6,1,4,4};
	int i = 0;
	struct Results res;

	res = solution(5, A, 7);

	for(i = 0; i < res.L; i++)
	{
		printf("res[%d] = %d\n", i, res.C[i]);
	}
		
}
