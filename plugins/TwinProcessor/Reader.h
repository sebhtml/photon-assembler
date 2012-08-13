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



#ifndef _Reader
#define _Reader

#include <string>
#include "plugins/TwinProcessor/Sequence.h"
#include "plugins/TwinProcessor/ReaderImplementation.h"
#include "plugins/TwinProcessor/ReaderImplementationFastq.h"

using namespace std;

class Reader{

	ReaderImplementationFastq m_fastq;
	ReaderImplementation*m_reader;

public:
	void open(string*file);

	bool hasNext();

	void getNext(Sequence*sequence);

	void close();
};

#endif

