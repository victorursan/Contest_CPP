//
//  Validator.h
//  Contest_CPP
//
//  Created by Victor Ursan on 4/27/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef __Contest_CPP__Validator__
#define __Contest_CPP__Validator__

#include <stdio.h>
#include "MyException.h"
#include "EntityValidator.h"
#include "Participant.h"
#include <string>
#include <stdexcept>

using namespace std;

class ParticipantStoreException: public MyException {
public:
  ParticipantStoreException(const string& msg = "productStore exception") : MyException { msg } {}
  ParticipantStoreException(const exception& ex) : MyException { ex } {}
};

class ParticipantValidator: public EntityValidator<Participant> {
  virtual void validate(const Participant& p) const;
};

#endif /* defined(__Contest_CPP__Validator__) */
