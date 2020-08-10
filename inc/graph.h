#include "link_list.h"
#define MAX_NODES 100
#define MAX_WEIGHT 999
struct GraphWithMatrix
{
    int edge[MAX_NODES][MAX_NODES];
};

void print_graph_matrix(struct GraphWithMatrix *g, int n)
{
    for (int i = 0; i < n; i++)
    {
        printArray(g->edge[i], n);
    }
}
GraphWithMatrix *create_empty_with_matrix(int n)
{
    struct GraphWithMatrix *g = new struct GraphWithMatrix;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                g->edge[i][j] = 0;
            }
            else
            {
                g->edge[j][i] = g->edge[i][j] = MAX_WEIGHT;
            }
        }
    }
    return g;
}

GraphWithMatrix *create_random_graph_with_matrix(int n)
{
    struct GraphWithMatrix *g = new struct GraphWithMatrix;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                g->edge[i][j] = 0;
            }
            else
            {
                g->edge[j][i] = g->edge[i][j] = rand() % 10;
            }
        }
    }
    return g;
}

void add_edge(int a, int b, struct GraphWithMatrix *g)
{
    g->edge[a][b] = 1;
}
void add_doble_edge(int a, int b, struct GraphWithMatrix *g)
{
    g->edge[a][b] = 1;
    g->edge[b][a] = 1;
}
void add_edge(int a, int b, int w, struct GraphWithMatrix *g)
{
    g->edge[a][b] = w;
}