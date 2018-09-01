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
	BSValueType _value;//出现次数
}BSTreeNode;
BSTreeNode* BuyBSNode(BSKeyType key, BSValueType value);//创建一个节点
int BSTreeInsert(BSTreeNode**pptree, BSKeyType key, BSValueType value);//插入
int BSTreeRemove(BSTreeNode**pptree, BSKeyType key);//删除
int BSTreeFind(BSTreeNode**pptree, BSKeyType key);//插入
void BSTreeInOrder(BSTreeNode**pptree);//中序遍历









