
#include "plugins/TwinProcessor/TwinProcessor.h"

int main(int argc,char**argv){

	TwinProcessor code;

	code.assignRunTimeInformation(argc,argv);

	while(code.hasNextInstruction())
		code.call_SLAVE_BUILD_TWINS();

	return 0x00000000;
}
