#include <iostream>
#include <ctime>
#include <random>
using namespace std;


const int MAXV = 10;

double prob()
{
    return (static_cast<double>(rand())/RAND_MAX);
}
int main()
{
bool** graph;
    srand(time(0)); // seed random generator
    graph = new bool*[MAXV];
    for(int i= 0; i<MAXV; ++i)
    {
        graph[i] = new bool[MAXV];
    }
    //heap created 2D model of bool
for(int i=0; i<MAXV;++i)
{
     for(int j=i; j<MAXV;++j)
        if(i==j) graph[i][j] = false; // no loops
        else graph[i][j]=graph[j][i]=(prob()<0.5);
}
for(int i=0; i<MAXV;++i)
{
    for(int j=0; j<MAXV;++j)
    cout<<graph[i][j]<<", ";
 cout<<"\n";
}


    return 0;
}


