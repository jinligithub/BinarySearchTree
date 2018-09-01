#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<malloc.h>
typedef char* BSKeyType;
typedef int BSValueType;
typedef struct BSTreeNode
{
	struct BSTreeNode*_left;
	struct BSTreeNode*_right;
	BSKeyType _key;
	BSValueType _value;//���ִ���
}BSTreeNode;
BSTreeNode* BuyBSNode(BSKeyType key, BSValueType value);//����һ���ڵ�
int BSTreeInsert(BSTreeNode**pptree, BSKeyType key, BSValueType value);//����
int BSTreeRemove(BSTreeNode**pptree, BSKeyType key);//ɾ��
int BSTreeFind(BSTreeNode**pptree, BSKeyType key);//����
void BSTreeInOrder(BSTreeNode**pptree);//�������









