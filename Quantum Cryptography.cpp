#include <iostream>           // Used for input/output operations
#include <cstdlib>            // Used for rand() and srand()
#include <ctime>              // Used to seed random number generator with current time

using namespace std;

int main() {
    srand(time(0));           // Initialize random generator using current time

    const int n = 8;          // Number of bits to simulate
    int aliceBits[n];         // Array to store Alice's random bits
    int aliceBases[n];        // Array to store Alice's random bases (0 = Z, 1 = X)
    int bobBases[n];          // Array to store Bob's random bases
    int bobResults[n];        // Array to store Bob’s measured bits
    int finalKey[n];          // Array will hold the final shared key
    int keyIndex = 0;         // Tracks how many matching bits are added to the key

    // ----- Step 1: Alice generates random bits and bases -----
    for (int i = 0; i < n; i++) {
        aliceBits[i] = rand() % 2;    // Alice picks a random bit (0 or 1)
        aliceBases[i] = rand() % 2;   // Alice picks a random basis (0=Z, 1=X)
    }

    // ----- Step 2: Bob chooses random bases and measures -----
    for (int i = 0; i < n; i++) {
        bobBases[i] = rand() % 2;     // Bob randomly chooses a basis (0=Z, 1=X)

        if (bobBases[i] == aliceBases[i]) {
            bobResults[i] = aliceBits[i];     // If bases match, Bob gets the correct bit
        }
        else {
            bobResults[i] = rand() % 2;       // If bases differ, Bob gets a random result
        }
    }

    // ----- Step 3: Compare bases to generate final key -----
    for (int i = 0; i < n; i++) {
        if (aliceBases[i] == bobBases[i]) {   // Keep only matching-basis positions
            finalKey[keyIndex++] = bobResults[i];  // Add bit to key
        }
    }

    // ----- Print everything -----
    cout << "Alice Bits:      ";
    for (int i = 0; i < n; i++) cout << aliceBits[i] << " ";
    cout << endl;

    cout << "Alice Bases:     ";
    for (int i = 0; i < n; i++) cout << aliceBases[i] << " ";
    cout << endl;

    cout << "Bob Bases:       ";
    for (int i = 0; i < n; i++) cout << bobBases[i] << " ";
    cout << endl;

    cout << "Bob Results:     ";
    for (int i = 0; i < n; i++) cout << bobResults[i] << " ";
    cout << endl;

    cout << "\nFinal Shared Key: ";
    for (int i = 0; i < keyIndex; i++) cout << finalKey[i] << " ";
    cout << endl;

    return 0;    // End of program
}
