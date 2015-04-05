//
//  Controller.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "Controller.h"

Controller::Controller(Repository repo) {
  this->repository = repo;
}

Controller::~Controller() {
  delete &repository;
  delete this;
}

vector<Participant> Controller::getParticipants(){
  return repository.getAll();
}

void Controller::addParticipant(string givenName, string familyName, float score) {
  Participant p(givenName, familyName, score);
  repository.save(p);
}

void Controller::updateParticipant(int id, string givenName, string familyName, float score) {
  Participant p(givenName, familyName, score);
  repository.update(id, p);
}

void Controller::removeParticipant(int id) {
  repository.remove(id);
}

vector<Participant> Controller::filterByGivenName(string givenName) {
  vector<Participant> toFilter = repository.getAll();
  vector<Participant> filtered;
  for (vector<Participant>::iterator p = toFilter.begin(); p != toFilter.end(); ++p) {
    if (p->getGivenName() == givenName) {
      filtered.push_back(*p);
    }
  }
  return filtered;
}

vector<Participant> Controller::filterByFamilyName(string familyName) {
  vector<Participant> toFilter = repository.getAll();
  vector<Participant> filtered;
  for (vector<Participant>::iterator p = toFilter.begin(); p != toFilter.end(); ++p) {
    if (p->getFamilyName() == familyName) {
      filtered.push_back(*p);
    }
  }
  return filtered;
}

vector<Participant> Controller::filterByScore(float score) {
  vector<Participant> toFilter = repository.getAll();
  vector<Participant> filtered;
  for (vector<Participant>::iterator p = toFilter.begin(); p != toFilter.end(); ++p) {
    if (p->getScore() == score) {
      filtered.push_back(*p);
    }
  }
  return filtered;
}
