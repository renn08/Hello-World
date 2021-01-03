#include <stdio.h>
#include <string.h>
int lengthOfLongestSubstring(char * s){
    
    int start = 0;
    int end = 0;
    int length = 0;
    int max = 0;

    /* 使用sizeof(s)不能正确计算字符串得长度 
     * strlen包含头文件：string.h
     * 参考: https://blog.csdn.net/magic_world_wow/article/details/80500473
     */
    while(end < strlen(s)) {
        /* 记录当前end值
         * 用于和索引值index进行对比
         */
        char tmpchar = s[end];
        
        /* 索引值从start开始，计算到end-1位置处 */
        for(int index = start; index < end; index++) {
            /* 若发现最新得end值与索引值相同 */
            if(tmpchar == s[index]) {
                /* 将start移动到当前索引index下一个位置 */
                start = index + 1;
                /* 从新计算长度 */
                length = end - start;
                break;
            }
        }
        length++;
        end++;
        max = max < length ? length : max;
    }

    return max;
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
