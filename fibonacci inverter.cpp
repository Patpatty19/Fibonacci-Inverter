#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char answer;
string name;


void sequence() {
    string name;
    int i, number;
    long int arr[100];

    cout << "Enter the number : " << endl;
    cin >> number;

    arr[0] = 0;
    arr[1] = 1;

    for (i = 2; i < number; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << "Fibonacci series is: ";
    for (i = 0; i < number; i++)
        cout << arr[i] << endl;


    cout << "What do you want to name your file?: ";
    cin >> name;


    ofstream fileCreate(name + ".txt");

    for (int i = 0; i < number; i++) {
        fileCreate << arr[i] << " \n";
    }

}
void existingFile() {

    cout << "What is the name of your file?: ";
    cin >> name;

    ifstream Read(name + ".txt");

    string Fibonacci;
    if (Read)
    {
        while (getline(Read, Fibonacci)) {
            cout << Fibonacci;
        }
    }
    else
    {
        cout << "Error please create a new one..." << endl;
        sequence();
    }
    cout << Fibonacci;
    Read.close();

}



int main() {
    
	cout << "Do you already have an existing file that you want to display?: \n"
        "Y - Yes \n"
        "N - No \n";
    cin >> answer;

    switch (answer) {
    case 'Y':
    case 'y':
        existingFile();
        break;
    case 'N':
    case 'n':
        sequence();
        break;
    default:
        cout << "Error";
        break;
    }
}
