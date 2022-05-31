/* ED 11 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __ENT_SAIDA_DAO_H__
#define __ENT_SAIDA_DAO_H__

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Entrada_Saida_Veiculo.h"

class EntradaSaidaVeiculoDAO {
public:

	EntradaSaidaVeiculoDAO() {
		this->current_id = 1;
	}

	std::vector<Entrada_Saida_Veiculo> carregarEntradaSaida();

	void salvaListaEntradaSaida(std::vector<Entrada_Saida_Veiculo>);

	long getCurrentID() const {
		return this->current_id;
	}

	void updateCurrentID() {
		this->current_id += 1;
	}

private:

	tm* convertStringToTm(std::string);

	std::vector<std::string> split(std::string, std::string);

	long current_id;
};

#endif