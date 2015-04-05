//
//  Console.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "Console.h"


Console::Console(Controller* ctrl) {
  this->ctrl = ctrl;
}

Console::~Console() {
  delete this->ctrl;
  delete this;
}

void options() {
  cout<<"Menu";
  cout<<"1. All Participants" << endl;
  cout<<"2. Add Participant" << endl;
  cout<<"3. Remove Participant" << endl;
  cout<<"4. Update Participant" << endl;
  cout<<"5. Filter Participants by given name" << endl;
  cout<<"6. Filter Participants by family name" << endl;
  cout<<"7. Filter Participants by score" << endl;
  cout<<"8. Filter Participants by given name" << endl;

}


void Console::run() {
  cout<<"Hellow Console";

}
