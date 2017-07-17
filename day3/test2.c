#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

int main(void)
{
    void *p = mmap(NULL, 128, PROT_READ|PROT_WRITE, 
            MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
    if (p==MAP_FAILED)
    {
        perror("my");
        return -1;
    }

    char* str = (char*)p;
    strcpy(str, "hello");
    printf("%s\n", str);

    munmap(p, 128);

    return 0;
}
