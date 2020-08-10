#include "graph.h"
#include <queue>
#include <stack>
using namespace std;

struct GraphWithMatrix *init_graph(int n)
{
    struct GraphWithMatrix *g = create_empty_with_matrix(n);
    add_edge(7, 1, g);
    add_edge(0, 1, g);
    add_edge(0, 2, g);
    add_edge(2, 4, g);
    add_edge(4, 6, g);
    add_edge(3, 5, g);
    add_edge(1, 3, g);
    add_edge(1, 4, g);
    add_edge(6, 3, g);
    return g;
}
void dfs(struct GraphWithMatrix *g, int n, int start, int *v)
{
    if (v[start])
    {
        return;
    }
    v[start] = true;
    for (int i = 0; i < n; i++)
    {
        if (g->edge[start][i] == 1)
        {
            dfs(g, n, i, v);
        }
    }
    printf("%d\n", start);
}
void top_sort_with_dfs(struct GraphWithMatrix *g, int n)
{
    int *v = (int *)malloc(sizeof(int) * n);
    std::stack<int> s;
    std::stack<int> o;
    for (int i = 0; i < n; i++)
    {
        if (!v[i])
        {
            dfs(g, n, i, v);
        }
    }
}
void top_sort(struct GraphWithMatrix *g, int n)
{
    std::queue<int> q;
    int *indgree = (int *)malloc(sizeof(int) * n);
    // indgree calculate
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g->edge[j][i] == 1)
            {
                indgree[i] += 1;
            }
        }
        if (indgree[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (!q.empty())
    {
        int i = q.front();
        printf("%d ", i);
        q.pop();
        count++;
        for (int j = 0; j < n; j++)
        {
            if (g->edge[i][j] == 1)
            {
                indgree[j] -= 1;
                if (indgree[j] == 0)
                {
                    q.push(j);
                }
            }
        }
    }
    if (count == n)
        printf("succeed!\n");
    else
        printf("failed!\n");
}

int main(int argc, char const *argv[])
{
    int n = 8;
    top_sort(init_graph(n), n);
    top_sort_with_dfs(init_graph(n), n);
    printf("\n");
    return 0;
}
