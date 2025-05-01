//BFS
#include<bits/stdc++.h>
#include <omp.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj,int s){
	int v=adj.size();
	vector<int> res;
	queue <int> q;
	vector<bool> visited(v,false);
	#pragma omp parallel
	
	{
	
	visited[s]=true;
	q.push(s);
	#pragma omp parallel
	while(!q.empty()){
		int curr=q.front();
		q.pop();
		res.push_back(curr);
		#pragma omp for
		for(int x: adj[curr]){
			if(visited[x]==false){
				visited[x]=true;
				q.push(x);
			}
		}
	}
}
	return res;
}
int main(){
	vector<vector<int>> adj={{2,3,1},{0},{0,4},{0},{2}};
	int src=0;
	vector<int> ans=bfs(adj,src);
	for(auto i:ans){
		cout<<i<<" ";
	}
	return 0;
}




//BFS 2

#include <iostream>
#include <vector>
#include <omp.h>

#define MAX_NODES 100
#define MAX_QUEUE 100

struct Node {
    std::vector<int> next;
    int neighbours;
};

Node nodes[MAX_NODES];
bool visited[MAX_NODES];
int level[MAX_NODES];
int q[2][MAX_QUEUE];    // Double-buffered queue
int l[2];               // Queue lengths
int start = 0;
int current_queue;

// Build a sample graph
void build_sample_graph() {
    // Graph:
    // 0 -- 1 -- 2
    // |    |
    // 3    4
    //      |
    //      5

    nodes[0].next = {1, 3};
    nodes[1].next = {0, 2, 4};
    nodes[2].next = {1};
    nodes[3].next = {0};
    nodes[4].next = {1, 5};
    nodes[5].next = {4};

    for (int i = 0; i < 6; i++) {
        nodes[i].neighbours = nodes[i].next.size();
    }
}

void parallel_bfs() {
    visited[start] = true;
    level[start] = 0;
    q[0][0] = start;
    l[0] = 1;
    current_queue = 0;

    while (1) {
        int next_queue = (current_queue + 1) % 2;
        l[next_queue] = 0;

        omp_set_dynamic(0);
        int current_node;

        #pragma omp parallel private(current_node)
        {
            #pragma omp for
            for (int i = 0; i < l[current_queue]; i++) {
                current_node = q[current_queue][i];
                for (int j = 0; j < nodes[current_node].neighbours; j++) {
                    if (!visited[nodes[current_node].next[j]]) {
                        visited[nodes[current_node].next[j]] = true;
                        level[nodes[current_node].next[j]] = level[current_node] + 1;

                        #pragma omp critical
                        {
                            q[next_queue][l[next_queue]++] = nodes[current_node].next[j];
                        }
                    }
                }
            }
        }

        if (l[next_queue] == 0)
            break;
        else
            current_queue = next_queue;
    }
}

int main() {
    build_sample_graph();

    // Initialize visited and level
    for (int i = 0; i < MAX_NODES; i++) {
        visited[i] = false;
        level[i] = -1;
    }

    parallel_bfs();

    std::cout << "BFS Levels from node " << start << ":\n";
    for (int i = 0; i < 6; i++) {
        std::cout << "Node " << i << ": Level " << level[i] << "\n";
    }

    return 0;
}


//MATRIX

#include <iostream>
#include <omp.h>
using namespace std;

#define N 3  // Matrix size (3x3)

int main() {
    int A[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[N][N] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int C[N][N] = {0};  // Result matrix

    // Parallel matrix multiplication
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {           // Rows of A
        for (int j = 0; j < N; j++) {       // Columns of B
            for (int k = 0; k < N; k++) {   // Dot product
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print result matrix
    cout << "Result matrix C = A * B:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


//DIJKSTRA

// Compile with: g++ -fopenmp dijkstra_parallel.cpp -o dijkstra_parallel

#include <iostream>
#include <climits>
#include <omp.h>
using namespace std;

#define V 6  // Number of vertices

// Find the vertex with minimum distance not yet processed
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index = -1;

    #pragma omp parallel for
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            #pragma omp critical
            {
                if (dist[v] < min) {
                    min = dist[v];
                    min_index = v;
                }
            }
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];       // Shortest distances
    bool visited[V];   // True if vertex is finalized

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        // Update distances in parallel
        #pragma omp parallel for
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    cout << "Vertex \t Distance from Source " << src << "\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t " << dist[i] << "\n";
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    dijkstra(graph, 0);

    return 0;
}


//HISTOGRAM
#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h>

void histogram_sort_parallel(std::vector<int>& data, int num_bins) {
    int n = data.size();
    int max_val = *std::max_element(data.begin(), data.end());
    int min_val = *std::min_element(data.begin(), data.end());

    int range = max_val - min_val + 1;
    int bin_size = (range + num_bins - 1) / num_bins;

    // Create bins
    std::vector<std::vector<int>> bins(num_bins);

    // Step 1: Assign elements to bins in parallel
    #pragma omp parallel
    {
        std::vector<std::vector<int>> local_bins(num_bins);

        #pragma omp for nowait
        for (int i = 0; i < n; ++i) {
            int bin_index = (data[i] - min_val) / bin_size;
            local_bins[bin_index].push_back(data[i]);
        }

        // Merge local bins into global bins
        #pragma omp critical
        {
            for (int i = 0; i < num_bins; ++i) {
                bins[i].insert(bins[i].end(), local_bins[i].begin(), local_bins[i].end());
            }
        }
    }

    // Step 2: Sort each bin in parallel
    #pragma omp parallel for
    for (int i = 0; i < num_bins; ++i) {
        std::sort(bins[i].begin(), bins[i].end());
    }

    // Step 3: Merge sorted bins into original array
    int index = 0;
    for (int i = 0; i < num_bins; ++i) {
        for (int val : bins[i]) {
            data[index++] = val;
        }
    }
}

int main() {
    std::vector<int> data = {35, 12, 43, 8, 51, 27, 3, 66, 23, 18};

    std::cout << "Original: ";
    for (int num : data) std::cout << num << " ";
    std::cout << "\n";

    int num_bins = 4; // Can be set based on data or thread count
    histogram_sort_parallel(data, num_bins);

    std::cout << "Sorted:   ";
    for (int num : data) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
