//
//  main.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include <iostream>
#include "Participant.h"

int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  Participant *p = new Participant;
  cin >> *p;
  cout << *p;
  return 0;
}