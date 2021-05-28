#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 80

int findnum(char str[], int len, int now)
{
    int digit_window = 2;
    int digit = 0;
    for(int i=now+1; i<=now+digit_window; i++){
        if(i >= len){
            break;
        }
        if(str[i] >= '0' && str[i] <= '9'){
            ++digit;
        }
        else{
            break;
        }
    }
    if(digit == 0){
        return 1;
    }

    int num = 0;
    int tmp_digit = digit;
    for(int i=now+1; i<=now+digit; i++){
        num += int(pow(10, --tmp_digit)) * (str[i] - '0');
    }
    return num;
}

int main()
{
    int cases; scanf("%d\n", &cases);
    while(cases--){
        char str[MAX_LEN];
        scanf("%s\n", str);
        int len = strlen(str);
        float total = 0.f;

        for(int i=0; i<len; i++){
            switch (str[i])
            {
            case 'C':
                total += 12.01 * findnum(str, len, i);
                break;
            case 'N':
                total += 14.01 * findnum(str, len, i);
                break;
            case 'H':
                total += 1.008 * findnum(str, len, i);
                break;
            case 'O':
                total += 16 * findnum(str, len, i);
                break;
            default:
                break;
            }
        }
        printf("%.3f\n", total);
    }
    return 0;
}

#ifdef __cplusplus
}
#endif