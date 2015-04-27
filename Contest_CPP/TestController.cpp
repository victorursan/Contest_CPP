//
//  TestController.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/6/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "TestController.h"


void test_addParticipant(Controller *ctrl) {
  //void addParticipant(string givenName, string familyName, float score);
  ctrl->addParticipant("a", "b", 10);
  assert(ctrl->getParticipants().size() == 1);
}

void test_updateParticipant(Controller *ctrl) {
  //void updateParticipant(int id, string givenName, string familyName, float score);
  ctrl->updateParticipant(0, "c", "d", 11);
  assert(ctrl->getParticipants()[0] == Participant("c", "d", 11));
}

void test_removeParticiapnt(Controller *ctrl) {
  ctrl->addParticipant("a", "b", 10);
  assert(ctrl->getParticipants().size() == 2);
  ctrl->removeParticipant(0);
  assert(ctrl->getParticipants().size() == 1);
}

void test_filterByGivenName(Controller *ctrl) {
  //vector<Participant> filterByGivenName(string givenName);
  vector<Participant> filter = ctrl->filterByGivenName("a");
  assert(filter.size() == 1);
  vector<Participant> filter2 = ctrl->filterByGivenName("b");
  assert(filter2.size() == 0);
}

void test_filterByFamilyName(Controller *ctrl) {
  //vector<Participant> filterByFamilyName(string familyName);
  vector<Participant> filter = ctrl->filterByFamilyName("b");
  assert(filter.size() == 1);
  vector<Participant> filter2 = ctrl->filterByFamilyName("c");
  assert(filter2.size() == 0);
}

void test_filterByScore(Controller *ctrl) {
  //vector<Participant> filterByScore(float score);
  vector<Participant> filter = ctrl->filterByScore(10);
  assert(filter.size() == 1);
  vector<Participant> filter2 = ctrl->filterByScore(11);
  assert(filter2.size() == 0);
}

void test_undoLastOperation(Controller *ctrl) {
  //void undoLastOperation();
  ctrl->addParticipant("a", "b", 10);
  assert(ctrl->getParticipants().size() == 2);
  ctrl->undoLastOperation();
  assert(ctrl->getParticipants().size() == 1);
}

void test_controller() {
  Repository<Participant> *repo = new Repository<Participant>(NULL);
  Controller *ctrl = new Controller(repo);
  test_addParticipant(ctrl);
  test_updateParticipant(ctrl);
  test_removeParticiapnt(ctrl);
  test_filterByGivenName(ctrl);
  test_filterByFamilyName(ctrl);
  test_filterByScore(ctrl);
  test_undoLastOperation(ctrl);
}
