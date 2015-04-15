//
//  TestParticipant.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/6/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "TestParticipant.h"

void test_participant() {
  Participant *p = new Participant("Mike", "Black", 10);

  assert(p->getFamilyName() == "Black");
  assert(p->getGivenName() == "Mike");
  assert(p->getScore() == 10);

  string newFamilyName = "Grey";
  string newGivenName = "John";
  p->setFamilyName(newFamilyName);
  p->setGivenName(newGivenName);
  p->setScore(11);

  assert(p->getFamilyName() == "Grey");
  assert(p->getGivenName() == "John");
  assert(p->getScore() == 11);

  assert(*p == Participant("John", "Grey", 11));
  assert(*p != Participant("Mike", "Black", 10));

  delete p;
}
