#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rearr(char input[]){
    int length = strlen(input);
    char *arr = (char *)malloc(sizeof(char)*(length + 1));

    for (int i = 0; i < length; i++)
    {
        arr[i] = input[i];
    }
    arr[length] = '\0';
    

}

int main(void){
    char input;
    scanf("%s",&input);

    char *resss = rearr(input);

    //printf("%c",ress[0]);
    free(resss);
    


}