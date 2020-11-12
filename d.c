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
	int a = 5, b = 25, c = 25, d = 5, e = 0, f = 5;
	if (func(a, b))
		printf("Function(%d, %d) = True\n", a, b);
	else 
		printf("Function(%d, %d) = False\n", a, b);

	if (func(c, d))
		printf("Function(%d, %d) = True\n", c, d);
	else 
		printf("Function(%d, %d) = False\n", c, d);

	if (func(e, f))
		printf("Function(%d, %d) = True\n", e, f);
	else 
		printf("Function(%d, %d) = False\n", e, f);


	return 0;
}
