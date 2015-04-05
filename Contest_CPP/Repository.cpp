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
  store.resize(0);
}

template <typename T>
Repository<T>::~Repository() {
//  delete this;
}

template <typename T>
vector<T> Repository<T>::getAll() {
  return this->store;
}

template <typename T>
void Repository<T>::save(T p) {
  store.push_back(p);
}

template <typename T>
void Repository<T>::insertAtPosition(int id, T p) {
  store.insert(store.begin() + id, p);
}

template <typename T>
void Repository<T>::update(int id, T p) {
  store[id] = p;
}

template <typename T>
void Repository<T>::remove(int id) {
  store.erase(store.begin() + id);
}

template <typename T>
const T Repository<T>::findById(int id) {
  return store[id];
}

template <class T>
int Repository<T>::size() {
  return (int)store.size();
}
