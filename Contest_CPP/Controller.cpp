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

//  Participant findParticipantWithId(int id);
//  Participant findParticipantWithGivenName(string givenName);
//  Participant findParticipantWithFamilyName(string familyName);

vector<Participant> Controller::filterByGivenName(string givenName) {
  vector<Participant> toFilter;
  for (vector<Participant>::iterator p = repository.getAll().begin(); p != repository.getAll().end(); ++p) {
    if (p->getGivenName() == givenName) {
      toFilter.push_back(*p);
    }
  }
  return toFilter;
}

vector<Participant> Controller::filterByFamilyName(string familyName) {
  vector<Participant> toFilter;
  for (vector<Participant>::iterator p = repository.getAll().begin(); p != repository.getAll().end(); ++p) {
    if (p->getFamilyName() == familyName) {
      toFilter.push_back(*p);
    }
  }
  return toFilter;
}

vector<Participant> Controller::filterByScore(float score) {
  vector<Participant> toFilter;
  for (vector<Participant>::iterator p = repository.getAll().begin(); p != repository.getAll().end(); ++p) {
    if (p->getScore() == score) {
      toFilter.push_back(*p);
    }
  }
  return toFilter;
}
