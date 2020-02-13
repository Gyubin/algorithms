#include <stdio.h>
#include <malloc.h>

struct node
{
	int val;
	node *pre, *nex;

	node() {}
	node(int n) :val(n) {}
};

struct queue
{
	int size;
	node *head, *tail;

	queue()
	{
		size = 0;
		head = new node();
		tail = new node();
		head->nex = tail;
		tail->pre = head;
	}

	bool empty()
	{
		return size == 0;
	}

	void enqueue(int val)
	{
		node *cur = new node(val);
		cur->pre = tail->pre;  // 뉴노드의 pre를 꼬리의 pre로
		cur->nex = tail;  // 뉴노드의 nex를 꼬리로
		tail->pre->nex = cur;  // 원래 마지막 노드의 다음을 뉴노드로
		tail->pre = cur;  // 꼬리의 pre를 뉴노드로
		size++;
	}

	int pop()
	{
		if (size == 0)
			return 0;
		node *obj = head->nex;
		obj->nex->pre = obj->pre;
		obj->pre->nex = obj->nex;
		size--;
		
		int val = obj->val;
		delete obj;
		return val;
	}

	int front() {
		return head->nex->val;
	}
};

int main()
{
	int n_node = 7;
	int data[] = { 1, 2, 1, 3, 2, 4, 2, 5, 4, 6, 5, 6, 6, 7, 3, 7 };
	bool adjacency_matrix[10][10] = { 0, };
	bool visited[10] = { 0, };

	// Make adjacency matrix
	for (int i = 0; i < sizeof(data) / sizeof(int); i += 2)
	{
		adjacency_matrix[data[i]][data[i + 1]] = true;
		adjacency_matrix[data[i + 1]][data[i]] = true;
	}

	// BFS
	queue q;
	q.enqueue(1);
	visited[1] = true;

	while (!q.empty())
	{
		int cur = q.pop();
		printf("%d ", cur);

		for (int nex = 1; nex <= n_node; nex++)
		{
			// 자기 자신이 아니고, 연결되어있고, 방문하지 않은 노드
			if (nex != cur &&
				adjacency_matrix[cur][nex] &&
				visited[nex] == false)
			{
				q.enqueue(nex);
				visited[nex] = true;
			}
		}
	}
	printf("\n");

	return 0;
}
