//
//  Console.h
//  Contest_CPP
//
//  Created by Victor Ursan on 4/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef __Contest_CPP__Console__
#define __Contest_CPP__Console__

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include "Controller.h"
#include "Repository.h"
#include "Participant.h"

using namespace std;

class Console {
  Controller *ctrl;

public:
  Console(Controller* ctrl);
  ~Console();

  void run();
};

#endif /* defined(__Contest_CPP__Console__) */
