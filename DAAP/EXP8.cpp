// prim's algorithm
#include "iostream"
#include "bits/stdc++.h"

class Prim {
private:
	int V;
	int **graph;
	int *key;
	int *parent;
	bool *MSTset;
public:
	Prim( int V ) {
		this->V = V;
		graph = new int*[V];
		for (int i = 0; i < V; ++i) {
			graph[i] = new int[V];
		}
		key = new int[V];
		parent = new int[V];
		MSTset = new bool[V];
		for (int i = 0; i < V; ++i) {
			key[i] = INT_MAX;
			MSTset[i] = false;
		}
		key[0] = 0;
		parent[0] = -1;
	}
	int minKey() {
		int min = INT_MAX, min_index;
		for (int i = 0; i < V; ++i)
			if (MSTset[i] == false && key[i] < min)
				min = key[i], min_index = i;
		return min_index;
	}
	void primMST() {
		for (int i = 0; i < V - 1; ++i) {
			int u = minKey();
			MSTset[u] = true;
			for (int j = 0; j < V; ++j)
				if (graph[u][j] && MSTset[j] == false && graph[u][j] < key[j])
					parent[j] = u, key[j] = graph[u][j];
		}
	}
	void display() {
		int total_weight = 0;
		std :: cout << "\n EDGE\tWeight\n";
		for (int i = 1; i < V; ++i) {
			std :: cout << " " << parent[i] << "->" << i << "\t"
						<< graph[i][parent[i]] << std :: endl;
			total_weight += graph[i][parent[i]];
		}
		std :: cout << "\n Total Weight : " << total_weight << std :: endl;
	}
	void input() {
		std :: cout << "Enter The Graph in form of Matrix\n\t";
		for (int i = 0; i < V; ++i) {
			std :: cout <<  i << " ";
		}
		std :: cout << std :: endl;
		for (int i = 0; i < V; ++i) {
			std :: cout << " " << i << "\t";
			for (int j = 0; j < V; ++j) {
				std :: cin >> graph[i][j];
			}
		}
	}
};
int main() {

	int n;
	std :: cout << "Enter the total Number of Vertices : ";
	std :: cin >> n;

	Prim a(n);

	a.input();
	a.primMST();
	a.display();
	
	return 0;
}