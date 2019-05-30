#include <iostream>
using namespace std;

class Point {
public:
  Point( double x_=0.0, double y_=0.0)
      : x{ x_}, y{y_} {}
  double getX() const { return x; }
  double getY() const { return y; }

  Point operator+ (const Point& p1){
    Point sum = {p1.getX()+ this->x, p1.getY()+ this->y};
    return sum;
  }
private:
  double x;
  double y;
};


  ostream& operator<< (ostream& out, const Point p){
    out <<"("<<p.getX()<<", "<<p.getY()<<")"<<"\n";
    return out;
  }

int main()
{
   Point p1 {2.0, 5.0};
   Point p2 {3.0, 5.5};
   Point p5;
   cout<<"\np1: "<<p1<<"p2: "<<p2;
   Point p3 = p1 + p2;
   cout<<"sum p3: "<<p3;


    return 0;
}


