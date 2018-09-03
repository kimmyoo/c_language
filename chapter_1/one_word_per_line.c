#include <stdio.h>
#define YES 1
#define NO 0


int main()
{
    int c, newline;
    newline = NO;
    
    while((c=getchar()) != EOF){
        
        if (c==' ' || c== '\t'|| c=='\n'){
            if (!newline){
                putchar('\n');
                newline = YES;
            }
        }
        else{
            putchar(c);
            newline = NO;
        }
    }
    return 0;
}
