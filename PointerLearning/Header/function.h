#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>

#define a_lenth 8
#define b_lenth 7
#define c_lenth 10
#define d_lenth 6
#define test_struct_lenth 4

int array_size(int* array);
void array_of_pointer(void);
void OneStepLenth(void);
void pointer_of_array(void);

void two_division_conversion_Print1(int arr[3][5], int r, int c);
void two_division_conversion_Print2(int(*pa)[5], int r, int c);
void print_two_division_array(void);

void deliver_test(void);
void two_division_pointer_deliver(void);
void Pointer_of_function(void);


#endif // !

