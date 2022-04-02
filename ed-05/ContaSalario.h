/* TRABALHO ESTUDO DIRIGIDO 5
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#ifndef __CONTA_SALARIO_H__
#define __CONTA_SALARIO_H__

#include <sstream>
#include <string>

#include "Conta.h"
#include "Investimento.h"

class ContaSalario : public Conta {

public:

	ContaSalario(std::string numero, std::string agencia, Cliente* cliente) : Conta(numero, agencia, cliente) {}
};

#endif