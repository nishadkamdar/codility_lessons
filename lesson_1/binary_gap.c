#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define LIMIT_MAX 1024

int solution(int N);
int int_to_bin(int N, char val[]);

int int_to_bin(int N, char val[])
{
	int i;
	char bin = 0;
	for (i = 0; (i < LIMIT_MAX) && N != 0; i++)
	{
		bin = N % 2;
		val[i] = bin;
		N /= 2;
	}
	return i+1;
}

int solution(int N)
{
	char bval[LIMIT_MAX] = {0};
	int i = 0;
	int new = 0;
	int old = 0;
	int cnt = 0;
        int len = 0;

	len = int_to_bin(N, bval);
	//printf("len = %d\n", len);

	for (i = 0; i < len; i++)
	{
		printf("%d", bval[i]);
	}
	printf("\n");

	for (i = 0; i < len; i++)
	{
		cnt = 0;
		if (bval[i] == 1)
		{
			i++;
			while ((bval[i] != 1) && (i < len))
			{
				cnt++;
				i++;
			}
		}
		if (i >= len)
			break;
		new = cnt;
		if(new > old)
		{
			old = new;
		}
	}

	return old;
}

int main()
{

	int i, max_int, min_int = 0;
	int bin_gap = 0;
	printf("min value of an int is %d\n", ~(int)((unsigned int) ~0 >> 1));
	min_int = ~(int)((unsigned int) ~0 >> 1);
	printf("max value of an int is %d\n", (int)((unsigned int) ~0 >> 1));
	max_int = (int)((unsigned int) ~0 >> 1);
	
	for(i = 0; i <= INT_MAX; i++)
	{
		bin_gap = solution(i);
		printf("%d : %d\n", i, bin_gap);
	}
}
