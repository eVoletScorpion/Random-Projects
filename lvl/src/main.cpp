#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct baseItem {
    string name;
    int level;
    double stat1;
    double stat2;
    
    baseItem(const string& name, int level,
    double stat1, double stat2) : name(name),
    level(level), stat1(stat1), stat2(stat2) {}
    
    virtual ~baseItem() = default;
};

struct itemClass : public baseItem {
    itemClass(const string& name, int level,
    double stat1, double stat2) : baseItem(name,
    level, stat1, stat2) {}
};

struct itemWeapon : public baseItem {
    itemWeapon(const string& name, int level,
    double stat1, double stat2) : baseItem(name,
    level, stat1, stat2) {}
};

void print(const string& thing) {
    cout << thing << " ";
}

void levelUp(const string& itemName,
    vector<itemWeapon>& weapons, 
    vector<itemClass>& classes) {
        
        double base = 1.00;
        double result;
        
    for (auto& weapon : weapons) {
        if (weapon.name == itemName) {
            weapon.level += 1;
            
            for (int i = 0; i <= weapon.level; i++) {
                result = base + 0.05 * i;
            }

            double newStat1 = weapon.stat1 * result;
            double newStat2 = weapon.stat2 * result;

            cout << weapon.name << ": Level " << weapon.level 
                 << ", Damage: " << newStat1 
                 << ", RPM: " << newStat2 << " \n";
            return;
        }
    }

    for (auto& classItem : classes) {
        if (classItem.name == itemName) {
            classItem.level += 1;
            
            for (int i = 0; i <= classItem.level; i++) {
                result = base + 0.05 * i;
            }
            
            double newStat1 = classItem.stat1 * result;
            double newStat2 = classItem.stat2 * result;

            cout << classItem.name << ": Level " << classItem.level 
                 << ", Health: " << newStat1 
                 << ", Speed: " << newStat2 << " \n \n";
            return;
        }
    }

    throw invalid_argument("item not found: " + itemName);
}

int main() {
    vector<itemWeapon> weapons = {
        {"M4", 0, 22.0, 530.0},
        {"Tommy", 0, 18.0, 630.0},
        {"Sten", 0, 26.0, 430.0},
        {"Sniper", 0, 70.0, 120.0},
        {"Launcher", 0, 100, 125},
        {"RPG", 0, 200, 100},
        {"Pistol", 0, 40.0, 400.0},
        {"Revolver", 0, 50.0, 400.0}
    };
    
    vector<itemClass> classes = {
        {"Assault", 0, 200, 20},
        {"Bandit", 0, 150, 22},
        {"Tactical", 0, 225, 16},
        {"Sniper", 0, 150, 18},
        {"Boomsmith", 0, 175, 18},
        {"Rocketeer", 0, 200, 18}
    };
    
    string item;
    
    while (true) {
        cout << "Write item name to level it up \n" << " \n";
        cin >> item;
        levelUp(item, weapons, classes);
    }
   // cout << __cplusplus;
  //  levelUp("Sniper", weapons, classes);
   // cout << "Hello, World!";
    return 0;
}

