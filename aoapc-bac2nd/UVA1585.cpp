#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cases; scanf("%d\n", &cases);
    while(cases--){
        char c;
        int last = 0;
        int total = 0;
        while(scanf("%c", &c) && c != '\n'){
            if(c == 'O'){
                ++last;
                total += last;
            }
            else{
                last = 0;
            }
        }
        printf("%d\n", total);
    }

    return 0;
}

#ifdef __cplusplus
}
#endif