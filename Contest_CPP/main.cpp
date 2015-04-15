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
#include "test_main.h"

int main(int argc, const char * argv[]) {
  test_main();
  Repository<Participant> *repo = new Repository<Participant>();
  Controller *ctrl = new Controller(*repo);
  Console *console = new Console(ctrl);
  console->run();
  return 0;
}