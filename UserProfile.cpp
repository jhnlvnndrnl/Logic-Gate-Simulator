#include "UserProfile.h"

UserProfile::UserProfile() {
    userName = "Guest";
}

void UserProfile::setUserName(string name) {
    if (name == "") {
        userName = "Guest";
    } else {
        userName = name;
    }
}

string UserProfile::getUserName() {
    return userName;
}
