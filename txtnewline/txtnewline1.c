/*From the left to the right, top to the bottom, set a new line before or after a string whenever come across it.*/
/*just want to reorganized the messy link to set my VPN.*/
/*this version is for Rick, please use txtnewline.c*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

const int SIZE = 40000;

int check_same_word(char *src, char *tar){ 
//判断和目标字符串是否一样
    int idx = 0;
    while (tar[idx] != '\0')
    {
        if (src[idx] != tar[idx])
            return 0;
        idx++;
    }
    return 1;
}

int main(){   
    char name[100];
    printf("filename(txt)?");
    scanf("%s",name);
    strcat(name,".txt");
    getchar();
    /*读取目标字符串*/
    char tar[10];
    printf("your target:");
    scanf("%[^\n]", tar); //自定义输入结束类型（这样就可以输入空格了）//that is dangerous...
    /*是否删除target*/
    int b;
    printf("delete it(1) or not(0)");
    scanf("%d", &b);
    /*读取换行方式*/
    int a;
    if(!b){
        printf("before(1) or after(0)?");
        scanf("%d", &a);
    }
    /*变成长字符串*/
    char line[SIZE]; //数字可调大
    char buf_in[SIZE];
    FILE *fp = fopen(name, "rb");
    while (!feof(fp) && !ferror(fp)){
        fgets(line, sizeof(line), fp); //fgets会覆盖掉原内容//sizeof就直接是40000
        /*1.文本读写与二进制读写*/
        line[strlen(line) - 2] = '\0'; //strlen 显示字符串长度到空结束字符但不包括空结束字符
        strcat(buf_in, line);
        //printf("%s\n", buf_in);
    }
    fclose(fp);
    /*使用buf*/
    FILE *fp2 = fopen("output.txt", "w");
    char buf_out[SIZE];
    int x_in;
    int x_out;
    x_in=x_out=0;
    if(!b){
        if (a)
        {
            /*2.a&&b or a&b*/
            while (buf_in[x_in] != '\0')
            {
                buf_out[x_out] = buf_in[x_in];
                /*判断是否换行*/
                if (check_same_word(buf_in + x_in + 1, tar))
                {
                    buf_out[++x_out] = '\n';
                }
                x_in++;
                x_out++;
            }
        }
        else
        {
            while (buf_in[x_in] != '\0')
            {
                buf_out[x_out] = buf_in[x_in];
                /*判断是否换行*/
                if (check_same_word(buf_in + x_in + 1, tar))
                {
                    int r = 0;
                    while (tar[r++] != '\0')
                    {
                        x_in++;
                        x_out++;
                        buf_out[x_out] = buf_in[x_in];
                    }
                    buf_out[++x_out] = '\n';
                }
                x_in++;
                x_out++;
            }
        }
    }
    else{
        while (buf_in[x_in] != '\0')
        {
            buf_out[x_out] = buf_in[x_in];
            if (check_same_word(buf_in + x_in + 1, tar))
            {
                buf_out[++x_out] = '\n';
                x_in+=strlen(tar);
            }
            x_in++;
            x_out++;
        }
    }
    buf_out[x_out]='\0';
    fputs(buf_out,fp2);
    fclose(fp2);
    return 0;
}

/*
1.
字符串最后的'\r''\n'分别是回车和换行。
在 UNIX/Linux 平台中，用文本方式或二进制方式打开文件没有任何区别。
在 UNIX/Linux 平台中，文本文件以\n（ASCII 码为 0x0a）作为换行符号；而在 Windows 平台中，文本文件以连在一起的\r\n（\r的 ASCII 码是 0x0d）作为换行符号。在 Windows 平台中，如果以文本方式打开文件，当读取文件时，系统会将文件中所有的\r\n转换成一个字符\n，如果文件中有连续的两个字节是 0x0d0a，则系统会丢弃前面的 0x0d 这个字节，只读入 0x0a。当写入文件时，系统会将\n转换成\r\n写入。
也就是说，如果要写入的内容中有字节为 0x0a，则在写人该字节前，系统会自动先写入一个 0x0d。因此，如果用文本方式打开二进制文件进行读写，读写的内容就可能和文件的内容有出入。因此，用二进制方式打开文件总是最保险的。

2.a&&b与a&b的区别
就前者而言，当判断a的结果为false的时候可以直接返回整个表达式的结果为false,而不用继续判断b的结果是true还是false，但对于后者而言，即使判断a的结果为false，但是它仍然会判断b的值是什么，这样效率没有前者高，所以一般使用前者。
*/