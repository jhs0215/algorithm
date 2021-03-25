#include <stdio.h>

#define MAX_DATA 100

struct tagLinkedListNode
{
	int value = 0;
	tagLinkedListNode* prev;
	tagLinkedListNode* next;
};

struct tagLinkedList
{
	int use = 0;
	tagLinkedListNode list;
};

tagLinkedList linkedList[MAX_DATA] = {0};
tagLinkedListNode* root = nullptr;

tagLinkedListNode* create(int v)
{
	tagLinkedListNode* newNode = nullptr;

	for (int i = 0; i < MAX_DATA; ++i)
	{
		if (!linkedList[i].use)
		{
			linkedList[i].use = true;
			newNode = &linkedList[i].list;
			break;
		}
	}

	newNode->value = v;
	newNode->prev = newNode->next = newNode;

	return newNode;
}

void destroy(tagLinkedListNode* node)
{
	tagLinkedList* destroyList = (tagLinkedList*)((int*)node - 1);
	destroyList->use = false;
}

void insert(int v)
{
	tagLinkedListNode* node = create(v);

	if (root == nullptr)
	{
		root = node;
	}
	else
	{
		tagLinkedListNode* tail = node->prev;

		node->next = root;
		node->prev = tail;
		tail->next = node;
		root->prev = node;
	}
}

void erase(tagLinkedListNode* node)
{
	tagLinkedListNode* prev = node->prev;
	tagLinkedListNode* next = node->next;
	
	if (next == node)
	{
		root = nullptr;

		destroy(node);
	}
	else
	{
		prev->next = next;
		next->prev = prev;

		if (node == root)
		{
			root = next;
		}

		destroy(node);
	}
}


int main()
{
	return 0;
}