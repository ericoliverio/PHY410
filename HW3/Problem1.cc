#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(void){
  float xi=0.,yi=0., shortest;
  int i=0,ishort;
  vector<float> X;
  vector<float> Y;
  cout<<"Please enter pairs of vectors. Type Start when done: \n";
  while( cin >> xi >> yi ) {    
    X.push_back(xi);
    Y.push_back(yi);
    cout << X[i] << "," << Y[i] << endl;  
    i++;
  }
  float arg1 = (X[1]-X[0])*(X[1]-X[0]) + (Y[1]-Y[0])*(Y[1]-Y[0]);
  shortest = pow(arg1,0.5); 
 for(unsigned int j=0; j < X.size(); j++){
  float arg = (X[j+1]-X[j])*(X[j+1]-X[j]) + (Y[j+1]-Y[j])*(Y[j+1]-Y[j]);
  float sqrt = pow(arg,0.5);
     if( sqrt < shortest){
       shortest = sqrt;
       ishort = j;
     }
  }
  cout << "The shortest vector is: " << X[ishort] << "," << Y[ishort] << " with magnitude: " << shortest  << endl;
    
}
