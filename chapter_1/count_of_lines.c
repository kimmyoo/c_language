#include <stdio.h>

int main()
{
    long nl = 0;
    int c;
    // precedence of != is higher than =
    while ((c = getchar())!= EOF){
        if (c=='\n')
            ++nl;
    }
    printf("number of lines: %ld", nl);
}
