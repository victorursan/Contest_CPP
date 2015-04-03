//
//  Participant.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "Participant.h"

Participant::Participant(const string &givenName, const string &familyName, const float& score) {
  this->givenName = givenName;
  this->familyName = familyName;
  this->score = score;
}

Participant::~Participant() {
  //destroy shit up
}

string Participant::getGivenName() const {
  return givenName;
}

void Participant::setGivenName(string &givenName) {
  this->givenName = givenName;
}

string Participant::getFamilyName() const {
  return familyName;
}

void Participant::setFamilyName(string &familyName) {
  this->familyName = familyName;
}

float Participant::getScore() const {
  return score;
}

void Participant::setScore(float score) {
  this->score = score;
}

bool Participant::operator ==(const Participant& other) const {
  return givenName == other.givenName && familyName == other.familyName;
}

bool Participant::operator !=(const Participant& other) const {
  return !(*this == other);
}

ostream& operator <<(ostream& os, const Participant& p) {
  os << p.getGivenName() << " " << p.getFamilyName() << ": " << p.getScore() << "\n";
  return os;
}

istream& operator >>(istream &is, Participant& p) {
  string givenName, familyName;
  float score;

  is >> givenName >> familyName >> score;
  p.setGivenName(givenName);
  p.setFamilyName(familyName);
  p.setScore(score);

  return is;
}
