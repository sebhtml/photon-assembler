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


#include <iostream>
#include "plugins/TwinProcessor/Reader.h"
using namespace std;

void Reader::open(string*file){

	m_reader=&m_fastq;

	m_reader->open(file);
}


bool Reader::hasNext(){
	return m_reader->hasNext();
}

void Reader::getNext(Sequence*sequence){
	m_reader->getNext(sequence);
}

void Reader::close(){
	m_reader->close();
}

