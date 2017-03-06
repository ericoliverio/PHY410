#ifndef StudentRecord_h 
#define StudentRecord_h

#include <iostream>

class StudentRecord{
  public:
  StudentRecord( std::string first = "" , std::string last = "" , float score = 0.);
  ~StudentRecord();

  float score() const;   
  std::string first() const;
  std::string last() const;

  bool input( std::istream & in );

    private:
  std::string first_;
  std::string last_;
  float score_; 

};

#endif
