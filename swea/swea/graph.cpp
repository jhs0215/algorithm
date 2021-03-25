#include <stdio.h>

#define MAX_DATA 101

struct tagGraphNode
{
	int value;
	tagGraphNode* graphNode = nullptr;
};

struct tagGraph
{
	tagGraphNode* head = nullptr;
	tagGraphNode* tail = nullptr;
};

int ngraph = 0;
tagGraph graph[MAX_DATA];

tagGraphNode* create(int v)
{
	tagGraphNode* newNode = new tagGraphNode;

	newNode->value = v;
	newNode->graphNode = nullptr;

	return newNode;
}

void insertEdge(int e1, int e2)
{
	tagGraphNode* n1 = create(e1);
	tagGraphNode* n2 = create(e2);

	if (graph[e1].head == nullptr)
	{
		graph[e1].head = graph[e1].tail = n2;
	}
	else
	{
		graph[e1].tail->graphNode = n2;
		graph[e1].tail = n2;
	}

	if (graph[e2].head == nullptr)
	{
		graph[e2].head = graph[e2].tail = n1;
	}
	else
	{
		graph[e2].tail->graphNode = n1;
		graph[e2].tail = n1;
	}
}

void destroy()
{
	for (int i = 1; i <= ngraph; ++i)
	{
		tagGraphNode* node = graph[i].head;

		while (node != nullptr)
		{
			tagGraphNode* tmp = node;
			node = node->graphNode;

			delete tmp;
		}
	}
}

int main()
{
	return 0;
}