#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

struct Weapon {
    std::string name;
    double damage;
    double rpm;
};

float calculate_ttk(double dmg, double rpm, double hp) {
    int shots = ceil(hp / dmg);
    
    double rps = rpm / 60;
    
    double ttk = (shots - 1) / rps;
    //std::cout << std::to_string(ttk) << std::endl;
    return std::max(ttk, 0.0);
}

int main() {
    std::cout << "\n";
    std::vector<Weapon> weapons = {
        {"ASS", 22.0, 530.0},
        {"BAN", 18.0, 630.0},
        {"TAC", 26.0, 430.0},
        {"SNI", 70.0, 120.0},
        {"PIS", 40.0, 400.0},
        {"REV", 50.0, 400.0}
    };
    
    double health;
    bool ran = false;
    while (true) {
        if (ran != true) {
            std::cout << "enter health (must be number)\n";
        }
        std::cin >> health;
        ran = true;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::string invalidInput;
            std::cin >> invalidInput; 
            if (invalidInput == "q" || invalidInput == "Q") {
                std::cout << "cya\n";
                break;
            }
            std::cerr << "i said a number\n";
            continue;
        }
        
        if (health <= 0) {
            std::cerr << "its a number but you cant have negative health\n";
            continue;
        }
        
        std::cout << "\nBody:\n";
        for (const auto& weapon : weapons) {
            double ttk = calculate_ttk(weapon.damage, weapon.rpm, health);
            printf("%s DMG: %.0lf RPM: %.0lf TTK: %.3f \n", weapon.name.c_str(), weapon.damage, weapon.rpm, ttk);
        }
        std::cout << "\n";
        
        std::cout << "Head:\n";
        for (const auto& weapon : weapons) {
            double hsdmg = weapon.damage * 1.72;
            double ttk = calculate_ttk(hsdmg, weapon.rpm, health);
            printf("%s HSDMG: %.0lf RPM: %.0lf TTK: %.3f \n", weapon.name.c_str(), hsdmg, weapon.rpm, ttk);
        }
        std::cout << "\n";
    }
    
    return 0;
}
