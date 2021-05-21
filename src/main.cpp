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
    for (auto it = cache.rbegin(); it != cache.rend(); it++) {
        auto res = ticketSystem.response("login -p 123 -u " + *it + " \n");
        for (auto ch : res.second) putchar(ch);
        putchar('\n');
    }
}

void TrainPressure() {
    std::vector<std::string> cache;
    for (int i = 1; i <= 500000; ++i) {
        auto tid = Sirius::randString(19);
        cache.push_back(tid);
        auto res = ticketSystem.response("add_train -i " + tid + " -n 3 -m 1000 -s 上院|中院|下院 -p 114|514 -x 19:19 -t 600|600 -o 5 -d 06-01|08-17 -y G\n");
        for (auto ch : res.second) putchar(ch);
        putchar('\n');
    }
    int cnt = 0;
    for (auto it = cache.begin(); it != cache.end(); it++) {
        auto res = ticketSystem.response("query_train -d 07-01 -i " + *it + " \n");
        for (auto ch : res.second) putchar(ch);
        putchar('\n');
        ++cnt;
        printf("%d\n", cnt);
    }
}

int main() {
    //TrainPressure();

    std::string cmd;
    while (getline(std::cin, cmd)) {
        auto res = ticketSystem.response(cmd);
        for (auto ch : res.second) putchar(ch);
        putchar('\n');
        if (!res.first) break;
        cmd.clear();
    }
}