//
//  UndoParticipant.h
//  Contest_CPP
//
//  Created by Victor Ursan on 4/5/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef __Contest_CPP__UndoParticipant__
#define __Contest_CPP__UndoParticipant__

#include <stdio.h>
#include "Participant.h"

class UndoParticipant {
  int position;
  int operation;
  Participant participant;

public:
  UndoParticipant(const int position, const int operation, const Participant participant);
  ~UndoParticipant();
  int getPosition() const;
  int getOperation() const;
  Participant getParticipant() const;
};

#endif /* defined(__Contest_CPP__UndoParticipant__) */
