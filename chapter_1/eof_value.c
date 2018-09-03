#include <stdio.h>

int main()
{
    int c;
    while ((c = getchar())!= EOF){
        printf("input EOF to stop\n");
    }
    printf("value of EOF is %d", c); //ctrl + d
}
