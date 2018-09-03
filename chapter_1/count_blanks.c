#include <stdio.h>

int main()
{
    int c, nt, nb, nl;
    nt = 0;
    nb = 0;
    nl = 0;
    while ((c=getchar())!= EOF){
        if(c==' ')
            ++nb;
        else if(c=='\t')
            ++nt;
        else if(c=='\n')
            ++nl;
    }
    printf ("%d, %d, %d", nt, nb, nl);
}
