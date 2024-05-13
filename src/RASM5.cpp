#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;


void displayMenu();                                                 // Reusuable Function to Displays the Menu 
void loadInputFile();                                               // Function that Loads the Input File
void BubbleSort(long long int a[], int size);                                 // Function cBubbleSort();                   // Function aBubbleSort();
extern "C" void a_bubble_sort(long long int a[], int size);         // Function aBubbleSort();
int SIZE = 0;                                                       // The Size of our Array
long long int *unSortedArray;                                       // Pointer to hold Memory Address of dynamicly created array
long long int *sortedCBubbleSortArray;                              // pointer for the cBubbleSortArray
long long int *sortedABubbleSortArray;
double CBubbleSortTime;
double ABubbleSortTime;
int main() {
    
    system("clear");
    char userChoice = 0;
    do  {
        displayMenu(); 
        cout  << "Enter your choice: " << endl;
        cin  >> userChoice;
        //fixes input failure and does not allow the "enter correct choice" screen to repeat
        while (userChoice < 49 || userChoice > 52 ) {
                system("clear");
                displayMenu(); ;
                cout << "Please enter a correct choice" << endl << endl;
                cout << "Enter your choice:"  << endl;
                cin  >> userChoice;
        }
        system("clear");
        switch (userChoice) {
            case '1':
                    loadInputFile();
                    break;
            case '2':
                    if (SIZE <= 0) {
                        cout << "There is no items to be sorted." << endl;
                    } else  {
                        sortedCBubbleSortArray = new long long int[SIZE];
                        for (int i = 0; i < SIZE; i++) {
                            sortedCBubbleSortArray[i] = unSortedArray[i];
                        }
                        clock_t start = clock(); 
                        BubbleSort(sortedCBubbleSortArray, SIZE);
                        clock_t end = clock();
                        CBubbleSortTime= static_cast<double>(end - start) / CLOCKS_PER_SEC;
                        cout << endl;
                      //------Write to a File-------------------
                      ofstream file("sortedCBubbleSort.txt");
                      for (int i =0; i < SIZE; i++) {
                        file << sortedCBubbleSortArray[i] << '\n';
                      }
                      file.close();
                        // ---TEST-------------------------------
                        // for (int i = 0; i < SIZE; i++) {
                        //     cout << sortedCBubbleSortArray[i] << endl;
                        // }
                    }
                    break;
            case '3':
                    if (SIZE <=0) {
                        cout << "There is no items to be sorted." << endl;
                    }
                    else {
                        sortedABubbleSortArray = new long long int[SIZE];
                        for (int i = 0; i < SIZE; i++) {
                            sortedABubbleSortArray[i] = unSortedArray[i];
                        }
                        clock_t start = clock();
                        a_bubble_sort(sortedABubbleSortArray, SIZE);
                        clock_t end = clock();
                        ABubbleSortTime= static_cast<double>(end - start) / CLOCKS_PER_SEC;

                                              //------Write to a File-------------------
                        ofstream file("sortedABubbleSort.txt");
                        for (int i =0; i < SIZE; i++) {
                            file << sortedABubbleSortArray[i] << '\n';
                        }
                        file.close();

                        //--------TEST-------------------------------------
                        // for (int i = 0; i < SIZE; i++) {
                        //     cout << sortedABubbleSortArray[i] << endl;
                        // }
                        // cout << "Test for a_bubble_sort: " <<  endl; 
                        //--------------------------------------------------
                    }
                    break;
            case '4':
                    break;
        }
        cout << endl;
    } while (userChoice != '4');
    return 0;
}

void displayMenu() {
    cout << "        RASM5 C vs Assembly                     "  << endl;
    cout << "       File Element Count: "   << SIZE << endl;
    cout << "------------------------------------------------" << endl;
    cout << "C          Bubblesort Time: " << CBubbleSortTime << " seconds" << endl;
    cout << "Assembly   Bubblesort Time: " << ABubbleSortTime << " seconds" << endl;
    cout << endl;
    cout << "C          Insertionsort Time: " << endl;
    cout << "Assembly   Insertionsort Time: " << endl;
    cout << "------------------------------------------------" << endl;
    cout << "<1> Load Input File (integers)"                   << endl;
    cout << "<2> Sort using C Bubblesort algorithim"           << endl;
    cout << "<3> Sort using Assembly Bubblesort algorithm"     << endl;
    cout << "<4> Quit"                                         << endl;
}


void loadInputFile() {
    //-- Getting the Size --------------------------
    ifstream file("input.txt");

    int counter = 0;
    long long int number;
    while (file >> number) {
        counter++;
    }
    file.close();

    SIZE = counter;
    counter = 0;
    //----------------------------------------------
    //--Loading the Data into Dynamic Array ----------------
    unSortedArray = new long long int [SIZE];
    
    file.open("input.txt");
    while (file >> number) {
        unSortedArray[counter] = number;
        counter++;
    }

    file.close();
    //---------------------------------------------------
    //--TEST---------------------------------------------
    // for (int i = 0; i < 5; i++) {
    //     cout << unSortedArray[i] << endl;
    // }
    //---------------------------------------------------


}
