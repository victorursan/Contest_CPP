//
//  TestUndoParticipant.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/6/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "TestUndoParticipant.h"

void test_undoParticipant() {
  Participant *p = new Participant("Mike", "Black", 10);
  UndoParticipant *undo = new UndoParticipant(1, 1, *p);
  assert(undo->getPosition() == 1);
  assert(undo->getOperation() == 1);
  assert(undo->getParticipant() == *p);
  delete undo;
  delete p;
}