#include <iostream>
#include <ctime>
using namespace std;

#include "Escape.h"

Escape::Escape() : numSnorcs(0), pit(nullptr), hero1(nullptr), hero2(nullptr) {
    srand(static_cast<unsigned>(time(nullptr)));

    int initialColumn1 = rand() % 10 + 7;

    int initialColumn2;
    do {
        initialColumn2 = rand() % 10 + 7;

    } while (initialColumn1 == initialColumn2);

    hero1 = new Hero('T', MAX_ROW-1, initialColumn1, "Timmy");
    hero2 = new Hero('H', MAX_ROW-1, initialColumn2, "Harold");

    participants.add(hero1);
    participants.add(hero2);

    const char templateGrid[MAX_ROW + 1][MAX_COL + 1] = {
        "-------------------------",
        "-             --        -",
        "-                      --",
        "-       --              -",
        "                  --    -",
        "--       -              -",
        "---                    --",
        "---       --          ---",
        "--                     --",
        "-            --        --",
        "---               --     ",
        "--        --    ---    --",
        "--  --                  -",
        "--        --       -     ",
        "--                  -    ",
        "--     --         --    -",
        "---                    --",
        "--       ---    --      -",
        "--                     --",
        "-------------------------"
    };
    pit = new Pit(templateGrid);
}

Escape::~Escape() {
    delete pit; 
    delete hero1; 
    delete hero2;
}

void Escape::runEscape() {
    while (!isOver()) {
        if (rand() % 100 < 90 && numSnorcs < 12)
            spawnSnorc();

        moveParticipants();

        system("clear");

        pit->print(&participants, hero1, hero2);
        std::this_thread::sleep_for(std::chrono::milliseconds(250)); 

    }
    printOutcome();
}


void Escape::spawnSnorc() {
    if (numSnorcs < 12 && rand() % 10 < 9) {

        int initialRow = rand() % 5 + (MAX_ROW - 4);
        if (initialRow == MAX_ROW) {
            initialRow += 1;
        }
        int initialColumn = rand() % MAX_COL;
        int strength = rand() % 3 + 2; 

        Snorc* newSnorc = new Snorc(initialRow, initialColumn, strength);
        participants.add(newSnorc);
        numSnorcs++;
    }
}

void Escape::moveParticipants() {
    for (int i = 0; i < participants.getSize(); i++) {
        Participant* participant = participants.get(i);

        if ((participant == hero1 && hero1->isSafe()) || (participant == hero2 && hero2->isSafe())) {
            continue;
        }

        participant->move(pit);

        Participant* collisionParticipant = checkForCollision(participant);
        if (collisionParticipant != nullptr) {
            participant->incurDamage(collisionParticipant);
            collisionParticipant->incurDamage(participant);
        }
    }
}


Participant* Escape::checkForCollision(Participant* p) {
    for (int i = 0; i < participants.getSize(); i++) {
        Participant* otherParticipant = participants.get(i);
        if (otherParticipant != p && otherParticipant->collide(p)) {
            return otherParticipant;
        }
    }
    return nullptr; 
}

bool Escape::isOver() {
    return (hero1->isDead() && hero2->isDead()) || (hero1->isSafe() && hero2->isSafe())
            || (hero1->getRow() == 1 && hero2->getRow() == 1);
}


void Escape::printOutcome() {
    pit->print(&participants, hero1, hero2);

    if (isOver()) {
        if (hero1->isDead() && hero2->isDead()) {
            cout << "Both heroes are dead." << endl;
        } else if (hero1->isSafe() && hero2->isSafe()) {
            cout << "Both heroes have escaped." << endl;
        } else if (hero1->isDead()) {
            cout << "Harold escaped. Timmy died." << endl;
        } else {
            cout << "Timmy escaped. Harold died." << endl;
        }
    }
}
