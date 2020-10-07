#include <iostream>
#include <climits>

//define V 9

using namespace std;

//menentukan jarak minimal dari node start kepada setiap node
int minDistance (int dist[], bool sptSet[]) 
{
int minIndex;
int minDist = INT_MAX; 	//pada awalnya, semua distance di-set menjadi INT_MAX dari climits
	
	for (int v = 0; v < V; v++) 						//!!!!!!!!!!!! GANTI V DENGAN SESUATU
	{ 
		if (!sptSet[v] && dist[v] <= minDist) 
		{
			minDist = dist[v];
			minIndex = v;
		}
	}
	
	return minIndex;
}

//menampilkan jalur yang diambil oleh algoritma Dijkstra
void printPath(int parent[], int x) 
{
    if (parent[x] == - 1)
    {
		return;
	}
	
    printPath(parent, parent[x]); 
  
    printf("-> %d", x); 
}

void printDijsktra (int dist[], int n, int parent[])
{
int source = 0; 

    printf("Vertex          Distance        Path"); 
    for (int i = 1; i < V; i++) 
    { 
    	printf("\n%d -> %d		%d		%d", 
            	source, i,   dist[i], source); 
        printPath(parent, i); 
    }
}
int main()
{
int i;
int j;
int hubung[99][99];
int vertex;
int edge;
	
	cout << "Input jumlah vertex : "; 
	cin >> vertex;
	cout << "Input jumlah edge   : ";
	cin >> edge;
	cout << endl;
	// menentukan hubungan dan besar edge
	cout << "Masukan besar bobot edge :" << endl;
	for (i = 1; i <= vertex; i++)
	{
		for (j = 1; j <= vertex; ++j)
		{
			cout << "{" << i << " , " << j << "}" << " = ";
			cin >> hubung[i][j]; 
		}
		cout << endl;
	}
	//algoritma Djikstra
	
	return 0;
}

