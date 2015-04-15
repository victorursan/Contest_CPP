//
//  Controller.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "Controller.h"

Controller::Controller(Repository<Participant> repo) {
  /* Initializes Controller
   */
  this->repository = repo;
}

Controller::~Controller() {
  /* Destroy Controller
   */
  //  delete &repository;
  //  delete this;
}

vector<Participant> Controller::getParticipants(){
  /* Get all the participants

   returns: all the participants
   */
  return repository.getAll();
}

void Controller::addParticipant(string givenName, string familyName, float score) {
  /* Add a participant

   param: givenName - a string with a given name
   param: familyName - a string with a family name
   param: score - a float with the score
   */
  Participant p(givenName, familyName, score);
  UndoParticipant undo = UndoParticipant(repository.size(), 1, p);
  undo_participants.push_back(undo);
  repository.save(p);
}

void Controller::updateParticipant(int id, string givenName, string familyName, float score) {
  /* Update a participant

   param: id - the position of the participant
   param: givenName - a string with a given name
   param: familyName - a string with a family name
   param: score - a float with the score
   */
  Participant p(givenName, familyName, score);
  UndoParticipant undo = UndoParticipant(id, 3, p);
  undo_participants.push_back(undo);
  repository.update(id, p);
}

void Controller::removeParticipant(int id) {
  /* Remove a participant

   param: id - the position from where to remove
   */
  Participant p = repository.findById(id);
  UndoParticipant undo = UndoParticipant(id, 2, p);
  undo_participants.push_back(undo);
  repository.remove(id);
}

vector<Participant> Controller::filterByGivenName(string givenName) {
  /* Filter participants by given name
   
   param: givenName - the name for which to filter
   
   returns: a filtered vector
   */
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
  /* Filter participants by family name

   param: familyName - the name for which to filter

   returns: a filtered vector
   */

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
  /* Filter participants by score

   param: score - the score for which to filter

   returns: a filtered vector
   */

  vector<Participant> toFilter = repository.getAll();
  vector<Participant> filtered;
  for (vector<Participant>::iterator p = toFilter.begin(); p != toFilter.end(); ++p) {
    if (p->getScore() == score) {
      filtered.push_back(*p);
    }
  }
  return filtered;
}

void Controller::undoLastOperation() {
  /* Undo last operation
   */
  UndoParticipant undo = undo_participants.back();
  int op = undo.getOperation();
  switch (op) {
    case 1:
      repository.remove(undo.getPosition());
      break;
    case 2:
      repository.insertAtPosition(undo.getPosition(), undo.getParticipant());
      break;
    case 3:
      repository.update(undo.getPosition(), undo.getParticipant());
      break;
    default:
      break;
  }
  undo_participants.pop_back();
}