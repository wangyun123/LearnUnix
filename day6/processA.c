#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("1.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    int ret = fcntl(fd, F_SETLK, &lock);
    if (ret == -1)
    {
        perror("fcntl");
        return -2;
    }

    printf("this is the process A\n");
    sleep(10);

    close(fd);

    return 0;
}
