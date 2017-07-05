#include <stdio.h>
#include "math.h"
#include "proc.h"

/*
void func()
{
	int a[2][3] = {1,2,3,4,5,6};
	printf("%x - %d\n", *(a+0), *(*(a+0)));
	printf("%x - %d\n", *(a+1), *(*(a+1)));
}
*/

void little()
{
	int i=1;
	char c = (char)i;
	if (c==0x1)
	{
		printf("this is little order!\n");
//		return true;
	}
	else
	{
		printf("this is big order!\n");
//		return false;
	}
}

int proc(math_t p, int x, int y)
{
	return p(x,y);
}

int main(int argc, char* argv[])
{
	int x=6, y=2;
	printf("a+b=%d\n", add(x,y));
	printf("a-b=%d\n", proc(sub, x, y));
	math_t f[4] = {add, sub, mul, div};
	printf("a*b=%d\n", proc(f[2], x, y));	
	printf("a/b=%d\n", proc(f[3], x, y));	

	little();
	func1();

	return 0;
}
