/* ED 11 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __TELA_ENTRADA_SAIDA_H__
#define __TELA_ENTRADA_SAIDA_H__

#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>

#include "Cliente.h"
#include "Entrada_Saida_Veiculo.h"

class TelaEntradaSaidaVeiculo {

public:

    void exibirMenuEntradaSaidaVeiculo() const {
        std::cout << "\n\n|== Entrada Saida de Veiculo ==|" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Cadastrar" << std::endl;
        std::cout << "2. Visualizar Todos" << std::endl;
        std::cout << "3. Visualizar Especifico" << std::endl;
        std::cout << "4. Alterar" << std::endl;
        std::cout << "5. Retornar Menu Principal" << std::endl;
    }

    int lerOpcao() const {
        try {
            std::cout << ":> ";
            int opcao;
            std::string buffer;
            std::cin >> opcao;
            std::getline(std::cin, buffer);

            return opcao;
        }
        catch (std::string erro) {

        }
    };

    int lerPosicao() const {
        try {
            std::cout << "\n\n== Posicao a ser acessada ==" << std::endl;

            int posicao;
            std::cout << "Posicao: ";
            std::cin >> posicao;

            return posicao;
        }
        catch (std::string erro) {
        }
    }

    void imprimirEntradaSaida(const std::vector<Entrada_Saida_Veiculo>& lista, std::vector<Cliente> clientes) const {
        std::cout << "\n\n== Entrada e Saida de Veiculos ==" << std::endl;

        for (int i = 0; i < lista.size(); i++) {

            std::cout << "ID......: " << lista[i].getID() << std::endl;
            std::cout << "Posicao......: " << i << std::endl;
            std::cout << "Cliente......: " << lista[i].getClienteID() << " - " << lista[i].getNomeCliente(clientes) << std::endl;
            std::cout << "Vaga......: " << lista[i].getVaga() << std::endl;
            std::cout << "DtEntrada......: " << lista[i].getDt_Entrada_Formatado() << std::endl;

            if (lista[i].getIsFinalizado()) {
                std::cout << "Saiu......: " << lista[i].getDt_Saida_Formatado() << std::endl;
                std::cout << "Valor......: " << lista[i].getValor() << std::endl;
            }
            else {
                std::cout << "Saiu......: Nao" << std::endl;
            }


            std::cout << std::endl;
        }
    }

    void visualizarEntradaSaida(const std::vector<Entrada_Saida_Veiculo>& lista, const std::vector<Cliente> clientes) const {
        int posicao = lerPosicao();

        if (posicao < 0 || posicao > lista.size()) {
            std::cout << "Nao foi possivel acessar este registro" << std::endl;
            return;
        }

        if (lista[posicao].getID() == 0 || lista[posicao].getCarro().empty()) {
            return;
        }

        std::cout << "\n\n== Entrada/Saida - " << lista[posicao].getID() << " == " << std::endl;
        std::cout << "ID......: " << lista[posicao].getID() << std::endl;
        std::cout << "Cliente......: " << lista[posicao].getNomeCliente(clientes) << std::endl;
        std::cout << "ClienteID......: " << lista[posicao].getClienteID() << std::endl;
        std::cout << "Tipo_Veiculo......: " << lista[posicao].getTipoVeiculo() << std::endl;
        std::cout << "Vaga......: " << lista[posicao].getVaga() << std::endl;
        std::cout << "Placa......: " << lista[posicao].getPlaca() << std::endl;
        std::cout << "Carro......: " << lista[posicao].getCarro() << std::endl;
        std::cout << "Cor_Carro......: " << lista[posicao].getCor_Carro() << std::endl;
        std::cout << "Dt_Entrada......: " << lista[posicao].getDt_Entrada_Formatado() << std::endl;
        std::cout << "Dt_Saida......: " << lista[posicao].getDt_Saida_Formatado() << std::endl;
        std::cout << "TipoPagamento......: " << lista[posicao].getTipoPagamento() << std::endl;
        std::cout << "Valor......: " << lista[posicao].getValor() << std::endl;
        std::cout << std::endl;
    }

    Entrada_Saida_Veiculo lerNovaEntrada(long ID) {

        try {
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

            std::cout << "\n\n== Dados da Entrada/Saida ==" << std::endl;

            std::cout << "ClienteID......: ";
            std::cin >> ClienteID;

            std::cin.ignore();
            std::cout << "Tipo_Veiculo......: ";
            std::getline(std::cin, Tipo_Veiculo);

            std::cout << "Vaga......: ";
            std::cin >> Vaga;

            std::cin.ignore();
            std::cout << "Placa......: ";
            std::getline(std::cin, Placa);

            std::cout << "Carro......: ";
            std::getline(std::cin, Carro);

            std::cout << "Cor do Carro......: ";
            std::getline(std::cin, Cor_Carro);

            std::cout << "TipoPagamento......: ";
            std::getline(std::cin, TipoPagamento);
            
            return Entrada_Saida_Veiculo(ID, ClienteID, Tipo_Veiculo, Vaga, Placa, Carro, Cor_Carro, TipoPagamento);
        }
        catch (std::string erro) {
            return NULL;
        }
    }

    float lerEntradaSaidaValor() {
        try {
            float valor;
            std::cout << "Insira o valor do estacionamento......: ";
            std::cin >> valor;

            return valor;
        }
        catch (std::string erro) {
            erro = "Nao foi possivel validar o valor!";
        }
    }

    void exibirMensagemErro(std::string erro) {
        std::cerr << erro << std::endl;
    }
};

#endif
