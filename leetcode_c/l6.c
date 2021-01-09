#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//最好的传递字符串方法：用原来的指针输出
char *convert(char *s, int numRows)
{
    //建立index数组
    int index[strlen(s)];
    char ret[1000] = {0};
    int row = 0;
    int down= 1;
    //特殊情况numRows==1
    if(numRows == 1)
    {
        return s;
    }
    //遍历
    for (int i = 0; i < strlen(s); ++i)
    {
        if (row == numRows - 1)
        {
            down = 0; //向上移
        }
        if (row == 0)
        {
            down = 1;
        }
        index[i] = row;
        if(down)
        {
            row++;
        }
        else
        {
            row--;
        }   
    }
    //找每行拼起
    int n = 0;
    for (int z = 0; z < numRows; ++z)
    {
        for (int j = 0; j < strlen(s); ++j)
        {
            if(index[j] == z)
            {
                ret[n++] = s[j];
            }
        }
    }
    strcpy(s,ret);
    return s;
}
int main()
{
    char s[]={"abcdefg"};
    int numRows = 1;
    char *a;
    a = convert(s, numRows);
    printf("%s", a);
    return 0;
}