#include <vector>
#include "plugins/TwinProcessor/Reader.h"
#include <string>
using namespace std;

#ifndef _TwinProcessor
#define _TwinProcessor

class TwinProcessor{
	bool m_started;
	char*m_configurationFile;
	vector<string> m_files;
	vector<string> m_commandParts;
	bool m_parsedArguments;
	Reader m_reader;
	int m_fileNumber;
	bool m_processedSequencesStarted;
	bool m_processedSequences;
	bool m_finished;
	bool m_openedFile;
	void __pumpFileName(int i);
	void parseCommands();
	void __processSequences();

public:
	void call_SLAVE_BUILD_TWINS();
	void assignRunTimeInformation(int argc,char**argv);

	bool hasNextInstruction();

};

#endif
