#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int file_copy(int fd_s, int fd_d);
int file_copy1(int fd_s, int fd_d);

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("the param is not enough!\n");
        return -1;
    }
    int fd_s, fd_d;
    fd_s = open(argv[1], O_RDONLY);
    fd_d = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC);
    if (fd_s == -1 || fd_d == -1)
    {
        perror("open");
        return -2;
    }

    file_copy1(fd_s, fd_d);

    close(fd_s);
    close(fd_d);

    return 0;
}

int file_copy(int fd_s, int fd_d)
{
    char* buf[128];
    memset(buf, 0, 128);

    int ret_rd, ret_wr;

    while( (ret_rd = read(fd_s, buf, 128)) != 0 )
    {
        ret_wr = write(fd_d, buf, ret_rd);
        memset(buf, 0, 128);
    }
    return 0;
}

int file_copy1(int fd_s, int fd_d)
{
    char* buf[128];
    memset(buf, 0, 128);

    int ret_rd, ret_wr;

    char* tmp;
    while( (ret_rd = read(fd_s, buf, 128)) != 0 )
    {
        tmp = (char*)buf;
        while( (ret_wr = write(fd_d, tmp, ret_rd)) )
        {
            tmp += ret_wr;
            ret_rd -= ret_wr;
        }
        memset(buf, 0, 128);
    }
    return 0;
}
