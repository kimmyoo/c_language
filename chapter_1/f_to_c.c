#include <stdio.h>

#define MIN -100
#define MAX 400
#define STEP 20

void f_to_c(int min, int max, int step)
{   
    float t;
    for(t = min; t <= max; t = t + step){
        float c;
        c = 5.0/9.0 * (t-32);
        printf("%3.0f \t %6.1f \n", t, c);
    }
}

int main()
{
    f_to_c(MIN, MAX, STEP);
}
