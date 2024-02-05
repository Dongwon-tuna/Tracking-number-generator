#include <stdio.h>
#include <string.h> 

int main()
{
    char str[] = "가나다라|마바사아|1234|5678";
    char* ptr = strchr(str, '|'); 
    int count = 0;

    while (ptr != NULL) 
    {
        printf("%s\n", ptr); 
        ptr = strchr(ptr + 1, '|'); 
        count++;
    }

    printf("찾은 문자 %d개", count);

    return 0;
}


