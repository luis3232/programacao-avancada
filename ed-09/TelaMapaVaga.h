/* ED 09 - 2 BIMESTRE PROGRAMA��O AVAN�ADA

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
        std::cout << "|== Mapa de Vagas ==|" << std::endl;
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
        std::cout << "== Posi��o a ser acessada ==" << std::endl;

        int posicao;
        std::cout << "Posi��o: ";
        std::cin >> posicao;

        return posicao;
    }

    void imprimirMapaVaga(const std::vector<Entrada_Saida_Veiculo>& lista) const {
        std::cout << "== Mapa de Vagas ==" << std::endl;

        for (int i = 0, aux = 0; i < 100; i++) {

            bool isExisteCarroVaga = false;

            for (int j = 0; j < lista.size(); j++) {
                if (lista[j].getVaga() == i) {
                    if (!lista[j].getIsFinalizado()) {
                        isExisteCarroVaga = true;
                    }
                }
            }

            std::cout << (i+1) << " - ";

            if (isExisteCarroVaga) {
                std::cout << "X";
            }
            else {
                std::cout << "V";
            }
            
            aux++;

            if (aux < 9) {
                std::cout << "\t";
            }
            else {
                std::cout << "\n";
            }
        }
    }

    void visualizarVaga(const std::vector<Entrada_Saida_Veiculo>& lista, std::vector<Cliente>& lista_clientes, int posicao) const {

        Entrada_Saida_Veiculo *ent_aux;
        bool found = false;

        for (int i = 0; i < lista.size(); i++) {
            if (lista[i].getID() == posicao) {
                *ent_aux = lista[i];
                found = true;
            }
        }

        if (!found || posicao < 0) {
            std::cout << "Nao foi possivel acessar este registro" << std::endl;
            return;
        }

        std::cout << "== Entrada/Saida - " << ent_aux->getVaga() << " == " << std::endl;
        std::cout << "ID......: " << ent_aux->getID() << std::endl;
        std::cout << "Vaga......: " << ent_aux->getVaga() << std::endl;
        std::cout << "Cliente......: " << ent_aux->getNomeCliente(lista_clientes) << std::endl;
        std::cout << "DtEntrada......: " << ent_aux->getDt_Entrada() << std::endl;
        std::cout << std::endl;
    }
};

#endif