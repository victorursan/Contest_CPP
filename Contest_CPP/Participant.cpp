//
//  Participant.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "Participant.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>

Participant::Participant(const string &givenName, const string &familyName, const float& score) {
  /* Initialize a Participant
   
   param: givenName - the given name of the participant
   param: familyName - the family name of the participant
   param: score - the score of the participant
   */
  this->givenName = givenName;
  this->familyName = familyName;
  this->score = score;
}

Participant::~Participant() {
  /* Destroy a Participant
   */
//  delete this;
}

string Participant::getGivenName() const {
  /* Get the given name of the Participant
   
   returns: the given name
   */
  return givenName;
}

void Participant::setGivenName(string &givenName) {
  /* Set the given name of the Participant

   param: givenName - the given name
   */
  this->givenName = givenName;
}

string Participant::getFamilyName() const {
  /* Get the family name of the Participant

   returns: the family name
   */
  return familyName;
}

void Participant::setFamilyName(string &familyName) {
  /* Set the family name of the Participant

   param: familyName - the family name
   */
  this->familyName = familyName;
}

float Participant::getScore() const {
  /* Get the score of the Participant

   returns: the score
   */
  return score;
}

void Participant::setScore(float score) {
  /* Set the score of the Participant

   param: scpre - the score
   */
  this->score = score;
}

bool Participant::operator ==(const Participant& other) const {
  /* Checks if two participants are the same
   
   param: other - the other Participant
   */
  return givenName == other.givenName && familyName == other.familyName && score == other.score;
}

bool Participant::operator !=(const Participant& other) const {
  /* Checks if two participants are different

   param: other - the other Participant
   */
  return !(*this == other);
}

ostream& operator <<(ostream& os, const Participant& p) {
  /* Prints a Participant
   */
  os << p.getGivenName() << " " << p.getFamilyName() << ": " << p.getScore() << "\n";
  return os;
}

istream& operator >>(istream &is, Participant& p) {
  /* Reads a Participant
   */
  string givenName, familyName;
  float score;

  is >> givenName >> familyName >> score;
  p.setGivenName(givenName);
  p.setFamilyName(familyName);
  p.setScore(score);

  return is;
}
