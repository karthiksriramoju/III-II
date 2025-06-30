#include <bits/stdc++.h>
using namespace std;

int sum(vector<int>& f, int i, int j) {
    int s = 0;
    for(; i <= j; i++) s += f[i];
    return s;
}

int optCost(vector<int>& f, int i, int j) {
    if(j < i) return 0;
    if(j == i) return f[i];

    int fsum = sum(f, i , j);
    int mini = INT_MAX, cost;

    for(int r = i; r <= j; r++) {
        cost = optCost(f, i , r - 1) + optCost(f, r + 1, j);
        mini = min(mini, cost);
    }
    return mini + fsum;
}



int main() {
    vector<int> f = {34,8,50};
    int n = f.size();
    printf("Cost of Optimal BST is %d\n", optCost(f ,0, n - 1));

}