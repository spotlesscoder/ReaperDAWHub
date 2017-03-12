#pragma once
#include "IEntity.h"

class Entity : IEntity {
public:
	void setId(long id) override;
	long getId() override;

private:
	long id;
};