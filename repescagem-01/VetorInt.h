/* TRABALHO REPESCAGEM
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#ifndef __VETOR_INT__
#define __VETOR_INT__

#include <iostream>
#include <sstream>
#include <string>

#include "Imprimivel.h"

class VetorInt : public Imprimivel {
	
public:
	VetorInt(int tamanho) : tamanho_vetor(tamanho) {
		vetor = new int[tamanho];
	}

	virtual ~VetorInt() {
		delete[] vetor;
	}

	virtual void imprime() {
		std::cout << "\n||||||||||||||||||||||||||||||||||||||||" << std::endl;

		std::cout << "Imprimindo vetor, (" << tamanho_vetor << ") posicoes!" << std::endl;

		for (int i = 0; i < tamanho_vetor; i++) {
			std::cout << "Posicao: " << i << ", valor: " << vetor[i] << std::endl;
		}

		std::cout << "\n||||||||||||||||||||||||||||||||||||||||" << std::endl;
	}

	int operator()(int x) {
		if (x < 0 || x >= tamanho_vetor) {
			return 0;
		}

		return vetor[x];
	}

	int operator[](int x) {
		if (x < 0 || x >= tamanho_vetor) {
			return 0;
		}

		return vetor[x];
	}

	VetorInt* operator+(VetorInt* v1) {
		int max_tam = v1->getTamanho() > this->tamanho_vetor ? v1->getTamanho() : this->tamanho_vetor;

		VetorInt* resultado = new VetorInt(max_tam);

		for (int i = 0; i < max_tam; i++) {
			resultado->setInteiro(i, (i < tamanho_vetor ? vetor[i] : 0) + (*v1)(i));
		}

		return resultado;
	}

	VetorInt* operator-(VetorInt* v1) {
		int max_tam = v1->getTamanho() > this->tamanho_vetor ? v1->getTamanho() : this->tamanho_vetor;

		VetorInt* resultado = new VetorInt(max_tam);

		for (int i = 0; i < max_tam; i++) {
			resultado->setInteiro(i, (i < tamanho_vetor ? vetor[i] : 0) - (*v1)(i));
		}

		return resultado;
	}

	void operator+=(VetorInt* v1) {
		for (int i = 0; i < this->tamanho_vetor; i++) {
			vetor[i] += (*v1)(i);
		}
	}

	void operator-=(VetorInt* v1) {
		for (int i = 0; i < this->tamanho_vetor; i++) {
			vetor[i] -= (*v1)(i);
		}
	}

	VetorInt* operator*(VetorInt* v1) {
		int max_tam = v1->getTamanho() > this->tamanho_vetor ? v1->getTamanho() : this->tamanho_vetor;

		VetorInt* resultado = new VetorInt(max_tam);

		for (int i = 0; i < max_tam; i++) {
			resultado->setInteiro(i, (i < tamanho_vetor ? vetor[i] : 0) * (*v1)(i));
		}

		return resultado;
	}

	VetorInt* operator*(int e) {
		VetorInt* resultado = new VetorInt(tamanho_vetor);

		for (int i = 0; i < tamanho_vetor; i++) {
			resultado->setInteiro(i, vetor[i] * e);
		}

		return resultado;
	}

	void operator*=(int e) {
		for (int i = 0; i < tamanho_vetor; i++) {
			vetor[i] *= e;
		}
	}

	bool operator==(VetorInt* v1) {
		if (tamanho_vetor != v1->getTamanho())
			return false;

		bool isIgual = true;

		for (int i = 0; i < tamanho_vetor; i++) {
			if (this->vetor[i] != (*v1)(i)) {
				isIgual = false;
			}
		}

		return isIgual;
	}

	bool operator!=(VetorInt* v1) {
		bool isDiferente = false;

		int x = v1->getTamanho() > this->tamanho_vetor ? v1->getTamanho() : this->tamanho_vetor;

		for (int i = 0; i < x; i++) {
			if ((*v1)(i) != (i < tamanho_vetor ? vetor[i] : 0)) {
				isDiferente = true;
			}
		}

		return isDiferente;
	}

	int getTamanho() const {
		return this->tamanho_vetor;
	}

	void setInteiro(int pos, int valor) {
		if (pos < 0 || pos >= tamanho_vetor) {
			return;
		}

		vetor[pos] = valor;
	}

private:
	int* vetor;
	int tamanho_vetor;
};

#endif