#include <stdio.h>

#define OUT 0
#define IN 1

int main()
{
    int nw, nc, nl, c, state;
    nw = nc = nl = 0;
    state = 0;
    
    while ((c = getchar())!= EOF){
        ++nc;
        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        if (c=='\n')
            ++nl;
        else if (state == OUT){
            //my solution: this line is different from the book
            if (c != '\t' && c!= '\n' && c!=' '){
                state = IN;
                ++nw;
            }
        }
    }
    printf("%d %d %d:", nw, nc, nl);
}
