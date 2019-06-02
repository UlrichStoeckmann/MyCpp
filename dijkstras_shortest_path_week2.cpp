#include <iostream>
#include <ctime>
#include <random>
using namespace std;


const int MAXV = 10;

double prob()
{
    return (static_cast<double>(rand())/RAND_MAX);
}
double dist()
{
    return(1.0+(static_cast<double>((90*rand())/RAND_MAX))/10);
}

class EdgeNode{
    public:
        int key;
        int weight;
        EdgeNode *next;
        EdgeNode(int, int);
};

EdgeNode::EdgeNode(int key, int weight){
    this->key = key;
    this->weight = weight;
    this->next = NULL;
}

class Graph{
    public:
        EdgeNode *edges[MAXV + 1];
        Graph();
        ~Graph();
        void insert_edge(int, int, int);
        void print();
};

int main()
{
bool** connected;
double **distance;
    srand(time(0)); // seed random generator
    connected = new bool*[MAXV];
    distance = new double*[MAXV];
    for(int i= 0; i<MAXV; ++i)
    {
        connected[i] = new bool[MAXV];
        distance[i] = new double[MAXV];
    }
    //heap created 2D model of bool
for(int i=0; i<MAXV;++i)
{
     for(int j=i; j<MAXV;++j)
     {
        if(i==j) connected[i][j] = false; // no loops
        else  connected[i][j]=connected[j][i]=(prob()<0.5); //generating the density with distances from 1.0 to 10.0
        distance[i][j]= distance[j][i]= connected[i][j] * dist();
     }
}

for(int i=0; i<MAXV;++i)
{
    for(int j=0; j<MAXV;++j)
    cout<<distance[i][j]<<", ";
 cout<<"\n";
}


    return 0;
}


