#pragma warning(disable :4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_FIELDS 30  

//------------------------------------------------------------------------
struct Zipcode_data
{
    char zipcode[10];
    char d[30];
    char d_eng[30];
    char c[20];
    char c_eng[20];

};

//-------------------------------------------------------------------------
int line_length(){
   FILE *fp;
   fp = fopen("read.txt", "r");
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
int main()
{
    struct Zipcode_data *data;
    int row =0;
    FILE* fp;
    fp = fopen("read.txt", "r");
    char frame[256];
    char buffer[256];
    int row_num = line_length();
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

        strcpy((data + row)->zipcode, fields[0]);
        strcpy((data + row)->d, fields[1]);
        strcpy((data + row)->d_eng, fields[2]);
        strcpy((data + row)->c, fields[3]);
        strcpy((data + row)->c_eng, fields[4]);

        row++;

    }

    for (int i = 0; i < row_num -1; i++)
    {
        printf("1: %s 2: %s 3: %s 4: %s 5: %s\n",(data+i)->zipcode,(data+i)->d, (data+i)->d_eng, (data+i)->c,(data+i)->c_eng );
    }
    
    fclose(fp);
    free(data);
}

