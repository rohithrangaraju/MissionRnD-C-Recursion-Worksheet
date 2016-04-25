/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

#include "stdafx.h"
#include<stdlib.h>

void spider1(int** p, int* arr, int up, int down, int left, int right, int* i, int j, int k, int go){
	if (up > down &&left > right) return;
	if (j<up || j>down || k > right || k < left)return;
	//printf("j:%d,k:%d\n", j, k);
	if (k <= right&&go == 0 && j == up){

		arr[(*i)] = p[j][k];

		(*i)++;
		spider1(p, arr, up, down, left, right, i, j, k + 1, go);
		go = 1;
		j++;
		// printf("------------------------------------");

	}
	if (j <= down&&go == 1 && k == right){
		// printf("j:%d,k:%d\n",j,k);
		arr[(*i)] = p[j][k];
		(*i)++;

		spider1(p, arr, up, down, left, right, i, j + 1, k, go);
		go = 2;
		k--;
	}
	if (k >= left&&go == 2 && j == down){
		// printf("j:%d,k:%d\n",j,k);
		arr[(*i)] = p[j][k];
		(*i)++;
		spider1(p, arr, up, down, left, right, i, j, k - 1, go);
		go = 3;
		j--;

	}
	if (j>up && go == 3 && k == left){
		// printf("j:%d,k:%d\n",j,k);
		arr[(*i)] = p[j][k];
		(*i)++;
		spider1(p, arr, up, down, left, right, i, j - 1, k, go);
		go = 0;

	}
	spider1(p, arr, up + 1, down - 1, left + 1, right - 1, i, up + 1, left + 1, go);
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)return NULL;
	int *a = (int*)calloc((rows*columns), sizeof(int));
	int *index = (int*)calloc(1, sizeof(int));
	(*index) = 0;
	spider1(input_array, a, 0, rows - 1, 0, columns - 1, index, 0, 0, 0);
	return a;
}
