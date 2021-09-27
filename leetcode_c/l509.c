#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
    int a;
    if (n == 0) {a = 0; return a;}
    if (n == 1) {a = 1; return a;}
    int *Fib = (int *)malloc(sizeof(int) * (n + 1));
    int i = 2;
    Fib[0] = 0;
    Fib[1] = 1;
    while (i <= n){
        Fib[i] = Fib[i - 1] + Fib[i - 2];
        i++;
    }
    a = Fib[n];
    return a;
}
int main(){
    int n=3;
    printf("%d\n", fib(n));
    return 0;
}
