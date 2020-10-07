#include <iostream>

#define V 7
#define INF 999

using namespace std;

// Cost matrix of the graph
int costMat[V][V] = {
					   {0, 3, 6, INF, INF, INF, INF},
					   {3, 0, 2, 1, INF, INF, INF},
					   {6, 2, 0, 1, 4, 2, INF},
					   {INF, 1, 1, 0, 2, INF, 4},
					   {INF, INF, 4, 2, 0, 2, 1},
					   {INF, INF, 2, INF, 2, 0, 1},
					   {INF, INF, INF, 4, 1, 1, 0}
					};

int minimum(int *status, int *dis, int n) 
{
int i;
int min;
int index;
	
	min = INF;
	
	for (i = 0; i < n; i++)
	{
		if (dis[i] < min && status[i] == 1) 
		{
			min = dis[i];
			index = i;
		}		
	}
	
	if (status[index] == 1)
	{
		return index; 		//minimum unconsidered vertex distance
	}
		else
		{
			return -1;    	//when all vertices considered
		}
}

void dijkstra(int n, int *dist,int *next, int s) 
{
int status[V];	//
int u;			//Sebagai parameter for
int v;			//----------------------

	//initialization
	for (u = 0; u < n; u++) 
	{
	  status[u] = 1;               //Vertex yang belum dilewati
	  dist[u] = costMat[u][s];     //Jarak dari vertex 
	  next[u] = s;				   //
	}
	
	//for source vertex
	status[s] = 2; dist[s] = 0; next[s] = -1; 			//-1 for starting vertex
	
	while ((u = minimum(status, dist, n)) > -1) 
	{ //open while
	  status[u] = 2;									//now considered
	  
	  for (v = 0; v < n; v++)
	  { //open for 
	     if (status[v] == 1)
	     { //open if 1
	        if (dist[v] > dist[u] + costMat[u][v]) 
			{ // open if 2
	           dist[v] = dist[u] + costMat[u][v];   	//update distance
	           next[v] = u;
	        } //close if 2	     	
		 } //close if 1
	  } //close for
	} //close while
}

int main() 
{
int dis[V];
int next[V];
int i;
int start = 0;

   dijkstra(V, dis, next, start);

   for (i = 0; i < V; i++)
   {
      if (i != start)
      {
        cout << start << " to " << i <<", Using: " << next[i] << ", Cost:  " << dis[i] << endl;      	
	  }
   }
}
