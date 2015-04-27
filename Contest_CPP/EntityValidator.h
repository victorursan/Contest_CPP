//
//  ParticipantFileRepository.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/27/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef ENTITYVALIDATOR_H_
#define ENTITYVALIDATOR_H_

template<class Entity>
class EntityValidator {
public:
  virtual ~EntityValidator() {}
  virtual void validate(const Entity&) const=0;
};

#endif /* ENTITYVALIDATOR_H_ */
