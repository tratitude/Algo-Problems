#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 82

void fixedPrint(int cases, int ans)
{
    if(cases != 0){
        printf("%d\n\n", ans);
    }
    else{
        printf("%d\n", ans);
    }
}

int main()
{
    int cases; scanf("%d", &cases);
    while(cases--){
        char str[MAX_LEN]; scanf("%s", str);
        int len = strlen(str);
        int flag = 0;

        for(int i=1; i < len; i++){
            if(len % i == 0){
                char *str1 = (char*)calloc(len+2, sizeof(char));
                char *str2 = (char*)calloc(len+2, sizeof(char));
                // memory not reset
                /*char str1[MAX_LEN];
                char str2[MAX_LEN];*/

                strncpy(str1, str, i);
                int check_flag = 1;
                for(int j=1; j<len/i; j++){
                    strncpy(str2, str + i*j, i);
                    
                    if(!strcmp(str1, str2)){
                        check_flag &= 1;
                    }
                    else{
                        check_flag = 0;
                        break;
                    }
                }
                if(check_flag){
                    flag = 1;
                    fixedPrint(cases, i);
                    break;
                }
            }
        }
        if(!flag){
            fixedPrint(cases, len);
        }
    }

    return 0;
}

#ifdef __cplusplus
}
#endif