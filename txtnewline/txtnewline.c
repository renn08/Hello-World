/*From the left to the right, top to the bottom, set a new line before or after a string whenever come across it.*/
/*just want to reorganized the messy links to set my VPN.*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

const int SIZE = 40000;


int check_same_word(char *src, char *tar)
{
    int idx = 0;
    while (tar[idx] != '\0')
    {
        if (src[idx] != tar[idx])
            return 0;
        idx++;
    }
    return 1;
}


int main()
{   char name[100];
    printf("filename(txt)?");
    scanf("%s",name);
    strcat(name,".txt");
    getchar();

    char tar[10];
    printf("your target:");
    scanf("%[^\n]", tar); 

    int a, b;
    printf("delete it(1) or not(0)?");
    scanf("%d", &b);

    if(!b){
        printf("before(1) or after(0)?");
        scanf("%d", &a);
    }

    char line[SIZE]; 
    char buf_in[SIZE];
    FILE *fp = fopen(name, "rb");
    while (!feof(fp) && !ferror(fp)){
        fgets(line, sizeof(line), fp); 
        line[strlen(line) - 2] = '\0'; 
        strcat(buf_in, line);
    }
    fclose(fp);
    FILE *fp2 = fopen("output.txt", "w");

    char buf_out[SIZE];
    int x_in;
    int x_out;
    x_in=x_out=0;
    if (!b){
        if (a){
            while (buf_in[x_in] != '\0'){
                buf_out[x_out] = buf_in[x_in];
                if (check_same_word(buf_in + x_in + 1, tar)){
                    buf_out[++x_out] = '\n';
                }
                x_in++;
                x_out++;
            }
        }
        else{
            while (buf_in[x_in] != '\0'){
                buf_out[x_out] = buf_in[x_in];
                if (check_same_word(buf_in + x_in + 1, tar)){
                    int r = 0;
                    while (tar[r++] != '\0'){
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
        while (buf_in[x_in] != '\0'){
            buf_out[x_out] = buf_in[x_in];
            if (check_same_word(buf_in + x_in + 1, tar)){
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