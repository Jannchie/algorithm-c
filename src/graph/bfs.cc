#include "graph.h"
#include <queue>
struct GraphWithMatrix *init_graph(int n)
{
    struct GraphWithMatrix *g = create_empty_with_matrix(n);
    add_doble_edge(0, 1, g);
    add_doble_edge(0, 2, g);
    add_doble_edge(2, 5, g);
    add_doble_edge(2, 3, g);
    add_doble_edge(3, 4, g);
    add_doble_edge(5, 6, g);
    return g;
}
void bfs(GraphWithMatrix *g, int n)
{
    int visit[MAX_NODES];
    std::queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int c = q.front();
        printf("%d, ", c);
        visit[c] = 1;
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (g->edge[c][i] != MAX_WEIGHT && visit[i] == 0)
            {
                q.push(i);
            }
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int n = 8;
    struct GraphWithMatrix *g = init_graph(n);
    bfs(g, n);
    return 0;
}
