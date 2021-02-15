#include "Card.hpp"

int main(int argc, char* argv[])
{
    Card* KingKrush = new Card("King Krush", 9, 8, 8);
    //(*KingKrush).display(); same as the line below it
    KingKrush->display();

    Card* AmaraWardenofHope = new Card("Amara, Warden of Hope", 5, 8, 8);
    AmaraWardenofHope->display();

    Card* ChaosGazer = new Card("Chaos Gazer", 3, 4, 3);
    ChaosGazer->display();

    Card* HalazziTheLinx = new Card("Hallazzi, the Linx", 5, 3, 2);
    HalazziTheLinx->display();
}