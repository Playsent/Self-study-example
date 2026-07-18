#include <stdio.h>

void *my_memcpy(void *dst, const void *src, int n)
{
    char *d = (char *)dst;
    char *c = (char *)src;
    for(int i = 0; i < n; i++) d[i] = c[i];
    return dst;
}

void *my_memmove(void *dst, const void *src, int n)
{
    char *d = (char *)dst;
    char *c = (char *)src;
    if(d < c)              // 用 char* 比较，而不是 void*
    {
        for(int i = 0; i < n; i++)
            d[i] = c[i];
    }
    else
    {
        for(int i = 0; i < n; i++) d[n - 1 - i] = c[n - 1 - i];
    }
    return dst;
}

int main()
{
    char buff[20] = "Hello World";
    my_memcpy(buff, "Hello 123456", 12);
    for(int i = 0; i < 12; i++) printf("%c", buff[i]);
    printf("\n");
    
    my_memmove(buff, "World 123456123", 16);
    for(int i = 0; i < 16; i++) printf("%c", buff[i]);
    printf("\n");
    return 0;
}