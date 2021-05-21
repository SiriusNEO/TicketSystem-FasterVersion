//TicketSystem main.cpp for test

#include "systemcore.hpp"

Sirius::System ticketSystem;

void UserPressure() {
    std::vector<std::string> cache;
    ticketSystem.response("add_user -c root -u root -p 123 -n ADMIN -m xxx -g 10\n");
    ticketSystem.response("login -u root -p 123");
    for (int i = 1; i <= 500000; ++i) {
        auto uid = Sirius::randString(19);
        cache.push_back(uid);
        auto res = ticketSystem.response("add_user -c root -u " + uid + " -p 123 -n fofo -m xxx -g 3\n");
        for (auto ch : res.second) putchar(ch);
        putchar('\n');
    }
    for (auto uid : cache) {
        auto res = ticketSystem.response("login -p 123 -u " + uid + " \n");
        for (auto ch : res.second) putchar(ch);
        putchar('\n');
    }
};

int main() {
    std::string cmd;
    while (getline(std::cin, cmd)) {
        auto res = ticketSystem.response(cmd);
        for (auto ch : res.second) putchar(ch);
        putchar('\n');
        if (!res.first) break;
        cmd.clear();
    }

    /*
    Sirius::FileManager<Sirius::tidType , int> fm("test.bin");
    for (int i = 1; i <= 100000; i++) fm.insert("bomb"+std::to_string(i), i);
    auto ret = fm.rangeFind("", Sirius::TrainIDStr_Max);
    for (auto i : ret) printf("%d\n", i);
    */
}