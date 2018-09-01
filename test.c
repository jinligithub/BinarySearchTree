#include"BSKeyVlueIp.h"


int main()
{
	BSTreeNode*ptree = NULL;
	BSTreeNode*node = NULL;
	//读取my.txt文件
	FILE*in = fopen("my.txt", "r");
	char buf[15] = {0};
	int index = 0;
	char ch = 0;
	int flag = 1;
	//文件打开失败
	if (in == NULL)
	{
		printf("文件打开失败\n");
		return  -1;
	}
	//将文件字符读入ch，读入内容等于文件结束符时停止循环
	while ((ch = getc(in)) != EOF)
	{
		//一个单词结束
		if (ch == ' ' || ch == ',' || ch == '.' || ch == '\n')
		{
			if (flag == 0)//防止遇到重复非字母的情况
				continue;
			flag = 0;
			//查找ip是否存在
			node = BSTreeFind(&ptree, buf);
			//存在,出现次数加一
			if (node != NULL)
			{
				node->_value++;
			}
			else//不存在，增加该IP，出现一次
			{
				BSTreeInsert(&ptree,buf,1);
			}
			memset(buf, 0, 15);
			index = 0;
		}
		else
		{
			flag = 1;
			buf[index++] = ch;
		}
	}
	BSTreeInOrder(&ptree);
    system("pause");
	return 0;
}