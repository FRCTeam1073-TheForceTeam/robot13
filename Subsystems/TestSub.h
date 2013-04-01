#ifndef TEST_SUB_H
#define TEST_SUB_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
class TestSub : public Subsystem{
public:
	TestSub();
	void InitDefaultCommand();
	void Print();
};
#endif
