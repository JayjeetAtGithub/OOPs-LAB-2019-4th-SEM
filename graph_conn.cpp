/**
 * OOPs Lab 2019 4th SEM
 * NAME : Jayjeet Chakraborty (17CS8036)
 * ASSIGNMENT : Connected Components
 * DATE : 07/02/2019
 */

#include <iostream>
#include <stdlib.h>
#define ll long long int

using namespace std;
int **p;
int *c;
int *pos;
struct edges
{
    int x;
    int y;
};
int MAX;
struct edges *edge;
int *visited;
ll dfs(ll x)
{
    cout << x << " ";
    visited[x] = 1;
    for (ll i = 0; i < c[x]; i++)
    {
        if (visited[p[x][i]] == 0)
        {
            dfs(p[x][i]);
        }
    }
    return 0;
}
int main()
{
    cout << "Enter the number of nodes" << endl;
    cin >> MAX;
    edge = new struct edges[MAX];
    p = new int *[MAX];
    c = new int[MAX];
    pos = new int[MAX];
    visited = new int[MAX];

    ll num;
    cout << "Enter the number ";
    cin >> num;
    edge = new struct edges[num];
    for (ll i = 0; i < MAX; i++)
    {
        c[i] = 0;
        pos[i] = 0;
        visited[i] = 0;
    }
    for (ll i = 0; i < num; i++)
    {
        cin >> edge[i].x >> edge[i].y;

        c[edge[i].x]++;
        c[edge[i].y]++;
    }
    for (ll i = 0; i < MAX; i++)
    {
        p[i] = new int[c[i]];
    }
    for (ll i = 0; i < num; i++)
    {
        p[edge[i].x][pos[edge[i].x]] = edge[i].y;
        p[edge[i].y][pos[edge[i].y]] = edge[i].x;
        pos[edge[i].x]++;
        pos[edge[i].y]++;
    }
    int cnt = 0;
    for (ll i = 0; i < MAX; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
            cnt++;
            cout << endl;
        }
    }
    cout << cnt << endl;
}