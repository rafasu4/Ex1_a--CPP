//
// Created by stycks on 05/03/2021.
//
#include "snowman.hpp"
#include <stdexcept>
#define SIZE 8

using namespace std;

const char *hat[7] = {"_===_", "___", ".....", "_", "/_\\", "___", "(_*_)"};
const char *nose[4] = {",", ".", "_", " "};
const char *leftEye[4] = {".", "o", "O", "-"};
const char *rightEye[4] = {".", "o", "O", "-"};
const char *leftArm[4] = {"<", "\\", "/", ""};
const char *rightArm[4] = {">", "/", "\\", ""};
const char *torso[4] = {" : ", "] [", "> <", "   "};
const char *base[4] = {" : ", "\" \"", "___", "   "};
int arr[SIZE];
bool flag = false;

/*inner function for input validity checkout*/
void inputCheck(int num) {
    string components = to_string(num);
    if (components.length() != 8) {
        throw length_error{"Invalid code "};
    }
    if (num <= 0){
        throw out_of_range{"input must be positive!"};
    }
    for (int i = 0; i < 8; ++i) {
        if (components[i] - '0' > 4 || components[i] - '0' < 1) {
            throw out_of_range{"each digit must be between 1 - 4! "};
        }
    }
}

namespace ariel {
    string snowman(int num) {
        inputCheck(num);
        int input;
        string components = to_string(num);
        string ans;
        //initiating arr in the wanted printing order
        arr[0] = components[0] - '0';//hat
        arr[2] = components[1] - '0';//nose
        arr[1] = components[2] - '0';//leftEye
        arr[3] = components[3] - '0';//rightEye
        arr[4] = components[4] - '0';//leftArm
        arr[6] = components[5] - '0';//rightArm
        arr[5] = components[6] - '0';//torso
        arr[7] = components[7] - '0';//base

        for (int i = 0; i < SIZE; ++i) {
            input = arr[i] - 1;//indexing
            switch (i) {
                //hat case
                case 0:
                    //"___
                    //....."
                    if (input == 1) {
                        ans += hat[1];
                        ans += hat[2];
                    }
                        //" _
                        // /_\"
                    else if (input == 2) {
                        ans += hat[3];
                        ans += hat[4];
                    }
                        // ___
                        //(_*_)
                    else if (input == 3) {
                        ans += hat[5];
                        //ans += " ";
                        ans += hat[6];
                    }
                        //_===_
                    else {
                        ans += hat[input];
                    }
                    break;

                //left eye case
                case 1:
                    //if the left hand is up
                    if (arr[4] == 2) {
                        ans += (leftArm[1]);
                    }
                    ans += "(";
                    ans += (leftEye[input]);
                    break;

                //nose case
                case 2:
                    ans += (nose[input]);
                    break;

                //right eye case
                case 3:
                    ans += (rightEye[input]);
                    ans += ")";
                    //if the right hand is up
                    if (arr[6] == 2) {
                        ans += (rightArm[1]);
                    }
                    break;

                //left arm case
                case 4:
                    //if the hand isn't up
                    if (arr[4] != 2) {
                        ans += (leftArm[input]);
                    }
                    break;

                //torso case
                case 5:
                    ans += "(";
                    ans += (torso[input]);
                    break;

                //right arm case
                case 6:
                    ans += ")";
                    //if the right arm isn't up
                    if (arr[6] != 2) {
                        ans += (rightArm[input]);
                    }
                    break;

                //base case
                case 7:
                    ans += "(";
                    ans += (base[input]);
                    ans += ")";
                    break;
            }
        }
        return ans;
    }
}

