#include <stdio.h>
#include <limits.h>
#include <string.h>
/*注意输出的数是在原字符串中连续的 假若遇到中间中断则舍去后面的所有字符*/
/*正如题文“连续数字”*/
int myAtoi(char *s)
{
    int i = 0;
    int ret = 0;
    while (i < strlen(s) && s[i] == ' ')
    {
        i++;
        if (i == strlen(s) - 1)
            ret = 0;
    }
    int j = 0;
    if (s[i] == 45)
    {
        for (i += 1; i < strlen(s); ++i)
        {
            if (47 < s[i] && s[i] < 58 && ret > (INT_MIN / 10 - 1))
            {
                j = 1;
                ret *= 10;
                if (ret == (INT_MIN / 10 * 10) && s[i] == '9')
                {
                    ret = INT_MIN;
                }
                else
                {
                    ret = ret - (int)(s[i] - '0');
                }
            }
            else if (47 < s[i] && s[i] < 58 && ret <= (INT_MIN / 10 - 1))
            {
                ret = INT_MIN;
            }
            else{break;}//排除数字中间出现非数字（不连续）
        }
        if (j == 0)
        {
            ret = 0;
        }
    }
    else if (s[i] == 43)
    {
        for (i += 1; i < strlen(s); ++i)
        {
            if (47 < s[i] && s[i] < 58 && ret <= (INT_MAX / 10))
            {
                j = 1;
                ret *= 10;
                if (ret == (INT_MAX / 10 * 10) && ((s[i] == '8') || (s[i] == '9')))
                {
                    ret = INT_MAX;
                }
                else
                {
                    ret = ret + (int)(s[i] - '0');
                }
            }
            else if (47 < s[i] && s[i] < 58 && ret > (INT_MAX / 10))
            {
                ret = INT_MAX;
            }
            else{break;}
        }
        if (j == 0)
        {
            ret = 0;
        }
    }
    else if (47 < s[i] && s[i] < 58) //注意不能写48 < s[i] < 57，永远为真
    {
        for (i; i < strlen(s); ++i)
        {
            if (47 < s[i] && s[i] < 58 && ret <= (INT_MAX / 10))
            {
                j = 1;
                ret *= 10;
                if (ret == ((INT_MAX / 10) * 10) && ((s[i] == 56) || (s[i] == 57))) //注意==优先级高于||，加括号，其他运算符优先于==，不能写成a == (56 || 57)
                {
                        ret = INT_MAX;
                }
                else
                {
                    ret = ret + (int)(s[i] - '0');
                }
            }
            else if (47 < s[i] && s[i] < 58 && ret > (INT_MAX / 10))
            {
                ret = INT_MAX;
            }
            else {break;}
        }
        if (j == 0)
        {
            ret = 0;
        }
    }
    else
    {
        ret = 0;
    }
    return ret;
}

int main()
{
    while(1){
        printf("Input:\n");
        char s[200] = {0};
        scanf("%s", &s);
        if(*s == 'b'){return 0;}
        printf("%d", myAtoi(s));
    }
    return 0;
}