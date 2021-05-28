#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n, k, num, ans;

    scanf("%d %d %d", &n, &k, &num);

    if ((int)n / 10 == 0 && k > 0)
    {
        ans = 0;
    }
    else
    {
        char str[n];
        snprintf(str, "%d", num, n);
        int change = k > n ? n : k;

        for (int i = change - 1; i >= 0; i--)
        {
            if (str[i] == change - 1)
            {
                str[i] = "1";
            }
            else
            {
                str[i] = "0";
            }
        }
        ans = stoi(str);
    }
    printf("%d\n", ans);
    return 0;
}