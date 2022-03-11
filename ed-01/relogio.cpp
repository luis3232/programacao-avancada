#include "relogio.h"

#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

template <typename T>
std::string numberToString(T Number)
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

string Relogio::getMinutosTotais()
{
    int horas_totais = (this->hora * 60) + this->minuto;

    return numberToString(horas_totais);
}

string Relogio::getHorarioFormatado()
{
    std::tm tm{};
    tm.tm_hour = this->hora;
    tm.tm_min = this->minuto;
    std::time_t t = std::mktime(&tm); 
    
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&t),"%H:%M");
    string novo_horario = oss.str();

    return novo_horario;
}

bool Relogio::isHorariosValidos()
{
    return this->hora >= 0 && this->hora <= 23 && this->minuto >= 0 && this->minuto <= 59;
}
