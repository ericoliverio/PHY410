#include <iostream>
int main() {
  float x1, y1, x2, y2, slope,b,slope2,b2;
  std::cout << "Please enter points in the form x1 y1 x2 y2: ";
  std::cin >> x1 >> y1 >> x2 >> y2;
  if ( (x2 - x1) == 0 ) {
    std::cout << " x = " << x2 << '\n';
    std::cout << " y = " << x1 << '\n';
  }
  else if ( y1 == y2){
    std::cout << " y = " << y1 << '\n';
    std::cout << " x = " << y1 << '\n';
  }
  else{
  slope = (y2 - y1 ) / (x2 - x1);
  b = y1 - slope * x1;
  std::cout << "y = " << slope  << " x + " << b  << '\n';
  slope2 = - ( y2 - y1 ) / ( x2 - x1);
  b2 = y1 - ( slope2 * x1 ); 
  std::cout << "y = " << slope2  << " x + " << b2  << '\n';
  }
}
