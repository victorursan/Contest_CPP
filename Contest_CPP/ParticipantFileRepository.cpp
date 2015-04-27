//
//  ParticipantFileRepository.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/27/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "ParticipantFileRepository.h"
#include "Repository.cpp"

void ParticipantFileRepository::save(Participant p) throw (MyException) {
  Repository<Participant>::save(p);
  ofstream fout(filename.c_str(), ios::app);
  fout << p;
  fout.close();
}

void ParticipantFileRepository::loadEntities() {
  string line { };
  ifstream fin(filename.c_str());
  if (!fin.is_open()) {
    throw RepositoryException("could not open file");
  }
  while (fin.good()) {
    Participant p { };
    fin >> p;
    if (p.getGivenName() != "") {
      Repository<Participant>::save(p);
    }
  }
  fin.close();
}

void ParticipantFileRepository::insertAtPosition(int id, Participant p) throw(MyException) {
  Repository<Participant>::insertAtPosition(id, p);
  ofstream fout(filename.c_str(), ios::out);
  for(int i = 0; i < this->size(); i++) {
    Participant p = this->findById(i);
    fout << p;
  }
  fout.close();  fout.close();
}

void ParticipantFileRepository::update(int id, Participant p) throw(MyException) {
  Repository<Participant>::update(id, p);
  ofstream fout(filename.c_str(), ios::out);
  for(int i = 0; i < this->size(); i++) {
    Participant p = this->findById(i);
    fout << p;
  }
  fout.close();
}

void ParticipantFileRepository::remove(int id) throw(MyException) {
  Repository<Participant>::remove(id);
  ofstream fout(filename.c_str(), ios::out);
  for(int i = 0; i < this->size(); i++) {
    Participant p = this->findById(i);
    fout << p;
  }
  fout.close();
}
