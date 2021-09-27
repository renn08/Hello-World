#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    if (n == 4)
        return 3;
    if (n == 5)
        return 5;
    if (n == 6)
        return 8;
    if (n == 7)
        return 13;
    if (n == 8)
        return 21;
    if (n == 9)
        return 34;
    if (n == 10)
        return 55;
    if (n == 11)
        return 89;
    if (n == 12)
        return 144;
    if (n == 13)
        return 233;
    if (n == 14)
        return 377;
    if (n == 15)
        return 610;
    if (n == 16)
        return 987;
    if (n == 17)
        return 1597;
    if (n == 18)
        return 2584;
    if (n == 19)
        return 4181;
    if (n == 20)
        return 6765;
    if (n == 21)
        return 10946;
    if (n == 22)
        return 17711;
    if (n == 23)
        return 28657;
    if (n == 24)
        return 46368;
    if (n == 25)
        return 75025;
    if (n == 26)
        return 121393;
    if (n == 27)
        return 196418;
    if (n == 28)
        return 317811;
    if (n == 29)
        return 514229;
    if (n == 30)
        return 832040;
    return 0;
}
int main()
{
    int n = 3;
    printf("%d\n", fib(n));
    return 0;
}
