#pragma warning(disable :4996)
#include <stdio.h>
#include <string.h>

void Eliminate(char *str)
{    
    int len = strlen(str) + 1;
    for (; *str != '\0'; str++,len--)//���� ���ڸ� ���� ������ �ݺ�
    {
        if (*str == '|')//ch�� ���� ������ ��
        {
            strcpy_s(str, len,str + 1);
            str--;            
        }
    }
}

int main()
{
    FILE* fp;
    fp = fopen("read.txt", "r");
    char frame[256];
    char buffer[256];


    while (fgets(buffer, 256, fp))
    {
        
        printf("%s\n",buffer);
        Eliminate(buffer);
        printf("%s\n",buffer);
        
        
    }
    fclose(fp);
}

