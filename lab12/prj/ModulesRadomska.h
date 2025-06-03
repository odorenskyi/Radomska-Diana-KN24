#ifndef MODULESRADOMSKA_H_INCLUDED
#define MODULESRADOMSKA_H_INCLUDED

class ClassLab12_Radomska {
private:
    float a;

public:
    ClassLab12_Radomska(float a);
    float getA();
    void setA(float a);
    float getVolume();
};

ClassLab12_Radomska::ClassLab12_Radomska(float a) : a(a) {}

float ClassLab12_Radomska::getA() { return a; }

void ClassLab12_Radomska::setA(float a) { this->a = a; }

float ClassLab12_Radomska::getVolume() { return a * a * a; }

#endif // MODULESRADOMSKA_H_INCLUDED