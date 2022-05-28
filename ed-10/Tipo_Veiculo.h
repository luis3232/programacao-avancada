/* ED 10 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA 

ALUNO: LUIS AURELIO CAMPOS 
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __TIPO_VEICULO_H__
#define __TIPO_VEICULO_H__

#include <string>

class Tipo_Veiculo {
public:

	Tipo_Veiculo(std::string NomeP = "", bool AtivoP = true) :
		Nome(NomeP),
		Ativo(AtivoP) {
	}

	const std::string& getNome() const {
		return Nome;
	}
	void setNome(const std::string& nome) {
		Nome = nome;
	}

	const bool& getAtivo() const {
		return Ativo;
	}

	void setAtivo(const bool& ativo) {
		Ativo = ativo;
	}

	const long& getID() const {
		return ID;
	}

	virtual ~Tipo_Veiculo() {}

private:
	long ID;
	std::string Nome;
	bool Ativo;
};

#endif