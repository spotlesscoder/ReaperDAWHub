#pragma once
class IEntity {

public:
	virtual long getId() = 0;
	virtual void setId(long id) { return; };
};