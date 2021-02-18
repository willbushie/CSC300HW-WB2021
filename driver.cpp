#include "Card.hpp"
#include "URL.hpp"
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char** argv)
{
    URL* u1 = new URL("https://api.hearthstonejson.com/v1/25770/enUS/cards.json");
    cout << u1->getContents() << endl;
    return 0;
}