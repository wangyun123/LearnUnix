#include <stdio.h>

int main(void)
{
    FILE* fp = fopen("1.txt", "r");
    if (!fp)
    {
        perror("open");
        return -1;
    }

    void *ptr;
    size_t len = fread(ptr, sizeof(char), 128, fp);
    printf("the len: %d\n", len);
    printf("content: %s\n", (char*)ptr);

    fclose(fp);
    return 0;
}
