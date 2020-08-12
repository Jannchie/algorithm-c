using namespace std;
#define INF 9999
#include "util.h"
const int n = 6;
int g[n][n];

int add_edge(int from, int to, int w)
{
    g[from][to] = w;
    g[to][from] = w;
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

// 負の重みはないのグラフ
// 時間計算量は　O(|V|^2),優先度付きキューを利用して、O(|V|log|V|)の時間計算量になることができる。
void dijkstra(int start)
{
    int d[n];
    int v[n];
    int p[n];
    // O(n)
    for (int i = 0; i < n; i++)
    {
        d[i] = INF;
        v[i] = 0;
        p[i] = start;
    }
    int c = start;
    d[start] = 0;
    // O(n)
    for (int a = 0; a < n; a++)
    {
        v[c] = 1;
        // Release
        // 邻接矩阵： O(n) (邻接表： O(E))
        for (int i = 0; i < n; i++)
        {
            if (d[c] + g[c][i] < d[i])
            {
                d[i] = d[c] + g[c][i];
                p[i] = c;
            }
        }
        // O(n)
        // Find min
        int min = INF;
        for (int i = 0; i < n; i++)
        {

            if (v[i] == 0 && d[i] < min)
            {
                c = i;
                min = d[i];
            }
        }
    }
    printArray(d, n);
    printArray(v, n);
    printArray(p, n);
    for (int i = 1; i < n; i++)
    {
        int c = i;
        do
        {
            printf("%d < ", c);
            c = p[c];
        } while (c != start);
        printf("0 \n");
    }
}

int main()
{
    init(g);
    dijkstra(0);
    return 0;
}