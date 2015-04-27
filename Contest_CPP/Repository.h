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
#include "EntityValidator.h"
#include "MyException.h"
#include "AbstractRepository.h"
#include "Validator.h"

using namespace std;

template <typename T>
class Repository : public AbstractRepository<T> {
  vector<T> store;
  EntityValidator<T> *validator;
public:
  Repository();
  ~Repository();

  Repository(EntityValidator<T> *validator);

  vector<T> getAll();

  virtual void save(T p) throw (MyException);
  virtual void insertAtPosition(int id, T p) throw (MyException);
  void update(int id, T p) throw (MyException);
  void remove(int id) throw (MyException);
  const T findById(int id) throw (MyException);
  int size();
};

#endif /* defined(__Contest_CPP__Repository__) */
