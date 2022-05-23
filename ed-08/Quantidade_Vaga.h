/* ED 07 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA 

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __QUANTIDADE_VAGAS_H__
#define __QUANTIDADE_VAGAS_H__

class Quantidade_Vaga {
public:

	Quantidade_Vaga(int quantidade = 0, int tipo_veiculoid = 0, int funcionarios_id = 0) :
		Quantidade(quantidade),
		Tipo_VeiculoID(tipo_veiculoid),
		Funcionarios_ID(funcionarios_id) {
	}

	const int& getQuantidade() const {
		return Quantidade;
	}
	void setQuantidade(const int& quantidade) {
		Quantidade = quantidade;
	}

	const long& getTipo_VeiculoID() const {
		return Tipo_VeiculoID;
	}

	void setTipo_VeiculoID(const long& tipo_VeiculoID) {
		Tipo_VeiculoID = tipo_VeiculoID;
	}

	const long& getFuncionarios_ID() const {
		return Funcionarios_ID;
	}

	void setFuncionarios_ID(const long& funcionarios_ID) {
		Funcionarios_ID = funcionarios_ID;
	}

	const long& getID() const {
		return ID;
	}

	virtual ~Quantidade_Vaga() {}

private:
	long ID;
	int Quantidade;
	long Tipo_VeiculoID;
	long Funcionarios_ID;
};

#endif