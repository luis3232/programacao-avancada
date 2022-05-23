/* ED 07 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __TABELA_PRECOS_H__
#define __TABELA_PRECOS_H__

class Tabela_Preco {
public:

	Tabela_Preco(long tipo_veiculoid = 0, int minutos = 0, float valor = 0.0, bool ativo = true) :
		Tipo_VeiculoID(tipo_veiculoid),
		Minutos(minutos),
		Valor(valor),
		Ativo(ativo) {
	}

	const long& getID() const {
		return ID;
	}

	const long& getTipo_VeiculoID() const {
		return Tipo_VeiculoID;
	}

	void setTipo_VeiculoID(const long& tipo_VeiculoID) {
		Tipo_VeiculoID = tipo_VeiculoID;
	}

	const int& getMinutos() const {
		return Minutos;
	}

	void setMinutos(const int& minutos) {
		Minutos = minutos;
	}

	const float& getValor() const {
		return Valor;
	}

	void setValor(const float& valor) {
		Valor = valor;
	}

	const bool& getAtivo() const {
		return Ativo;
	}

	void setAtivo(const bool& ativo) {
		Ativo = ativo;
	}

	virtual ~Tabela_Preco() {}

private:
	long ID;
	long Tipo_VeiculoID;
	int Minutos;
	float Valor;
	bool Ativo;
};

#endif