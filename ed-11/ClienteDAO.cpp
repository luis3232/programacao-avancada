/* ED 11 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#include <iostream>
#include <fstream>
#include <string>
#include <iostream> 
#include <sstream> 
#include <vector>

#include "ClienteDAO.h"

#define ARQUIVO "clientes.txt"

using namespace std;

vector<string> ClienteDAO::split(string s, string delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	string token;
	vector<string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}

std::vector<Cliente> ClienteDAO::carregarCliente() {
	ifstream myfile(ARQUIVO);

	std::vector<Cliente> _clientes;

	string linha;

	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, linha);

			if (linha.length() <= 2) {
				continue;
			}

			vector<string> v = this->split(linha, ",");

			try {
				int aux = 0;
				Cliente cliente;

				for (auto i : v) {
					if (aux == 0) {
						long id = std::stol(i);
						cliente.setID(id);

						if (id > ClienteDAO::current_id) {
							ClienteDAO::current_id = id + 1;
						}
					}

					if (aux == 1) {
						cliente.setNome(i);
					}

					if (aux == 2) {
						cliente.setEmail(i);
					}

					if (aux == 3) {
						cliente.setCelular(i);
					}

					if (aux == 4) {
						cliente.setCPF(i);
					}

					if (aux == 5) {
						cliente.setMensalidade(std::stof(i));
					}

					if (aux == 6) {
						cliente.setEndereco(i);
					}

					if (aux == 7) {
						cliente.setBairro(i);
					}

					if (aux == 8) {
						cliente.setCidade(i);
					}

					if (aux == 9) {
						cliente.setEstado(i);
					}

					if (aux == 10) {
						cliente.setNumero(std::stoi(i));
					}

					if (aux == 11) {
						cliente.setComplemento(i);
					}

					if (aux == 12) {
						cliente.setisAtivo(i == "1" ? true : false);
					}

					aux++;
				}

				_clientes.push_back(cliente);
			}
			catch (...) {
			}
		}
	}

	myfile.close();

	return _clientes;
}

void ClienteDAO::salvaListaCliente(std::vector<Cliente> _clientes) {
	
	ofstream fout(ARQUIVO);

	for (int i = 0; i < _clientes.size(); i++) {

		fout << _clientes[i].getID() << "," 
			<< _clientes[i].getNome() << ","
			<< _clientes[i].getEmail() << ","
			<< _clientes[i].getCelular() << ","
			<< _clientes[i].getCPF() << ","
			<< _clientes[i].getMensalidade() << ","
			<< _clientes[i].getEndereco() << ","
			<< _clientes[i].getBairro() << ","
			<< _clientes[i].getCidade() << ","
			<< _clientes[i].getEstado() << ","
			<< _clientes[i].getNumero() << ","
			<< _clientes[i].getComplemento() << ","
			<< _clientes[i].getisAtivo()
			<< endl;
	}

	fout.close();
}