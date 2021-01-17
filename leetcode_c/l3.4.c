#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s)
{
    int i; //计数器
    int count = 0; //子串当前长度
    int max = 0; //子串最大长度
    int start = 0; //子串起始位置
    int index[128] = {0}; //记录每个字符先后出现的位置 0-127是所有的字符

    for (i = 0; s[i] != '\0'; i++)
    {
        if (index[s[i]] > start)
        { //若为真，则说明字符s[i]在之前重复出现过
            count = i - start; // 记录此时子串的长度 
            if (count > max) // 若当前子串大于先前记录的最大字串长度，则更新max 
                max = count;
            start = index[s[i]]; // 更新新子串的起始位置 
        }
        index[s[i]] = i + 1; // 记录字符s[i]在整个字符串中出现的位置 
    }

    count = i - start; // 计算最后一个子串的长度 
    return count > max ? count : max;
}

int main()
{
    char s[40];
    int ret;
    strcpy(s, "abcabcdd"); //strcpy把含有'\0'结束符的字符串复制到另一个地址空间，返回值的类型为char*
    ret = lengthOfLongestSubstring(s);
    //printf("%s\n",s);
    //printf("%d\n",strlen(s));
    printf("%d\n", ret);
    return 0;
}

