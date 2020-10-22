# include <stdio.h>

void f();
void g();
void k();

void f()
{
	printf("FFFFF\n");
	g();
	printf("11111\n");
}

void g()
{
	printf("GGGGG\n");
	k();
	printf("22222\n");
}

void k()
{
	printf("KKKKK\n");
}

int main(void)
{
	f();

	return 0;
}