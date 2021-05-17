//TicketSystem main.cpp for test

#include "systemcore.hpp"

Sirius::System ticketSystem;

int main() {
    std::string cmd;
    while (getline(std::cin, cmd)) {
        auto res = ticketSystem.response(cmd);
        for (auto ch : res.second) putchar(ch);putchar('\n');
        if (!res.first) break;
        cmd.clear();
    }
    return 0;
}
