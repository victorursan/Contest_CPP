//
//  Repository.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "Repository.h"

template <typename T>
Repository<T>::Repository() {
  /* Initializes repository
   */
  store.resize(0);
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
void Repository<T>::save(T p) {
  /* Save a element
   
   param: p - add a element of type T to the repository
   */
  store.push_back(p);
}

template <typename T>
void Repository<T>::insertAtPosition(int id, T p) {
  /* Insert a new element

   param: id - position of the element
   param: p - element to be saved
   */
  store.insert(store.begin() + id, p);
}

template <typename T>
void Repository<T>::update(int id, T p) {
  /* Update the repository
   
   param: id - position to be updated
   param: p - element to replace
   */
  store[id] = p;
}

template <typename T>
void Repository<T>::remove(int id) {
  /* Remove element at position

   param: id - position from where to remove an element
   */
  store.erase(store.begin() + id);
}

template <typename T>
const T Repository<T>::findById(int id) {
  /* Find element at position
   
   param: id - position of the element
   
   returns: element at the position id
   */
  return store[id];
}

template <class T>
int Repository<T>::size() {
  /* The size of the Repository
   
   returns: the size of the repository
   */
  return (int)store.size();
}
