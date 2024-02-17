#include <stdio.h>
#include <string.h>

char **parsing() {
    static char *arr1[3] = {"hi", "hiii", "hiiiq"};
    return arr1;
}

int main(void) {
    // char str[] = "Block D mask";
    // char *ptr = strtok(str," ");
    // char *return1[3];
    // int cnt = 0;
    // while (ptr != NULL)
    // {
    //     printf("%s\n", ptr);
        
    //     return1[cnt] = ptr;
    //     printf("%s\n",return1[cnt]);
    //     ptr = strtok(NULL," ");
    //     cnt ++;

    // }

    char **getpar = parsing();

    for (int i = 0; i < 3; i++) {
        printf("%s\n", getpar[i]);
    }

    return 0;
}
