/* ED 11 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __CONTROLE_PRINCIPAL_H__
#define __CONTROLE_PRINCIPAL_H__

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>

#include "Cliente.h"
#include "Entrada_Saida_Veiculo.h"
#include "ControleCliente.h"
#include "TelaPrincipal.h"
#include "ControleEntradaSaidaVeiculo.h"
#include "ControleMapaVaga.h"

class ControlePrincipal {

public:

    ControlePrincipal() : 
        _controle_cliente(ControleCliente()),
        _controle_ent_saida(ControleEntradaSaidaVeiculo()),
        _controle_mapa_vagas()

    {
        // vazio
    }

    void executar() {
        while (true) {

            // Exibir o menu principal
            _tela_principal.exibirMenuPrincipal();

            // Usuário escolhe uma opção
            int opcao = _tela_principal.lerOpcao();

            // Tratamento da opção
            switch (opcao) {
            case 1:
                _controle_ent_saida.executar(_controle_cliente.retornaClientes());
                break;
            case 2:
                _controle_cliente.executar();
                break;
            case 3:
                _controle_mapa_vagas.executar(_controle_ent_saida.retornaEnt_Saida(), _controle_cliente.retornaClientes());
                break;
            case 4:
                return;
            }
        }
    }

    int lerOpcao() const {
        std::cout << ":> ";
        int opcao;
        std::string buffer;
        std::cin >> opcao;
        std::getline(std::cin, buffer);

        return opcao;
    };

private:
    ControleCliente _controle_cliente;
    TelaPrincipal _tela_principal;
    ControleEntradaSaidaVeiculo _controle_ent_saida;
    ControleMapaVaga _controle_mapa_vagas;
};

#endif