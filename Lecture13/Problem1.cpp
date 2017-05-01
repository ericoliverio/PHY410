#include <cmath>
#include <iostream>
using namespace std;

#include <iostream>
#include <fstream>

#include "../cpt/linalg.cpp"
using namespace cpt;

int main()
{
  cout << " Resistor Cube \n"
       << " --------------------------------------\n";

  double v0 = 1;
  bool r_same = true;

  ofstream myfile;
  myfile.open ("req.txt");

  for(double j = 0.0; j < 51; j = j+1){
  //if (r_same){
    double r1 = j, r2 = 1, r3= 1, r4 = 1, r5 = 1, r6=1,r7=1,r8=1,r9=1,r10=1,r11=1,r12=1;
    //}

  Matrix<double,2> v(6, 1);       // column vector with 3 rows                                                                  
  for(int i = 0; i < 6; i = i + 1){
    v[i][0] = v0;
  }
  
  Matrix<double,2> R(6, 6);       // 3x3 resistance matrix                                                                      
  R[0][0] = r1 + r2 + r3;        // set components using slicing notation                                                      
  R[0][1] = r1;
  R[0][2] = r3;
  R[0][3] = 0;
  R[0][4] = 0;
  R[0][5] = 0; 

  R[1][0] = r1;
  R[1][1] = r1+r9+r5;
  R[1][2] = 0;
  R[1][3] = 0;
  R[1][4] = r5;
  R[1][5] = 0;

  R[2][0] = r3;
  R[2][1] = 0;
  R[2][2] = r4+r10+r3;
  R[2][3] = r4;
  R[2][4] = 0;
  R[2][5] = 0;

  R[3][0] = 0;
  R[3][1] = 0;
  R[3][2] = r4;
  R[3][3] = r4 + r12 + r8;
  R[3][4] = 0;
  R[3][5] = r8;

  R[4][0] = 0;
  R[4][1] = r5;
  R[4][2] = 0;
  R[4][3] = 0;
  R[4][4] = r5+r6+r11;
  R[4][5] = r6;

  R[5][0] = 0;
  R[5][1] = 0;
  R[5][2] = 0;
  R[5][3] = r8;
  R[5][4] = r6;
  R[5][5] = r6+r7+r8;

  cout << " R = \n" << R << std::endl;
  cout << " R.dim1 = " << R.dim1() << endl;
  cout << " R.dim2 = " << R.dim2() << endl;

  // the solve_Gauss_Jordan replaces R by R^-1 and v by i                                                                       
  // so save the original R and copy v into a vector i                                                                          
  Matrix<double,2> R_save(R), i(v);

  solve_Gauss_Jordan(R, i);
    cout << " Solution using Gauss-Jordan elimination\n i = \n"
	 << i << endl;

    double itot = i(0,0) + i(1,0) + i(2,0) + i(3,0) + i(4,0) + i(5,0); 
    cout << "Total current\n itot = \n" 
     << itot <<endl;

    double r_eq = v0 / itot;
    cout << "Equivalent Resistance of cube\n Req = \n"
	 << r_eq << endl;

    //ofstream myfile;
    //myfile.open ("req.txt");
    myfile << j  <<  "     " << r_eq  <<  "\n";
    }
    myfile.close();
}
