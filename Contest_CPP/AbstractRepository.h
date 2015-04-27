//
//  ParticipantFileRepository.cpp
//  Contest_CPP
//
//  Created by Victor Ursan on 4/27/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef ABSTRACTREPOSITORY_H_
#define ABSTRACTREPOSITORY_H_

template<class Entity>
class AbstractRepository {
public:
	virtual void save(Entity e)=0;
	virtual void remove(int id)=0;
	virtual void update(int id, Entity entity)=0;
	virtual std::vector<Entity> getAll()=0;
  virtual int size()=0;
  virtual void insertAtPosition(int id,Entity p)=0;
  virtual const Entity findById(int id)=0;
	virtual ~AbstractRepository() {
	}
};

#endif /* ABSTRACTREPOSITORY_H_ */
