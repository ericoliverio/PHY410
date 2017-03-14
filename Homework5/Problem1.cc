#include <iostream>
#include "StudentRecord.h"
#include "StudentRecordPhysics.h"
#include "StudentRecordHistory.h"
#include "StudentRecordLiterature.h"
#include <vector>
#include <fstream>

#include <sstream>

int main(int argc, char * argv[]) {
  
  std::ifstream in ( argv[1] );
  std::string line;

  float phytot=0.0, littot=0.0, histot = 0.0;
  std::vector<StudentRecordPhysics> phyvec;
  std::vector<StudentRecordLiterature> litvec;
  std::vector<StudentRecordHistory> histvec;
  
  while (getline(in,line,'\n')){
    std::string subject;

    std::istringstream sline( line );
    getline(sline,subject,',');

    if(subject == "Physics"){
      StudentRecordPhysics srp;
      srp.input(sline);
      srp.print();
      phytot = phytot + srp.score();
      phyvec.push_back(srp);
      }
    else if(subject == "History"){
      StudentRecordHistory srh;
      srh.input(sline);
      srh.print();
      histot = histot + srh.score();
      histvec.push_back(srh);
    }
    else if(subject == "Literature"){
      StudentRecordLiterature srl;
      srl.input(sline);
      srl.print();     
 littot = littot + srl.score();
      litvec.push_back(srl);
    }
  }
  std::cout<< "The averages for Physics, Literature, and History are: " << phytot/phyvec.size() << ", " << littot/ litvec.size() << ", " << histot/ histvec.size() << " respectively" << std::endl;

}
   

