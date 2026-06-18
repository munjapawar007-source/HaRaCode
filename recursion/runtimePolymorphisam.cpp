#include<iostream>
#include<vector>
using namespace std;

class Enemy
{
    protected:
        int Health;
    public:
        Enemy()
        {
            Health = 0;
            cout << "In Enmay constructor\n";
        }

        virtual ~ Enemy()
        {
            cout << "In Enmay Destructor\n";
        }

        virtual int getHelath() const 
        {
            return Health;
        }
};

class Zombie : public Enemy
{
    public:
    Zombie() {
        Health = 110;
        cout << "In Zombie Constructor\n" << endl;
    }

    ~ Zombie()
    {
        cout << " In Zombie Destructor\n";
    }

    int getHealth() const{
        return Health;
    }

};


int main()
{
    std::vector<Enemy*> enemies;

    enemies.push_back(new Zombie());

    cout << "\n Display Health\n";
}