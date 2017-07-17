#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("1.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    
    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    int ret = fcntl(fd, F_SETLKW, &lock);
    if (ret == -1)
    {
        perror("fcntl");
        return -2;
    }

    printf("this is the process B\n");

    close(fd);

    return 0;
}
