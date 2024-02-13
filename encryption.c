#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int div_number(int num){
    int res;
    int cnt = 0;
    while (num != 0)
    {
        res = num%2;
        num = num/2;
        cnt ++;
    }
    return cnt;
}

int *dec_to_bin(int num){
    static int array[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    array[3] = num;
    return array;

}

int main() {
    int in;
    
 
    scanf("%d", &in);
    printf("나누기 완료");
    printf(": %d\n",div_number(in));
    int *arr = dec_to_bin(div_number(in));
    for (int i = 0; i < 12; i++)
    {
        
        printf("%d",arr[i]);
    }
    

    return 0;

}
