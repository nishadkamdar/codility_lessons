#include <stdio.h>
#include <stdlib.h>

#define MIN_LEN	2
#define MAX_LEN 100000

#define MIN_VAL	-1000
#define MAX_VAL 1000

int solution(int A[], int N);

int solution(int A[], int N)
{
	int i = 0;
        int j = 0;
	int pos = 0;
	int lsum = 0;
	int rsum = 0;
	int old_diff = MAX_LEN;
	int new_diff = 0;
	
	for(pos = 1; pos < N; pos++)
	{
		lsum = 0;
		rsum = 0;

		for(i = 0; i < pos; i++)
		{
			lsum += A[i];
		}

		for(j = pos; j < N; j++)
		{
			rsum += A[j];
		}

		new_diff = lsum - rsum;
		if (new_diff < 0)
			new_diff = -new_diff;
		
		if (new_diff < old_diff)
			old_diff = new_diff;

	}

	return old_diff;
}

int main(void)
{
	int A[5] = {0};
	int diff = 0;

	A[0] = 3;	
	A[1] = 1;	
	A[2] = 2;	
	A[3] = 4;	
	A[4] = 3;	

	diff = solution(A, 5);
	
	printf("Diff is %d\n", diff);
}
