# include <stdio.h>
# include <malloc.h>

struct Student
{
	int age;
	int score;
	char name[50];
};

int main(void)
{
	int count;
	struct Student* p = (struct Student*) malloc( sizeof (struct Student) ); 

	printf("请输入学生的总数");
	scanf("%d", &count);

	p = student_int(len);



	return 0;
}