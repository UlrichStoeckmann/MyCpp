#include "iostream"
#include<conio.h>
#define INFINITY 99999
using namespace std;
class Dijkstra
{
      private:
              int graph[30][30];
              int predecessor[30],dist[30];
              bool mark[30];
              int source;
              int vertices;
      public:
              void input();
              void initialize();
              int search_min_node();
              void calculate_dist();
              void output();
              void display_path(int);
};
void Dijkstra::input() {
     cout<<"Enter the number of vertices of the graph(should be > 0)\n";
     cin>>vertices;
     while(vertices <= 0) {
          cout<<"Enter the number of vertices of the graph(should be > 0)\n";
          cin>>vertices;  }
     cout<<"Enter the adjacency matrix for the graph\n";
     cout<<"To enter infinity enter "<<INFINITY<<endl;
     for(int i=1;i<=vertices;i++) {
        cout<<"Enter the positive weights for the row "<<i<<endl;
        for(int j=1;j<=vertices;j++) {
              cin>>graph[i][j];
              while(graph[i][j]<0) {
                  cout<<"Weights should be positive. Enter the weight again\n";
                  cin>>graph[i][j];
     }  }  }
       cout<<"Enter the source vertex\n";
       cin>>source;
       while((source<0) && (source>vertices-1)) {
           cout<<"Source vertex should be between 0 and"<<vertices-1<<endl;
           cout<<"Enter the source vertex again\n";
           cin>>source;
     }
}
void Dijkstra::initialize() {
     for(int i=1;i<=vertices;i++) {
             mark[i] = false;
             dist[i] = INFINITY ;
     predecessor[i] = -1;
     }
     dist[source]= 0;
 }
int Dijkstra::search_min_node() {
     int min_dist = INFINITY;
     int closestUnmarkedNode;
     for(int i=1;i<=vertices;i++) {
         if((!mark[i]) && ( min_dist >= dist[i])) {
  min_dist = dist[i];
  closestUnmarkedNode = i;
}  }
     return closestUnmarkedNode;
}
void Dijkstra::calculate_dist() {
initialize();
int minDistance = INFINITY;
int closestUnmarkedNode;
  	 int count = 0;
  	 while(count<vertices) {
   	closestUnmarkedNode = search_min_node();
   	mark[closestUnmarkedNode] = true;
 		        for(int i=1;i<=vertices;i++) {
       if((!mark[i]) && (graph[closestUnmarkedNode][i]>0) ) {
         if(dist[i] > dist[closestUnmarkedNode]+graph[closestUnmarkedNode][i]) {
dist[i] = dist[closestUnmarkedNode]+graph[closestUnmarkedNode][i];
predecessor[i] = closestUnmarkedNode;
    }  }  }
count++;  }
}
void Dijkstra::display_path(int node) {
if(node == source)
cout<<(char)(node + 65)<<"..";
else if(predecessor[node] == -1)
cout<<"No path from “<<source<<”to "<<(char)(node + 97)<<endl;
else {
display_path(predecessor[node]);
cout<<(char) (node+65)<<"..";
   }
getch();
}
void Dijkstra::output() {
for(int i=1;i<=vertices;i++) {
if(i == source)
cout<<(char)(source + 65)<<".."<<source;
else
display_path(i);
cout<<"->"<<dist[i]<<endl;
}
getch();
}

int main()
{
Dijkstra a;
a.input();
a.calculate_dist();
a.output();
return 0;
}
