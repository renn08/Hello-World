#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;//末尾为0显然是false
    int revertNum = 0;
    while (x > revertNum)
    {
        revertNum = x % 10 + revertNum * 10;
        x /= 10;
    }
    return revertNum == x || revertNum / 10 == x;
}

int main(){
    int x = 121;
    if(isPalindrome(x)) printf("Yes!");
    return 0;
}