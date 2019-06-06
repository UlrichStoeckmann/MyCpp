/*ToDo: 1. alle Variablen und Methoden in die Klasse verschieben
2. den Dijkstra Algorithmus implementieren */
#include <iostream>
#include <ctime>
#include <random>
using namespace std;


double prob()
{
    return (static_cast<double>(rand())/RAND_MAX);
}
double  dist()
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
};

class Dijkstra{
    public:
        void initialize();
        int nodes_amount, MAXV;
        double edge_density;

};
void Dijkstra::initialize()
{
  bool** connected;
  double **distance;
  cout<<"Number of nodes (>1): ";
  cin>>nodes_amount;
  cout<<"\nEdge Density (0-1)";
  cin>>edge_density;
  MAXV = nodes_amount;
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
        else  connected[i][j]=connected[j][i]=(prob()<edge_density); //generating the density with distances from 1.0 to 10.0
        distance[i][j]= distance[j][i]= connected[i][j] * dist();
     }
}

for(int i=0; i<MAXV;++i)
{
    for(int j=0; j<MAXV;++j)
    cout<<distance[i][j]<<", ";
 cout<<"\n";
}

}
int main()
{
 Dijkstra a;
 a.initialize();

    return 0;
}


