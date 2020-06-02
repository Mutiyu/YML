#include "stdafx.h"
#include"win32.h"
int factorial(int n)
{
	int a = 1;
	for (int i = 1; i <= n; i++)
	{
		a = a*i;
	}
	return a;
}
float FAC::convert(float deg)
{
	return deg*0.01745;
}