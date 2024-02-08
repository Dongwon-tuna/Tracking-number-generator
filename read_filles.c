#pragma warning(disable :4996)
#include <stdio.h>
#include <string.h>
/*
typedef struct info_list
{
    char zipcode[5];
    char doo[10];
    char doo_eng[30];
    char city[10];
    char city_eng[20];
    char eup[10];
    char eup_eng[20];
    char road_code[13];
    char road_add[15];
    char road_add_eng[20];

};list;
*/

void Eliminate(char *str)
{    
    int len = strlen(str) + 1;
    
    for (; *str != '\0'; str++,len--)
    {   
        if (*str == '|')
        {
            strcpy_s(str, len,str + 1);
            printf("%s\n", str); 
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
    char *info_arr[8][30];


    while (fgets(buffer, 256, fp))
    {
        
        
        
        Eliminate(buffer);
        printf("%s\n",buffer);
        
    }
    fclose(fp);
}

