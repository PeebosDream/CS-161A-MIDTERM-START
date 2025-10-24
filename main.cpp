// ------------- FILE HEADER -------------
// Author:
// Assignment:
// Date:
// Description:
// Sources:

// ------------- ZYBOOKS SCORES -------------
// https://learn.zybooks.com/zybook/PCCCS161ASummer25
// Chapter: NONE MIDTERM WEEK

// ------------- DESIGN DOCUMENT -------------
// A. INPUT [yes/no]:
// B. OUTPUT [yes/no]:
// C. CALCULATIONS [yes/no]:
// D. LOGIC and ALGORITHMS [yes/no]:
//    (Optional) flow chart link or file name:

// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS [yes/no]:
// (Optional) Additional tests count:

// ------------- CODE -------------
#include <iostream>
#include <string>
#include <limits> // NOT <climits> for cin.ignore(numeric_limits<streamsize>::max(), '\n');
#include <iomanip>

// RUN AND TEST COMMAND
// cd _midterm // Or the directory containing these files
// g++ main.cpp && for t in *.txt; do ./a.out < $t; done; rm ./a.out

// MINIMAL COMPILE AND RUN, one line each
// COMPILE
// g++ main.cpp

// RUN
// ./a.out

// REMOVE ./a.out
// rm ./a.out

using namespace std;

int main()
{
  string p1_name = "";
  string p2_name = "";
  string p3_name = "";

  int p1_count = 0;
  int p2_count = 0;
  int p3_count = 0;

  cout << "Welcome to the Rock Collector Championships!" << endl;

  cout << "Enter player 1 name: ";
  getline(cin, p1_name);
  cout << "How many rocks did " << p1_name << " collect? ";
  cin >> p1_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (p1_count < 0)
  {
    cout << "Invalid amount. 0 will be entered." << endl;
    p1_count = 0;
  }

  cout << "Enter player 2 name: ";
  getline(cin, p2_name);
  cout << "How many rocks did " << p2_name << " collect? ";
  cin >> p2_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (p2_count < 0)
  {
    cout << "Invalid amount. 0 will be entered." << endl;
    p2_count = 0;
  }

  cout << "Enter player 3 name: ";
  getline(cin, p3_name);
  cout << "How many rocks did " << p3_name << " collect? ";
  cin >> p3_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (p3_count < 0)
  {
    cout << "Invalid amount. 0 will be entered." << endl;
    p3_count = 0;
  }
  // DEBUG
  cout << endl;
  cout << left << setw(15) << "NAME" << right << setw(10) << "COUNT" << endl;
  cout << "-----------------------------" << endl;
  cout << left << setw(15) << p1_name << right << setw(10) << p1_count << endl;
  cout << left << setw(15) << p2_name << right << setw(10) << p2_count << endl;
  cout << left << setw(15) << p3_name << right << setw(10) << p3_count << endl;
  cout << endl;

  // Calculations

  float average = (p1_count + p2_count + p3_count) / 3.0;

  cout << fixed << setprecision(2);

  int a = p1_count;
  int b = p2_count;
  int c = p3_count;

  string first_name = "";
  string second_name = "";
  string third_name = "";

  bool tie_first = false;
  bool tie_second = false;

  // Determine places
  // tie cases first
  if (a == b && b == c) 
  { // case 1: three way tie
    cout << "It is a three way tie!" << endl;
  }
  else if (a == b && a > c) 
  { // case 2: p1 and p2 tie for first
    first_name = p1_name + " and " + p2_name;
    second_name = p3_name;
    tie_first = true;
  }
  else if (a == c && a > b) 
  { // case 3: p1 and p3 tie for first
    first_name = p1_name + " and " + p3_name;
    second_name = p2_name;
    tie_first = true;
  }
  else if (b == c && b > a) 
  { // case 4: p2 and p3 tie for first
    first_name = p2_name + " and " + p3_name;
    second_name = p1_name;
    tie_first = true;
  }
  // p1 wins
  if (a > b && a > c)
  {
    first_name = p1_name;
    if (b > c) // case 5: p2 is second
    { 
      second_name = p2_name;
      third_name = p3_name;
    }
    else if (c > b) // case 6: p3 is second
    { 
      second_name = p3_name;
      third_name = p2_name;
    }
    else
    { // case 7: p2 and p3 tie for second
      second_name = p2_name + " and " + p3_name;
      tie_second = true;
    }
  }
  // p2 wins
  else if (b > a && b > c)
  {
    first_name = p2_name;
    if (a > c)
    { // case 8: p1 is second
      second_name = p1_name;
      third_name = p3_name;
    }
    else if (c > a)
    { // case 9: p3 is second
      second_name = p3_name;
      third_name = p1_name;
    }
    else
    { // case 10: p1 and p3 tie for second
      second_name = p1_name + " and " + p3_name;
      tie_second = true;
    }
  }
  // p3 wins
  else if (c > a && c > b)
  {
    first_name = p3_name;
    if (a > b)
    { // case 11: p1 second
      second_name = p1_name;
      third_name = p2_name;
    }
    else if (b > a)
    { // case 12: p2 is second
      second_name = p2_name;
      third_name = p1_name;
    }
    else
    { // case 13: p1 and p2 tie for second
      second_name = p1_name + " and " + p2_name;
      tie_second = true;
    }
  }
  // Output places
  if (!(a == b && b == c))
  {
    if (tie_first)
    {
      cout << first_name << " are tied for first place." << endl;
      cout << second_name << " is in second place!" << endl;
    }
    else if (tie_second)
    {
      cout << first_name << " is in first place!" << endl;
      cout << second_name << " are tied for second place." << endl;
    }
    else
    {
      cout << first_name << " is in first place!" << endl;
      cout << second_name << " is in second place." << endl;
      cout << third_name << " is in third place." << endl;
    }
  }

  cout << "The average number of rocks collected by the top three players is " << average << " rocks!" << endl;
  cout << "Congratulations Rock Collectors!" << endl;

  return 0;
}

// ------------- DESIGN -------------
/*
Program Name: Rock Collector Championships

Program Description: This program collects the names and rock counts of three players,
determines their rankings (including handling ties), and calculates the average number of rocks collected.

Design:
A. INPUT
Define the input variables including name data type.

B. OUTPUT
Define the output variables including data types.

C. CALCULATIONS
Describe calculations used by algorithms in step D.
List all formulas.
If there are no calculations needed, state there are no calculations.

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts.
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs.
https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt

DECLARE string p1_name, p2_name, p3_name
DECLARE integer p1_count, p2_count, p3_count
DECLARE string first_name, second_name, third_name
DECLARE boolean first_tied, second_tied
DECLARE integer a, b, c
DECLARE float average

DISPLAY "Welcome to the Rock Collector Championships!"

DISPLAY "Enter player 1 name: "
INPUT p1_name
DISPLAY "How many rocks did " + p1_name + " collect? "
INPUT p1_count
IF p1_count < 0 THEN
    DISPLAY "Invalid amount. 0 will be entered."
    SET p1_count = 0
END IF

DISPLAY "Enter player 2 name: "
INPUT p2_name
DISPLAY "How many rocks did " + p2_name + " collect? "
INPUT p2_count
IF p2_count < 0 THEN
    DISPLAY "Invalid amount. 0 will be entered."
    SET p2_count = 0
END IF

DISPLAY "Enter player 3 name: "
INPUT p3_name
DISPLAY "How many rocks did " + p3_name + " collect? "
INPUT p3_count
IF p3_count < 0 THEN
    DISPLAY "Invalid amount. 0 will be entered."
    SET p3_count = 0
END IF

SET a = p1_count
SET b = p2_count
SET c = p3_count

SET first_name = ""
SET second_name = ""
SET third_name = ""
SET first_tied = FALSE
SET second_tied = FALSE

IF a = b AND b = c THEN
    DISPLAY "It is a three way tie!"

ELSE IF a = b AND a > c THEN
    SET first_name = p1_name + " and " + p2_name
    SET second_name = p3_name
    SET first_tied = TRUE

ELSE IF a = c AND a > b THEN
    SET first_name = p1_name + " and " + p3_name
    SET second_name = p2_name
    SET first_tied = TRUE

ELSE IF b = c AND b > a THEN
    SET first_name = p2_name + " and " + p3_name
    SET second_name = p1_name
    SET first_tied = TRUE

ELSE IF a > b AND a > c THEN
    SET first_name = p1_name

    IF b > c THEN
        SET second_name = p2_name
        SET third_name = p3_name

    ELSE IF c > b THEN
        SET second_name = p3_name
        SET third_name = p2_name

    ELSE
        SET second_name = p2_name + " and " + p3_name
        SET second_tied = TRUE

    END IF

ELSE IF b > a AND b > c THEN
    SET first_name = p2_name

    IF a > c THEN
        SET second_name = p1_name
        SET third_name = p3_name

    ELSE IF c > a THEN
        SET second_name = p3_name
        SET third_name = p1_name

    ELSE
        SET second_name = p1_name + " and " + p3_name
        SET second_tied = TRUE

    END IF
ELSE
    SET first_name = p3_name

    IF a > b THEN
        SET second_name = p1_name
        SET third_name = p2_name

    ELSE IF b > a THEN
        SET second_name = p2_name
        SET third_name = p1_name

    ELSE
        SET second_name = p1_name + " and " + p2_name
        SET second_tied = TRUE
    END IF
END IF

SET average = (p1_count + p2_count + p3_count) / 3.0

IF NOT (a = b AND b = c) THEN
    IF first_tied THEN
        DISPLAY first_name + " are tied for first place."
        DISPLAY second_name + " is in second place!"

    ELSE IF second_tied THEN
        DISPLAY first_name + " is in first place!"
        DISPLAY second_name + " are tied for second place."

    ELSE
        DISPLAY first_name + " is in first place!"
        DISPLAY second_name + " is in second place."
        DISPLAY third_name + " is in third place."
    END IF
END IF

DISPLAY "The average number of rocks collected by the top three players is " + average + " rocks!"
DISPLAY "Congratulations Rock Collectors!"


}

SAMPLE RUNS
Welcome to the Rock Collector Championships!

Enter player 1 name: Gordan Freeman
How many rocks did Gordan Freeman collect? -9
Invalid amount. 0 will be entered.

Enter player 2 name: Link
How many rocks did Link collect? 45

Enter player 3 name: D. Va
How many rocks did D. Va collect? 45

Link and D. Va are tied for first place.
Gordan Freeman is in second place!

The average number of rocks collected by the top three players is 30.00 rocks!

Congratulations Rock Collectors!




Welcome to the Rock Collector Championships!

Enter player 1 name: Mario
How many rocks did Mario collect? 56

Enter player 2 name: Master Chief
How many rocks did Master Chief collect? 56

Enter player 3 name: Sonic
How many rocks did Sonic collect? 56

It is a three way tie!

The average number of rocks collected by the top three players is 56.00 rocks!

Congratulations Rock Collectors!




Welcome to the Rock Collector Championships!

Enter player 1 name: King Dedede
How many rocks did King Dedede collect? 57

Enter player 2 name: Samus
How many rocks did Samus collect? 102

Enter player 3 name: Kirby
How many rocks did Kirby collect? 62

Samus is in first place!
Kirby is in second place.
King Dedede is in third place.

The average number of rocks collected by the top three players is 73.67 rocks!

Congratulations Rock Collectors!

*/
