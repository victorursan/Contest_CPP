//
//  UndoParticipant.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/5/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "UndoParticipant.h"

UndoParticipant::UndoParticipant(const int position, const int operation, const Participant participant) {
  this->position = position;
  this->operation = operation;
  this->participant = participant;
}

UndoParticipant::~UndoParticipant() {
//  delete this;
}

int UndoParticipant::getPosition() const {
  return position;
}

int UndoParticipant::getOperation() const {
  return operation;
}

Participant UndoParticipant::getParticipant() const {
  return participant;
}
