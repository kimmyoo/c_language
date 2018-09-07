#include <stdio.h>
#define LIMIT 1000

//function declarations
int get_line(char t[], int lim);
void copy(char from[], char to[]);
void reverse(char original[], char container[], int len);
void reverse_inplace(char original[], int len);

//main function
int main(void)
{
    int cur_len, cur_max;
    char temp[LIMIT];
    char longest[LIMIT];
    cur_max = 0;
    while ((cur_len = get_line(temp, LIMIT))>0)
        if (cur_len > cur_max){
            //dont forget to update cur_max
            cur_max = cur_len;
            copy(temp, longest);
            //reverse(temp, longest, cur_max);
        }
    if (cur_max > 0){
        printf("the longest input is:%s\n", longest);
        reverse_inplace(longest, cur_max);
        printf("the longest input being reversed is:%s", longest);
    }
	return 0;
}

// function definitions 
int get_line (char t[], int lim)
{
    int i;
    char c;
    
    for (i = 0; i < lim -1 && (c = getchar())!= EOF && c != '\n'; ++i){
        t[i] = c;
    }
    //append newline to the last valid character in the array
    if (c == '\n'){
        t[i] = c;
        ++i;
    }
    //append EOF at the end
    t[i] = '\0';
    return i;
}


// function that copies chars from one array to destination array
void copy(char from[], char to[])
{
    int i;
    i = 0;
    
    //~ for (i = 0; from[i] != '\0'; ++i){
        //~ to[i] = from[i];
    //~ }
    
    while ((to[i] = from[i]) != '\0')
        ++i;
}

//function that copies and reverses char elements from one array to another
void reverse(char original[], char container[], int len)
{
    int i, j;
    j = 0;
    for (i = len; i >= 0; --i){
        if (original[i] == '\n' || original [i] == '\0');
        else{
            container[j] = original[i];
            ++j;
        }
    }
    container[j] = '\0';
}

//reverse an array in place. 
void reverse_inplace(char original[], int len)
{
    int temp;
    int i, j; 
    j = 0;
    temp = 0;
    
    // don't go over the middle!
    for (i = len; i>j; --i){
        if (original[i] == '\n' || original[i] == '\0');
        else{
            temp = original[i];
            original[i] = original[j];
            original[j] = temp;
            ++j;
        } 
    }
}
