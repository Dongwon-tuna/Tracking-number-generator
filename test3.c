#include <stdio.h>

void alphabetToHex(char alphabet, char hexString[3]) {
    sprintf(hexString, "%02x", alphabet);  // 알파벳의 아스키코드를 16진수 문자열로 변환
}

int main() {
    char input;
    char hexString[3];  // 두 자리의 16진수를 저장할 문자열

    printf("Enter an alphabet: ");
    scanf("%c", &input);

    alphabetToHex(input, hexString);

    printf("Character: %c, ASCII Hex: %s\n", input, hexString);

    return 0;
}