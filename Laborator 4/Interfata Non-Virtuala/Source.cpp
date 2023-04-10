#include <iostream>


class curs {
public:
    void evalueaza() {
        std::cout << "evaluarea a început\n";
        examineaza();
        corecteaza();
        noteaza();
        std::cout << "evaluarea s-a încheiat\n";
    }
private:
    virtual void examineaza() = 0;
    virtual void corecteaza() = 0;
    virtual void noteaza() = 0;
};

class curs_obligatoriu : public curs {
private:
    void examineaza() override { /* codul din curs_obligatoriu::examineaza() */ }
    void corecteaza() override { /* codul din curs_obligatoriu::corecteaza() */ }
    void noteaza() override { /* codul din curs_obligatoriu::noteaza() */ }
};

class curs_optional : public curs {
private:
    void examineaza() override { /* codul din curs_optional::examineaza() */ }
    void corecteaza() override { /* codul din curs_optional::corecteaza() */ }
    void noteaza() override { /* codul din curs_optional::noteaza() */ }
};