#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int lineNumber = 1;
    string line, word = "";
    map<string, size_t>  Count;
    map<string, map<size_t, size_t>> Place;

    ifstream fd("input.txt");
    while(getline(fd,line))
    {
        for(int i = 0; i < line.length(); i++)
        {
            if(!(( line[i] >= ' ' && line[i] <= '/' ) || ( line[i] >= ':' && line[i] <= '?' ) || ( line[i] >= '[' && line[i] <= '`' ) || ( line[i] >= '{' && line[i] <= '~' )))
            {
                word.push_back(line[i]);
                while(!(( line[i+1] >= ' ' && line[i+1] <= '/' ) || ( line[i+1] >= ':' && line[i+1] <= '?' ) || ( line[i+1] >= '[' && line[i+1] <= '`' ) || ( line[i+1] >= '{' && line[i+1] <= '~' )) && i+1 < line.length())
                {
                    i++;
                    word.push_back(line[i]);
                }
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                Count[word]++;
                Place[word][lineNumber]++;
                word = "";
            }
        }
        lineNumber++;
    }
    fd.close();

    ofstream fr("output.txt");
    for (auto &i : Count)
        if(i.second > 1)
        {
            fr << "Word '" << i.first << "' is repeated " << i.second << " times:" << endl;
            for (auto &j : Place.at(i.first)){
                fr << "Line " <<j.first << " - " << j.second << " times" << endl;
            }
            fr << endl << endl;
        }

    return 0;


}