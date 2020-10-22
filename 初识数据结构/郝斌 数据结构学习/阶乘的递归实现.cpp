# include <stdio.h>

/*
long f(long n)
{
	long mult;
	//while(n != 1)是错误的，最外层n一直不为0进入死循环
	if(n != 1)
	{
		mult = n * f(n-1);
	}
	if(n == 1)
		mult = 1;

	return mult;
}
*/

long f(long n)
{
	if(1 == n)
		return 1;
	else
		return f(n-1) * n;
}

int main(void)
{
	printf("%ld\n", f(6));
	
	return 0;
}