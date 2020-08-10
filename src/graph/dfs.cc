#include "graph.h"
#include <stack>
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
void dfs_1(GraphWithMatrix *g, int n, int start)
{
    int visit[MAX_NODES];
    std::stack<int> s;
    s.push(start);
    while (!s.empty())
    {
        int c = s.top();
        printf("%d ", c);
        visit[c] = 1;
        s.pop();
        for (int i = 0; i < n; i++)
        {
            if (g->edge[c][i] != MAX_WEIGHT && visit[i] == 0)
            {
                s.push(i);
            }
        }
    }
    printf("\n");
}

int visit[MAX_NODES];
void dfs_2(GraphWithMatrix *g, int n, int start)
{
    printf("%d ", start);
    visit[start] = 1;
    for (int i = 0; i < n; i++)
    {
        if (g->edge[start][i] != MAX_WEIGHT && visit[i] == 0)
        {
            dfs_2(g, n, i);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n = 8;
    struct GraphWithMatrix *g = init_graph(n);
    dfs_1(g, n, 0);
    dfs_2(g, n, 2);
    printf("\n");
    return 0;
}
