#include <stdio.h>
#include <stdlib.h>

#define N_min 1 
#define X_min 1 
#define N_max 100000 
#define X_max 100000 

void insertion_sort (int arr[], int nr_elements)
{
        int i, j, key;

        for (j=1; j < nr_elements; j++)
        {
                key = arr[j];
                i   = j - 1;

                while (i > -1 && arr[i] > key)
                {
                        arr[i+1] = arr[i];
                        i = i - 1;
                }

                arr[i+1] = key;
        }
}

// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}

int solution(int X, int A[], int N)
{
	int i = 0;
	int j = 0;
	int search_num = 0;
	int earliest_time = 0;
	int ret= 0;
	int found = 0;

	//insertion_sort(A, N);
	/*for (i = 0; i < N; i++)
	{
		printf("A[%d]=%d\n", i, A[i]);
	}*/
	/*for (search_num = 1; search_num <= X; search_num++)
	{
		ret = binarySearch(A, 0, N-1, search_num);
		if (ret == -1)
			return ret;
	}*/

	for(search_num = 1; search_num <= X; search_num++)
	{
		found = 0;
		for(i = 0; i < N; i++)
		{
			if(A[i] == search_num)
			{
				found = 1;
				if (i > earliest_time)
					earliest_time = i;
				break;
			}
		}

		if (!found)
		{
			return -1;
		}
	}

	return earliest_time;
}

int main()
{
	int arr[8] = {1,3,5,4,1,3,1,2};
	int ret = 0;

	ret = solution(5, arr, 8);

	printf("ret = %d\n", ret);
}
