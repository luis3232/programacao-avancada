/* ED 11 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __MAPA_VAGA_H__
#define __MAPA_VAGA_H__

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>

#include "Entrada_Saida_Veiculo.h"
#include "TelaMapaVaga.h"

class ControleMapaVaga {

public:

    ControleMapaVaga() :
        _tela_mapa_vaga(TelaMapaVaga())
    {
        // vazio
    }

    void executar(const std::vector<Entrada_Saida_Veiculo> _ent_saidas, const std::vector<Cliente> clientes) {
        while (true) {

            // Exibir o menu principal
            _tela_mapa_vaga.exibirMenuMapaVaga();

            // Usuário escolhe uma opção
            int opcao = _tela_mapa_vaga.lerOpcao();

            // Tratamento da opção
            switch (opcao) {
            case 1:
                _tela_mapa_vaga.imprimirMapaVaga(_ent_saidas);
                break;
            case 2:
                _tela_mapa_vaga.visualizarVaga(_ent_saidas, clientes);
                break;
            case 3:
                return;
                break;
                return;
            }
        }
    }

private:
    TelaMapaVaga _tela_mapa_vaga;
};

#endif