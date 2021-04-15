#include <string>

using namespace std;

class Card
{
    private:
        string name;
        string type;
        int mana_cost;
        int attack;
    
    public:
        int defense;
        Card(string name, string type, int mana_cost, int attack, int defense);
        void display();
};