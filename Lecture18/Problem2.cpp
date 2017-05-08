#include "nacl.hpp"

int main()
{
  string name("Na4Cl4");      // for output files                                                                                        
  //3 or 4
  const int nNa = 4, nCl = 4;
  const int n = nNa + nCl;
  double a = 0.2;

  //Na3Cl3
  //double r_Na[nNa][3] = { {0, 0, 0}, { a, 0, 0 }, { a/2,1.866* a, 0} };
  //double r_Cl[nCl][3] = { {a/2, -0.866*a, 0}, { a, a, 0 }, { 0, a, 0 } };
  
  //Na4Cl4
  double r_Na[nNa][4] = { {0, 0, 0}, { a, a, 0 }, { 2*a, 0, 0}, {3*a,a,0} };                                                        
  double r_Cl[nCl][4] = { {0,a,0}, {a, 0, 0}, { 2*a, a, 0 }, { 3*a, 0, 0 } }; 

  // Initialize the cluster, add guesses at the                                                                                          
  // minimum arrangement.                                                                                                                
  Cluster cluster;
  for (int i = 0; i < nNa; i++) {
    Matrix<double,1> r(3, r_Na[i]);
    cluster.add(Na(r));
  }
  for (int i = 0; i < nCl; i++) {
    Matrix<double,1> r(3, r_Cl[i]);
    cluster.add(Cl(r));
  }
  cout << " " << name << " cluster" << endl
       << " Initial potential energy = "
       << cluster.potential_energy() << endl;


  // Minimize the function                                                                                                               
  int iterations = 0;
  double accuracy = 1e-6;
  double pe = cluster.minimize( accuracy, iterations );


  // Print out resulting files to be plotted in                                                                                          
  // either matplotlib or gnuplot.                                                                                                       
  cout << " Minimized potential energy = " << pe << "\n"
       << " Binding energy of cluster  = " << pe / 4 << " eV\n"
       << " Number of iterations = " << iterations << endl;

  string file_name = name + ".data";
  ofstream file(file_name.c_str());
  for (int i = 0; i < nNa + nCl - 1; i++) {
    for (int j = i + 1; j < nNa + nCl; j++) {
      Matrix<double,1> rij = cluster.ion(i).r - cluster.ion(j).r;
      double dr = sqrt(dot(rij, rij));
      string s = "(" + cluster.ion(i).name + ")-(" +
	cluster.ion(j).name + ")";
      cout << " " << s << " r_" << i << j << " = " << dr << " nm\n";
  }
}
file << cluster;
file.close();
cout << " xyz coordinates in " << file_name << endl;

file_name = name + ".gnu";
file.open(file_name.c_str());
file << "set title \"(NaCl)_4 Energy = " << pe / 4 << " eV\"\n"
<< "set hidden3d\n"
<< "unset key\n"
<< "splot \"na4cl4.data\" with points lt 3 pt 7 ps 8\n"
<< "pause -1 \"Hit return to continue \"\n";
file.close();
cout << " Gnuplot script in " << file_name << endl;
}


