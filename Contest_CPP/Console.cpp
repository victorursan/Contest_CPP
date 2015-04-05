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

int get_number(string msg) {
  char c[16];
  int res = -1;
  int flag = 0;
  while (flag == 0) {
    cout<<msg;
    scanf("%16s", c);
    flag = sscanf(c, "%d", &res) == 1;
    if (flag == 0) {
      printf("Error reading number!\r\n");
    }
  }
  return res;
}


void options() {
  cout<<"Menu\n____\n";
  cout<<"1. All Participants" << endl;
  cout<<"2. Add Participant" << endl;
  cout<<"3. Remove Participant" << endl;
  cout<<"4. Update Participant" << endl;
  cout<<"5. Filter Participants by given name" << endl;
  cout<<"6. Filter Participants by family name" << endl;
  cout<<"7. Filter Participants by score" << endl;
  cout<<"0. Exit" << endl;
}

void Console::print_all_participants() {
  vector<Participant> participants = ctrl->getParticipants();
  for (vector<Participant>::size_type i = 0; i < participants.size(); i++) {
    cout<< i << ". "<< participants[i];
  }
}

void Console::add_participant() {
  string givenName, familyName;
  float score;
  cout << "Given name: ";
  cin >> givenName;
  cout << "Family name: ";
  cin >> familyName;
  cout << "Score: ";
  cin >> score;
  cin.clear();
  ctrl->addParticipant(givenName, familyName, score);
}

void Console::remove_participant() {
  int position;
  position = get_number("Position: ");
  ctrl->removeParticipant(position);
}

void Console::update_participant() {
  int position;
  string givenName, familyName;
  float score;
  position = get_number("Position: ");
  cout << "Given name: ";
  cin >> givenName;
  cout << "Family name: ";
  cin >> familyName;
  cout << "Score: ";
  cin >> score;
  cin.clear();
  ctrl->updateParticipant(position, givenName, familyName, score);
}

void Console::filter_participants_by_given_name() {
  string givenName;
  cout << "Given name: ";
  cin >> givenName;
  vector<Participant> participants = ctrl->filterByGivenName(givenName);
  cout<< participants.size() << endl;
  for (vector<Participant>::size_type i = 0; i < participants.size(); i++) {
    cout<< i << ". "<< participants[i];
  }
}

void Console::filter_participants_by_family_name() {
  string familyName;
  cout << "Family name: ";
  cin >> familyName;
  vector<Participant> participants = ctrl->filterByFamilyName(familyName);
  cout<< participants.size()<< endl;
  for (vector<Participant>::size_type i = 0; i < participants.size(); i++) {
    cout<< i << ". "<< participants[i];
  }
}

void Console::filter_participants_by_score() {
  float score;
  cout << "Score: ";
  cin >> score;
  cin.clear();
  vector<Participant> participants = ctrl->filterByScore(score);
  cout<< participants.size()<< endl;
  for (vector<Participant>::size_type i = 0; i < participants.size(); i++) {
    cout<< i << ". "<< participants[i];
  }
}

void Console::run() {
  while (true) {
    options();
    int k = get_number("");
    switch (k) {
      case 0:
        return;
        break;
      case 1:
        print_all_participants();
        break;
      case 2:
        add_participant();
        break;
      case 3:
        print_all_participants();
        remove_participant();
        break;
      case 4:
        print_all_participants();
        update_participant();
        break;
      case 5:
        filter_participants_by_given_name();
        break;
      case 6:
        filter_participants_by_family_name();
        break;
      case 7:
        filter_participants_by_score();
        break;
      default:
        break;
    }
  }
}
