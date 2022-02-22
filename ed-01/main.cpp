#include "iostream"

using namespace std;

#include "relogio.h"

int main()
{
    Relogio horario[3];

    int valores[3][2] = {};

    for (int i = 0; i < 3; i++)
    {
        bool isDadosValidos = false;

        do
        {
            cout << "Insira as informacoes do " << i+1 << " horario !\nHora: ";
            cin >> valores[i][0];
            cout << "Minutos: ";
            cin >> valores[i][1];
            cout << "\n";

            horario[i].setHora(valores[i][0]);
            horario[i].setMinutos(valores[i][1]);

            isDadosValidos = horario[i].isHorariosValidos();

            if (!isDadosValidos)
                cout << "Preencha as informacoes de horarios corretamente!\n" << endl;
        } while (!isDadosValidos);
    }

    for (int i = 0; i < 3; i++)
        cout << "\nHorarios informados no " << i + 1 << " horario: " << horario[i].RetornaHorarioFormatado()
        << ", totalizando: " << horario[i].RetornaMinutosTotais() << " minutos!" << endl;

    return 0;
}
