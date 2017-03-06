#include <iostream>
#include "StudentRecord.h"

#include <vector>
#include <fstream>

StudentRecord rec;
std::vector<StudentRecord> vec;
float calculate_average( std::vector<StudentRecord> *pvec );

int main(int argc, char * argv[]) {
  
  std::ifstream in( argv[1] );

  while(rec.input(in)){    
    vec.push_back(rec);
  }

  float average =  calculate_average( &vec);
  std::cout << "Average is: " << average << std::endl;
  return 0;
}

float calculate_average( std::vector<StudentRecord> *pvec ) {
   float avg = 0.0;
   for( unsigned int i = 0; i < pvec->size(); i++ ){
      avg = avg + pvec->at(i).score();    
   }
    
  avg = avg/(pvec->size());
  return avg;
}
   

