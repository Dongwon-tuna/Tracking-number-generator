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

int *key_value(int num){
    static int array2[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    int cnt = div_number(num);
    int cnt2 = cnt + 1;
    for (int i = 0; i < cnt2; i++)
    {
    cnt = cnt-1;
    if (num - pow(2,cnt)>=0){ 
        array2[11-cnt] = 1;
        num = num -pow(2,cnt);
    }
    else {
        array2[11-cnt] = 0;
    }
    }
    array2[0] = array2[11];
    array2[1] = array2[10];
    array2[2] = array2[9];
    array2[3] = array2[8];
    array2[4] = array2[7];
    array2[5] = array2[6];
    return array2;

}

int *xor_process(int arr1[], int arr2[]){
    static int returnarr[12];
    for (int i = 0; i < 12; i++)
    {
        
        if (arr1[i] == arr2[i])
        {
            returnarr[i] = 0;
        }
        else{
            returnarr[i] = 1;
        }
        
    }
    return returnarr;

}

int bin_to_dec(int arr[]){
    int sum = 0;
    for (int i = 0; i < 12; i++)
    {
        sum = sum + pow(2,11-i)* arr[i];
    }
    
    
    printf("\n%d",sum);
}


int main() {

   
    int in,sec;
    int result[12];

    scanf("%d", &in);
    scanf("%d", &sec);

    int *time = dec_to_bin(in);
    int *key = key_value(sec);
    // XOR 연산의 특성을 이용하여 디코딩 할 수 있다.
    int *process = xor_process(time,key);
    int *pro2 = xor_process(process,key);
    for (int i = 0; i < 12; i++)
    {
        printf("%d",pro2[i]);
    
    }    
    return 0;


}