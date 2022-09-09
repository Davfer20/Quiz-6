#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

// Quiz #6
// 1. Utilizando esta classe agregue los atributos del vuelo: aerolinea, numero de vuelo, cantidad de pasajeros
// 2. Complete el constructor de la clase, de tal forma que se pueda modificar el flightTime para una hora y minutos específicos
// 3. Implementar alguna forma de convertir el time a un número entero de tal forma que entre menor la hora menor el número, eso en getIntTimeValue()
// 4. En el main3.cpp, implementar la función fillFlights()
// fecha de entrega: jueves 8 de setiembre antes de las 10pm
// entrega al asistente al correo: kevinqj.2002@gmail.com
// subject: estructuras de datos - quiz #6
// adjuntan el archivo test.cpp y Flight.h

class Flight
{

private:
    time_t flightTime;
    string aerolinea;
    string numVuelo;
    int cantidadPasajeros;
    int hora;
    int minutos;

public:
    Flight(int pHour, int pMinutes, string pAerolina, string pVuelo, int pCantidadPasajeros)
    {
        this->aerolinea = pAerolina;
        this->numVuelo = pVuelo;
        this->cantidadPasajeros = pCantidadPasajeros;
        this->hora = pHour;
        this->minutos = pMinutes;
    }

    void addTime() // Le da la opcion a agregar la hora y minutos exactos para el objeto
    {
        flightTime = time(NULL);
        tm *local_time = localtime(&flightTime);
        typeid(local_time->tm_hour).name();
        this->hora = local_time->tm_hour;
        this->minutos = local_time->tm_min;
    }

    int getHora()
    {
        return hora;
    }

    int getMinutos()
    {
        return minutos;
    }

    string getAerolinea()
    {
        return aerolinea;
    }

    string getVuelo()
    {
        return numVuelo;
    }

    int getPasajeros()
    {
        return cantidadPasajeros;
    }

    void changeFlightTime(int pHora, int pMinutos)
    {
        this->hora = pHora;
        this->minutos = pMinutos;
    }

    char flightTimeString()
    {
        time_t ttime = time(NULL);
        return ttime;
    }

    int getIntTimeValue()
    {
        time_t now = time(0);
        struct tm tstruct = *localtime(&now);

        float value = tstruct.tm_hour + tstruct.tm_min / 60.0 + tstruct.tm_sec / 3600.0;
        int res = round(value);
        return res;
    }
};