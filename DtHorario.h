#ifndef DTHORARIO
#define DTHORARIO
#include <iostream>

using namespace std;

class DtHorario{
private:
    string horaIni;
    string horaFin;
public:
    DtHorario();
    DtHorario(string, string);
    string getHoraIni();
    string getHoraFin();
    ~DtHorario();

    friend bool operator <(const DtHorario&, const DtHorario&);
    // friend ostream& operator <<(const&, const DtHorario&);
};
#endif
