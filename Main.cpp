#include "Flight.h"
#include "../Generic/List.h"
#include <iostream>
#include <stdlib.h>
#include <random>

string aerolines[6] = {"American Airlines", "Spirit", "JetBlue", "Frontier", "Allegiant", "Emirates"};
string numerosVuelo[6] = {"VIN2230", "W2DUAD", "124JBA", "AA114", "TY6969", "DXR2D2"};

int randomGeneral(int min, int max)
{
    const int range_from = min;
    const int range_to = max;
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(range_from, range_to);

    return distr(generator);
}

int horaLimites(string pTiempo)
{
    string numeroInicio = pTiempo.substr(0, 2);
    int min = stoi(numeroInicio);
    return min;
}

int minutoLimites(string pTiempo)
{
    string numeroInicio = pTiempo.substr(3, 4);
    int min = stoi(numeroInicio);
    return min;
}

void fillFlights(List<Flight> *pLista, int repeticiones, string pStartHour, string pEndHour)
{
    for (int i = 0; i < repeticiones; i++)
    {
        int hora, minutos, minHora, maxHora, minMin, maxMin = 0;
        minHora = horaLimites(pStartHour);
        maxHora = horaLimites(pEndHour);
        minMin = minutoLimites(pStartHour);
        maxMin = minutoLimites(pEndHour);

        hora = randomGeneral(minHora, maxHora);
        minutos = randomGeneral(minMin, maxMin);

        int aerolinea = randomGeneral(0, 5);
        string marcaAvion = aerolines[aerolinea];

        int vueloPoci = randomGeneral(0, 5);
        string vuelo = numerosVuelo[vueloPoci];

        int pasajeros = randomGeneral(0, 20);

        Flight *avionNuevo = new Flight(hora, minutos, marcaAvion, vuelo, pasajeros);
        pLista->add(avionNuevo);
    }
}

int main()
{
    List<Flight> *aviones = new List<Flight>();
    fillFlights(aviones, 3, "01:00", "03:20"); // Se pone cantidad de repeticiones y horas limites
    int size = sizeof(aviones) - 1;

    for (int i = 0; i < size; i++)
    {
        Flight *currentPlane = aviones->find(i);
        cout << "---------------Creacion De Avion Nuevo--------------------" << endl;
        cout << "Hora: " << currentPlane->getHora() << endl;
        cout << "Minutos: " << currentPlane->getMinutos() << endl;
        cout << "Aerolinea: " << currentPlane->getAerolinea() << endl;
        cout << "Numero de vuelo: " << currentPlane->getVuelo() << endl;
        cout << "Cantidad de Pasajeros: " << currentPlane->getPasajeros() << endl;
    }
}
