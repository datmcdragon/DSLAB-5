#include <iostream>
using namespace std;
#define V 6 // заміна v на 6
bool isitsafetocolourVwiththisC(bool graph[V][V], int v, int c, int color[V]) //є безпечним кольором V з цимC
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && (c == color[i]))
            return false;
    }
    return true;
}

bool graphColoring(bool graph[V][V], int m, int v, int color[V])// забарвлення графіка
{
    if (v == V)
        return true;

    for (int i = 1; i <= m; i++) {
        if (isitsafetocolourVwiththisC(graph, v, i, color))
        {
            color[v] = i;
            if (graphColoring(graph, m, v + 1, color))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

void printcolours(int color[V])// вивід кольорів
{
    for (int i = 0; i < V; i++)
        cout << color[i] << " ";
}

int main()
{
    bool graph[V][V] = { {0, 1, 0, 0,1, 0},
                        {1, 0, 1, 0, 0, 0},
                        {0, 1, 0, 1, 0, 0},
                        {0, 0, 1, 0, 1, 2},
                        {1, 0, 0, 1, 0, 2},
                        {0, 0, 0, 2, 2, 0} };
    int m = 3; // Number of colors
    int color[V];
    memset(color, 0, sizeof color);// заповнення масиву символами
    bool flag = graphColoring(graph, m, 0, color);
    if (flag)
        printcolours(color);
    else
        cout << "Solution doesn't exist.";
    return 0;
}
