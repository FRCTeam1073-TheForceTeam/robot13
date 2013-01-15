#include "KillCommandCommand.h"
KillCommandCommand::KillCommandCommand(Command* command) {command->Cancel();}
void KillCommandCommand::Initialize() {}
void KillCommandCommand::Execute() {}
bool KillCommandCommand::IsFinished() {return true;}
void KillCommandCommand::End() {}
void KillCommandCommand::Interrupted() {}