/* This application is designed to assist a librarian with a book keeping task. */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>


using namespace std;

const int MAX_NUM_OF_BOOKS = 10; // maximum number of books that we can store


// structure that will hold all of the library data
struct
{
    string place;
    string status;
    string aName;
    string aLast;
    string bookName;
    string ibn;
} library[MAX_NUM_OF_BOOKS] ;


// function prototype

void upload ();
int getAction ();
void write ();
void addBook ();
void searchBook ();


// Main function acts as a driver function

int main ()
{
    int action;

    upload (); // call this function to do initial file upload into the structure

    //up until user decides to close application, keep the app going

    do
    {
        action = getAction(); // get action that user wants to do

        // Based on the action chosen, perform that action

        switch ( action )
        {
            case 1:
                addBook ();
            break;

            case 2:
                //searchBook ();
            break;

        case 3:
            cout << "Thanks for using. " << endl;
            write (); // call this function to write all of the changes into the file.
            exit (0);
        }
    }
    while (true);




    return 0;
}

/* Description of function "upload"
    This function will upload already existent data into the library structure */

void upload ()
{
    ifstream dataIn; // to hold the variable with an open file

    string fileName = "library.txt"; // file name


    dataIn.open ( fileName ); // open file

    // Upload all of the data from the file

   for ( int i = 0; i < MAX_NUM_OF_BOOKS; i++)
    {
        getline ( dataIn, library[i].place );
        getline ( dataIn, library[i].status );
        getline ( dataIn, library[i].aName );
        getline ( dataIn, library[i].aLast );
        getline ( dataIn, library[i].bookName );
        getline ( dataIn, library[i].ibn );
    }

   //To test the upload
    for ( int i = 0; i < MAX_NUM_OF_BOOKS; i++)
    {
        cout << library[i].place << endl;
        cout << library[i].status << endl;
        cout << library[i].aName << endl;
        cout << library[i].aLast << endl;
        cout << library[i].bookName << endl;
        cout << library[i].ibn << endl;
    }
     dataIn.close(); // close the file
}


/* Description of function "getAction"
    This function will prompt the user to enter one of the actions that one wants to perform that are available from the main menu */

int getAction ()
{
    string userChoice; // string to hold the user`s input

    int convertedUserChoice = -1; // hold the converted user`s input from string to int

    // Prompt the user to input the desired choice, force him to do so up until valid option is chosen


    while ( ( convertedUserChoice < 0 ) || ( convertedUserChoice > 3 ) )
    {
        cout << "Select an action from the menu: " << endl;
        cout << "1. Add a new book " << endl;
        cout << "2. Search for an existing book" << endl;
        cout << "3. Exit program" << endl;
        cout << "______________________________" << endl;
        getline ( cin, userChoice); // get input

        // convert string to int

        stringstream in(userChoice);
        in >> convertedUserChoice;

        //if wrong option was chosen, start it over

        if ( ( convertedUserChoice < 0 ) || ( convertedUserChoice > 3 ) )
        {
            cout << "You selected an invalid action, please try again." << endl;
        }
    }
    return convertedUserChoice;
}

/* Description of function "addBook"
    This function will add a new book to an empty position in the structure */

void addBook ()
{
    string emptySpot;
    int position;
    char space;

    // Look for an empty spot in the structure. Empty spot is indicated by "n" symbol

    for ( int i = 0; i < MAX_NUM_OF_BOOKS; i++ )
    {
        emptySpot = library[i].status;
        if ( emptySpot == "n" )
        {
            position = i;
            break;
        }
    }

    // Prompt the user through the book adding process

    cout << "You are adding a new book to the library" << endl;
    cout << "Please follow the prompts on the screen, if you wish to skip the certain prompt, please enter 0." << endl;
    cout << "Enter author`s first name:" << endl;
    getline ( cin, library[position].aName );
    cout << "Enter author`s last name:" << endl;
    getline ( cin,  library[position].aLast );
    cout << "Enter book name:" << endl;
    getline (cin, library[position].bookName);
    cout << "Enter IBN number:" << endl;
    getline (cin, library[position].ibn );
    library[position].status = 'y'; // indicate that that position is taken

    cout << "New book was successfully added." << endl;
    cout << "________________________________" << endl;
}

/* Description of function "write"
    This function will update the file before closing the application */

void write ()
{
   ofstream dataOut; // variable that points  to the file
   dataOut.open("library.txt"); // name of the file

   for (int i = 0; i < MAX_NUM_OF_BOOKS; i++ )
   {
        dataOut << library[i].place << endl;
        dataOut << library[i].status << endl;
        dataOut << library[i].aName << endl;
        dataOut << library[i].aLast << endl;
        dataOut << library[i].bookName << endl;
        dataOut << library[i].ibn << endl;
   }

    dataOut.close (); // close the file
}


/*void searchBook ()
{
*/

