#pragma warning(disable :4996)
#define MAX_LEN 100
#include <stdio.h>
#include <string.h>

int main()
{
    FILE* fs;
    fs = fopen("read.txt", "r");
    while (feof(fs) == 0)
    {
        char str[MAX_LEN];
        fgets(str,MAX_LEN,fs);
        printf("%s",str);
        
       
           
    }
    fclose(fs);
}

/*int counting(char ab){
    char str[] = ab;
    char* ptr = strchr(str, '|'); 
    int count = 0;

    while (ptr != NULL) 
    {
        ptr = strchr(ptr + 1, '|'); // 리턴된 포인터 +1 계속 검색
        count++;
    }

    

    return count;
}
*/