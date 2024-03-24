#include <stdio.h>

int factorial(int count){
    int res=1;
    for (int i=1 ; i<=count ; i++)
        res=res*i;
    return res;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n > 7 || n < 1)
    {
        return 0;
    } else 
        return printf("%d",factorial(n));
}
