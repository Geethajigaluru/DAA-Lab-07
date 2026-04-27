#include <iostream>
using namespace std;

#define N 4

int cost[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

int visited[N];
int minCost = 9999;

void assignJob(int worker, int currentCost) {
    if(worker == N) {
        if(currentCost < minCost)
            minCost = currentCost;
        return;
    }

    for(int j = 0; j < N; j++) {
        if(!visited[j]) {
            visited[j] = 1;

            assignJob(worker + 1, currentCost + cost[worker][j]);

            visited[j] = 0; // backtrack
        }
    }
}

int main() {
    assignJob(0, 0);
    cout << "Minimum Assignment Cost: " << minCost;
}