/* TRABALHO ESTUDO DIRIGIDO 5
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#ifndef __BANCO_H__
#define __BANCO_H__

#include <iostream>
#include <string>

#include "Conta.h"

class Banco {

public:

	Banco(int capacidade_banco) {
		if (capacidade_banco <= 0) {
			std::cout << "Tamanho invalido para o banco" << std::endl;
			return;
		}

		_capacidade_banco = capacidade_banco;
		_qtd_contas = 0;

		_contas = new Conta*[capacidade_banco];

		std::cout << "\nBanco inicializado com sucesso!" << std::endl;
	}

	~Banco() {
		for (int i = 0; i < _capacidade_banco; i++) {
			delete _contas[i];
		}

		delete[] _contas;
	}

	void imprime_contas() const {
		std::cout << "\nImprimindo contas do banco!" << std::endl;

		for (int i = 0; i < _qtd_contas; i++) {
			std::cout << "\nSaldo da conta " << (i + 1) << ":" << std::endl;
			_contas[i]->imprimeSaldo();
		}
	}

	void setConta(Conta* conta) {
		if (_qtd_contas >= _capacidade_banco) {
			std::cout << "\nNao e possivel adicionar mais contas a esse banco!" << std::endl;
			return;
		}

		_contas[_qtd_contas++] = conta;
		
		std::cout << "\nConta adicionada com sucesso!" << std::endl;
	}


private:
	int _capacidade_banco;
	int _qtd_contas;

	Conta** _contas;
};

#endif