//
//  ParticipantFileRepository.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/27/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef MYEXCEPTION_H_
#define MYEXCEPTION_H_

#include <stdexcept>

using namespace std;

class MyException: public exception {
  string msg;
public:
  MyException(const string& msg): msg { msg } {}
  MyException(const exception& ex): MyException { ex.what() } {}
  virtual ~MyException() throw () {}
  virtual const char* what() const throw () {
    return msg.c_str();
  }
};

class RepositoryException: public MyException {
public:
  RepositoryException(const string& msg = "repository exception"): MyException { msg } {}
  virtual ~RepositoryException() throw () {
  }
};

#endif /* MYEXCEPTION_H_ */
