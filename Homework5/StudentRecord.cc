#include "StudentRecord.h" 

StudentRecord::StudentRecord() {}
StudentRecord::~StudentRecord() {}

float StudentRecord::score() const { return score_; }

std::string StudentRecord::first() const { return first_; }

std::string StudentRecord::last() const { return last_; }

void StudentRecord::compute_score(void) {

  if ( scores_.size() == 0 ) {
    return ; 
  }

  score_ = 0.0;
  for ( unsigned int i = 0; i < scores_.size(); ++i ) {
    double iscore = scores_[i];
    score_ += iscore;
  }
  score_ /= scores_.size(); 
  //  std::cout << score_ << std::endl;
} 

