/*

You have N steps to climb .
You can either take one step or two steps at a time .
You need to find the total number of ways you can reach N steps .

Example : For N=4 , You can either reach 4 steps in following ways
->1111
->112
->121
->211
->22
So total number of ways is 5

Input : A Integer denoting N (number of steps )
Output : Return an Integer denoting the number of ways to reach N steps

Example Input : get_steps(5)
Example Output : Returns 8

Note : Test Cases would be small <25.

*/
#include "stdafx.h"
#include<stdlib.h>


int fib(int s);
int p[25];
int get_steps(int s)
{
	if (s == 0)return 0;
	if (s == 1)return 1;
	//int *p;
	//p = (int*)calloc(s + 1, sizeof(int));
	int i;
	for (i = 0; i <= s + 1; i++){
		p[i] = -1;
	}
	return fib(s + 1);

}

int fib(int s){
	if (s <= 1) return s;
	if (p[s] != -1) return p[s];
	p[s] = fib(s - 1) + fib(s - 2);
	return p[s];
}