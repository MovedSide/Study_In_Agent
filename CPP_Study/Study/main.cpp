#include<iostream>
#include<stdio.h>


int& fn(int &x)
{
	return x;
}


int main()
{
	int a = 7;
	int b = 2;
	int &p = a;
	printf("%d", fn(a));
	return 0;
}