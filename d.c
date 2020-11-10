#include <stdio.h>

int func(int a, int b)
{	
	int c = b;
	int count = 0;

	if (a == 0)
		return 0;

	while (c > 1)
	{
		c /= a;
		++count;
	}

	c = 1;

	while (count != 0)
	{
		c *= a;
		--count;
	}
	if (c == b)
		return 1;
	else 
		return 0;
}

int main()
{
	if (func(5, 25))
		printf("First check true\n");
	else 
		printf("First check false\n");

	if (!(func(25, 5)))
		printf("Second check true\n");
	else 
		printf("Second check false\b");

	if (!(func(0, 25)))
		printf("Third check true\n");
	else 
		printf("Third check false\b");


	return 0;
}
