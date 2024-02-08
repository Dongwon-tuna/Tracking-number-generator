#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 30  

int main() {
    char input[] = "32833|충청남도|Chungcheongnam-do|계룡시|Gyeryong-si|||442503256001|금암로|Geumam-ro|0|172|0|4425010100100540004000001|||4425010100|금암동||금암동|0|54|01|4||";

   
    char *fields[MAX_FIELDS];

    
    char *token = strtok(input, "|");

    int field_count = 0;

    while (token != NULL && field_count < MAX_FIELDS) {
       
        fields[field_count] = token;

        token = strtok(NULL, "|");

        field_count++;
    }

    printf("파싱된 정보:\n");
    for (int i = 0; i < field_count; i++) {
        if (fields[i] != NULL) {
            printf("Field %d: %s\n", i + 1, fields[i]);
        } else {
            printf("Field %d: NULL\n", i + 1);
        }
    }

    return 0;
}