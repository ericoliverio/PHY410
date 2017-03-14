#ifndef StudentRecord_h 
#define StudentRecord_h

#include <iostream>
#include <vector>

class StudentRecord{
  public:
  StudentRecord();
  ~StudentRecord();

  float  score() const;   
  std::string first() const;
  std::string last() const;

  virtual bool input( std::istream & in ) = 0;
  virtual void print(std::ostream & out = std::cout) const = 0;
    protected:
  std::string first_;
  std::string last_;
  std::vector< float > scores_;
  float score_;

  void compute_score(void);
};

#endif
