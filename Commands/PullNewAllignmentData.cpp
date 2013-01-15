#include "PullNewAllignmentData.h"
PullNewAllignmentData::PullNewAllignmentData() {Requires(Robot::allignmentData);}
void PullNewAllignmentData::Initialize() {}
void PullNewAllignmentData::Execute() {Robot::allignmentData->Refresh();}
bool PullNewAllignmentData::IsFinished() {return false;}
void PullNewAllignmentData::End() {}
void PullNewAllignmentData::Interrupted() {}
