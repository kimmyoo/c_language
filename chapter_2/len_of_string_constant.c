#include <stdio.h>
#include <string.h>
int str_len(char s[]);

int main(void)
{   
    int len1, len2;
    char testArray [] = "hello world!";
    len1 = str_len(testArray);
    len2 = strlen(testArray);
    printf("according to my own function, len is %d\n", len1);
    printf("according to standard library funcion, len is %d\n", len2);
	return 0;
}

int str_len(char s[])
{
    int n;
    n = 0;
    while (s[n] != '\0'){
        ++n;
    }
    return n;
}


/*
The difference here is that

char *s = "Hello world";
will place "Hello world" in the read-only parts of the memory, and 
making s a pointer to that makes any writing operation on this memory illegal.

While doing:
char s[] = "Hello world";
puts the literal string in read-only memory and copies the string to 
newly allocated memory on the stack. Thus making
s[0] = 'J';
legal.
 */
