//
//  Participant.h
//  Contest_CPP
//
//  Created by Victor Ursan on 4/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef __Contest_CPP__Participant__
#define __Contest_CPP__Participant__

#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Participant {
  string givenName;
  string familyName;
  float score;

public:

  Participant(const string &givenName = "", const string &familyName = "",const float &score = 0);
  ~Participant();

  string getGivenName() const;
  void setGivenName(string &givenName);

  string getFamilyName() const;
  void setFamilyName(string &familyName);

  float getScore() const;
  void setScore(float score);

  bool operator ==(const Participant& p2) const;
  bool operator !=(const Participant& p3) const;

  friend std::ostream& operator <<(std::ostream&, const Participant&);
  friend std::istream& operator >>(std::istream&, Participant&);

};

#endif /* defined(__Contest_CPP__Participant__) */
