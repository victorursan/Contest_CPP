//
//  Participant.h
//  Contest_CPP
//
//  Created by Victor Ursan on 4/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef __Contest_CPP__Participant__
#define __Contest_CPP__Participant__

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>

using namespace std;

class Participant {
  string givenName;
  string familyName;
  float score;

public:

  Participant(const string &givenName = "", const string &familyName = "",const float &score = 0);
  ~Participant();

  const string getGivenName() const;
  void setGivenName(string &givenName);

  const string getFamilyName() const;
  void setFamilyName(string &familyName);

  const float getScore() const;
  void setScore(float score);

  bool operator ==(const Participant& other) const;
  bool operator !=(const Participant& other) const;

  friend std::ostream& operator <<(std::ostream&, const Participant&);
  friend std::istream& operator >>(std::istream&, Participant&);

};

#endif /* defined(__Contest_CPP__Participant__) */
