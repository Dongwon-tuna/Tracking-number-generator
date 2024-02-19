#include <stdio.h>
#include <string.h>

void extractCharacters( char *inputString, char *result) {
    int length = strlen(inputString);

    // 첫 번째 문자
    result[0] = inputString[0];

    // 가운데 문자 (홀수 길이인 경우)
    if (length % 2 != 0) {
        result[1] = inputString[length / 2];
    }
    // 가운데 문자 (짝수 길이인 경우)
    else {
        result[1] = inputString[length / 2 - 1];
    }

    // 마지막 문자
    result[2] = inputString[length - 1];

    // 결과 문자열의 끝을 표시
    result[3] = '\0';
}

int main() {
    char inputString[100] = "hihihi";  // 충분한 크기의 문자열 배열
    char result[4];  // 첫 번째, 가운데, 마지막 문자 및 null 문자를 저장하는 배열
    char in = "hihihi";
    printf("%s\n",in);
    //printf("Enter a string: ");
    //scanf("%s", inputString);

    extractCharacters(inputString, result);

    printf("Result: %s\n", result);

    return 0;
}
