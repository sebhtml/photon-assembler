

#ifndef _Reader
#define _Reader

#include <string>
#include "plugins/TwinProcessor/Sequence.h"

using namespace std;

class Reader{

	bool m_hasNext;

public:
	void open(string*file);

	bool hasNext();

	void getNext(Sequence*sequence);

	void close();
};

#endif

