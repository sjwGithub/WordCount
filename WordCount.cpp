#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{
    // argc ��ʾ��������, *argv[]ָ������, ÿһ��ָ��ָ��һ���ַ���
    FILE *fp;
    int cnt = 0; // ͳ�Ƹ����ı��� 
    if ((fp=fopen(argv[2], "r")) == NULL) // ����ļ�Ϊ����������� 
    {
        printf("error!\n");
        return 0;
    }
    if (argv[1][1] == 'w') // 'w'Ϊͳ�Ƶ���
    {
        char s[1024]; // ����һ���ַ������� 
        while (fscanf(fp, "%s", s) != EOF)
        {
            cnt ++; //�������� 
            for (int i = 1; i < strlen(s) - 1; i ++)
            	// ���ŷָ���ո�ָ������е���������һ 
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',')
                {
                	cnt ++;
				}
                else if (s[i] == ' ' && s[i-1] != ',' && s[i+1] != ',')
				{
					cnt ++;
				} 
        }
        printf("������=%d\n", cnt);
    }
    else if (argv[1][1] == 'c') // 'c'Ϊͳ���ַ�
    {
        char c;
        while ((c = fgetc(fp)) != EOF) // �����ַ�����м�һ 
			cnt ++;
        printf("�ַ���=%d", cnt);
    }
    fclose(fp);
    return 0;
}

