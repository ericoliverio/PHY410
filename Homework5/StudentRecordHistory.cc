#include "StudentRecordHistory.h"

StudentRecordHistory::StudentRecordHistory(){};
StudentRecordHistory::~StudentRecordHistory(){};

void StudentRecordHistory::print(std::ostream & out) const{
  out << "History score: " << first_ << " " << last_
      << " total: " << score() << std::endl;
}


bool StudentRecordHistory::input( std::istream & in ) {
  std::string line;
  std::getline( in, line, ',');
  last_ = line;
  std::getline( in, line, ',');
  first_ = line;
  std::getline( in, line, ',');
  float score1 = std::atof( line.c_str() );
  std::getline( in, line, ',');
  float score2 = std::atof( line.c_str() );
  if ( score1 >= score2 ){
    scores_.push_back( score1 * 1.2);
    scores_.push_back(score2 *0.8);
  }
  else{
  scores_.push_back( score1 *0.8 );
  scores_.push_back(score2 *1.2);
  }
  if (line == "")
    return false;
  else{
    compute_score();
    return true;
  }
}





