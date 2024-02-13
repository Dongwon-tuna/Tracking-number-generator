#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* parseStringToArray(char source[]) {
    int length = strlen(source);

    char* resultArray = (char*)malloc((length + 1) * sizeof(char));

    if (resultArray == NULL) {
        fprintf(stderr, "메모리 할당 오류\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; i++) {
        resultArray[i] = source[i];
    }

    resultArray[length] = '\0';

    return resultArray;
}

int main() {
    char inp;
    scanf("%s",&inp);
    char* inputString = inp;

    char* resultArray = parseStringToArray(inputString);

    printf("Result Array: %c\n", inputString[1]);

    free(resultArray);

    return 0;
}


