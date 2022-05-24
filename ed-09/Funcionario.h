/* ED 09 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA 

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __FUNCIONARIOS_H__
#define __FUNCIONARIOS_H__

#include <string>
#include <ctime>

class Funcionario {
public:

	Funcionario(std::string nome = "", std::string email = "", std::string senha = "", bool ativo = true, std::string cpf = "",
		tm* dt_entrada = nullptr, tm* dt_saida = nullptr, std::string endereco = "", std::string bairro = "", std::string cidade = "",
		std::string estado = "", int numero = 0, std::string complemento = "", float salario = 0.0) :
		Nome(nome),
		Email(email),
		Senha(senha),
		Ativo(ativo),
		Dt_Entrada(dt_entrada),
		Dt_Saida(dt_saida),
		Endereco(endereco),
		Bairro(bairro),
		Cidade(cidade),
		Estado(estado),
		Numero(numero),
		Complemento(complemento),
		CPF(cpf),
		Salario(salario) {
	}

	const long& getID() const {
		return ID;
	}

	const std::string& getNome() const {
		return Nome;
	}

	void setNome(const std::string& nome) {
		Nome = nome;
	}

	const std::string& getEmail() const {
		return Email;
	}

	void setEmail(const std::string& email) {
		Email = email;
	}

	const std::string& getSenha() const {
		return Senha;
	}

	void setSenha(const std::string& senha) {
		Senha = senha;
	}

	const bool& getAtivo() const {
		return Ativo;
	}

	void setAtivo(const bool& ativo) {
		Ativo = ativo;
	}

	const tm* getDt_Entrada() const {
		return Dt_Entrada;
	}

	void setDt_Entrada(const tm* dt_entrada) {
		*Dt_Entrada = *dt_entrada;
	}

	const tm* getDt_Saida() const {
		return Dt_Saida;
	}

	void setDt_Saida(const tm* dt_Saida) {
		*Dt_Saida = *dt_Saida;
	}

	const std::string& getEndereco() const {
		return Endereco;
	}

	void setEndereco(const std::string& endereco) {
		Endereco = endereco;
	}

	const std::string& getBairro() const {
		return Bairro;
	}

	void setBairro(const std::string& bairro) {
		Bairro = bairro;
	}

	const std::string& getCidade() const {
		return Cidade;
	}

	void setCidade(const std::string& cidade) {
		Cidade = cidade;
	}

	const std::string& getEstado() const {
		return Estado;
	}

	void setEstado(const std::string& estado) {
		Estado = estado;
	}

	const int& getNumero() const {
		return Numero;
	}

	void setNumero(const int& numero) {
		Numero = numero;
	}

	const std::string& getComplemento() const {
		return Complemento;
	}

	void setComplemento(const std::string& complemento) {
		Complemento = complemento;
	}

	const std::string& getCPF() const {
		return CPF;
	}

	void setCPF(const std::string& CPF_P) {
		CPF = CPF_P;
	}

	const float& getSalario() const {
		return Salario;
	}

	void setSalario(const float& salario) {
		Salario = salario;
	}

	virtual ~Funcionario() {}

private:
	long ID;
	std::string Nome;
	std::string Email;
	std::string Senha;
	bool Ativo;
	tm* Dt_Entrada;
	tm* Dt_Saida;
	std::string Endereco;
	std::string Bairro;
	std::string Cidade;
	std::string Estado;
	int Numero;
	std::string Complemento;
	std::string CPF;
	float Salario;
};

#endif