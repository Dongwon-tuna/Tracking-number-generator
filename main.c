#pragma warning(disable :4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binary_operations.h"
#define MAX_FIELDS 30  


//------------------------------------------------------------------------
struct Zipcode_data
{
    char Id[10];
    char time[50];
    char address[70];
    char zipcode[6];
    char etc[70];

};

//-------------------------------------------------------------------------
int line_length(){
   FILE *fp;
   fp = fopen("data.txt", "r");
   char tmp;
   int cnt = 1;

   if (fp == NULL) {
      printf("Failed");
   }

   while (fscanf(fp, "%c", &tmp) != EOF) {
      if (tmp == '\n')
         cnt++;
   }
   
   return cnt; 
}

//----------------------------------------------------------------------------
int *time_parsing(char time[]){

    char *ptr = strtok(time,"_");
    static int time_arr[6];
    int cnt = 0;
    while (ptr != NULL)
    {
        int num1;
        num1 = atoi(ptr);
        time_arr[cnt] = num1;
        ptr = strtok(NULL,"_");
        cnt ++;
    }
    return time_arr;
    
}

//-----------------------------------------------------------------------------
char **address_parsing(char add[]){
    char *ptr = strtok(add," ");
    static char *add_arr[10];
    int cnt = 0;
    while (ptr != NULL)
    {
        add_arr[cnt]= ptr ;
        ptr = strtok(NULL," ");
        cnt ++;
    }
    return add_arr;
}
//-----------------------------------------------------------------------------
int main()
{
    struct Zipcode_data *data;
    int row =0;
    FILE* fp;
    fp = fopen("data.txt", "r");
    char frame[256];
    char buffer[256];
    int row_num = line_length();
    printf("%d\n",row_num);
    data = (struct Zipcode_data *)malloc(sizeof(struct Zipcode_data)*row_num);
    

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

        strcpy((data + row)->Id, fields[0]);
        strcpy((data + row)->time, fields[1]);
        strcpy((data + row)->address, fields[2]);
        strcpy((data + row)->zipcode, fields[3]);
        strcpy((data + row)->etc, fields[4]);

        row++;

    }



    for (int i = 0; i < row_num; i++)
    {
        printf("1: %s 2: %s 3: %s 4: %s 5: %s\n",(data+i)->Id,(data+i)->time, (data+i)->address, (data+i)->zipcode,(data+i)->etc);
    
        int *time_p = time_parsing((data+i)->time);
        printf("%d, %d\n",time_p[3]*100 + time_p[4],time_p[5]);
        char **add_p = address_parsing((data+i)->address);
        printf("%s\n",add_p[2]);

        int time2[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
        
        int *time = dec_to_bin(time_p[3]*100 + time_p[4]);
        
        for (int j = 0; j < 12; j++) {
            printf("%d", time[j]);
            time2[j] = time[j];
        }
        for (int j = 0; j < 12; j++) {
            time[j] = 0;
        }
        printf("\n");

        //int *key[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
        int key2[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
        int *key = key_value(time_p[5]);
        for (int j = 0; j < 12; j++) {
            printf("%d", key[j]);
            key2[j] = key[j];
        }
        
        for (int j = 0; j < 12; j++) {
            key[j] = 0;
        }
        printf("\n");

        int *process = xor_process(time2, key2);
        for (int j = 0; j < 12; j++) {
            printf("%d", process[j]);
        }
        printf("\n");
        int decc = bin_to_dec(process);
        printf("%d", decc);
        
    
    }

    
    fclose(fp);
    free(data);
}