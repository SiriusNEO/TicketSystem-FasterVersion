//TicketSystem main.cpp for test

#include "systemcore.hpp"

Sirius::System ticketSystem;
char buffer[7005];

struct A {
    int a, b;
};

int main() {
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, 7000, stdin);
        if (!ticketSystem.response(buffer)) return 0;
    }
}