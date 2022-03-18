#include "stdio.h"
#include <function.h>

void array_of_pointer(void)
{
	unsigned int i, j;
	int	size;
	int a[] = {1,2,3,4,5,6,78,4};
	int b[] = {145,34,33,6,78,9,5,6};
	int c[] = { 2,7,5,3,3,12,2,8 };
	int d[] = {2,5,6,7,8,2,3,5};

	int* prr[] = { a, b, c, d};

	for ( i=0; i<4; i++)
	{
		for ( j=0; j<8; j++)
		{
			//if()
			printf("%d ", prr[i][j]);//prr[i][j] <==> *(*(prr+i)+j)
		}
		printf("\n");
	}
}
