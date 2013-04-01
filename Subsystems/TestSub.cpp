#include "TestSub.h"
#include "../Commands/TestCommand.h"
TestSub::TestSub() : Subsystem("Test Subsystem"){
	puts("test sub construcfftor");
}
void TestSub::InitDefaultCommand(){
	puts("in robot init default cmd");
	SetDefaultCommand(new TestCommand());
}
void TestSub::Print(){
puts("executing");
}
