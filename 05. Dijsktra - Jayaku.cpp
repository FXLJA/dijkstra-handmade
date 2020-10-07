#include <stdio.h>
#include <limits.h>

#define V 9

int minDistance (int dist[], bool sptSet[]) 
{
	int minIndex;
	int minDist = INT_MAX; 
	
	for (int v=0; v<V; v++) 
	{
		if (!sptSet[v] && dist[v] <= minDist) 
		{
			minDist = dist[v];
			minIndex = v;
		}
	}
	return minIndex;
}

void printPath(int parent[], int x) 
{ 
      
    if (parent[x] == - 1) 
        return; 
  
    printPath(parent, parent[x]); 
  
    printf("->%d", x); 
}

void printDijsktra (int dist[], int n, int parent[])
{
	int source = 0; 
    printf("Vertex          Distance      Path"); 
    for (int i = 1; i < V; i++) 
    { 
    printf("\n%d -> %d           %d             %d", 
                      source, i, dist[i], source); 
        printPath(parent, i); 
    }
}

void dijsktra (int graph[V][V], int source) 
{
	int dist[V];
	
	bool sptSet[V];
	
	int parent[V];
	
	for (int i=0; i<V; i++) 
	{
		parent[i] = -1;
		dist[i] = INT_MAX; //set to Infinity
		sptSet[i] = false;
	}
	
	dist[source] = 0;
	
	for (int i=0; i<V-1; i++) 
	{
		int vertex = minDistance(dist,sptSet);
		
		sptSet[vertex] = true;
		
		for (int v=0; v<V; v++)
		{
			if (!sptSet[v] && graph[vertex][v] && dist[vertex] != INT_MAX 
				&& dist[vertex] + graph[vertex][v] < dist[v])
			{
				parent[v] = vertex;
				dist[v] = dist[vertex] + graph[vertex][v];
			}
		}
	}
	printDijsktra(dist,V,parent);
}

int main ()
{
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     };
	
	dijsktra(graph, 0);
	return 0;
}
