//Lab 7:Task 1:Dijkstra's Algorithm

#include <iostream>
#include <string>
#include <climits>
using namespace std;

// EdgeNode: Linked List node used in adjacency list 
// represents one edge from current vertex to one neighbour vertex
struct EdgeNode {
    int v;          // index of neighbour vertex
    int w;          // cost of the edge
    EdgeNode* next; // pointer to next edge 
};

// PQNode: Linked List node used as priority queue
// stores one (distance,vertex) pair
// queue sorted by smallest distance
struct PQNode {
    int dist;       // current shortest known distance
    int node;       // vertex index
    PQNode* next;   // pointer to the next queue node
};

//array that stores label of each vertex
string* label;

// indexOf: convert a vertex label into its corresponding index
int indexOf(const string& name, int V) {
    for (int i = 0; i < V; i++)
        if (label[i] == name)
            return i;
    return -1; // not found
}

// pqPush: insert a new node into the priority queue
// sorted insert so smallest distance is always at the head
void pqPush(PQNode*& head, int dist, int node) {
    PQNode* n = new PQNode{dist, node, nullptr};
    if (!head || dist < head->dist) {   // check if queue is empty 
        n->next = head;                 // or the new distance is smallest 
        head = n;                       // then insert at head
        return;
    }
    PQNode* cur = head;
    while (cur->next && cur->next->dist <= dist)  // trasverse until correct sorted position is found
        cur = cur->next;
    //insert new node into linked list(ascending order of distance)
    n->next = cur->next;               
    cur->next = n;
}

// pqPop: remove and return the queue node with smallest distance(head)
PQNode pqPop(PQNode*& head) {
    PQNode top = *head;   // copy dist+node out
    PQNode* tmp = head;
    head = head->next;    // move head forward
    delete tmp;           // remove old head
    return top;
}

// addEdge: covert vertex label into integer index before storing in adjacency list
void addEdge(EdgeNode* adj[], int V, const string& uName, const string& vName, int w) {
    int u = indexOf(uName, V);   
    int v = indexOf(vName, V);   
    adj[u] = new EdgeNode{v, w, adj[u]}; // head insertion into vertex u's adjacency list
    adj[v] = new EdgeNode{u, w, adj[v]}; // insert the reverse edge beacuse graph is undirected
}

// Dijkstra's Algorithm: Find shortest distance from the source vertex
// to every other vertex using a priority queue
int* dijkstra(EdgeNode* adj[], int V, int src) {
    PQNode* pq = nullptr;

    int* dist = new int[V];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;  //  Initialize every vertex as unreachable

    dist[src] = 0;          //  Distance from the source to itself is always zero.
    pqPush(pq, 0, src);     //  Insert the source vertex into the priority queue.

    while (pq != nullptr) {
        PQNode top = pqPop(pq);
        int d = top.dist;
        int u = top.node;

        if (d > dist[u])    // ignore outdated entries
            continue; 

        // Traverse every neighbour of the current vertex.
        for (EdgeNode* p = adj[u]; p != nullptr; p = p->next) {
            int v = p->v;
            int w = p->w;

            //Relaxation:check whether going through vertex u produces
            //shorter path to vertex v
            if (dist[u] + w < dist[v]) {     
                dist[v] = dist[u] + w;    // Update the shortest distance to vertex v
                pqPush(pq, dist[v], v);   // Insert the updated distance into the priority queue 
            }
        }
    }

    return dist;
}

int main() {
    int V = 5;

    // define the letters for each index 
    label = new string[V];
    label[0] = "A";
    label[1] = "B";
    label[2] = "C";
    label[3] = "D";
    label[4] = "E";

    // Create an adjacency list
    // Each array index represents one vertex
    EdgeNode* adj[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};

    // build weighted undirected graph
    addEdge(adj, V, "A", "B", 4);
    addEdge(adj, V, "A", "C", 8);
    addEdge(adj, V, "B", "E", 6);
    addEdge(adj, V, "B", "C", 3);
    addEdge(adj, V, "C", "D", 2);
    addEdge(adj, V, "D", "E", 10);

     // Convert the source vertex label into its index.
    string srcName = "A";
    int src = indexOf(srcName, V);

    // Compute the shortest distance from the source to every other vertex.
    int* result = dijkstra(adj, V, src);

    for (int i = 0; i < V; i++)
        cout << label[i] << " -> " << result[i] << "\n";

    delete[] result;
    delete[] label;
    return 0;
}