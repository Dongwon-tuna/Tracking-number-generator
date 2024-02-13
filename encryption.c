#include <stdio.h>

//Xor 연산을 통한 암호화

int main() {
    int in, res;
    scanf("%d", &in);
    
    //% 나머지 /는 몫

    while (in != 0)
    {
        res = in%2;
        in = in/2;
        printf("%d\n",in);
    }
    printf("나누기 완료");
    return 0;

}
