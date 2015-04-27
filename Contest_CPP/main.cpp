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
#include "Validator.h"
#include "ParticipantFileRepository.h"

int main(int argc, const char * argv[]) {
  //  test_main();
  EntityValidator<Participant>* validator = new ParticipantValidator;
  ParticipantFileRepository *repo = new ParticipantFileRepository(validator, "Participant.txt");
  Controller *ctrl = new Controller(repo);
  Console *console = new Console(ctrl);
  console->run();

  return 0;
}