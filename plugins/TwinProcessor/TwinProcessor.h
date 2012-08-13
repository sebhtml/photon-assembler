/*
 	photon -- a distributed de novo assembler for long erroneous Pacific Biosciences reads
    Copyright (C) 2012  Sébastien Boisvert


    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You have received a copy of the GNU General Public License
    along with this program (gpl-3.0.txt).  
	see <http://www.gnu.org/licenses/>
*/



#include <vector>
#include "plugins/TwinProcessor/Reader.h"
#include "plugins/TwinProcessor/TwinData.h"
#include <string>
using namespace std;

#ifndef _TwinProcessor
#define _TwinProcessor

class TwinProcessor{
	TwinData m_twinData;
	bool m_started;
	char*m_configurationFile;
	vector<string> m_files;
	vector<string> m_commandParts;
	bool m_parsedArguments;
	int m_sequences;
	Reader m_reader;
	int m_fileNumber;
	bool m_processedSequencesStarted;
	bool m_processedSequences;
	bool m_finished;
	bool m_openedFile;
	void __pumpFileName(int i);
	void parseCommands();
	void __processSequences();
	int m_period;
	int m_sequencesInFile;
	void printProcessedSequences();

public:
	void call_SLAVE_BUILD_TWINS();
	void assignRunTimeInformation(int argc,char**argv);

	bool hasNextInstruction();

};

#endif
