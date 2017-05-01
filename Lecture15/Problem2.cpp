#include <iostream>
using namespace std;

#include "../cpt/linalg.cpp"
using namespace cpt;

int main()
{


  double M1 = 15.9, m = 12; 

  // Matrix with masses as the diagonal elements                                                                                
  Matrix<double,2> M(5, 5);
  M(0,0) = M1;
  M(1,1) = m;
  M(2,2) = m;
  M(3,3) = m;
  M(4,4) = M1;
  cout << "M =\n" << M;


  Matrix<double,2> Minv(5,5);
  inverse(M, Minv);
  cout << "Minv=" << endl << Minv << endl;

  // "Spring" constants affecting each mass                                                                                     
  double k = 12.4, bigK = 14.5;
  double Lagrange[5][5] = {
    {   bigK,    -bigK,       0,   0,   0    },
    {    -bigK,   bigK+k,     -k,   0,   0    },
    {    0,      -k,  2*k,   -k,   0    },
    {    0,    0,       -k,   k+bigK,-bigK    },
    {    0,    0,       0,    -bigK,  bigK}
  };
  Matrix<double,2> K(5, 5);
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      K(i,j) = Lagrange[i][j];
  cout << "K =\n" << K;




  // Solve with generalized eigenvector solution                                                                                
  Matrix<double,1> eigenvalues = solve_eigen_generalized(K, M, false);

  cout << "Eigenvalues =\n" << eigenvalues << endl
       << "Eigenvectors =\n" << K;


}
