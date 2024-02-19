#pragma warning(disable :4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binary_operations.h"
#define MAX_FIELDS 30  


//------------------------------------------------------------------------
struct Zipcode_data
{
    char Id[30];
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
void idparse(char id[],char re[]){
    int cnt = strlen(id);
    printf("%d\n",cnt);
    int oe2 = cnt/2;

    re[0] = id[0];
    re[1] = id[oe2];
    re[2] = id[cnt-1];
    re[3] = '\0';
}
//-----------------------------------------------------------------------------
void ASCII(char input, char input2, char input3, char output[3],char output2[3], char output3[3]){
    sprintf(output,"%02x",input);
    sprintf(output2,"%02x",input2);
    sprintf(output3,"%02x",input3);
}

//-----------------------------------------------------------------------------
void sido(char sido[]){
    //우선은 천안지역 택배번호 생성기이기에 충청남도 천안시 서북구/봉정로 기준으로 작성함
    //추후에 대한민국 행정지역별로 분류하여 보완할 계획
    printf("%s",sido);
    const char *str1 = "충청남도";
    if(strcmp(str1,sido)==0){
        printf("same\n");
    }
    else{
        printf("diff\n");
    }
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
        char idarr[4];
        char hex[3];
        char hex2[3];
        char hex3[3];
        int *time_p = time_parsing((data+i)->time);
        printf("%d, %d\n",time_p[3]*100 + time_p[4],time_p[5]);
        char **add_p = address_parsing((data+i)->address);
        idparse((data+i)->Id,idarr);
        printf("%s\n",idarr);
        ASCII(idarr[0],idarr[1],idarr[2],hex,hex2,hex3);
        printf("%s%s%s",hex,hex2,hex3);
        printf("%s\n",add_p[2]);
        sido(add_p[0]);

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