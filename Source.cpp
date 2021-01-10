

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int MAX_NUM_OF_BOOKS = 10;

struct
{
    int place;
    string aName;
    string aLast;
    string bookName;
    int ibn;
} library[MAX_NUM_OF_BOOKS] ;

void update ();
int getAction ();


int main ()
{
    int action;
    update ();
    action = getAction();
    cout << "Your action is " << action ;



    return 0;
}


void update ()
{
    ifstream dataIn;
    ofstream dataOut;
    string fileName = "library.txt";


    dataIn.open ( fileName );

    for ( int i = 0; i < MAX_NUM_OF_BOOKS; i++)
    {
        dataIn >> library[i].place;
        dataIn >> library[i].aName;
        dataIn >> library[i].aLast;
        dataIn >> library[i].bookName;
        dataIn >> library[i].ibn;
    }

   //To test the upload
   /* for ( int i = 0; i < MAX_NUM_OF_BOOKS; i++)
    {
        cout << library[i].place << endl;
        cout << library[i].aName << endl;
        cout << library[i].aLast << endl;
        cout << library[i].bookName << endl;
        cout << library[i].ibn << endl;
    }
     dataIn.close();*/
}

int getAction ()
{
    int userChoice = -1;


    while ( ( userChoice < 0 ) || ( userChoice > 3 ) )
    {
        cout << "Select an action from the menu: " << endl;
        cout << "1. Add a new book " << endl;
        cout << "2. Search for an existing book" << endl;
        cout << "3. Exit program" << endl;
        cin >> userChoice;
        if ( ( userChoice < 0 ) || ( userChoice > 3 ) )
        {
            cout << "You selected an invalid action, please try again." << endl;
        }
    }
    return userChoice;
}









