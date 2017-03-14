#include "StudentRecordLiterature.h"

StudentRecordLiterature::StudentRecordLiterature(){};
StudentRecordLiterature::~StudentRecordLiterature(){};

void StudentRecordLiterature::print( std::ostream & out ) const {
  out << "Literature score: " << lastname_ << "," << firstname_
      << ", analytic: " << scores_[0] << ", creative: " << scores_[1] << ", commentary: " << scores_[2]
      << ", average: " << score() << std::endl;
}

void StudentRecordLiterature::compute_score (void) {
  score_=0.;
  score_= 0.4*scores_[0]+0.4*scores_[1]+0.2*scores_[2];
  score_ /= scores_.size();
}

bool StudentRecordLiterature::input( std::istream & in) {
  std::string line;
  std::getline( in, line, ',');
  lastname_ = line;
  std::getline( in, line, ',');
  firstname_ = line;
  std::getline( in, line, ',');
  scores_.push_back( std::atof( line.c_str() ) );
  std::getline( in, line, ',');
  scores_.push_back( std::atof( line.c_str() ) );
  std::getline( in, line );
  scores_.push_back( std::atof( line.c_str() ) );
  if ( line == "")
    return false;
    else {
      compute_score();
      return true;
    }
}


void StudentRecordLiterature::clear (void){
  for (unsigned int j=0; j < scores_.size(); ++j){
    scores_.erase(scores_.begin());
  }
}
