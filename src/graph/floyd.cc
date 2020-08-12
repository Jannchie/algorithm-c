using namespace std;
#define INF 9
#include "util.h"
const int n = 6;
int g[n][n];

int add_edge(int from, int to, int w)
{
    g[from][to] = w;
}

int init(int g[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][j] = i == j ? 0 : INF;
        }
    }
    add_edge(0, 1, 1);
    add_edge(0, 2, 3);
    add_edge(1, 3, 1);
    add_edge(2, 3, 2);
    add_edge(3, 5, 6);
    add_edge(2, 4, 1);
    add_edge(4, 5, 1);
    add_edge(1, 5, 1);
}

//　動的計画法によって、三つのループを利用して。
void floyd()
{
    int d[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d[i][j] = g[i][j];
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    for (int k = 0; k < n; k++)
        printArray(d[k], n);
}

int main()
{
    init(g);
    floyd();
    return 0;
}