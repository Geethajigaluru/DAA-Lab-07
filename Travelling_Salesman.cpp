#include <iostream>
using namespace std;

#define N 4
int cost[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[N];

int minCost = 9999;

void tsp(int city, int count, int currCost) {
    if(count == N && cost[city][0]) {
        minCost = min(minCost, currCost + cost[city][0]);
        return;
    }

    for(int i = 0; i < N; i++) {
        if(!visited[i] && cost[city][i]) {
            visited[i] = 1;
            tsp(i, count + 1, currCost + cost[city][i]);
            visited[i] = 0; // backtrack
        }
    }
}

int main() {
    visited[0] = 1;
    tsp(0, 1, 0);

    cout << "Minimum Cost: " << minCost;
}