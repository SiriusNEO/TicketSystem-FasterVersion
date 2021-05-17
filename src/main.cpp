//TicketSystem main.cpp for test

#include "systemcore.hpp"

Sirius::System ticketSystem;

int main() {
    std::string cmd;
    while (getline(std::cin, cmd)) {
        auto res = ticketSystem.response(cmd);
        std::cout << res.second << '\n';
        if (!res.first) break;
        cmd.clear();
    }
    /*
    Sirius::FileManager<int, int> fm("test.bin");
    fm.insert(2, 666);
    std::cout << fm.find(2).first << '\n';
    fm.modify(2, 233);
    std::cout << fm.find(2).first << '\n';
    fm.del(2);
    std::cout << fm.find(2).second << '\n';
     */
    return 0;
}
