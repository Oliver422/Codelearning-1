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

void OneStepLenth(void)
{
	int arr[10] = { 0 };
	int* p1 = arr;//arr是数组首元素地址，为int型
	int(*p2)[10] = &arr;//&arr是整个数组的地址，为int [10]型
	//arr和&arr值一样，但类型不一样

	//p1和p2是相同的指向同一位置
	printf("%p\n", p1);//204
	printf("%p\n", p2);//204
	//指针类型决定指针±整数的步长
	printf("%p\n", p1 + 1);//跳过一个整型,208
	printf("%p\n", p2 + 1);//跳过一个数组,244
	return 0;
	//为了简单理解,  204,208,244表示地址
}