/* TRABALHO ESTUDO DIRIGIDO 5
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#ifndef __CONTA_CORRENTE_H__
#define __CONTA_CORRENTE_H__

#include <sstream>
#include <string>

#include "Conta.h"
#include "Investimento.h"

class ContaCorrente : public Conta, public Investimento {

public:

	ContaCorrente(std::string numero, std::string agencia, Cliente* cliente) : Conta(numero, agencia, cliente), Investimento(0.03) {}

	void aplicaJurosDiarios(int dias) {
		float juros = (Investimento::getTaxaJuros() * dias * Conta::getSaldo()) / 100;

		std::cout << "\n-- JUROS --" << std::endl;
		std::cout << "Juros: " << juros << std::endl;

		Conta::deposita(juros);
	}
};

#endif