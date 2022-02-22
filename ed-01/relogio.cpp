

#include "relogio.h"

#include <sstream>

using namespace std;

template <typename T>
  std::string NumberToString ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }

void Relogio::setHora(int hora)
{
    this->hora = hora;
}

void Relogio::setMinutos(int minuto)
{
    this->minuto = minuto;
}

string Relogio::RetornaMinutosTotais()
{
    int horas_totais = (this->hora * 60) + this->minuto;

    return NumberToString(horas_totais);
}

string Relogio::RetornaHorarioFormatado()
{
    string nova_hora = (this->hora < 10 ? "0" : "") + NumberToString(this->hora);
    string novo_minuto = (this->minuto < 10 ? "0" : "") + NumberToString(this->minuto);

    string novo_horario = nova_hora + ":" + novo_minuto;

    return novo_horario;
}

bool Relogio::isHorariosValidos()
{
    if (this->hora > 23 || this->hora < 0)
        return false;
    if (this->minuto > 59 || this->minuto < 0)
        return false;

    return true;
}
