#include <cassert>
#include <iostream>

#include "character.h"

void testApplyDamage() {
    Character mael{1, 1, 100, 3, 0};

    applyDamage(mael, 20);
    assert(mael.energy == 80);

    mael.energy = 30;
    applyDamage(mael, 50);
    assert(mael.energy == 0);

    mael.energy = 40;
    applyDamage(mael, 40);
    assert(mael.energy == 0);

    mael.energy = 100;
    applyDamage(mael, -20);
    assert(mael.energy == 100);


    applyDamage(mael, 0);
    assert(mael.energy == 100);

    std::cout << "Testes de dano aprovados!" << std::endl;
}

void testRecoverEnergy() {
    Character mael{1, 1, 50, 3, 0};

    recoverEnergy(mael, 20, 100);
    assert(mael.energy == 70);

    mael.energy = 85;
    recoverEnergy(mael, 30, 100);
    assert(mael.energy == 100);

    mael.energy = 100;
    recoverEnergy(mael, 20, 100);
    assert(mael.energy == 100);

    mael.energy = 40;
    recoverEnergy(mael, -10, 100);
    assert(mael.energy == 40);

    recoverEnergy(mael, 0, 100);
    assert(mael.energy == 40);

    recoverEnergy(mael, 20, 0);
    assert(mael.energy == 40);

    std::cout << "Testes de recuperação aprovados!" << std::endl;
}

int main() {
    testApplyDamage();
    testRecoverEnergy();

    return 0;
}
