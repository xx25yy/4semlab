#include <stdio.h>
int kruskals(int n, int mincost, int cost[][10]) {
int ne = 1, a = 0, u = 0, b = 0, v = 0, min;
int parent[10] = {0}; // Initializing parent array
while (ne < n) {
min = 999;
for (int i = 1; i <= n; i++) {
for (int j = 1; j <= n; j++) {
if (cost[i][j] < min) {
min = cost[i][j];
a = u = i;
b = v = j;
}
}
}
while (parent[u] > 0)
u = parent[u];
while (parent[v] > 0)
v = parent[v];
if (u != v) {
printf("%d>minimum edge is : (%d,%d) and its cost is: %d\n", ne++, a, b, min);
mincost += min;
parent[v] = u;
}
cost[a][b] = cost[b][a] = 999;
}
return mincost;

}

int main() {
int cost[10][10], i, j, mincost = 0;
printf("********* KRUSKAL'S ALGORITHM *******\n");
printf("Enter the number of nodes: ");
int n;
scanf("%d", &n);
printf("Enter the cost matrix:\n");
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
scanf("%d", &cost[i][j]);
}
}
printf("The entered cost matrix is:\n");
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
printf("%d\t", cost[i][j]);
}
printf("\n");
}
mincost = kruskals(n, mincost, cost);
printf("The minimum spanning tree cost is: %d\n", mincost);
printf("********* ****************** **********\n");
return 0;
}