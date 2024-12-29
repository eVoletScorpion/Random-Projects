/*i asked chatgpt to write /ttk/ttk.lua in c++ and it spat this out
it works from 1 minute of testing, but for level 1 you have to input 0 lol
im not fixing it*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>

struct Weapon {
    std::string name;
    int damage;
    int rpm;
};

int health = 200;
std::vector<Weapon> weapons = {
    {"M4", 22, 530},
    {"TOMMY", 18, 630},
    {"STEN", 26, 430},
    {"SNIPER", 70, 120},
    {"PISTOL", 40, 400},
    {"REVOLVER", 50, 400}
};

float calculate_ttk(float damage, int health, int rpm) {
    int shots_to_kill = std::ceil(static_cast<float>(health) / damage);
    float rps = static_cast<float>(rpm) / 60.0f;
    float ttk = (shots_to_kill - 1) / rps;
    return std::max(ttk, 0.0f);
}

float calculate_dps(int damage, int rpm) {
    return damage * rpm / 60.0f;
}

std::vector<std::string> split(const std::string& input, char delimiter = ' ') {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void add_item(const std::string& name, int damage, int rpm) {
    weapons.push_back({name, damage, rpm});
}

void list_weapons() {
    for (const auto& weapon : weapons) {
        std::cout << weapon.name << " DMG: " << weapon.damage << " RPM: " << weapon.rpm << "\n";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Commands:\nadd [name] [damage] [rpm],\nttk [name] [level],\nhealth [number],\nlist,\nquit\n";

    while (true) {
        std::string input;
        std::getline(std::cin, input);
        auto words = split(input);
        if (words.empty()) continue;

        std::string command = words[0];
        std::transform(command.begin(), command.end(), command.begin(), ::tolower);

        if (command == "ttk") {
            if (words.size() < 3) {
                std::cout << "Missing weapon or level argument\n";
                continue;
            }

            std::string inputWeapon = words[1];
            std::transform(inputWeapon.begin(), inputWeapon.end(), inputWeapon.begin(), ::toupper);
            int level = std::stoi(words[2]);

            Weapon* weapon = nullptr;
            for (auto& w : weapons) {
                if (w.name == inputWeapon) {
                    weapon = &w;
                    break;
                }
            }

            if (!weapon) {
                std::cout << "Weapon not found\n";
                continue;
            }

            float result = 1.0f;
            for (int i = 1; i <= level; ++i) {
                result += 0.05f;
            }

            float damage = weapon->damage * result;
            float ttk = calculate_ttk(damage, health, weapon->rpm);

            std::cout << std::fixed << std::setprecision(2);
            std::cout << weapon->name << "\nDMG: " << damage << " RPM: " << weapon->rpm
                      << "\nTTK: " << ttk << "\nLVL: " << level << " HP: " << health << "\n";
        } else if (command == "health") {
            if (words.size() < 2) {
                std::cout << "Missing health argument\n";
                continue;
            }
            health = std::stoi(words[1]);
            std::cout << "Health is now " << health << "\n";
        } else if (command == "list") {
            list_weapons();
        } else if (command == "add") {
            if (words.size() < 4) {
                std::cout << "Missing arguments\n";
                continue;
            }
            std::string name = words[1];
            int dmg = std::stoi(words[2]);
            int rpm = std::stoi(words[3]);
            add_item(name, dmg, rpm);
        } else if (command == "quit" || command == "q" || command == "exit") {
            std::cout << "cya\n";
            break;
        } else {
            std::cout << "Unknown command, try again\n";
        }
    }

    return 0;
}
