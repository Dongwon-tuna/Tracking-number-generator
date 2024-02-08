#pragma warning(disable :4996)
#include <stdio.h>
#include <string.h>
#define MAX_FIELDS 30  
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



int main()
{
    FILE* fp;
    fp = fopen("read.txt", "r");
    char frame[256];
    char buffer[256];
    char *info_arr[8][30];


    while (fgets(buffer, 256, fp))
    {
        
        char *fields[MAX_FIELDS];
        char *token = strtok(buffer, "|");
        int field_count = 0;

        while (token != NULL && field_count < MAX_FIELDS) {
       
        fields[field_count] = token;

        token = strtok(NULL, "|");

        field_count++;
        }

        
        for (int i = 0; i < field_count; i++) {
            if (fields[i] != NULL) {
                printf("Field %d: %s\n", i , fields[i]);
            } else {
                printf("Field %d: NULL\n", i );
            }
        }
        
    }
    fclose(fp);
}

