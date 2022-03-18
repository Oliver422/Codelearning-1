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
	int* p1 = arr;//arr是数组首元素地址，为int型
	int(*p2)[10] = &arr;//&arr是整个数组的地址，为int [10]型
	//arr和&arr值一样，但类型不一样

	//p1和p2是相同的指向同一位置
	printf("%p\n", p1);//204
	printf("%p\n", p2);//204
	//指针类型决定指针±整数的步长
	printf("%p\n", p1 + 1);//跳过一个整型,208
	//由于跳过了一个有十个元素的数组，跳过了9个地址，一个int地址4字节，故而指针跳过了36个字节
	printf("%p\n", p2 + 1);//跳过一个数组,244
	//为了简单理解,  204,208,244表示地址
}

void pointer_of_array(void)
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*parr)[10] = &arr;//指针指向数组，数组有10个元素，每个元素为int型
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *((*parr) + i));//*parr相当于arr
	}
	printf("\n");
}

void two_division_conversion_Print1(int arr[3][5], int r, int c)//二维数组传参,用二维数组接收,实际上不会创建二维数组,编译器会将int arr[3][5]退化为int(*pa)[5] 和下面那个函数等价
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

void two_division_conversion_Print2(int(*pa)[5], int r, int c)//二维数组传参,用数组指针接收
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
/*因此，二维数组的数组名是首行的地址，类型是int(*)[5]
二维数组首元素地址和数组指针是等价的，即数组指针pa就是数组名。
指针类型是int(*)[5]，解一层引用找到的是二维数组的行
指针所指向的类型是int[5]，再解一层引用找到的是某行中的元素*/
void print_two_division_array(void)
{
	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
	two_division_conversion_Print1(arr, 3, 5);//二维数组首元素是首行 
	two_division_conversion_Print2(arr, 3, 5);//二维数组首元素是首行 
}
/*二维数组传参时，函数形参的两种设计方法：
①形参给出第二维(列)的长度,如int (*p)[5]
②形参为指向数组的指针*/
void test1(int* p)
{
	printf("%d\n ",*p);//10
}
/*传参*/
void deliver_test(void) 
{
		int a = 10;
		int* pa = &a;
		test1(&a);//传输的是一个地址，接收的函数test1需要对该地址解码，即加上*取得该地址存储的内容
		test1(pa);
		return 0;
}

/*二级指针传参*/
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
	
	test2(&p);//这里的&p 传递的是p的地址 p又指向a的地址，故而&p是二级指针，符合形参的设计
	test3(pp);//形参为int* arr[]，由于数组在形参时会降级为指针，故而这里的形参也是一个二级指针
}
/*函数形参为二级指针时，实参可以是二级指针(一级指针的地址)，也可以是指针数组的元素的地址(特殊的为数组名，因为它是数组首元素的地址嘛)。*/

/*函数指针*/
int Add(int x, int y)
{
	return x + y;
}
/*表示函数地址的方式：
*1 直接写函数名
*2 取址运算符 &函数名 
*/
void Pointer_of_function(void)
{
	printf("%p\n", &Add);
	printf("%p\n",Add);
}
/*
*如果要保存 Add的地址
* 则要写成 int (*p)(int,int)=&Add;
*/