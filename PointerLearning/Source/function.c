#include "stdio.h"
#include <function.h>

typedef struct data
{
	int a[a_lenth];
	int b[b_lenth];
	int c[c_lenth];
	int d[d_lenth];
}array_combine;

array_combine e[test_struct_lenth] = {
	{1,2,3,4,5,6,7,8},
	{5, 4, 7, 4, 5, 6, 74},
	{1, 3, 2, 4, 5, 7, 6, 8,5,4},
	{567,254,55,44,33,55}
};

int array_size(int array[])
{
	int array_size = 0;
	array_size = sizeof(array);
	return array_size;
}

void array_of_pointer(void)
{
	unsigned int i, j;
	int	size;
	
	int* prr[] = { e->a, e->b, e->c, e->d};

	for ( i=0; i<4; i++)
	{
		for ( j=0; j<8; j++)
		{
			//if()
			printf("%d ", prr[i][j]);//prr[i][j] <==> *(*(prr+i)+j)
		}
		printf("\n");
		size = array_size(e->a);
		printf("%d ", size);
	}
}
