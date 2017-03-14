#include "StudentRecordPhysics.h"

StudentRecordPhysics::StudentRecordPhysics(){};
StudentRecordPhysics::~StudentRecordPhysics(){};

void StudentRecordPhysics::print(std::ostream & out) const{
  out << "Physics score: " << first_ << " " << last_
      << " total: " << score() << std::endl;
}

bool StudentRecordPhysics::input( std::istream & in ) {
  std::string line;
   std::getline( in, line, ','); 
  last_ = line;
  std::getline( in, line, ',');
  first_ = line;
  std::getline( in, line, ',');
  scores_.push_back(1.6* std::atof( line.c_str() ) );
  std::getline( in, line, ',');
  scores_.push_back(0.4 * std::atof( line.c_str() ) );
  if (line == "")
    return false;
  else{
    compute_score();
    return true;
  }
}
