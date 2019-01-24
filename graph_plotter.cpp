/**
 * OOPs Lab 2019 4th SEM
 * NAME : Jayjeet Chakraborty (17CS8036)
 * ASSIGNMENT : Graph Plotter
 * DATE : 25/01/2019
 */

#include <bits/stdc++.h>
#define int long long
using namespace std;

class GraphPlotter
{
    int x;

  public:
    GraphPlotter(int x)
    {
        this->x = x;
    }
    void print_sin_graph();
    void print_cos_graph();
};

void GraphPlotter::print_sin_graph()
{
    for (double i = 0; i <= x; i += 0.1)
    {
        if (sin(i) < 0)
        {
            cout << setw(55 - abs(50 * sin(i))) << "*\n";
        }
        else
        {
            cout << setw(50 * sin(i) + 55) << "*\n";
        }
    }
}

void GraphPlotter::print_cos_graph()
{
    for (double i = 0; i <= x; i += 0.1)
    {
        if (cos(i) < 0)
        {
            cout << setw(55 - abs(50 * cos(i))) << "*\n";
        }
        else
        {
            cout << setw(50 * cos(i) + 55) << "*\n";
        }
    }
}

int32_t main()
{
    int x;
    cin >> x;
    GraphPlotter plotter = GraphPlotter(x);
    cout << "Sine Graph\n";
    plotter.print_sin_graph();
    cout << "Cosine Graph\n";
    plotter.print_cos_graph();
}
