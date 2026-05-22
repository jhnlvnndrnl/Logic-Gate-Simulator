#ifndef USER_PROFILE_H
#define USER_PROFILE_H

#include <string>

using namespace std;

// ENCAPSULATION: userName is private and controlled by setters/getters.
class UserProfile {
private:
    string userName;

public:
    UserProfile();
    void setUserName(string name);
    string getUserName();
};

#endif
