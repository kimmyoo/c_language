#include <stdio.h>
#include <string.h>

void squeeze(char[], int);


int main()
{   
    char test[] = "aaaaaaTZa";
    squeeze(test, 'a');
    printf ("%s", test);
    return 0;
}


// a function that eliminates occurence of c in s[]
void squeeze(char s[], int c)
{
    int i, j;
    
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            // use j first then increment
            s[j++] = s[i];
    //and finally add '\0' to its end
    s[j] = '\0'; 
}

