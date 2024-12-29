/* i don't speak any russian and this guy still managed to teach me classes
 * https://youtu.be/NA-v1eHF_gg
 */

#include <iostream>

class Weapon_Primary {
    private:
    std::string name;
    
    public:
    int damage;
    double damage_head;
    double rpm;
    void setName(std::string newName) {
        name = newName;
    }
    
    std::string getName() {
        return name;
    }
};

int main() {
    Weapon_Primary m4;
    m4.setName("M4");
    m4.damage = 22;
    m4.damage_head = (m4.damage * 1.72);
    m4.rpm = 530.0;
    
    std::cout << m4.getName() << " " << m4.damage_head;
    return 0;
}
