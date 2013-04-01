#include "TestCommand.h"
TestCommand::TestCommand(){
	puts("test command constructed");
	Requires(Robot::testSub);
}
void TestCommand::Initialize(){
	puts("test command init");
}
void TestCommand::Execute(){
	Robot::testSub->Print();
}
bool TestCommand::IsFinished(){
	return false;
}
void TestCommand::End(){
	puts("test command end");
}
void TestCommand::Interrupted(){
	puts("test command interrupted");
}