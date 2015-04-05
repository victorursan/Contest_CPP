//
//  Repository.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "Repository.h"

Repository::Repository() {
  store.resize(0);
}

Repository::~Repository() {
//  delete this;
}

vector<Participant> Repository::getAll() {
  return this->store;
}

void Repository::save(Participant p) {
  store.push_back(p);
}

void Repository::insertAtPosition(int id, Participant p) {
  store.insert(store.begin() + id, p);
}

void Repository::update(int id, Participant p) {
  store[id] = p;
}

void Repository::remove(int id) {
  store.erase(store.begin() + id);
}

const Participant Repository::findById(int id) {
  return store[id];
}

int Repository::size() {
  return (int)store.size();
}
