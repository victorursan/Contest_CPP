//
//  Controller.h
//  Contest_CPP
//
//  Created by Victor Ursan on 4/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef __Contest_CPP__Controller__
#define __Contest_CPP__Controller__

#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include "Participant.h"
#include "Repository.h"

using namespace std;

class Controller {
  Repository repository;

public:
  Controller(Repository repo);
  ~Controller();

  vector<Participant> getParticipants();
  void addParticipant(string givenName, string familyName, float score);
  void updateParticipant(int id, string givenName, string familyName, float score);
  void removeParticipant(int id);
  //  Participant findParticipantWithId(int id);
  //  Participant findParticipantWithGivenName(string givenName);
  //  Participant findParticipantWithFamilyName(string familyName);
  vector<Participant> filterByGivenName(string givenName);
  vector<Participant> filterByFamilyName(string familyName);
  vector<Participant> filterByScore(float score);

};

#endif /* defined(__Contest_CPP__Controller__) */
