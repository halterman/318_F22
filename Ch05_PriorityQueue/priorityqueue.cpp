#include <iostream>
#include <queue>
#include <string>

struct Person {
    int id;
    std::string name;
};

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "[" << person.id << ", " << person.name << "]";
    return os;
}

struct CompID {
    bool operator()(Person p1, Person p2) {
        return p1.id > p2.id;
    }
};

struct CompName {
    bool operator()(Person p1, Person p2) {
        return p1.name > p2.name;
    }
};

int main() {
    std::priority_queue<Person, std::vector<Person>, CompID> pq1;
    pq1.push({10, "Fred"});
    pq1.push({ 4, "Wilma"});
    pq1.push({44, "Barney"});
    pq1.push({ 7, "Betty"});
    pq1.push({32, "Dino"});
    pq1.push({19, "Pebbles"});
    while (!pq1.empty()) {
        Person p = pq1.top();
        pq1.pop();
        std::cout << p << '\n';
    }
    std::cout << "\n-------------------------------\n"; 

    std::priority_queue<Person, std::vector<Person>, CompName> pq2;
    pq2.push({10, "Fred"});
    pq2.push({ 4, "Wilma"});
    pq2.push({44, "Barney"});
    pq2.push({ 7, "Betty"});
    pq2.push({32, "Dino"});
    pq2.push({19, "Pebbles"});
    while (!pq2.empty()) {
        Person p = pq2.top();
        pq2.pop();
        std::cout << p << '\n';
    }
     
}
