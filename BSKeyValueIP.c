#include"BSKeyVlueIp.h"
BSTreeNode* BuyBSNode(BSKeyType key, BSValueType value)//创建一个节点
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
int BSTreeInsert(BSTreeNode**pptree, BSKeyType key, BSValueType value)//插入
{
	BSTreeNode* cur = *pptree;
	BSTreeNode*parent = NULL;
	//空树
	if (*pptree == NULL)
	{
		*pptree = BuyBSNode(key, value);
		return 1;
	}
	//非空树
	while (cur)
	{
		if (strcmp(cur->_key, key) > 0)//根节点的ip长度大于key的ip长度，插入到左边
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (strcmp(cur->_key, key) < 0)//根节点的ip长度小于key的ip长度，插入到右边
		{
			parent = cur;
			cur = cur->_right;
		}
		else//该ip已经存在
		{
			return 0;
		}
	}
	if (strcmp(parent->_key, key)>0)//长度大于父节点
		parent->_right = BuyBSNode(key, value);
	else
		parent->_left = BuyBSNode(key, value);
	return 1;
}
int BSTreeFind(BSTreeNode**pptree, BSKeyType key)//插入
{
	BSTreeNode*cur = *pptree;
	assert(pptree);//排除空树的可能
	while (cur)
	{
		if (strcmp(cur->_key, key) > 0)//key的长度小于根节点，在左边找
		{
			cur=cur->_left;
		}
		else if (strcmp(cur->_key, key) < 0)//key的长度大于根节点，在右边找
		{
			cur = cur->_right;
		}
		else
		{
			return cur;//找到了，返回cur
		}
	}
	return NULL;//没有找到
}

void BSTreeInOrder(BSTreeNode**pptree)//左 根 右
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



