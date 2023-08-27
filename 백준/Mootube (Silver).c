#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p, q, r;
} Connection;

typedef struct {
    int k, v;
} Query;

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

// Compare function for sorting connections by decreasing r value
int compare_connections(const void *a, const void *b) {
    return ((Connection *)b)->r - ((Connection *)a)->r;
}

// Function to find the root of a node (with path compression)
int find_root(int parent[], int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = find_root(parent, parent[node]);
}

// Function to perform union of two nodes
void union_nodes(int parent[], int size[], int a, int b) {
    a = find_root(parent, a);
    b = find_root(parent, b);
    if (a != b) {
        if (size[a] < size[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    Connection connections[N - 1];
    for (int i = 0; i < N - 1; ++i) {
        scanf("%d %d %d", &connections[i].p, &connections[i].q, &connections[i].r);
    }

    // Sort connections by decreasing r value
    qsort(connections, N - 1, sizeof(Connection), compare_connections);

    Query queries[Q];
    for (int i = 0; i < Q; ++i) {
        scanf("%d %d", &queries[i].k, &queries[i].v);
    }

    int parent[N + 1];
    int size[N + 1];
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        size[i] = 1;
    }

    int result[Q];
    int connection_index = 0;

    for (int i = 0; i < Q; ++i) {
        while (connection_index < N - 1 && connections[connection_index].r >= queries[i].k) {
            union_nodes(parent, size, connections[connection_index].p, connections[connection_index].q);
            ++connection_index;
        }
        int root = find_root(parent, queries[i].v);
        result[i] = size[root] - 1;  // Excluding the query vertex itself
    }

    for (int i = 0; i < Q; ++i) {
        printf("%d\n", result[i]);
    }

    return 0;
}
