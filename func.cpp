#include <iostream>

class Weapon {
protected:
    int _damage;
    int _bullets;
public:
    Weapon(int damage, int bullets) :
        _damage{ damage }, _bullets{ bullets } {}

    
    virtual void Shoot() {
        _bullets--;
        std::cout << "Bang!" << std::endl;
        std::cout << "Bullets: " << _bullets << std::endl;
    }
};

class Gun : public Weapon {
public:
    Gun(int damage, int bullets) :
        Weapon(damage, bullets){}

     void Shoot() override {
        std::cout << "---Gun---" << std::endl;
        Weapon::Shoot();
    }
};

class Rifle : public Weapon {
public:
    Rifle(int damage, int bullets) :
        Weapon(damage, bullets) {}

    void Shoot() override {
        std::cout << "---Rifle---" << std::endl;
        _bullets-=3;
        std::cout << "Bang! Bang! Bang!" << std::endl;
        std::cout << "Bullets: " << _bullets << std::endl;
    }
};


int main()
{
    Weapon** array = new Weapon * [3];
    array[0] = new Gun(15, 7);
    array[1] = new Gun(10, 15);
    array[2] = new Rifle(24, 30);
    
    for (size_t i = 0; i < 3; i++)
    {
        array[i]->Shoot();
    }

    for (size_t i = 0; i < 3; i++)
    {
        delete array[i];
    }
}
