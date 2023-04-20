#include <limits.h>
#include <iostream>
#include <vector>

void print(const std::vector<int> &dist)
{
    std::cout << "Vertex \t Distance from Source" << std::endl;
    for (int i = 0; i < 9; i++)
    {
        std::cout << i << "\t\t" << dist[i] << std::endl;
    }
}

int minDistance(const std::vector<int> &dist, const std::vector<bool> &sptSet)
{
    int min = INT_MAX, idx;
    for (int v = 0; v < 9; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            idx = v;
        }
    }
    return idx;
}

std::vector<int> dijkstraAlgorithm(const std::vector<std::vector<int>> &input, int src)
{
    std::vector<int> distance(9, INT_MAX);
    std::vector<bool> sptSet(9, false);

    distance[src] = 0;

    for (int count = 0; count < 8; count++)
    {
        int u = minDistance(distance, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < 9; v++)
        {
            if (!sptSet[v] && input[u][v] &&
                distance[u] != INT_MAX &&
                distance[u] + input[u][v] < distance[v])
            {
                distance[v] = distance[u] + input[u][v];
            }
        }
    }
    return distance;
}

int main()
{
    std::vector<std::vector<int>> input = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                           {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                           {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                           {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                           {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                           {0, 0, 4, 14, 10, 0, 2, 0, 0},
                                           {0, 0, 0, 0, 0, 2, 0, 1, 6},
                                           {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                           {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    std::vector<int> output = dijkstraAlgorithm(input, 0);
    print(output);
    return 0;
}
