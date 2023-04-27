

#include <stdio.h>
#include <stdlib.h>

int comparator(const void* p1, const void* p2)
{
	const int(*x)[3] = p1;
	const int(*y)[3] = p2;

	return (*x)[2] - (*y)[2];
}

void makeSet(int parent[], int imp[], int n)
{
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		imp[i] = 0;
	}
}

int findParent(int parent[], int component)
{
	if (parent[component] == component)
		return component;

	return parent[component]
		= findParent(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int imp[], int n)
{
	u = findParent(parent, u);
	v = findParent(parent, v);

	if (imp[u] < imp[v]) {
		parent[u] = v;
	}
	else if (imp[u] > imp[v]) {
		parent[v] = u;
	}
	else {
		parent[v] = u;
		imp[u]++;
	}
}

void KA(int n, int edge[n][3])
{
	qsort(edge, n, sizeof(edge[0]), comparator);

	int parent[n];
	int imp[n];
	makeSet(parent, imp, n);

	int minCost = 0;

	printf(
		"MST Edges\n");
	for (int i = 0; i < n; i++) {
		int v1 = findParent(parent, edge[i][0]);
		int v2 = findParent(parent, edge[i][1]);
		int wt = edge[i][2];

		if (v1 != v2) {
			unionSet(v1, v2, parent, imp, n);
			minCost += wt;
			printf("%d -%d => %d\n", edge[i][0],
				edge[i][1], wt);
		}
	}

	printf("MST Cost: %d\n", minCost);
}
int main()
{
	int e[5][3] = { { 0, 1, 10 },
					{ 0, 2, 6 },
					{ 0, 3, 5 },
					{ 1, 3, 15 },
					{ 2, 3, 4 } };

	KA(5, e);

	return 0;
}
