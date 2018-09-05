#include <stdio.h>
int power_ver1(int, int);
int power_ver2(int, int);

int main()
{
    int i;
    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power_ver1(2, i), power_ver2(-3, i));
    return 0;
}


int power_ver1(int base, int n)
{
    int i, res;
    res = 1;
    for (i = 1; i <= n; ++i){
        res = res * base;
    }
    return res;
}

//n is used as a local variable, any change of n in local function 
//will not affect original n. 
//this pass-by-value property will result in less varaibles in programs.
int power_ver2 (int base, int n)
{
    int res;
    
    for (res = 1; n >0; --n)
        res = res * base;
    return res;
}
