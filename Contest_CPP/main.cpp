//
//  main.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include <iostream>
#include "Console.h"
#include <vector>

int main(int argc, const char * argv[]) {
  Repository *repo = new Repository();
  Controller *ctrl = new Controller(*repo);
  Console *console = new Console(ctrl);
  console->run();
}