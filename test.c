#include"BSKeyVlueIp.h"


int main()
{
	BSTreeNode*ptree = NULL;
	BSTreeNode*node = NULL;
	//��ȡmy.txt�ļ�
	FILE*in = fopen("my.txt", "r");
	char buf[15] = {0};
	int index = 0;
	char ch = 0;
	int flag = 1;
	//�ļ���ʧ��
	if (in == NULL)
	{
		printf("�ļ���ʧ��\n");
		return  -1;
	}
	//���ļ��ַ�����ch���������ݵ����ļ�������ʱֹͣѭ��
	while ((ch = getc(in)) != EOF)
	{
		//һ�����ʽ���
		if (ch == ' ' || ch == ',' || ch == '.' || ch == '\n')
		{
			if (flag == 0)//��ֹ�����ظ�����ĸ�����
				continue;
			flag = 0;
			//����ip�Ƿ����
			node = BSTreeFind(&ptree, buf);
			//����,���ִ�����һ
			if (node != NULL)
			{
				node->_value++;
			}
			else//�����ڣ����Ӹ�IP������һ��
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