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
	int* p1 = arr;//arr��������Ԫ�ص�ַ��Ϊint��
	int(*p2)[10] = &arr;//&arr����������ĵ�ַ��Ϊint [10]��
	//arr��&arrֵһ���������Ͳ�һ��

	//p1��p2����ͬ��ָ��ͬһλ��
	printf("%p\n", p1);//204
	printf("%p\n", p2);//204
	//ָ�����;���ָ��������Ĳ���
	printf("%p\n", p1 + 1);//����һ������,208
	printf("%p\n", p2 + 1);//����һ������,244
	return 0;
	//Ϊ�˼����,  204,208,244��ʾ��ַ
}