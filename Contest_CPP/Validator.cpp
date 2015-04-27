//
//  Validator.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/27/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "Validator.h"

void ParticipantValidator::validate(const Participant& p) const{
  string err;
  if (p.getFamilyName().empty()) {
    err += "Family name cannot be empty! ";
  }
  if (p.getGivenName().empty()) {
    err += "Given name cannot be empty! ";
  }
  if (p.getScore() < 0) {
    err += "Price cannot be negative! ";
  }
  if (!err.empty()) {
    throw ParticipantStoreException(err) ;
  }
}