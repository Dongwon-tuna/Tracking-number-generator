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
    int cnt = div_number(num);
    printf("cnt : %d\n",cnt);
    int cnt2 = cnt + 1;
    for (int i = 0; i < cnt2; i++)
    {
    cnt = cnt-1;
    if (num - pow(2,cnt)>=0){ 
        array[11-cnt] = 1;
        num = num -pow(2,cnt);
    }
    else {
        array[11-cnt] = 0;
    }
    }
    return array;

}

int *key_value(int sec){
    
}

int main() {
    int in;

    scanf("%d", &in);
    int *arr = dec_to_bin(in);
    for (int i = 0; i < 12; i++)
    {
        
        printf("%d",arr[i]);
    }
    
    return 0;

}
