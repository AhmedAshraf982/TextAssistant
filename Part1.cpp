#include <bits/stdc++.h>
#include "linkedlist.h"

using namespace std;

string lowerCase(string temp)
{
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] >= 'A' and temp[i] <= 'Z')
        {
            temp[i] += 32;
        }
    }
    return temp;
}

UserDefine sentence(string s)
{
    UserDefine stl;
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.' || s[i] == '?' || s[i] == '|')
        {
            temp += s[i];
            stl.insert_last(temp);
            temp.clear();
        }
        else
        {
            temp += s[i];
        }
    }
    return stl;
}
UserDefine words(string s)
{
    UserDefine stl;
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            stl.insert_last(temp);
            temp.clear();
        }
        else if (!ispunct(s[i]))
        {
            temp += s[i];
        }
    }
    return stl;
}
int main()
{
    string s = "AHMEDAHDHK SKJBD JBDKBDK D.BJDVJBD MBDCD DKVNDKV DBKBD?VKNDK NVKBVDKBVK DVDKDVKVD! KVKNVKNV DK BDDV,BVDJKNVKDNKDBKDBQQQQccCKJCBJDSBCDSMCB,SMcdksjdsbkdsdsk.";
    // cout << lowerCase(s) << endl;
    //  UserDefine temp = sentence(s);
    // for (auto x : temp)
    //     cout << x << endl;
    UserDefine t = words(s);
    for (auto x : t)
        cout << x << endl;
    return 0;
}