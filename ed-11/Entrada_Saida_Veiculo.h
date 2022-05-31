/* ED 11 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#pragma warning(disable:4996)

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

	Entrada_Saida_Veiculo(long id = 1,  long clienteID = 0,
		std::string tipo_Veiculo = "", int vaga = 0, std::string placa = "", std::string carro = "", std::string cor_carro = "",
		std::string tipopagamento = "",
		float valor = 0.0) :
		ID(id),
		ClienteID(clienteID),
		Tipo_Veiculo(tipo_Veiculo),
		Vaga(vaga),
		TipoPagamento(tipopagamento),
		Placa(placa),
		Carro(carro),
		Cor_Carro(cor_carro),
		Valor(valor) {

		isFinalizado = false;

		std::time_t t = std::time(0);
		std::tm* now = std::localtime(&t);

		Dt_Entrada = new tm;
		Dt_Saida = new tm;

		Dt_Entrada->tm_year = now->tm_year;
		Dt_Entrada->tm_mon = now->tm_mon;
		Dt_Entrada->tm_mday = now->tm_mday;
		Dt_Entrada->tm_hour = now->tm_hour;
		Dt_Entrada->tm_min = now->tm_min;
	}

	~Entrada_Saida_Veiculo() {
	}

	void setID(const long& id) {
		ID = id;
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

	const std::string getDt_Entrada_Formatado() const {
		std::string aux = "";

		aux = std::to_string(Dt_Entrada->tm_mday) + '-'
			+ std::to_string(Dt_Entrada->tm_mon + 1) + '-'
			+ std::to_string(Dt_Entrada->tm_year + 1900) + " - "
			+ std::to_string(Dt_Entrada->tm_hour) + ":"
			+ std::to_string(Dt_Entrada->tm_min);

		return aux;
	}

	void setDt_Entrada(const tm* dt_entrada) {
		Dt_Entrada->tm_year = dt_entrada->tm_year;
		Dt_Entrada->tm_mon = dt_entrada->tm_mon;
		Dt_Entrada->tm_mday = dt_entrada->tm_mday;
		Dt_Entrada->tm_hour = dt_entrada->tm_hour;
		Dt_Entrada->tm_min = dt_entrada->tm_min;
	}

	const std::string getDt_Saida_Formatado() const {

		if (!isFinalizado) {
			return "Nao finalizado";
		}

		std::string aux = "";

		aux = std::to_string(Dt_Saida->tm_mday) + '-'
			+ std::to_string(Dt_Saida->tm_mon + 1) + '-'
			+ std::to_string(Dt_Saida->tm_year + 1900) + " - "
			+ std::to_string(Dt_Saida->tm_hour) + ":"
			+ std::to_string(Dt_Saida->tm_min);

		return aux;
	}

	void setDt_Saida(const tm* dt_Saida) {
		Dt_Saida->tm_year = dt_Saida->tm_year;
		Dt_Saida->tm_mon = dt_Saida->tm_mon;
		Dt_Saida->tm_mday = dt_Saida->tm_mday;
		Dt_Saida->tm_hour = dt_Saida->tm_hour;
		Dt_Saida->tm_min = dt_Saida->tm_min;
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

	void setClienteID(const long& id) {
		ClienteID = id;
	}

	long getClienteID() const {
		return this->ClienteID;
	}

	bool getIsFinalizado() const {
		return this->isFinalizado;
	}

	void setIsFinalizado(const bool& finalizado) {
		isFinalizado= finalizado;
	}

	bool alterarEntradaSaida(float valor) {

		this->Valor = valor;
		this->isFinalizado = true;

		std::time_t t = std::time(0);   // get time now

		this->setDt_Saida(std::localtime(&t));

		return true;
	}

	bool isPermiteCadastrarEntradaSaida(std::vector<Entrada_Saida_Veiculo>& lista, Entrada_Saida_Veiculo cliente) {

		int vaga_current = cliente.getVaga();

		if (vaga_current <= 0 || vaga_current > 100) {
			return false;
		}

		bool isEstacionado = false;

		for (int i = 0; i < lista.size(); i++) {
			if (lista[i].getIsFinalizado()) {
				continue;
			}

			if (lista[i].getVaga() == vaga_current) {
				isEstacionado = true;
				break;
			}
		}

		if (isEstacionado) {
			return false;
		}

		return true;
	}

	bool insereEntSaida(std::vector<Entrada_Saida_Veiculo>& lista, Entrada_Saida_Veiculo cliente)
	{
		bool isInserido = false;

		if (Entrada_Saida_Veiculo::isPermiteCadastrarEntradaSaida(lista, cliente)) {
			lista.push_back(cliente);
			isInserido = true;
		}

		return isInserido;
	}

	std::string getNomeCliente(const std::vector<Cliente>& lista) const {

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

	std::string getDt_Entrada_TXT() const {
		std::string data_formatada = "";

		data_formatada = std::to_string(Dt_Entrada->tm_year + 1900) + '/'
			+ std::to_string(Dt_Entrada->tm_mon + 1) + '/'
			+ std::to_string(Dt_Entrada->tm_mday) + " "
			+ std::to_string(Dt_Entrada->tm_hour) + ":"
			+ std::to_string(Dt_Entrada->tm_min);

		return data_formatada;
	}

	std::string getDt_Saida_TXT() const {
		std::string data_formatada = "";

		data_formatada = std::to_string(Dt_Saida->tm_year + 1900) + '/'
			+ std::to_string(Dt_Saida->tm_mon + 1) + '/'
			+ std::to_string(Dt_Saida->tm_mday) + " "
			+ std::to_string(Dt_Saida->tm_hour) + ":"
			+ std::to_string(Dt_Saida->tm_min);

		return data_formatada;
	}

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
	std::string TipoPagamento;
	float Valor;
	bool isFinalizado;
};

#endif