#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd3 = open("log.txt", O_RDWR|O_CREAT|O_APPEND);
    if (fd3 == -1)
    {
        perror("open");
        return -1;
    }
    printf("the log.txt's : %d\n", fd3);

//    dup2(fd3, STDOUT_FILENO);
    printf("hello\n");

    close(fd3);

    return 0;
}
