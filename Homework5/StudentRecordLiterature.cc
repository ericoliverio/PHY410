#include "StudentRecordLiterature.h"

StudentRecordLiterature::StudentRecordLiterature(){};
StudentRecordLiterature::~StudentRecordLiterature(){};

void StudentRecordLiterature::print(std::ostream & out) const{
  out << "Literature score: " << first_ << " "<< last_
      << " total: " << score() << std::endl;
}

bool StudentRecordLiterature::input( std::istream & in ) {
  std::string line;
  std::getline( in, line, ',');
  last_ = line;
  std::getline( in, line, ',');
  first_ = line;
  std::getline( in, line, ',');
  scores_.push_back(1.2* std::atof( line.c_str() ) );
  std::getline( in, line, ',');
  scores_.push_back(1.2 * std::atof( line.c_str() ) );
  std::getline( in, line, ',');
  scores_.push_back(0.6 * std::atof( line.c_str() ) );
  if (line == "")
    return false;
  else{
    compute_score();
    return true;
  }
}


