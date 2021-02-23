#include "Card.hpp"
#include "URL.hpp"
#include <iostream>
#include <string>
#include "myFunctions.hpp"

using namespace std;

int main(int argc, char** argv)
{
    //URL* u1 = new URL("https://api.hearthstonejson.com/v1/25770/enUS/cards.json");
    //cout << u1->getContents() << endl;
    string jsonString = "[{\"fname\":\"val1\", \"lname\": \"val2\", \"sums\":[1,2,3]},{\"fname\":\"val3\", \"lname\":\"val4\"}]";
    cout << jsonString << endl;
    string answer = processJSON(jsonString);
    cout << answer << endl;
    
    return 0;
}

string processJSON(string json)
{
    string temp = "";
    if(json[0] == '[')
    {
        int countSquareBrackets = 1;
        //process contents of the array
        for(int i = 1; i < json.length(); i++)
        {
            if(json[i] == '[')
            {
                countSquareBrackets++;
            }
            else if(json[i] == ']')
            {
                countSquareBrackets--;
                if(countSquareBrackets == 0)
                {
                    return temp;
                }
            }
            temp = temp + json[i];
            
        }

    }
    return "Something went wrong!!!";

}