/* ED 11 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <iostream> 
#include <sstream> 
#include <vector>

#include "Entrada_Saida_Veiculo_DAO.h"

#define ARQUIVO "ent_saidas.txt"

using namespace std;

vector<string> EntradaSaidaVeiculoDAO::split(string s, string delimiter) {
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

tm* EntradaSaidaVeiculoDAO::convertStringToTm(std::string startTime) {

	const char* zStart = startTime.c_str();

	int yy, month, dd, hh, mm, ss;
	sscanf(zStart, "%d/%d/%d %d:%d:%d", &yy, &month, &dd, &hh, &mm, &ss);

	tm* whenStart = new tm;

	whenStart->tm_year = yy - 1900;
	whenStart->tm_mon = month - 1;
	whenStart->tm_mday = dd;
	whenStart->tm_hour = hh;
	whenStart->tm_min = mm;
	whenStart->tm_sec = ss;
	whenStart->tm_isdst = -1;
}

std::vector<Entrada_Saida_Veiculo> EntradaSaidaVeiculoDAO::carregarEntradaSaida() {
	ifstream myfile(ARQUIVO);

	std::vector<Entrada_Saida_Veiculo> _ent_saida_list;

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

				Entrada_Saida_Veiculo ent_saida;

				bool isFinalizado = false;

				for (auto i : v) {
					if (aux == 0) {
						long id = std::stol(i);
						ent_saida.setID(id);

						if (id > EntradaSaidaVeiculoDAO::current_id) {
							EntradaSaidaVeiculoDAO::current_id = id + 1;
						}
					}

					if (aux == 1) {
						long id = std::stol(i);
						ent_saida.setClienteID(id);
					}

					if (aux == 2) {
						ent_saida.setTipoVeiculo(i);
					}

					if (aux == 3) {
						ent_saida.setVaga(std::stoi(i));
					}

					if (aux == 4) {
						ent_saida.setPlaca(i);
					}

					if (aux == 5) {
						ent_saida.setCarro(i);
					}

					if (aux == 6) {
						ent_saida.setCor_Carro(i);
					}

					if (aux == 7) {
						ent_saida.setDt_Entrada(this->convertStringToTm(i));
					}

					if (aux == 8) {
						ent_saida.setTipoPagamento(i);
					}

					if (aux == 9) {
						ent_saida.setValor(std::stof(i));
					}

					if (aux == 10) {
						isFinalizado = (i == "1" ? true : false);
						ent_saida.setIsFinalizado(isFinalizado);
					}

					if (aux == 11) {
						if (!isFinalizado) {
							std::tm* now = new tm;
							ent_saida.setDt_Saida(now);
						}
						else {
							ent_saida.setDt_Saida(this->convertStringToTm(i));
						}
					}

					aux++;
				}
				_ent_saida_list.push_back(ent_saida);
			}
			catch (...) {
				
			}
		}
	}

	myfile.close();

	return _ent_saida_list;
}

void EntradaSaidaVeiculoDAO::salvaListaEntradaSaida(std::vector<Entrada_Saida_Veiculo> _ent_saidas) {

	ofstream fout(ARQUIVO);

	for (int i = 0; i < _ent_saidas.size(); i++) {

		fout << _ent_saidas[i].getID() << ","
			<< _ent_saidas[i].getClienteID() << ","
			<< _ent_saidas[i].getTipoVeiculo() << ","
			<< _ent_saidas[i].getVaga() << ","
			<< _ent_saidas[i].getPlaca() << ","
			<< _ent_saidas[i].getCarro() << ","
			<< _ent_saidas[i].getCor_Carro() << ","
			<< _ent_saidas[i].getDt_Entrada_TXT() << ","
			<< _ent_saidas[i].getTipoPagamento() << ","
			<< _ent_saidas[i].getValor() << ","
			<< _ent_saidas[i].getIsFinalizado() << ","
			<< _ent_saidas[i].getDt_Saida_TXT() 
			<< endl;
	}

	fout.close();
}