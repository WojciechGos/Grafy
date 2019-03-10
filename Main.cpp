#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <complex>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <iterator>
#include <list>
#include <set>

using namespace std;

typedef vector<int> VI;
typedef long long LL;
#define FOR(x, from, to) for(int x = from; x <= (to); ++x)
#define FORD(x, from, to) for(int x = from; x >= (to); – –x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second

template <class V, class E> struct Graph {

    struct Edge : E {
        int v;
        Edge(E p, int w) : E(p), v(w){ };
    };
    struct Vertex : V, vector<Edge> {};
    
    vector<Vertex> graphVertex;

    Graph(int n=0) : graphVertex(n) {};

    void EdgeDirect(int from, int to, E data = E()) {
        graphVertex[from].PB(Edge(data, to));
    }

    void EdgeUndirect(int from, int to, E data = E()) {
        Edge eg(data, to);
        eg.rev = SIZE(graphVertex[to]) + (from==to);
        graphVertex[from].PB(eg);    
        eg.rev = SIZE(graphVertex[eg.v=from]) - 1;
        graphVertex[to].PB(eg);
    }

    void write(){
        REP(x, SIZE(graphVertex)){
            cout << x << ":";

            FOREACH(it, graphVertex[x]){
                cout << " " << it->v;
            }
            cout << endl;
        }
 
    }
};

struct Empty {};

int main(){

    int n, m, b, e;

    // wczytaj liczbe wierzchołków i krawędzi w grafie

    cin >> n >> m;

    Graph<Empty,Empty> gr(n); 
    // wczytaj początek i koniec kolejnej krawędzi
    REP(x, m){
        cin >> b >> e;

        // dodawanie krawędzi skierowanej 
        gr.EdgeDirect(b, e);
    }

    // wypisywanie grafu
    gr.write();

    return 0;
}