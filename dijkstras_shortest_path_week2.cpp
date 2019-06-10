/*ToDo: 1. alle Variablen und Methoden in die Klasse verschieben
2. den Dijkstra Algorithmus implementieren */
#include <iostream>
#include <ctime>
#include <random>
#include <conio.h>
using namespace std;

#define DISTANCE_INIT 9999; //means not connected

double prob()
{
    return (static_cast<double>(rand())/RAND_MAX);
}
double  weight()
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

class Dijkstra{
    public:
        void create_graph(); //initialize all edges for the graph
        void print(); // print the adjacent matrix of the graph
        void initialize(); // create start values for the dijkstra algo
        void calculate_dist(); //
        int search_min_node(); //
        void output(); //present result
        void display_path(int);
        int nodes_amount, MAXV, source; // number of nodes and start node for finding the shortest path
        double edge_density; // edge density for the graph
        double **connection; // distance between the nodes
        double* dist; // ?
        bool* mark; // see breitensuche
        int* predecessor; // predecessor of the node on the shortest path

};
void Dijkstra::create_graph()
{
  cout<<"Number of nodes (>1): ";
  cin>>nodes_amount;
  cout<<"\nEdge Density (0-1)";
  cin>>edge_density;
  cout<<"Enter the source vertex\n";
  cin>>source;
  MAXV = nodes_amount;
    srand(time(0)); // seed random generator
    connection = new double*[MAXV];
    for(int i= 0; i<MAXV; ++i)
    {
        connection[i] = new double[MAXV];
    }
    //heap created 2D model of bool
    for(int i=0; i<MAXV;++i)
    {
        for(int j=i; j<MAXV;++j)
        {
            if(i==j) connection[i][j] = 0; // no loops
            else
            {
               connection[i][j]=connection[j][i]=(prob()<edge_density)*weight(); //generating the density with distances from 1.0 to 10.0
            }

        }
    }
}

void Dijkstra::print()
{
  for(int i=0; i<MAXV;++i)
    {
    for(int j=0; j<MAXV;++j)
    cout<<connection[i][j]<<", ";
    cout<<"\n";
    }
}

void Dijkstra::initialize()
{
    mark = new bool[MAXV];
    dist = new double[MAXV];
    predecessor = new int [MAXV];
    for(int i=0;i<MAXV;i++)  // set initial values for all nodes
    {
        mark[i] = false;
        dist[i] = DISTANCE_INIT ;
        predecessor[i] = -1;
    }
     dist[source]= 0;
 }
int Dijkstra::search_min_node()
{
 int min_dist = DISTANCE_INIT;
 int closestUnmarkedNode;
 for(int i=0;i<MAXV;i++)
    {
        if((!mark[i]) && ( min_dist >= dist[i]))
        {
            min_dist = dist[i];
            closestUnmarkedNode = i;
        }
    }
 return closestUnmarkedNode;
}
 void Dijkstra::calculate_dist()
 {
     initialize();
     int closestUnmarkedNode;
     int count = 0;
  	 while(count<MAXV)
  	 {
        closestUnmarkedNode = search_min_node();
        mark[closestUnmarkedNode] = true;
        for(int i=0;i<MAXV;i++)
        {
            if((!mark[i]) && (connection[closestUnmarkedNode][i]>0) ) //
            {
                if(dist[i] > dist[closestUnmarkedNode]+connection[closestUnmarkedNode][i])
                {
                  dist[i] = dist[closestUnmarkedNode]+connection[closestUnmarkedNode][i]; //found new shortest path to node i
                  predecessor[i] = closestUnmarkedNode;
                }
            }
  	   }
  	   count++;
  	 }
 }

void Dijkstra::display_path(int node)
{
    if(node == source)
      cout<<node<<"..";
    else
        if(predecessor[node] == -1)
            cout<<"No path from “<<source<<”to "<<node<<endl;
        else {
                display_path(predecessor[node]);
                cout<<node<<"..";
             }
    getch();
}
void Dijkstra::output()
{
    for(int i=0;i<MAXV;i++)
        {
            if(i == source)
              cout<<source<<".."<<source;
            else
                display_path(i);
            cout<<"->"<<dist[i]<<endl;
        }
    getch();
}
int main()
{
 Dijkstra a;
 a.create_graph();
 a.print();
 a.calculate_dist();
 a.output();

 return 0;
}


