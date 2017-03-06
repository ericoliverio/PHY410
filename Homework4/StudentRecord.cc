#include "StudentRecord.h" 

StudentRecord::StudentRecord( std::string last , std::string first, float score ) {
  last_ = last; first_ = first; score_ = score;
}

StudentRecord::~StudentRecord(){}

float StudentRecord::score() const { return score_; }

std::string StudentRecord::first() const { return first_; }

std::string StudentRecord::last() const { return last_; }

bool StudentRecord::input ( std::istream & in ) {   
  std::string line;   
  std::getline( in, line, ',');   
  last_ = line;   
  std::getline( in, line, ',');   
  first_ = line;   
  std::getline( in, line );   
  score_ = std::atof( line.c_str() );   
  if ( line == "")      
    return false;   
  else     
    return true; 
}
