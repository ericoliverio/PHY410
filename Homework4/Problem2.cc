#include <iostream>
#include "StudentRecord.h"

#include <vector>
#include <fstream>

StudentRecord rec;
std::vector<StudentRecord> vec;

int main(int argc, char * argv[]) {

  std::ifstream in( argv[1] );

  while(rec.input(in)){
    vec.push_back(rec);
  }

  int index = atoi(argv[2]);
  if ( index > vec.size()) {
    std::cout << "Whoah there buddy, there aren't that many kids. There are only " << vec.size() << " members of the record. Try again!" << std::endl;
  } else {
  std::cout << "Full name: " << vec[index].first() << " " <<  vec[index].last() << "\nScore: " << vec[index].score()  << std::endl; 
  }
  // std::cout <<  "index: " << atoi(argv[2]) << std::endl;
}
