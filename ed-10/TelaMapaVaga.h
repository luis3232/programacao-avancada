/* ED 10 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __TELA_MAPA_H__
#define __TELA_MAPA_H__

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>

#include "Cliente.h"
#include "Entrada_Saida_Veiculo.h"

class TelaMapaVaga {

public:

    void exibirMenuMapaVaga() const {
        std::cout << "\n\n|== Mapa de Vagas ==|" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Visualizar" << std::endl;
        std::cout << "2. Consultar Vaga" << std::endl;
        std::cout << "3. Retornar Menu Principal" << std::endl;
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
        std::cout << "\n\n== Vaga a ser acessada ==" << std::endl;

        int posicao;
        std::cout << "Vaga: ";
        std::cin >> posicao;

        return posicao;
    }

    void imprimirMapaVaga(const std::vector<Entrada_Saida_Veiculo> lista) const {
        std::cout << "\n\n== Mapa de Vagas ==" << std::endl;

        for (int i = 1, aux = 0; i <= 100; i++) {

            bool isExisteCarroVaga = false;

            for (int j = 0; j < lista.size(); j++) {
                if (lista[j].getVaga() == i) {
                    if (!lista[j].getIsFinalizado()) {
                        isExisteCarroVaga = true;
                    }
                }
            }

            std::cout << (i < 10 ? + "0" : "") << i << " - ";

            if (isExisteCarroVaga) {
                std::cout << "X";
            }
            else {
                std::cout << "V";
            }
            
            aux++;

            if (aux < 10) {
                std::cout << "\t";
            }
            else {
                std::cout << "\n";
                aux = 0;
            }
        }
    }

    void visualizarVaga(const std::vector<Entrada_Saida_Veiculo> lista, const std::vector<Cliente> clientes) const {

        int posicao = lerPosicao();

        if (posicao < 0 || posicao > 100) {
            return;
        }

        Entrada_Saida_Veiculo ent_aux;
        bool found = false;

        for (int i = 0; i < lista.size(); i++) {
            if (lista[i].getVaga() == posicao) {
                ent_aux = lista[i];
                found = true;
            }
        }

        if (!found || posicao < 0) {
            std::cout << "Nao foi possivel acessar este registro" << std::endl;
            return;
        }

        std::cout << "\n\n== Entrada/Saida - " << ent_aux.getVaga() << " == " << std::endl;
        std::cout << "ID......: " << ent_aux.getID() << std::endl;
        std::cout << "Vaga......: " << ent_aux.getVaga() << std::endl;
        std::cout << "Cliente......: " << ent_aux.getNomeCliente(clientes) << std::endl;
        std::cout << "ClienteID......: " << ent_aux.getClienteID() << std::endl;
        std::cout << "DtEntrada......: " << ent_aux.getDt_Entrada() << std::endl;
        std::cout << std::endl;
    }
};

#endif