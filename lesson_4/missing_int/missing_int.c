#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100000
#define MIN_LEN 1

#define MAX_VAL 1000000
#define MIN_VAL -1000000

int solution(int A[], int N)
{
	int i = 0;
	int j = 0;
	int smallest_val = MAX_VAL;
	int missing_int = MAX_VAL;

	for(i = 0; i < N; i++)
	{
		if(A[i] <= 0)
			continue;
		else
		{
			if (A[i] < smallest_val)
				smallest_val = A[i];
		}
	}

	printf("smallest_val = %d\n", smallest_val);

	if(smallest_val > 1)
		missing_int = 1;	
	else
	{
		for(i = 2; i <= MAX_VAL; i++)
		{
			for(j = 0; j < N; j++)
			{
				if(A[j] == i)
					break;
			}

			if(j == N)
			{
				missing_int = i;
				break;
			}
		}
	}

	return missing_int;
}

int main(void)
{
	//int A[6] = {1, 3, 6, 4, 1, 2};
	int A[2] = {-1, -3};
	int missing_int = 0;

	missing_int = solution(A, 2);
	printf("missing_int = %d\n", missing_int);
}
