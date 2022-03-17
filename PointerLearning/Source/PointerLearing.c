#include<stdio.h>
int main()
{
    //int a = 10;
    //int b = 20;
    //int c = 30;
    //int* arr[3] = { &a, &b, &c };//不常用的写法

    int arr1[] = { 1,2,3,4,5 };
    int arr2[] = { 2,3,4,5,6 };
    int arr3[] = { 3,4,5,6,7 };
    int* parr[] = { arr1,arr2,arr3 };//常见的写法
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            //1.
           // printf("%d ", parr[i][j]);
            //2.
          printf("%d ", *(*(parr + i) + j));
        }
        printf("\n");
    }
    return 0;
}