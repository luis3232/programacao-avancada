/* ED 09 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __TELA_ENTRADA_SAIDA_H__
#define __TELA_ENTRADA_SAIDA_H__

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>

#include "Cliente.h"
#include "Entrada_Saida_Veiculo.h"

class TelaEntradaSaidaVeiculo {

public:

    void exibirMenuEntradaSaidaVeiculo() const {
        std::cout << "|== Entrada Saida de Veiculo ==|" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Cadastrar" << std::endl;
        std::cout << "2. Visualizar Todos" << std::endl;
        std::cout << "3. Visualizar Especifico" << std::endl;
        std::cout << "4. Alterar" << std::endl;
        std::cout << "5. Retornar Menu Principal" << std::endl;
    }

    int lerOpcao() const {
        std::cout << ":> ";
        int opcao;
        std::string buffer;
        std::cin >> opcao;
        std::getline(std::cin, buffer);

        return opcao;
    };

    int lerPosicao() const {
        std::cout << "== Posição a ser acessada ==" << std::endl;

        int posicao;
        std::cout << "Posição: ";
        std::cin >> posicao;

        return posicao;
    }

    void imprimirEntradaSaida(const std::vector<Entrada_Saida_Veiculo>& lista, std::vector<Cliente>& lista_clientes) const {
        std::cout << "== Entrada e Saida de Veiculos ==" << std::endl;

        for (int i = 0; i < lista.size(); i++) {
            std::cout << "ID......: " << lista[i].getID() << std::endl;
            std::cout << "Cliente......: " << lista[i].getNomeCliente(lista_clientes) << std::endl;
            std::cout << "DtEntrada......: " << lista[i].getDt_Entrada() << std::endl;
            std::cout << "Saiu......: " << lista[i].getDt_Saida() << std::endl;
            std::cout << "Valor......: " << lista[i].getValor() << std::endl;
            std::cout << std::endl;
        }
    }

    void visualizarEntradaSaida(const std::vector<Entrada_Saida_Veiculo>& lista, std::vector<Cliente>& lista_clientes, int posicao) const {

        if (posicao < 0 || posicao > lista.size()) {
            std::cout << "Nao foi possivel acessar este registro" << std::endl;
            return;
        }

        std::cout << "== Entrada/Saida - " << lista[posicao].getID() << " == " << std::endl;
        std::cout << "ID......: " << lista[posicao].getID() << std::endl;
        std::cout << "Cliente Nome......: " << lista[posicao].getNomeCliente(lista_clientes) << std::endl;
        std::cout << "ClienteID......: " << lista[posicao].getClienteID() << std::endl;
        std::cout << "Tipo_Veiculo......: " << lista[posicao].getTipoVeiculo() << std::endl;
        std::cout << "Vaga......: " << lista[posicao].getVaga() << std::endl;
        std::cout << "Placa......: " << lista[posicao].getPlaca() << std::endl;
        std::cout << "Carro......: " << lista[posicao].getCarro() << std::endl;
        std::cout << "Cor_Carro......: " << lista[posicao].getCor_Carro() << std::endl;
        std::cout << "Dt_Entrada......: " << lista[posicao].getDt_Entrada() << std::endl;
        std::cout << "Dt_Saida......: " << lista[posicao].getDt_Saida() << std::endl;
        std::cout << "Tempo_Total......: " << lista[posicao].getTempo_Total() << std::endl;
        std::cout << "TipoPagamento......: " << lista[posicao].getTipoPagamento() << std::endl;
        std::cout << "Valor......: " << lista[posicao].getValor() << std::endl;
        std::cout << std::endl;
    }

    bool cadastrarEntradaSaida(std::vector<Entrada_Saida_Veiculo>& lista, Entrada_Saida_Veiculo cliente) {

        lista.push_back(cliente);

        std::cout << "Entrada/Saida inserido com sucesso!" << std::endl;

        return true;
    }

    bool alterarEntradaSaida(std::vector<Entrada_Saida_Veiculo>& lista, Entrada_Saida_Veiculo entrada_current, int posicao) {

        if (posicao < 0 || posicao > lista.size()) {
            return false;
        }

        lista[posicao] = entrada_current;

        std::cout << "Entrada/Saida alterada com sucesso!" << std::endl;

        return true;
    }

};

#endif