#include <iostream>
#include <string>
#include "LinkedList.hpp"

using namespace std;

int main(int argc, char** argv)
{
    //URL* u1 = new URL("https://api.hearthstonejson.com/v1/25770/enUS/cards.json");
    //cout << u1->getContents() << endl;
    //string jsonString = "[{\"fname\":\"val1\", \"lname\": \"val2\", \"sums\":[1,2,3]},{\"fname\":\"val3\", \"lname\":\"val4\"}]";
    //cout << jsonString << endl;
    //processJSONObject(jsonString, 0);
    LinkedList* ll = new LinkedList();
    ll->addEnd(4);
    ll->addEnd(6);
    ll->addEnd(8);
    ll->addEnd(2);
    ll->display();
    int valueRME = ll->removeEnd();
    int valueRMF = ll->removeFront();
    ll->display();
    ll->addFront(1);
    ll->display();
    cout << valueRME << endl;
    cout << valueRMF << endl;
    return 0;
}
/*
string processJSONObject(string json, int start)
{
    if(json[start] == '[')
    {
        return processJSONArray(json, start);
    }
    else if(json[start] == '{')
    {
        //must be an json object
        string temp = "";
        int countCurlyBraces = 1;
        for(int i = start+1; i < json.length(); i++)
        {
            if(json[i] == '{')
            {
                temp += '{';
                string answer = processJSONObject(json, i);
                temp += answer;
                i += answer.length()+1;
                countCurlyBraces++;
            }
            else if(json[i] == '}')
            {
                countCurlyBraces--;
                if(countCurlyBraces == 0)
                {
                    cout << temp << endl;
                    return temp;
                }
            }
            else if(json[i] == '[')
            {
                temp += '[';
                string answer = processJSONArray(json, i);
                temp += answer;
                i += answer.length()+1;
            }

            if(i < json.length())
            {
                temp = temp + json[i];
            }  
        }
    }
}

string processJSONArray(string json, int start)
{
    string temp = "";
    int countSquareBrackets = 1;
    //process contents of the array
    for(int i = start+1; i < json.length(); i++)
    {
        if(json[i] == '[')
        {
            string answer = processJSONArray(json, i);
            temp += answer;
            i += answer.length()+1;
            countSquareBrackets++;
        }
        else if(json[i] == ']')
        {
            countSquareBrackets--;
            if(countSquareBrackets == 0)
            {
                cout << temp << endl;
                return temp;
                //return temp;
            }
        }
        else if(json[i] == '{')
        {
            temp += '{';
            string answer = processJSONObject(json, i);
            temp += answer;
            i += answer.length()+1;
        }
        
        if(i < json.length())
        {
            temp = temp + json[i];
        }  
        
    }
}
*/
