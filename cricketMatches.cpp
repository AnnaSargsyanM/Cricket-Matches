//     This program asks how many students were surveyed, and 
//     how mant matches they played. Then, it dynamically allocates
//     the array for number of students and matches played.
//     
//****************************************************************************************************

#include <iostream>
#include <string>

using namespace std;

void input(string[], int[], int);

void display(const string[], const int[], int);

void displayMostMatches(const string[], const int[], int);

double mean(const int[], int);

void sortStudents(string[], int[], int);

//****************************************************************************************************

int main()
{
    int numStudents;
    cout << "How many students were surveyed? ";
    cin >> numStudents;

    string* studentNames = new string[numStudents];
    int* matchesPlayed = new int[numStudents];

    input(studentNames, matchesPlayed, numStudents);

    cout << endl;
    cout << "Displaying student data:\n";
    display(studentNames, matchesPlayed, numStudents);

    cout << endl;
    displayMostMatches(studentNames, matchesPlayed, numStudents);

    double averageMatches = mean(matchesPlayed, numStudents);
    cout << "Average number of matches played: " << averageMatches << endl;

    sortStudents(studentNames, matchesPlayed, numStudents);

    cout << "\nDisplaying sorted student data:\n";
    display(studentNames, matchesPlayed, numStudents);

    delete[] studentNames;
    delete[] matchesPlayed;

    return 0;

}

//****************************************************************************************************

void input(string names[], int matches[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> names[i];

        do 
        {
            cout << "Enter the number of cricket matches played by " 
                << names[i] << ": ";
            cin >> matches[i];

            if (matches[i] < 0) 
            {
                cout << "Enter a non-negative number of matches.\n";
            }
        } while (matches[i] < 0);
    }

}

//****************************************************************************************************

void display(const string names[], const int matches[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        cout << "Name: " << names[i] << ", Matches Played: " 
            << matches[i] << endl;
    }

}

//****************************************************************************************************

void displayMostMatches(const string names[], const int matches[],
	int size)
{
    int maxMatches = -1;
    string playerName;

    for (int i = 0; i < size; i++)
    {
        if (matches[i] > maxMatches)
        {
            maxMatches = matches[i];
            playerName = names[i];
        }  
    }

    cout << "The most matches played:\n";
    cout << "Name: " << playerName << endl;
    cout << "The number of matches: " << maxMatches << endl;
}

//****************************************************************************************************

double mean(const int matches[], int num)
{
    int totalMatches = 0;

    for (int i = 0; i < num; i++) 
    {
        totalMatches += matches[i];
    }

    return static_cast<double>(totalMatches) / num;

}

//****************************************************************************************************

void sortStudents(string names[], int matches[], int size)
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (names[j] > names[j + 1]) 
            {
                string tempName = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempName;

                int tempMatches = matches[j];
                matches[j] = matches[j + 1];
                matches[j + 1] = tempMatches;
            }
        }
    }

}

//****************************************************************************************************
/*

How many students were surveyed? 3
Enter the name of student 1: David
Enter the number of cricket matches played by David: 4
Enter the name of student 2: Anna
Enter the number of cricket matches played by Anna: 3
Enter the name of student 3: Elena
Enter the number of cricket matches played by Elena: 5

Displaying student data:
Name: David, Matches Played: 4
Name: Anna, Matches Played: 3
Name: Elena, Matches Played: 5

The most matches played:
Name: Elena
The number of matches: 5
Average number of matches played: 4

Displaying sorted student data:
Name: Anna, Matches Played: 3
Name: David, Matches Played: 4
Name: Elena, Matches Played: 5

*/

