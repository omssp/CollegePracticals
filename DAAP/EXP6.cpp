#include "iostream"
#include "list"

class Graph {
private:
	int vn;
	std :: list<int> *adj;
public:
	Graph(int vn) {
		this->vn = vn;
		adj = new std :: list<int>[vn];
	}
	void addEdge( int v, int w ) {
		adj[v].push_back(w);
	}
	void BFS( int source ) {
		bool *visited = new bool[vn];
		for ( int i = 0; i < vn; i++ )
			visited[i] = false;
		
		std :: list<int> queue;

		visited[source] = true;
		queue.push_back(source);

		std :: list<int> :: iterator i;

		std :: cout << "\n BFS : [ ";

		while (!queue.empty()) {
			source = queue.front();
			std :: cout << source << ", ";
			queue.pop_front();
			for ( i = adj[source].begin(); i != adj[source].end(); ++i ) {
				if ( !visited[*i] ) {
					visited[*i] = true;
					queue.push_back(*i);
				}
			}
		}
		std :: cout << "\b\b ]";
	}

	void DFSUtil(int source, bool visited[]) {
		visited[source] = true;
		std :: cout << source << ", ";

		std :: list<int>::iterator i;
		for ( i = adj[source].begin(); i != adj[source].end(); ++i ) {
			if ( !visited[*i] )
				DFSUtil(*i, visited);
		}
	}

	void DFS( int source ) {
		bool *visited = new bool[vn];
		for (int i = 0; i < vn; ++i) {
			visited[i] = false;
		}
		std :: cout << "\n\n DFS : [ ";
		DFSUtil(source, visited);
		std :: cout << "\b\b ]";
	}

	void input() {
		int n;
		std :: cout << "\nEnter the total number of Edges : ";
		std :: cin >> n;
		for (int i = 0; i < n; ++i) {
			int s, d;
			std :: cout << "Enter Edge " << (i + 1) << " [S D] : ";
			std :: cin >> s >> d;
			addEdge(s, d);
		}
	}

	/*void input() {
		std :: cout << "\nEnter the Edges\n\n";
		for (int i = 0; i < vn; ++i) {
			for (int j = 0; j < vn; ++j) {
				char ch;
				std :: cout << " Edge [" << i << ", " << j << "] Present(y/n)? ";
				std :: cin >> ch;
				if ( ch == 'y' || ch == 'Y' )
					addEdge(i, j);
			}
		}
	}*/
};
int main() {
	int n;
	std :: cout << "Enter the number of verices : ";
	std :: cin >> n;

	Graph a(n);
	a.input();

	std :: cout << "\nEnter the source vertex number : ";
	std :: cin >> n;

	a.BFS(n);
	a.DFS(n);

	return 0;
}