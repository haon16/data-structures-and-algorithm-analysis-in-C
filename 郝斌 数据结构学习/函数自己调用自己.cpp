# include <stdio.h>

void f(int n)
{
	if(n == 1)
	{
		printf("¹þ¹þ\n");
	}
	else
		f(n-1);
}

int main(void)
{
	f(4);
	return 0;
}