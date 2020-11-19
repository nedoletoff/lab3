#include <stdio.h>

int meter(char* a)
{
	int count = 0;
	while (a[++count] != '\0');
//		++count;
	return count;
}


int conv(char* a)
{
	int number = 0;
	int len = meter(a);
	if (len > 0 && a[0] != '0')
		for (int i = 0; i < len; ++i)
		{
			number *= 10;
			number += (a[i] & 0x0F);
		}
	else if (len > 1 && a[1] != 'x')
		for (int i = 1; i < len; ++i)
		{
			number *= 8;
			number += (a[i] & 0x0F);
		}
	else if (len > 2 && a[1] == 'x')
		for (int i = 2; i < len; ++i)
		{
			number *= 16;	
			if (a[i] > '9')
				number += (a[i] & 0x0F) + 9;
			else 
				number += (a[i] & 0x0F);
		}
	return number;
}

int check(int a, int b)
{	
	int c = b;
	int count = 0;

	if (a == 0)
		return 0;

	while (c > 1 || c < 0)
	{
		c /= a;
		if (c < 0)
			c *= -1;
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

int func(char* a, char* b)
{
	int c, d, e;
	c = conv(a);
	d = conv(b);
//	printf("c = %d, d = %d\n", c, d);
	e = check(c, d);
	return e;
}

int main()
{
	char* a = "5";
       	char* b = "25";
	char* c = "0x5";
	char* d = "0x19";
	char* e = "05";
	char* f = "031";
	if (func(a, b))
		printf("Function(%s, %s) = True\n", a, b);
	else 
		printf("Function(%s, %s) = False\n", a, b);

	if (func(c, d))
		printf("Function(%s, %s) = True\n", c, d);
	else 
		printf("Function(%s, %s) = False\n", c, d);

	if (func(e, f))
		printf("Function(%s, %s) = True\n", e, f);
	else 
		printf("Function(%s, %s) = False\n", e, f);

	return 0;
}
