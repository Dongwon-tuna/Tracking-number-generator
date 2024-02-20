#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binary_operations.h"
#include "parson.h"
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
char* generateDeliveryCode(const char *sido, const char *sigun, const char *gu) {
    static char sido_code[6];  
    static char sigungu_code[3]; 
    const char *str1 = "충청남도"; // 충남의 시/도 코드는 12
    const char *str2 = "천안시";
    const char *str3 = "서북구";    // 천안시 서북구의 시/군/구 코드는 56
    const char *str4 = "동남구";    // 천안시 동남구의 시/군/구 코드는 57

    if (strcmp(str1, sido) == 0) {
        strcpy(sido_code, "12");
    }
    if (strcmp(str2, sigun) == 0) {
        if (strcmp(str3, gu) == 0) {
            strcpy(sigungu_code, "56");
        } else if (strcmp(str4, gu) == 0) {
            strcpy(sigungu_code, "57");
        }
    }
    strcat(sido_code, sigungu_code);
    return sido_code;
}
//-----------------------------------------------------------------------------
void createAndAppendJSON(JSON_Array *mainArray, char* trackingNum, int key, char* address, char* note){
    JSON_Value *rootValue = json_value_init_object();
    JSON_Object *rootObject = json_value_get_object(rootValue);

    json_object_set_string(rootObject, "Tracking Number", trackingNum);
    json_object_set_number(rootObject, "Key", key);
    json_object_set_string(rootObject, "Address", address);
    json_object_set_string(rootObject, "Note", note);

    json_array_append_value(mainArray, rootValue);
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
    data = (struct Zipcode_data *)malloc(sizeof(struct Zipcode_data)*row_num);
    JSON_Value *mainValue = json_value_init_array();
    JSON_Array *mainArray = json_value_get_array(mainValue);
    
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
        char hex[16];
        char hex2[3];
        char hex3[3];
        
        int *time_p = time_parsing((data+i)->time);
        char **add_p = address_parsing((data+i)->address);
        idparse((data+i)->Id,idarr);
        ASCII(idarr[0],idarr[1],idarr[2],hex,hex2,hex3);
        char* result = generateDeliveryCode(add_p[0], add_p[1], add_p[2]);
        printf("%s\n", result);


        int time2[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
        int *time = dec_to_bin(time_p[3]*100 + time_p[4]);
        for (int j = 0; j < 12; j++) {
            time2[j] = time[j];
        }
        for (int j = 0; j < 12; j++) {
            time[j] = 0;
        }

        int key2[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
        int *key = key_value(time_p[5]);
        for (int j = 0; j < 12; j++) {
            key2[j] = key[j];
        }
        
        for (int j = 0; j < 12; j++) {
            key[j] = 0;
        }
   
        int *process = xor_process(time2, key2);
        int decc = bin_to_dec(process);
        char toChar[22];
        char date[3];
        sprintf(toChar,"%d", decc);
        sprintf(date,"%d",time_p[2]);
        printf("%d\n", decc);
        strncat(hex,hex2,2);
        strncat(hex,hex3,2);
        strncat(hex,result,4);
        strncat(hex,(data+i)->zipcode,5);
        strcat(toChar,date);
        strcat(toChar,hex);
        printf("%s\n",toChar);
        createAndAppendJSON(mainArray,toChar,time_p[5],(data+i)->address,(data+i)->etc);
        
    
    }

    json_serialize_to_file_pretty(mainValue, "trackingdata.json");  
    json_value_free(mainValue); 
    fclose(fp);
    free(data);
    return 0;
}