#include <stdio.h>
#include <string.h> 

int main()
{
    char str[] = "�����ٶ�|���ٻ��|1234|5678";
    char* ptr = strchr(str, '|'); 
    int count = 0;

    while (ptr != NULL) 
    {
        printf("%s\n", ptr); 
        ptr = strchr(ptr + 1, '|'); 
        count++;
    }

    printf("ã�� ���� %d��", count);

    return 0;
}


