//
// Created by stycks on 05/03/2021.
//
#include "snowman.hpp"
#include <stdexcept>
#include <array>
constexpr int SIZE = 8;
constexpr int PARTS_SIZE = 4;

using namespace std;
array<string, SIZE - 1> hat = {"_===_", "___", ".....", "_", "/_\\", "___", "(_*_)"};
array<string, PARTS_SIZE> nose = {",", ".", "_", " "};
array<string, PARTS_SIZE> leftEye = {".", "o", "O", "-"};
array<string, PARTS_SIZE> rightEye = {".", "o", "O", "-"};
array<string, PARTS_SIZE> leftArm = {"<", "\\", "/", ""};
array<string, PARTS_SIZE> rightArm= {">", "/", "\\", ""};
array<string, PARTS_SIZE> torso = {" : ", "] [", "> <", "   "};
array<string, PARTS_SIZE> base = {" : ", "\" \"", "___", "   "};
int arr[SIZE];
bool flag = false;

/*inner function for input validity checkout*/
void inputCheck(int num) {
    string components = to_string(num);
    if (components.length() != SIZE) {
        throw length_error{"Invalid code "};
    }
    if (num <= 0){
        throw out_of_range{"input must be positive!"};
    }
    for (int i = 0; i < SIZE; ++i) {
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
                        ans += hat.at(1);
                        ans += hat.at(2);
                    }
                        //" _
                        // /_\"
                    else if (input == 2) {
                        ans += hat.at(3);
                        ans += hat.at(4);
                    }
                        // ___
                        //(_*_)
                    else if (input == 3) {
                        ans += hat.at(5);
                        //ans += " ";
                        ans += hat.at(6);
                    }
                        //_===_
                    else {
                        ans += hat.at(input);
                    }
                    break;

                //left eye case
                case 1:
                    //if the left hand is up
                    if (arr[4] == 2) {
                        ans += (leftArm.at(1));
                    }
                    ans += "(";
                    ans += (leftEye.at(input));
                    break;

                //nose case
                case 2:
                    ans += (nose.at(input));
                    break;

                //right eye case
                case 3:
                    ans += (rightEye.at(input));
                    ans += ")";
                    //if the right hand is up
                    if (arr[6] == 2) {
                        ans += (rightArm.at(1));
                    }
                    break;

                //left arm case
                case 4:
                    //if the hand isn't up
                    if (arr[4] != 2) {
                        ans += (leftArm.at(input));
                    }
                    break;

                //torso case
                case 5:
                    ans += "(";
                    ans += (torso.at(input));
                    break;

                //right arm case
                case 6:
                    ans += ")";
                    //if the right arm isn't up
                    if (arr[6] != 2) {
                        ans += (rightArm.at(input));
                    }
                    break;

                //base case
                case 7:
                    ans += "(";
                    ans += (base.at(input));
                    ans += ")";
                    break;
                default:
                    continue;
            }

        }
        return ans;
    }
}

