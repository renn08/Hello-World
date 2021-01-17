/*理解错题意解成了没有连续重复的最长字符串*/
/*正确见l3.3.c and l3.4.c*/
#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s)
{
    int length[100];//要先申请一段内存才能对指针所指的东西赋值，否则*p=j+1会报segment错
    int *p = length;
    for (int i, j = 0; i < strlen(s); i++, j++)
    {
        if (s[i] == s[i + 1]){//encounter the same character
            *p = j + 1;
            p++;//先将这个长度储存，然后p指向了下一个储存长度的位置
            j = -1;
        } 
        if (i == strlen(s) - 1) *p = j + 1;
    }
    //遍历一遍储存的长度，找出最长的~
    int ret = length[0];
    for (int *q = length; q <= p; q++){
        ret = ((*q) > ret)? (*q) : ret; 
    } 
    return ret;
}

int main(){
    char s[40];
    int ret;
    strcpy(s, "abcddabcsdahfkahkjdfhkajshdfkjagd"); //strcpy把含有'\0'结束符的字符串复制到另一个地址空间，返回值的类型为char*
    ret = lengthOfLongestSubstring(s);
        //printf("%s\n",s);
        //printf("%d\n",strlen(s));
        printf("%d\n", ret);
        return 0;
}
