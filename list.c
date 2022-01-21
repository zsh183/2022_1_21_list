#include "stdio.h"
#include "stdlib.h"


//链表排序

typedef struct _listnode{
	int value;
	struct _listnode *next;
}listnode;

//创建一个链表---链表头

void CreateListHead(listnode **listhead)
{
	*listhead = (listnode *)malloc(sizeof(listnode));
}

//创建一个新结点---插入到链表  头插法  尾插法
void CreateNewNode(listnode **newnode)
{
	*newnode = (listnode *)malloc(sizeof(listnode));
}

int main(int argc,char **argv)
{
	listnode *ListHead;//用头节点代表一个链表
	CreateListHead(&ListHead);

	//创建一个新节点  通过尾插法 插入链表
	listnode *NewNode;
    CreateNewNode(&NewNode);
	ListHead->next = NewNode;
	ListHead->value = 9;
	
	NewNode->next = NULL;//尾节点

	//新建一个节点 插入到头节点后面
	listnode *NewNode1;

	CreateNewNode(&NewNode1);
	
	ListHead->next = NewNode1;
	NewNode1->next = NewNode;
	
}


//链表排序   冒泡法

void listSort(listnode **HeadList)
{
	listnode *cur;
	listnode *tail;
	
	
	cur = *HeadList;
	tail = NULL;

	if(*HeadList == NULL)
	return;

	while(cur != tail)
	{
		while(cur->next != NULL)
		{
			if(cur->value > cur->next->value)
			{
				int temp = cur->value;
				cur->value = cur->next->value;
				cur->next->value = temp;
			}
	
			cur = cur->next;
		}
		tail = cur;
		cur = *HeadList;

	}
}
