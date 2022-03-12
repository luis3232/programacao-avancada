/* TRABALHO ESTUDO DIRIGIDO 2
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#ifndef __CONTA_H__
#define __CONTA_H__

#include <sstream>
#include <string>

#include "Cliente.h"

class Conta {

public:

	Conta() {

	}

	Conta(std::string numero, std::string agencia, Cliente cliente) :
		_numero(numero), _agencia(agencia), _cliente(cliente) {
		std::cout << "\nCriando conta do cliente " << _cliente.getNome() << "!" << std::endl;
	}

	void deposita(float valor) {
		if (valor > 0) {
			_saldo += valor;

			std::cout << "\nValor de " << this->getStringValue(valor) << " adicionado com sucesso!" << std::endl;
		}
		else {
			std::cout << "\nValor deve ser positivo!" << std::endl;
		}
	}

	void retira(float valor) {
		if (_saldo - valor < 0) {
			std::cout << "\nNao e possivel retirar a quantidade " << this->getStringValue(valor) 
				<< ", o saldo atual e de: " << _saldo << std::endl;
		}
		else {
			_saldo -= valor;

			std::cout << "\nValor de " << this->getStringValue(valor) << " retirado com sucesso!" << std::endl;
		}
	}

	void alteraCliente(Cliente cliente) {

		std::string old_nome = _cliente.getNome();
		_cliente = cliente;

		std::cout << "\nCliente alterado com sucesso, de " << old_nome << " para " 
			<< _cliente.getNome() << "!" << std::endl;
	}

	void imprimeSaldo() const {
		std::cout << "\nConta: " << _numero << " / Cliente: " << _cliente.getNome() << std::endl;
		std::cout << "Saldo: " << _saldo << std::endl;
	}

	std::string getStringValue(int x) const
	{
		std::string str;

		std::stringstream ss;
		ss << x;
		ss >> str;

		return str;
	}

private:

	std::string _agencia, _numero;
	float _saldo;

	Cliente _cliente;
};

#endif