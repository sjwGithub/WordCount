#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{
    // argc 表示参数个数, *argv[]指针数组, 每一个指针指向一个字符串
    FILE *fp;
    int cnt = 0; // 统计个数的变量 
    if ((fp=fopen(argv[2], "r")) == NULL) // 如果文件为空则输出错误 
    {
        printf("error!\n");
        return 0;
    }
    if (argv[1][1] == 'w') // 'w'为统计单词
    {
        char s[1024]; // 声明一个字符串数组 
        while (fscanf(fp, "%s", s) != EOF)
        {
            cnt ++; //单词数量 
            for (int i = 1; i < strlen(s) - 1; i ++)
            	// 逗号分隔或空格分隔都进行单词数量加一 
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',')
                {
                	cnt ++;
				}
                else if (s[i] == ' ' && s[i-1] != ',' && s[i+1] != ',')
				{
					cnt ++;
				} 
        }
        printf("单词数：%d\n", cnt);
    }
    else if (argv[1][1] == 'c') // 'c'为统计字符
    {
        char c;
        while ((c = fgetc(fp)) != EOF) // 凡是字符则进行加一 
			cnt ++;
        printf("字符数：%d", cnt);
    }
    fclose(fp);
    return 0;
}

