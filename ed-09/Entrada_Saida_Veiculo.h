/* ED 09 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA 

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __ENTRADA_SAIDA_VEICULOS_H__
#define __ENTRADA_SAIDA_VEICULOS_H__

#include <string>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

#include "Cliente.h"

class Entrada_Saida_Veiculo {
public:

	Entrada_Saida_Veiculo(long clienteID = 0, 
		std::string tipo_Veiculo = "", int vaga = 0, std::string placa = "", std::string carro = "", std::string cor_carro = "",
		tm* dt_entrada = nullptr, tm* dt_saida = nullptr, tm* tempo_total = nullptr, std::string tipopagamento = "",
		float valor = 0.0) :
		ClienteID(clienteID),
		Tipo_Veiculo(tipo_Veiculo),
		Vaga(vaga),
		Dt_Entrada(dt_entrada),
		Dt_Saida(dt_saida),
		Tempo_Total(tempo_total),
		TipoPagamento(tipopagamento),
		Valor(valor) {
		isFinalizado = false;
	}

	const long& getID() const {
		return ID;
	}
	const int& getVaga() const {
		return Vaga;
	}

	void setVaga(const int& vaga) {
		Vaga = vaga;
	}

	const std::string& getPlaca() const {
		return Placa;
	}

	void setPlaca(const std::string& placa) {
		Placa = placa;
	}

	const std::string& getCarro() const {
		return Carro;
	}

	void setCarro(const std::string& carro) {
		Carro = carro;
	}

	const std::string& getCor_Carro() const {
		return Cor_Carro;
	}

	void setCor_Carro(const std::string& cor_Carro) {
		Cor_Carro = cor_Carro;
	}

	const tm* getDt_Entrada() const {
		return Dt_Entrada;
	}

	void setDt_Entrada(const tm* dt_entrada) {
		*Dt_Entrada = *dt_entrada;
	}

	const tm* getDt_Saida() const {
		return Dt_Saida;
	}

	void setDt_Saida(const tm* dt_Saida) {
		*Dt_Saida = *dt_Saida;
		isFinalizado = true;
	}

	const tm* getTempo_Total() const {
		return Tempo_Total;
	}

	void setTempo_Total(const tm* tempo_total) {
		*Tempo_Total = *tempo_total;
	}

	const std::string& getTipoPagamento() const {
		return TipoPagamento;
	}

	void setTipoPagamento(const std::string& tipoPagamento) {
		TipoPagamento = tipoPagamento;
	}

	const std::string& getTipoVeiculo() const {
		return Tipo_Veiculo;
	}

	void setTipoVeiculo(const std::string& tipoVeiculo) {
		Tipo_Veiculo = tipoVeiculo;
	}

	const float& getValor() const {
		return Valor;
	}

	void setValor(const float& valor) {
		Valor = valor;
	}

	std::string getNomeCliente(std::vector<Cliente>& lista) const {

		if (this->getClienteID() < 0) {
			return "";
		}

		std::string nome = "";

		for (int i = 0; i < lista.size(); i++) {
			if (lista[i].getID() == this->getClienteID()) {
				nome = lista[i].getNome();
			}
		}

		return nome;
	}

	long getClienteID() const {
		return this->ClienteID;
	}

	bool getIsFinalizado() const {
		return this->isFinalizado;
	}

	virtual ~Entrada_Saida_Veiculo() {}

private:
	long ID;
	long ClienteID;
	std::string Tipo_Veiculo;
	int Vaga;
	std::string Placa;
	std::string Carro;
	std::string Cor_Carro;
	tm* Dt_Entrada;
	tm* Dt_Saida;
	tm* Tempo_Total;
	std::string TipoPagamento;
	float Valor;
	bool isFinalizado;
};

#endif