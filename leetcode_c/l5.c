#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//中心扩散
char *longestPalindrome(char *s)
{
    int i = 0; //指向中心数字（偶数为后一位）
    int j = 0; //扩散范围
    int a = 0; //指向回文字符串开始字符
    int l = 1; //长度
    int begin[1000];
    int length[1000];
    int begin2[1000];
    // int *begin = (int *)malloc(strlen(s) * sizeof(int));
    // int *length = (int *)malloc(strlen(s) * sizeof(int));
    // int *begin2 = (int *)malloc(strlen(s) * sizeof(int));
    int length2[1000] = {0};
    char *ret = (char *)malloc(1001 * sizeof(char));

    //奇数回文子串
    for (i = 0; i < strlen(s); ++i)
    {
        a = i;
        l = 1;
        j = 0;
        while ((i - j >= 0) && ((i + j + 1) <= strlen(s)))
        {
            if (s[i - j] != s[i + j])
            { //回文条件
                break;
            }
            l = 1 + j * 2;
            a = i - j;
            j++;
        }
        //store the information
        begin[i] = a;
        length[i] = l;
    }

    //偶数回文子串
    //search 对子
    for (i = 0; i < strlen(s) - 1; ++i)
    {
        if (s[i] == s[i + 1])
        {
            a = i;
            l = 2;
            j = 0;
            while ((i - j >= 0) && (i + j + 2) <= strlen(s))
            {
                if (s[i - j] != s[i + 1 + j])
                {
                    break;
                }
                l = 2 + j * 2;
                a = i - j;
                j++;
            }
            begin2[i] = a;
            length2[i] = l;
        }
    }

    //最长回文子串
    int max = 0;
    for (i = 0; i < strlen(s); ++i)
    {
        if (length[i] > max)
        {
            max = length[i];
            l = max;
            a = begin[i];
        }
    }
    for (i = 0; i < 1000; ++i)
    {
        if (length2[i] > max)
        {
            max = length2[i];
            l = max;
            a = begin2[i];
        }
    }

    for (int m = 0; m < l; ++m){
        ret[m] = s[a + m];
    }
    ret[l] = 0;//important
    return ret;
}

int main(){
    char s[1000] = "asdfascbcbcabbbbafasada";
    char *a;
    a = longestPalindrome(s);
    printf("%s\n", a);
    free(a);
    return 0;
}