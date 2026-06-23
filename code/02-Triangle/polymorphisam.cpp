#include<iostream>
#include<vector>
using namespace std;

class Enemy
{
    private:
        int health;
    
    public:
        Enemy()
        {
            health = 00;
            cout << "in enemy constructor\n";
        }

         ~Enemy()
        {
            cout << "in enemy distructor\n";
        }

        int getHealth()const // func chya atil value change karta yet nahi
        {
            return health; 
        }
};

class Robo:public Enemy
{
    private:
         int health;
    public:
        Robo()
        {
            health = 100;
            cout << "in Robo constructor\n";
        }

        ~Robo()
        {
            cout << "in robo distructor\n";
        }

       int getHealth() const
       {
            return health;

        }
};

class Ghost:public Enemy
{
    private:
        int health;

    public:
        Ghost()
        {
            health = 999;
            cout << "in ghost constructor\n";
        }

        ~Ghost()
        {
            cout << "in Ghost Distructor\n";
        }

        int getHealth()const
        {
            return health;
        }
};

int main()
{
    std::vector<Enemy*> enemies;

    Enemy* roboEnemy = new Robo();
    enemies.push_back(roboEnemy);

    Enemy* ghostEnemy = new Ghost();
    enemies.push_back(ghostEnemy);

    for (Enemy* enemy:enemies)
    {
        std::cout << enemy->getHealth() << std::endl;
    }

    for(Enemy* enemy:enemies)
    {
        delete enemy;
    }
}
