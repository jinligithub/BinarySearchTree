#include"BSKeyVlueIp.h"
BSTreeNode* BuyBSNode(BSKeyType key, BSValueType value)//����һ���ڵ�
{
	BSTreeNode*node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	if (node == NULL)
	{
		perror("use malloc for node");
		exit(EXIT_FAILURE);
	}
	node->_key = key;
	node->_value = value;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}
int BSTreeInsert(BSTreeNode**pptree, BSKeyType key, BSValueType value)//����
{
	BSTreeNode* cur = *pptree;
	BSTreeNode*parent = NULL;
	//����
	if (*pptree == NULL)
	{
		*pptree = BuyBSNode(key, value);
		return 1;
	}
	//�ǿ���
	while (cur)
	{
		if (strcmp(cur->_key, key) > 0)//���ڵ��ip���ȴ���key��ip���ȣ����뵽���
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (strcmp(cur->_key, key) < 0)//���ڵ��ip����С��key��ip���ȣ����뵽�ұ�
		{
			parent = cur;
			cur = cur->_right;
		}
		else//��ip�Ѿ�����
		{
			return 0;
		}
	}
	if (strcmp(parent->_key, key)>0)//���ȴ��ڸ��ڵ�
		parent->_right = BuyBSNode(key, value);
	else
		parent->_left = BuyBSNode(key, value);
	return 1;
}
int BSTreeFind(BSTreeNode**pptree, BSKeyType key)//����
{
	BSTreeNode*cur = *pptree;
	assert(pptree);//�ų������Ŀ���
	while (cur)
	{
		if (strcmp(cur->_key, key) > 0)//key�ĳ���С�ڸ��ڵ㣬�������
		{
			cur=cur->_left;
		}
		else if (strcmp(cur->_key, key) < 0)//key�ĳ��ȴ��ڸ��ڵ㣬���ұ���
		{
			cur = cur->_right;
		}
		else
		{
			return cur;//�ҵ��ˣ�����cur
		}
	}
	return NULL;//û���ҵ�
}

void BSTreeInOrder(BSTreeNode**pptree)//�� �� ��
{
	if ((*pptree) == NULL)
	{
		return;
	}
	if ((*pptree)->_left != NULL)
		BSTreeInOrder(&(*pptree)->_left);
	printf("%s: %d ", (*pptree)->_key, (*pptree)->_value);
	if ((*pptree)->_right != NULL)
		BSTreeInOrder(&(*pptree)->_right);
}



