#include <iostream>
#include <string.h>

using namespace std;

// declaration of new variabels to be used in main
string jsonString; // input json formatted string
string outputJsonString; // output json formatted string without jibberish
string currentWorkingChar; // used to check current working character
int stringPlacement = 0; // used to find where in the string we currently are
int openBracketCount; // used to prevent a false positive when finding a closed bracket

int main(int argc, char** argv)
{
    jsonString = "fillerstuffatthestartofstring[{\"fname\":\"val1\", \"lname\": \"val2\", \"sums\":[1,2,3]},{\"fname\":\"val3\", \"lname\":\"val4\"}]fillerstuffattheendofstring";
    
    // loop to check every character 
    while (stringPlacement < jsonString.length())
    {
        // set currentWorkingChar 
        currentWorkingChar = jsonString[stringPlacement];
        if (currentWorkingChar == "[") // if a square bracket has been found, begin recording to output string
        {
            openBracketCount += 1; 
            while (openBracketCount > 0) // until the last closed bracket is found continue in this loop
            {
                // advance currentWorkingChar to being recording new string characters
                currentWorkingChar = jsonString[(stringPlacement+1)];
                if (currentWorkingChar == "[") // add to openBracketCount should another open bracket be found
                {
                    openBracketCount += 1;
                    // add currentWorking to the outputJsonString 
                    outputJsonString += currentWorkingChar;
                    stringPlacement += 1;
                }
                else if (currentWorkingChar == "]") // subtract from openBracketCount should a closed bracket be found
                {
                    openBracketCount -= 1;
                    if (openBracketCount == 0)
                    {
                        openBracketCount = 0;
                    }
                    else
                    {
                    outputJsonString += currentWorkingChar;
                    stringPlacement += 1;
                    }
                }
                else
                {
                // add currentWorking to the outputJsonString
                outputJsonString += currentWorkingChar;
                stringPlacement += 1;
                }
            }
        }
        else // no open square bracket has been found
        {
            stringPlacement += 1;
        }
    }
    
    cout << "Final output product:" << endl;
    cout << outputJsonString << endl;
    return 0;
}
