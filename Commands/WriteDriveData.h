#ifndef WRITEDRIVEDATA_H
#define WRITEDRIVEDATA_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class WriteDriveData: public Command {
public:
	static int count;
	WriteDriveData();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	FILE* file;
	static const char* name;
};

#endif
