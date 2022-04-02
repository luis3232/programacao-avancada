/* TRABALHO ESTUDO DIRIGIDO 5
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#ifndef __INVESTIMENTO_H__
#define __INVESTIMENTO_H__

#include <iostream>

class Investimento {

public:

	Investimento(float taxajuros) : _taxajuros(taxajuros) {}

	float getTaxaJuros () const {
		return _taxajuros;
	}

	void imprime_taxas() const {
		std::cout << "\nImprimindo detalhes do investimento!" << std::endl;

		std::cout << "\nA taxa de juros para esta conta e de: " << _taxajuros << std::endl;
	}

private:

	float _taxajuros;
};

#endif