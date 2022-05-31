/* ED 11 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __CONTROLE_ENTRADA_SAIDA_VEICULO_H__
#define __CONTROLE_ENTRADA_SAIDA_VEICULO_H__

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>

#include "Cliente.h"
#include "Entrada_Saida_Veiculo.h"
#include "TelaEntradaSaidaVeiculo.h"
#include "Entrada_Saida_Veiculo_DAO.h"

class ControleEntradaSaidaVeiculo {

public:

    ControleEntradaSaidaVeiculo() : 
        _ent_saida_dao(EntradaSaidaVeiculoDAO()),
        _tela_ent_saida(TelaEntradaSaidaVeiculo()),
        _ent_saida_veiculos(std::vector<Entrada_Saida_Veiculo>())
    {
        _ent_saida_veiculos = _ent_saida_dao.carregarEntradaSaida();
    }

    void executar(const std::vector<Cliente> _clientes) {
        while (true) {

            // Exibir o menu principal
            _tela_ent_saida.exibirMenuEntradaSaidaVeiculo();

            // Usuário escolhe uma opção
            int opcao = _tela_ent_saida.lerOpcao();

            // Tratamento da opção
            switch (opcao) {
            case 1:
                cadastrarEntradaSaida();
                break;
            case 2:
                _tela_ent_saida.imprimirEntradaSaida(_ent_saida_veiculos, _clientes);
                break;
            case 3:
                _tela_ent_saida.visualizarEntradaSaida(_ent_saida_veiculos, _clientes);
                break;
            case 4:
                alterarEntradaSaida();
                break;
            case 5:
                return;
                break;
                return;
            }
        }
    }

    void cadastrarEntradaSaida() {
        Entrada_Saida_Veiculo ent_saida = _tela_ent_saida.lerNovaEntrada(_ent_saida_dao.getCurrentID());

        if (_tela_ent_saida.isPermiteCadastrarEntradaSaida(_ent_saida_veiculos, ent_saida)) {
            ent_saida.insereEntSaida(_ent_saida_veiculos, ent_saida);

            _ent_saida_dao.salvaListaEntradaSaida(_ent_saida_veiculos);

            _ent_saida_dao.updateCurrentID();
        }
    }

    void alterarEntradaSaida() {
        try {
            int posicao = _tela_ent_saida.lerPosicao();
            float novo_valor = _tela_ent_saida.lerEntradaSaidaValor();

            _ent_saida_veiculos[posicao].alterarEntradaSaida(novo_valor);

            _ent_saida_dao.salvaListaEntradaSaida(_ent_saida_veiculos);
        }
        catch (const char* erro) {
            _tela_ent_saida.exibirMensagemErro(erro);
        }
    }

    std::vector<Entrada_Saida_Veiculo> retornaEnt_Saida() {
        return _ent_saida_veiculos;
    }

private:
    TelaEntradaSaidaVeiculo _tela_ent_saida;
    std::vector<Entrada_Saida_Veiculo> _ent_saida_veiculos;

    EntradaSaidaVeiculoDAO _ent_saida_dao;
};

#endif