//
//  ParticipantFileRepository.h
//  Contest_CPP
//
//  Created by Victor Ursan on 4/27/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef __Contest_CPP__ParticipantFileRepository__
#define __Contest_CPP__ParticipantFileRepository__

#include <stdio.h>
#include <iostream>
#include "Repository.h"
#include <string>
#include "EntityValidator.h"
//#include "Participant.h"
#include "MyException.h"
#include <fstream>

using namespace std;

class ParticipantFileRepository: public Repository<Participant>{
  string filename;
public:
  ParticipantFileRepository(EntityValidator<Participant>* validator, string filename) : Repository<Participant>(validator) {
    this->filename = filename;
    loadEntities();
  }
  void save(Participant p) throw (MyException);
  void insertAtPosition(int id, Participant p) throw (MyException);
  void update(int id, Participant p) throw (MyException);
  void remove(int id) throw (MyException);
private:
  void loadEntities();
};

#endif /* defined(__Contest_CPP__ParticipantFileRepository__) */
