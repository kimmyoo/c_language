#include <stdio.h>

int main()
{
    int c;
    while ((c=getchar()) != EOF){
        if (c == ' '|| c == '\t'){
            while((c=getchar()) == ' '|| c == '\t')
                ;
            putchar(' ');
            if ( c == EOF)
                break;
        }
        putchar(c);
    }
}
