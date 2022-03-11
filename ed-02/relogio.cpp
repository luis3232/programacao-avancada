/* TRABALHO ESTUDO DIRIGIDO 2
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#include "relogio.h"

#include <iomanip>
#include <ctime>

using namespace std;

string Relogio::getStringValue(int x) const
{
    std::string str;
        
    std::stringstream ss;  
    ss << x;  
    ss >> str;
    
    return str;
}

string Relogio::getHorarioFormatado() const
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
