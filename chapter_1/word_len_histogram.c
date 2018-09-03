#include <stdio.h>
#define MAX 16
#define YES 1
#define NO 0

int main()
{
    int c, i, word_index;
    int histogram[MAX];
    int len_word, newword;
    word_index = -1;
    newword = YES;
    len_word = 0;
    
    for (i = 0; i < MAX; ++i)
        histogram[i] = 0;
    printf ("put a sentence:");
    
    while(((c=getchar()) != EOF) && word_index < MAX){
        if (c == ' '|| c=='\n' || c=='\t' || c == -1){
            newword = YES;
            if (len_word >= MAX-1)
                histogram[MAX]++;
            else
                histogram[len_word]++;
            len_word = 0;
        }else{
            if (newword){
                ++word_index;
                len_word++;
            }
            else{
                ++len_word;
            }
            newword = NO;
        }
    }

    for (i = 0; i < MAX-1; i++){
        printf("\n%2d:", i+1);
        int j;
        for (j = 0; j < histogram[i+1]; j++)
            printf ("[]");
    }

    return 0;
}
