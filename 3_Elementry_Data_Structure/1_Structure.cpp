// Structure is an aggregate type to define collection of data
#include <iostream>
#include <cmath>

// Point Data Interface
struct Point{
  float x, y;
};
// Calculates distance between the points
float distance(Point, Point);
// Convertes the point in polar form
void polar(float, float, float*, float*);

int main() 
{

}

float distance(Point a, Point b) {
  float dx = a.x - b.x;
  float dy = a.y - b.y;
  return sqrt(dx*dx + dy*dy);
}

void polar(float x, float y, float* r, float* theta) {
  *r = sqrt(x*x + y*y);
  *theta = atan2(x, y);
}