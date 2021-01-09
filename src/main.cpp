#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

string mixLetter(string letterWord)
{
    string mix;
    int position(0);

    while (letterWord.size() != 0)
    {
        position = rand() % letterWord.size();
        mix += letterWord[position];
        letterWord.erase(position, 1);
    }
    return mix;
}

int space()
{
    char i;

    while (i <= 3)
    {
        cout << endl;
        i++;
    }
}


string randomWord()
{
    string line, word, b;
    string const dicoTxt("/home/yvs/code/yvs1364/cplusplus/mysteryWord/src/dico.txt");

    ifstream dico(dicoTxt);
    int numbWord(0);
    
    if(dico)
    {

    while(getline(dico, line))
        { 
            numbWord++;
        }
        dico.clear();
        dico.seekg(0, ios::beg);

        int index = rand() % numbWord;    
      

        int j;
        while(j < index)
        {
            getline(dico, b);
            j++;
        }
        return b;
    }
    else
    {
     cout << "error dico.txt doesn't load" << endl;
     exit(1);
    }
   
}


int main()
{
    string word, userInput, mixWord, yesNo;
    int chance(5), score(0);
    srand(time(0));

    do
    {
        cout << "----- Welcome to the Mystery Word -----" << endl;
        word = randomWord();
        cout <<  word << endl;
    
        space();
        space();
        
        mixWord = mixLetter(word);
        
        do
        {
           cout << " what is this word ? " << mixWord << endl;
            cout << "You have " << chance << " try" << endl;
            cin >> userInput;

            if (userInput == word)
            {
                cout << "Congratulations the word is " << word << endl;
                score += 10;
                cout << "your score is : " << score << endl;
            }
            else if (chance <= 0)
            {
                cout << "Game over !" << endl;
                break;
            }
            else
            {
                space();
                cout << "Nop ! try again" << endl;
                chance--;
            }
        } while (userInput != word);
        cout << "retry? y/n" << endl;
        cin >> yesNo;

        if (yesNo == "n")
        {
            break;
        }
    } while (yesNo == "y");

    return 0;
}
