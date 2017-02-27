#include <iostream>

long factorial( int x ){ 
  long fact = 1; 
  if (x == 0){
    return fact;
  }
  else{
  for (unsigned int j = 1; j <  x+1; j++) { 
   fact  = j * fact;
  }
  return fact;} }

int main(void) {
  int y;
  bool check = true;
  while ( check == true ){
  std::cout << "Please enter an integer less than or equal to 20: " << std::endl;
  std::cin >> y;
  
  if(y <= 20){check = false;}
  }
  long facto = factorial(y);
  std::cout << y << "! = " << facto << std::endl;
  return 0;
}
