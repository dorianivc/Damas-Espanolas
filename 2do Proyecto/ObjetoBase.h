#ifndef OBJETOBASE
#define OBJETOBASE
#include <string>
#include <sstream>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
class ObjetoBase
{
	virtual string serializar() = 0;

};
#endif // !OBJETOBASE
