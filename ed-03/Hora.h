/* TRABALHO ESTUDO DIRIGIDO 3
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#ifndef __HORA_H__
#define __HORA_H__

#include <iostream>

class Hora {

public:

	Hora() : _hora(0), _minuto(0), _segundo(0) {}

	Hora(int hora, int minuto, int segundo) : _hora(hora), _minuto(minuto), _segundo(segundo) {
		std::cout << "\nInicializando o objeto hora!" << std::endl;
	}

	int getHora() const {
		return _hora;
	}

	int getMinuto() const {
		return _minuto;
	}

	int getSegundo() const {
		return _segundo;
	}

	void soma(Hora hora) {
		int segundos_totais = this->getSegundosTotaisHora(hora.getHora(), hora.getMinuto(), hora.getSegundo());
		int segundos_current = this->getSegundosTotaisHora(_hora, _minuto, _segundo);

		segundos_current += segundos_totais;

		if (this->setValoresHorario(segundos_current)) {
			std::cout << "\nHoras somadas com sucesso!" << std::endl;
		}
		else {
			std::cout << "\Falha ao somar as horas!" << std::endl;
		}
	}

	void subtrai(Hora hora) {
		int segundos_totais = this->getSegundosTotaisHora(hora.getHora(), hora.getMinuto(), hora.getSegundo());
		int segundos_current = this->getSegundosTotaisHora(_hora, _minuto, _segundo);

		segundos_current -= segundos_totais;

		if (this->setValoresHorario(segundos_current)) {
			std::cout << "\nHoras subtraidas com sucesso!" << std::endl;
		}
		else {
			std::cout << "\Falha ao subtrair as horas!" << std::endl;
		}
	}

	int getSegundosTotaisHora(int hora, int minuto, int segundo) const {
		return (hora * 3600) + (minuto * 60) + segundo;
	}

	bool setValoresHorario(int segundos_totais) {
		if (segundos_totais > 0) {
			int resto;

			_hora = segundos_totais / 3600;
			resto = segundos_totais % 3600;
			_minuto = resto / 60;
			_segundo = resto % 60;

			return true;
		}

		return false;
	}

private:
	int _hora;
	int _minuto;
	int _segundo;
};

#endif