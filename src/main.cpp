//TicketSystem main.cpp for test

#include "systemcore.hpp"

Sirius::System ticketSystem;

int main() {
    while (getline(std::cin, cmd)) {
        auto res = ticketSystem.response(cmd);
        std::cout << res.second << '\n';
        if (!res.first) break;
        cmd.clear();
    }
    return 0;
}
