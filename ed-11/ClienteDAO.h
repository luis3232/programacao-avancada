/* ED 11 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __CLIENTES_DAO_H__
#define __CLIENTES_DAO_H__

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Cliente.h"

class ClienteDAO {
public:

	ClienteDAO() {
		this->current_id = 1;
	}

	std::vector<Cliente> carregarCliente();

	void salvaListaCliente(std::vector<Cliente>);

	long getCurrentID() const {
		return this->current_id;
	}

	void updateCurrentID() {
		this->current_id += 1;
	}

private:

	std::vector<std::string> split(std::string s, std::string delimiter);

	long current_id;
};

#endif