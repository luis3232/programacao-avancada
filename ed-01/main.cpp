#include <iostream>

using namespace std;

#include "relogio.h"

int main()
{
    Relogio horario[3];

    int hora = 0, minuto = 0;
    
    for (int i = 0; i < 3; i++)
    {
        bool isDadosValidos = false;

        do
        {
            cout << "Insira as informacoes do " << i+1 << " horario !\nHora: ";
            cin >> hora;
            cout << "Minutos: ";
            cin >> minuto;
            cout << "\n";

            horario[i].setHora(hora);
            horario[i].setMinutos(minuto);

            isDadosValidos = horario[i].isHorariosValidos();

            if (!isDadosValidos)
            {
                cout << "Preencha as informacoes de horarios corretamente!\n" << endl;
            }

        } while (!isDadosValidos);
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "\nHorarios informados no " << i + 1 << " horario: " << horario[i].getHorarioFormatado()
        << ", totalizando: " << horario[i].getMinutosTotais() << " minutos!" << endl;
    }

    return 0;
}
