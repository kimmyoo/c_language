#include <stdio.h>
#include <string.h>

int atoi(char[]);
int lower(int);

int main()
{   
    int n = 0;
    int i;

    char test[] = "98371AZ";
    n = atoi(test);
    printf ("%d:", n);
    
    for (i = 0; i < strlen(test); ++i)
        printf ("\n%c", lower(test[i]));
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

int lower (int c)
{
    if ( c >= 'A' && c <= 'Z')
        // 'A' dec: 65, 'a' dec: 97
        return  c  + 'a' - 'A';
    else
        return c;
}
