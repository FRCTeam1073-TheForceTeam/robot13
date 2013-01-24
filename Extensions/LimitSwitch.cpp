#include "LimitSwitch.h"
LimitSwitch::LimitSwitch(int CHANNEL): 
	DigitalInput(CHANNEL){}
bool LimitSwitch::IsPressed(){
	return Get() == 1;
}
