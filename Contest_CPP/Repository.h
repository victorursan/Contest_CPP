//
//  Repository.h
//  Contest_CPP
//
//  Created by Victor Ursan on 4/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef __Contest_CPP__Repository__
#define __Contest_CPP__Repository__

#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include "Participant.h"

using namespace std;

class Repository {
  vector<Participant> store;

public:
  Repository();
  ~Repository();

  vector<Participant> getAll();
  void save(Participant p);
  void update(int id, Participant p);
  void remove(int id);
  const Participant* findById(int id);
};

#endif /* defined(__Contest_CPP__Repository__) */
