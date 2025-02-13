#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>  

const int m = 15000;
const int n = 15000;


void assign(int** arr, int m, int n)
{
	printf("\n Assign random values to the 2D array \n");
	// Assign random values to the 2D array
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++) {
			arr[i][j] = (14 * i) % (i + j + 1);
		}
	}
}


void _print(int** arr, int m, int n)
{
	printf("\n print 2D array \n");
	// Print the 2D array
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}


void _free(int** arr, int m, int n)
{
	printf("\n Free \n");
	// Free the memory space locating the 2D array
	int i;
	for (i = 0; i < m; i++) {
		free(arr[i]);
	}
	free(arr);
}

void _add(int** arr1, int** arr2, int** arr3, int m, int n)
{
	printf("\n Add 2D arrays \n");
	// Add two 2D arrays and stor the results in a third array
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++) {
			arr3[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
}

int main(void)
{

	struct timeval wallStart, wallEnd;

	gettimeofday(&wallStart, NULL); // save start time in to variable 'wallStart'

	printf("\n main() \n");
	int r, i;

	// dynamically create an array of pointers of size `m`
	int** arr1 = (int**)malloc(m * sizeof(int*));
	int** arr2 = (int**)malloc(m * sizeof(int*));
	int** arr3 = (int**)malloc(m * sizeof(int*));

	// dynamically allocate memory of size `n` for each row
	for (r = 0; r < m; r++) {
		arr1[r] = (int*)malloc(n * sizeof(int));
		arr2[r] = (int*)malloc(n * sizeof(int));
		arr3[r] = (int*)malloc(n * sizeof(int));
	}

	// assign the arrays with random values
	assign(arr1, m, n);
	assign(arr2, m, n);
	assign(arr3, m, n);
	// arr3 = arr1 + arr2
 // add timer to count processing time for the _add function
	_add(arr1, arr2, arr3, m, n);

	// deallocate memory
	_free(arr1, m, n);
	_free(arr2, m, n);
	_free(arr3, m, n);

	gettimeofday(&wallEnd, NULL); // end time
	double wallSecs = (wallEnd.tv_sec - wallStart.tv_sec);           // just integral number of seconds
  	double WALLtimeTaken = 1.0E-06 * ((wallSecs*1000000) + (wallEnd.tv_usec - wallStart.tv_usec)); // and now with any microseconds
  	printf("WALL CLOCK Time: %f seconds  \n", WALLtimeTaken);

	return 0;
}

