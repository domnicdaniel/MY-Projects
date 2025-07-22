#include <iostream>
#include <iomanip>                        // <iomanip> stands for "input/output manipulators". It contains functions and objects
                                          // that help you format your output in a clean and controlled way..ex:setw()
using namespace std;

const int Row = 5;
const int Col = 10;

// Function to display the seat chart
void display(bool seats[Row][Col])
{
    system("cls");                       // Clear screen (Windows only)
    cout << "  ";
    for (int i = 1; i <= Col; i++)
    {
        cout << setw(3) << i;            //For column numbers
    }
    cout << endl;

    for (int i = 0; i < Row; i++)
    {
        cout << static_cast<char>('A' + i) << " ";      //Converts the integer result back into a character (like 66 → 'B')or we also use char()
        for (int j = 0; j < Col; j++)
        {
            cout << setw(3) << (seats[i][j] ? "X" : "-"); //Ternary opertaor
        }
        cout << endl;
    }
}

// Function to reserve a seat
void reserveSeat(bool seats[Row][Col], char row, int col)
{
    int rowIndex = row - 'A';
    int colIndex = col - 1;

    if (seats[rowIndex][colIndex])
    {
        cout << "Seat " << row << col << " is already reserved." << endl;
    }
    else
    {
        seats[rowIndex][colIndex] = true;
        cout << "Seat " << row << col << " reserved successfully." << endl;
    }
}

int main()
{
    bool seats[Row][Col] = {false};  // Initialize all to false
    char row;
    int col;
    int numberOfSeats;

    while (true)
    {
        display(seats);
        cout << "How many seats do you want to book? ";
        cin >> numberOfSeats;

        for (int i = 0; i < numberOfSeats; ++i)
        {
            cout << "Enter seat " << i + 1 << " details:" << endl;
            cout << "Enter Row (A-E): ";
            cin >> row;
            cout << "Enter Column (1-10): ";
            cin >> col;

            // Input validation
            if ((row < 'A' || row > 'E') || (col < 1 || col > 10))
            {
                cout << "Invalid Row or Column! Please try again." << endl;
                --i; // Retry this seat
                continue;
            }

            reserveSeat(seats, row, col);
        }

        display(seats);

        char choice;
        cout << "Do you want to book more seats? (Y/N): ";
        cin >> choice;
        if (choice != 'Y' && choice != 'y')
        {
            exit(0);                            //break also applicable
        }
    }

    return 0;
}


//#include<iomanip>
//cout << setw(5) << 42 << endl;      // Prints "   42"
//cout << setw(5) << "Hi" << endl;    // Prints "   Hi"
//cout << setw(5) << 123456 << endl;  // Prints "123456" (no truncation)


