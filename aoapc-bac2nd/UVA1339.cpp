#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
    char encrypt[MAX_LEN];
    char org[MAX_LEN];
    while(scanf("%s\n%s", encrypt, org)){
        int alphabet_org[26]; memset(alphabet_org, 0, 26);
        int alphabet_encrypt[26]; memset(alphabet_encrypt, 0, 26);

        int encrypt_num = 0;
        int first_org = 25;
        for(int i=0; i<strlen(org); i++){
            first_org = org[i] - 'A' < first_org ? org[i] - 'A' : first_org;
            alphabet_org[org[i] - 'A'] = 1;
            
            if(alphabet_encrypt[encrypt[i] - 'A'] == 0){
                ++encrypt_num;
            }
            alphabet_encrypt[encrypt[i] - 'A'] = 1;
        }

        for(int i=0; i<encrypt_num; i++){

        }
    }

    return 0;
}

#ifdef __cplusplus
}
#endif