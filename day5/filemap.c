#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main(void)
{
    int fd = open("1.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    int len = lseek(fd, 0, SEEK_END);
    printf("the length of file: %d\n", len);
    void *p = mmap(NULL, len, \
            PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    printf("the content of file: \n%s\n", p);
    char* str = (char*) p;
    str[1] = 'A';
    munmap(fd, len);

    close(fd);

    return 0;
}
