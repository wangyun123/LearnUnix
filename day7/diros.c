#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
    DIR *pdir;
    pdir = opendir(argv[1]);
    if(pdir == NULL)
    {
        perror("open");
        return -1;
    }

    struct dirent * p;
    //while(p = readdir(pdir));
    while( (p=readdir(pdir)) != NULL )
    {
        printf("inode: %ld\n", p->d_ino);
        printf("name : %s\n", p->d_name);
    }

    closedir(pdir);

    return 0;
}
