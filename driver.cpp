#include "Card.hpp"
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char** argv)
{
    //Card* KingKrush = new Card("King Krush", 8, 8, 8);
    //(*KingKrush).display();
    //KingKrush->display();
    char url[1000] = "https://api.hearthstonejson.com/v1/25770/enUS/cards.json";
    
    fstream fs;
    fs.open(url);
    string str;
    getline(in,str);  // Get the frist line from the file, if any.
    while ( in ) 
    {  // Continue if the line was sucessfully read.
        cout << str << endl;  // Process the line.
        getline(in,str);   // Try to get another line.
    }
    fs.close();

    return 0;
}