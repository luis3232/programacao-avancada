/* TRABALHO REPESCAGEM
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#ifndef __IMPRIMIVEL_H__
#define __IMPRIMIVEL_H__

#include <sstream>
#include <string>

class Imprimivel {

public:

	Imprimivel() {
	
	}

	virtual void imprime() = 0;
};

#endif