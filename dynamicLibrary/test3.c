#include <stdio.h>

int main(void)
{
	FILE* pf = fopen("etc/pwd", "w");
	if (!pf)
	{
		perror("adf");
		return -1;
	}

	return 0;
}
