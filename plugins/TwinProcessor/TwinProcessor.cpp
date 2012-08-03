
#include <string.h>
#include <fstream>
#include <iostream>
#include "plugins/TwinProcessor/TwinProcessor.h"
#include "plugins/TwinProcessor/Reader.h"
#include "plugins/TwinProcessor/Sequence.h"
using namespace std;

#define __OPERATION_CODE_READ_FILE "ReadDataFile"
#define MATCH 0x000000

void TwinProcessor::__pumpFileName(int i){
	
	#ifdef VERBOSE_PARSING
	cout<<"Origin= "<<i<<endl;
	#endif

	string file="";

	if(i+1<(int)m_commandParts.size())
		file=m_commandParts[i+1];

	if(file!=""){

		#ifdef VERBOSE_PARSING
		cout<<"Found op. code ReadDataFile"<<endl;
		cout<<" operand is "<<file<<endl;
		#endif

		m_files.push_back(file);
	}
}

void TwinProcessor::parseCommands(){

	#ifdef VERBOSE_PARSING
	for(int i=0;i<(int)m_commandParts.size();i++){

		const char*operationCode=m_commandParts[i].c_str();
		cout<<" Command part # "<<i<<" is "<<operationCode<<endl;
	}
	#endif

	for(int i=0;i<(int)m_commandParts.size();i++){


		const char*operationCode=m_commandParts[i].c_str();
		
		#ifdef VERBOSE_PARSING
		cout<<"Checking operation "<<i<<" / "<<operationCode<<endl;
		#endif

		if(strcmp(operationCode,__OPERATION_CODE_READ_FILE)== MATCH )
			__pumpFileName(i);
		
	}
}

void TwinProcessor::call_SLAVE_BUILD_TWINS(){

	if(!m_started){

		m_started=true;

		ifstream f(m_configurationFile);
		while(!f.eof()){
			string token;
			f>>token;

			m_commandParts.push_back(token);
		}



		m_parsedArguments=false;
	}else if(!m_parsedArguments){

	
		parseCommands();

		m_parsedArguments=true;

		m_processedSequences=false;

		m_processedSequencesStarted=false;

	}else if(!m_processedSequences){

		__processSequences();


	}else{
		m_finished=true;
	}
}

void TwinProcessor::assignRunTimeInformation(int argc,char**argv){
	if(argc!=2){
		cout<<"You must provide a configuration file, see photon.conf"<<endl;
		m_finished=true;
		return;
	}


	m_started=false;
	
	m_configurationFile=argv[1];

	m_finished=false;
}

bool TwinProcessor::hasNextInstruction(){
	return !m_finished;
}

void TwinProcessor::__processSequences(){

	if(!m_processedSequencesStarted){

		m_openedFile=false;
		m_fileNumber=0;

		m_processedSequencesStarted=true;

	}else if(m_fileNumber < (int) m_files.size()){

		if(!m_openedFile){
			m_reader.open(&(m_files[m_fileNumber]));

			m_openedFile=true;
		}

		if(m_reader.hasNext()){
			Sequence sequence;
			m_reader.getNext(&sequence);
		}else{
			m_reader.close();

			m_openedFile=false;
			m_fileNumber++;
		}

	}else{

		m_processedSequences=true;
	}
}
