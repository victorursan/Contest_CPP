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

template <typename T>
class Repository {
  vector<T> store;

public:
  Repository();
  ~Repository();

  vector<T> getAll();
  void save(T p);
  void insertAtPosition(int id, T p);
  void update(int id, T p);
  void remove(int id);
  const T findById(int id);
  int size();
};

#endif /* defined(__Contest_CPP__Repository__) */
