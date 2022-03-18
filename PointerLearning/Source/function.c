#include "stdio.h"
#include <function.h>

void array_of_pointer(void)
{
	unsigned int i, j;
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
	//����������һ����ʮ��Ԫ�ص����飬������9����ַ��һ��int��ַ4�ֽڣ��ʶ�ָ��������36���ֽ�
	printf("%p\n", p2 + 1);//����һ������,244
	//Ϊ�˼����,  204,208,244��ʾ��ַ
}

void pointer_of_array(void)
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*parr)[10] = &arr;//ָ��ָ�����飬������10��Ԫ�أ�ÿ��Ԫ��Ϊint��
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *((*parr) + i));//*parr�൱��arr
	}
	printf("\n");
}

void two_division_conversion_Print1(int arr[3][5], int r, int c)//��ά���鴫��,�ö�ά�������,ʵ���ϲ��ᴴ����ά����,�������Ὣint arr[3][5]�˻�Ϊint(*pa)[5] �������Ǹ������ȼ�
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			//printf("%d ", arr[i][j]);
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}
}

void two_division_conversion_Print2(int(*pa)[5], int r, int c)//��ά���鴫��,������ָ�����
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			//1.
			printf("%d ", pa[i][j]);
			//2.
		//	printf("%d ", *(*(pa + i) + j));
		}
		printf("\n");
	}
}
/*��ˣ���ά����������������еĵ�ַ��������int(*)[5]
��ά������Ԫ�ص�ַ������ָ���ǵȼ۵ģ�������ָ��pa������������
ָ��������int(*)[5]����һ�������ҵ����Ƕ�ά�������
ָ����ָ���������int[5]���ٽ�һ�������ҵ�����ĳ���е�Ԫ��*/
void print_two_division_array(void)
{
	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
	two_division_conversion_Print1(arr, 3, 5);//��ά������Ԫ�������� 
	two_division_conversion_Print2(arr, 3, 5);//��ά������Ԫ�������� 
}
/*��ά���鴫��ʱ�������βε�������Ʒ�����
���βθ����ڶ�ά(��)�ĳ���,��int (*p)[5]
���β�Ϊָ�������ָ��*/
void test1(int* p)
{
	printf("%d\n ",*p);//10
}
/*����*/
void deliver_test(void) 
{
		int a = 10;
		int* pa = &a;
		test1(&a);//�������һ����ַ�����յĺ���test1��Ҫ�Ըõ�ַ���룬������*ȡ�øõ�ַ�洢������
		test1(pa);
		return 0;
}

/*����ָ�봫��*/
void test2(int** pp)
{
	printf("%d\n", **pp);
}
void test3(int* arr[])
{
	printf("%d\n", *arr[0]);
}
void two_division_pointer_deliver(void)
{
	int a = 10;
	int* p = &a;
	int** pp = &p;
	
	test2(&p);//�����&p ���ݵ���p�ĵ�ַ p��ָ��a�ĵ�ַ���ʶ�&p�Ƕ���ָ�룬�����βε����
	test3(pp);//�β�Ϊint* arr[]�������������β�ʱ�ή��Ϊָ�룬�ʶ�������β�Ҳ��һ������ָ��
}
/*�����β�Ϊ����ָ��ʱ��ʵ�ο����Ƕ���ָ��(һ��ָ��ĵ�ַ)��Ҳ������ָ�������Ԫ�صĵ�ַ(�����Ϊ����������Ϊ����������Ԫ�صĵ�ַ��)��*/

/*����ָ��*/
int Add(int x, int y)
{
	return x + y;
}
/*��ʾ������ַ�ķ�ʽ��
*1 ֱ��д������
*2 ȡַ����� &������ 
*/
void Pointer_of_function(void)
{
	printf("%p\n", &Add);
	printf("%p\n",Add);
}
/*
*���Ҫ���� Add�ĵ�ַ
* ��Ҫд�� int (*p)(int,int)=&Add;
*/