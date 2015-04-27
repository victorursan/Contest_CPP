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
#include <unistd.h>
#include "Participant.h"
#include "Repository.h"
#include "Repository.cpp"
#include "UndoParticipant.h"
#include "AbstractRepository.h"

using namespace std;

class Controller {
  AbstractRepository<Participant> *repository;
  vector<UndoParticipant> undo_participants;
public:
  Controller(AbstractRepository<Participant>* repo);
  ~Controller();

  vector<Participant> getParticipants();
  void addParticipant(string givenName, string familyName, float score) throw (MyException);
  void updateParticipant(int id, string givenName, string familyName, float score) throw (MyException);
  void removeParticipant(int id) throw (MyException);
//  Participant findParticipantWithId(int id);
  vector<Participant> filterByGivenName(string givenName);
  vector<Participant> filterByFamilyName(string familyName);
  vector<Participant> filterByScore(float score);
  void undoLastOperation();
};

#endif /* defined(__Contest_CPP__Controller__) */
