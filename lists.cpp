// Copyright (c) 2022 Peter Sobowale All rights reserved.
//
// Created by: Peter Sobowale
// Created on: January 2, 2023
// This program uses a while loop to collect input
// from the user. It then calls a function calculate
// the average of the input.
#include <cmath>
#include <iostream>
#include <list>
#include <string>

// function calculates the average in the list of elements
double calcAverage(std::list<int> marks) {
    float median = 0;
    for (int counter : marks) {
        median += counter;
    }

    if (marks.empty()) {
        return -1;
    } else {
        median = median / marks.size();
        return median;
    }
}

int main() {
    // Declaring variable
    std::list<int> marksList;
    std::string tempMark;
    int markInt;

    // user interface
    std::cout << "This program will calculate the average of "
              << "all the user's marks.\n"
              << std::endl;

    // gets input from user and adds it to end of list
    while (tempMark != "-1") {
        std::cout << "Enter a mark between 0 and 100 (-1 to stop): ";
        std::cin >> tempMark;
        try {
            markInt = stoi(tempMark);

            // if statement to make sure it isn't a float
            if (tempMark.find(".") != std::string::npos) {
                std::cout << tempMark << " is not a valid mark." << std::endl;
                continue;
            } else {
                // Make sure it isn't -1
                if (markInt == -1) {
                    continue;
                } else if (markInt < 0 || markInt > 100) {
                    std::cout << markInt << " is not between 0 and 100."
                              << std::endl;
                    continue;
                }
                marksList.push_back(markInt);
            }
        } catch (std::invalid_argument) {
            std::cout << tempMark << " is not a valid mark." << std::endl;
            continue;
        }
    }

    // assigns variable to function call
    double averageUser = calcAverage(marksList);
    averageUser = round(averageUser);

    // displays results to user
    std::cout << "\nFor the list of marks: [";
    int z = marksList.back();
    marksList.pop_back();

    for (int mark : marksList) {
        std::cout << mark << ", ";
    }
    std::cout << z << "]" << std::endl;
    std::cout << "The average is " << averageUser << "%" << std::endl;
}
