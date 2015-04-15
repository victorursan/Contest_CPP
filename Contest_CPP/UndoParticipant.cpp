//
//  UndoParticipant.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/5/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "UndoParticipant.h"

UndoParticipant::UndoParticipant(const int position, const int operation, const Participant participant) {
  /* Initialize a UndoParticipant

   param: position - position of the participant
   param: operation - the operation performed on the participant
   param: participant - the participant
   */
  this->position = position;
  this->operation = operation;
  this->participant = participant;
}

UndoParticipant::~UndoParticipant() {
  /* Destroy the UndoParticipant
   */
//  delete this;
}

int UndoParticipant::getPosition() const {
  /* Get the position of the UndoParticipant

   returns: the position
   */
  return position;
}

int UndoParticipant::getOperation() const {
  /* Get the operation of the UndoParticipant

   returns: the operation
   */
  return operation;
}

Participant UndoParticipant::getParticipant() const {
  /* Get the participant of the UndoParticipant

   returns: the participant
   */
  return participant;
}
