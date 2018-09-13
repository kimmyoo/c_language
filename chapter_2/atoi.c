#include <stdio.h>
int atoi(char[]);

int main()
{   
    int n = 0;

    char test[] = "98371a";
    n = atoi(test);
    printf ("%d:", n);
    return 0;
}

int atoi(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}
