

#include <limits.h>
#include <stdio.h>

#define V 4

int minD(int dist[], short sptSet[])
{
	int min = INT_MAX, min_index;

	for (int i = 0; i < V; i++)
		if (sptSet[i] == 0 && dist[i] <= min)
			min = dist[i], min_index = i;

	return min_index;
}


void printy(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}


void dijkstra(int graph[V][V], int src)
{
	int dist[V]; 
	short sptSet[V]; 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = 0;

	dist[src] = 0;
	for (int count = 0; count < V - 1; count++) {

		int u = minD(dist, sptSet);

		sptSet[u] = 1;

		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	printy(dist);
}

int main()
{

	int g[V][V] =       {
						{ 4, 1, 8, 0 },
						{ 0, 8, 0, 6},
						{ 3, 0, 14, 0},
						{ 0, 0, 0, 9}
					 };

	dijkstra(g, 0);

	return 0;
}
