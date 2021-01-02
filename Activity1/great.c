#include "great.h"

int great(int a, int b, int c)
{
	int g;
	
	if(a>b)
	{
		if(a>c)
		{
			g = a;
		}
		else
		{
			g = c;
		}
	}
	else
	{
		if(b>c)
		{
			g = b;
		}
		else
		{
			g = c;
		}
	}
	
	return g;
}	