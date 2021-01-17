/*理解错题意解成了没有连续重复的最长字符串*/
/*正确见l3.3.c and l3.4.c*/
#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s)
{
    int length[100]; //要先申请一段内存才能对指针所指的东西赋值，否则*p=j+1会报segment错
    int *p = length;
    for (int j = 0, k = 0; j < strlen(s);j++)//k左指针，j右指针
    {
        for (int m = k; m < j; m++){
            if (s[m] == s[j]) {
                k++;
                j--;
                break;
            }
            if (m == j - 1)
                *p = j - k + 1; //直到选中数组中最后一个验证也不重复确实是所求不重复字符串, 右指针移动左指针不移动
                p++;
            // if (j == strlen(s) - 1) p--;
            // else{
            //     *p = j - k + 1;
            //     p++;
            //     if (j == strlen(s) - 1) p--;
            // } 
        }
    }
    int ret = length[0];
    if (strlen(s) == 0) ret = 0;//字符串为空
    if (strlen(s) == 1) ret = 1;
    //遍历一遍储存的长度，找出最长的
    for (int *q = length; q < p; q++)
    {
        ret = ((*q) > ret) ? (*q) : ret;
    }
    return ret;
}

int main()
{
    char s[40];
    int ret;
    strcpy(s, "abdddab"); //strcpy把含有'\0'结束符的字符串复制到另一个地址空间，返回值的类型为char*
    ret = lengthOfLongestSubstring(s);
    //printf("%s\n",s);
    //printf("%d\n",strlen(s));
    printf("%d\n", ret);
    return 0;
}
