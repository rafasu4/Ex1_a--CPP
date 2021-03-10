//
// Created by stycks on 05/03/2021.
//
#include "snowman.hpp"
#include <stdexcept>
#include <array>

constexpr int SIZE = 8;
constexpr int PARTS_SIZE = 4;
constexpr int hatIndex = 0;
constexpr int noseIndex = 2;
constexpr int leftEyeIndex = 1;
constexpr int rightEyeIndex = 3;
constexpr int leftArmIndex = 4;
constexpr int rightArmIndex = 6;
constexpr int torsoIndex = 5;
constexpr int baseIndex = 7;

using namespace std;

array<string, SIZE - 1> hat = {"_===_", "___", ".....", "_", "/_\\", "___", "(_*_)"};
array<string, PARTS_SIZE> nose = {",", ".", "_", " "};
array<string, PARTS_SIZE> leftEye = {".", "o", "O", "-"};
array<string, PARTS_SIZE> rightEye = {".", "o", "O", "-"};
array<string, PARTS_SIZE> leftArm = {"<", "\\", "/", ""};
array<string, PARTS_SIZE> rightArm = {">", "/", "\\", ""};
array<string, PARTS_SIZE> torso = {" : ", "] [", "> <", "   "};
array<string, PARTS_SIZE> base = {" : ", "\" \"", "___", "   "};
array<int, SIZE> arr;
bool flag = false;

/*inner function for input validity checkout*/
void inputCheck(int num) {
    string components = to_string(num);
    if (components.length() != SIZE) {
        throw length_error{"Invalid code "};
    }
    if (num <= 0) {
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
        string components = to_string(num);
        string ans;
        //initiating arr in the wanted printing order
        arr[hatIndex] = components[hatIndex] - '0';//hat
        arr[noseIndex] = components[noseIndex - 1] - '0';//nose
        arr[leftEyeIndex] = components[leftEyeIndex + 1] - '0';//leftEye
        arr[rightEyeIndex] = components[rightEyeIndex] - '0';//rightEye
        arr[leftArmIndex] = components[leftArmIndex] - '0';//leftArm
        arr[rightArmIndex] = components[rightArmIndex - 1] - '0';//rightArm
        arr[torsoIndex] = components[torsoIndex + 1] - '0';//torso
        arr[baseIndex] = components[baseIndex] - '0';//base

        for (int i = 0; i < SIZE; ++i) {
            int input = arr[i] - 1;//indexing
            switch (i) {
                //hat case
                case hatIndex:
                    //"___
                    //....."
                    if (input == 1) {
                        int secHat = 1;
                        ans += hat.at(secHat);
                        ans += hat.at(secHat + 1);//second part of the hat
                    }
                        //" _
                        // /_\"
                    else if (input == 2) {
                        int thirdHat = 3;
                        ans += hat.at(thirdHat);
                        ans += hat.at(thirdHat + 1);//second part of the hat
                    }
                        // ___
                        //(_*_)
                    else if (input == 3) {
                        int forthHat = 5;
                        ans += hat.at(forthHat);
                        //ans += " ";
                        ans += hat.at(forthHat + 1);//second part of the hat
                    }
                        //_===_
                    else {
                        ans += hat.at(input);
                    }
                    break;

                    //left eye case
                case leftEyeIndex:
                    //if the left hand is up
                    if (arr[leftArmIndex] == 2) {
                        ans += (leftArm.at(1));
                    }
                    ans += "(";
                    ans += (leftEye.at(input));
                    break;

                    //nose case
                case noseIndex:
                    ans += (nose.at(input));
                    break;

                    //right eye case
                case rightEyeIndex:
                    ans += (rightEye.at(input));
                    ans += ")";
                    //if the right hand is up
                    if (arr[rightArmIndex] == 2) {
                        ans += (rightArm.at(1));
                    }
                    break;

                    //left arm case
                case leftArmIndex:
                    //if the hand isn't up
                    if (arr[leftArmIndex] != 2) {
                        ans += (leftArm.at(input));
                    }
                    break;

                    //torso case
                case torsoIndex:
                    ans += "(";
                    ans += (torso.at(input));
                    break;

                    //right arm case
                case rightArmIndex:
                    ans += ")";
                    //if the right arm isn't up
                    if (arr[rightArmIndex] != 2) {
                        ans += (rightArm.at(input));
                    }
                    break;

                    //base case
                case baseIndex:
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

