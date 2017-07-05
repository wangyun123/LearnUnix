#include <stdio.h>
#include <dlfcn.h>
#include <errno.h>

int main(void)
{
	void* handle = dlopen("libmath1.so", RTLD_NOW);
	if (!handle)
	{
		printf("can't open the libmath.so\n");
		perror("dynamic load");
		printf("%s\n", strerror(errno));
		return -1;
	}

	typedef int (*pFunc)(int, int);
	void* pf = dlsym(handle, "sub");
	pFunc func = (pFunc)pf;

	printf("dynamic load the library, result=%d\n", func(8,3));

	dlclose(handle);

	return 0;
}
