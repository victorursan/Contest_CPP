//
//  Repository.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "Repository.h"
#include "Validator.h"

template <typename T>
Repository<T>::Repository() {
  /* Initializes repository
   */
  //  EntityValidator<Participant>* validator = new ParticipantValidator;
  this->validator = new ParticipantValidator;
  store.resize(0);
}

template <typename T>
Repository<T>::Repository(EntityValidator<T> *validator) {
  store.resize(0);
  this->validator = validator;
}

template <typename T>
Repository<T>::~Repository() {
  /* Destroy repository
   */
  //  delete this;
}

template <typename T>
vector<T> Repository<T>::getAll() {
  /* Get all the elemts

   returns: a vector with all the elements
   */
  return this->store;
}

template <typename T>
void Repository<T>::save(T p) throw (MyException) {
  /* Save a element

   param: p - add a element of type T to the repository
   */
  validator->validate(p);
  store.push_back(p);
}

template <typename T>
void Repository<T>::insertAtPosition(int id, T p) throw(MyException) {
  /* Insert a new element

   param: id - position of the element
   param: p - element to be saved
   */
  if(id >= store.size()){
    throw MyException("Index error");
  } else {
    validator->validate(p);
    store.insert(store.begin() + id, p);
  }
}

template <typename T>
void Repository<T>::update(int id, T p) throw(MyException) {
  /* Update the repository

   param: id - position to be updated
   param: p - element to replace
   */
  if(id >= store.size()){
    throw MyException("Index error");
  } else {
    validator->validate(p);
    store[id] = p;
  }
}

template <typename T>
void Repository<T>::remove(int id) throw(MyException) {
  /* Remove element at position

   param: id - position from where to remove an element
   */
  if(id >= store.size()){
    throw MyException("Index error");
  } else {
    store.erase(store.begin() + id);
  }
}

template <typename T>
const T Repository<T>::findById(int id) throw (MyException) {
  /* Find element at position

   param: id - position of the element

   returns: element at the position id
   */
  if(id >= store.size()){
    throw MyException("Index error");
  } else {
    return store[id];
  }
}

template <class T>
int Repository<T>::size() {
  /* The size of the Repository

   returns: the size of the repository
   */
  return (int)store.size();
}
