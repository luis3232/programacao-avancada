/* ED 07 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __ENTRADA_SAIDA_VEICULOS_H__
#define __ENTRADA_SAIDA_VEICULOS_H__

#include <string>
#include <ctime>

class Entrada_Saida_Veiculos {
public:

	Entrada_Saida_Veiculos(long clienteID = 0, long funcionarios_EntradaID = 0, long funcionarios_SaidaID = 0, 
		long tipo_VeiculoID = 0, int vaga = 0, std::string placa = "", std::string carro = "", std::string cor_carro = "",
		tm* dt_entrada = nullptr, tm* dt_saida = nullptr, tm* tempo_total = nullptr, std::string tipopagamento = "",
		float valor = 0.0) :
		ClienteID(clienteID),
		Funcionarios_EntradaID(funcionarios_EntradaID),
		Funcionarios_SaidaID(funcionarios_SaidaID),
		Tipo_VeiculoID(tipo_VeiculoID),
		Vaga(vaga),
		Dt_Entrada(dt_entrada),
		Dt_Saida(dt_saida),
		Tempo_Total(tempo_total),
		TipoPagamento(tipopagamento),
		Valor(valor) {
	}

	const long& getID() const {
		return ID;
	}

	const long& getFuncionarios_EntradaID() const {
		return Funcionarios_EntradaID;
	}

	void setFuncionarios_EntradaID(const long& funcionarios_EntradaID) {
		Funcionarios_EntradaID = funcionarios_EntradaID;
	}

	const long& getFuncionarios_SaidaID() const {
		return Funcionarios_SaidaID;
	}

	void setFuncionarios_SaidaID(const long& funcionarios_SaidaID) {
		Funcionarios_SaidaID = funcionarios_SaidaID;
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

	const float& getValor() const {
		return Valor;
	}

	void setValor(const float& valor) {
		Valor = valor;
	}

	virtual ~Entrada_Saida_Veiculos() {}

private:
	long ID;
	long ClienteID;
	long Funcionarios_EntradaID;
	long Funcionarios_SaidaID;
	long Tipo_VeiculoID;
	int Vaga;
	std::string Placa;
	std::string Carro;
	std::string Cor_Carro;
	tm* Dt_Entrada;
	tm* Dt_Saida;
	tm* Tempo_Total;
	std::string TipoPagamento;
	float Valor;
};

#endif