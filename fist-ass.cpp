#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string givenText = "Pegasus is a spyware developed by the Israeli cyberarms firm NSO Group that can be covertly installed on mobile phones and other devices running most versions of iOS and Android. The 2021 Project Pegasus revelations suggest that the current Pegasus software can exploit all recent iOS versions up to iOS 14.6. As of 2016, Pegasus was capable of reading text messages, tracking calls, collecting passwords, location tracking, accessing the target device's microphone and camera, and harvesting information from apps. The spyware is named after Pegasus, the winged horse of Greek mythology. It is a Trojan horse computer virus that can be sent 'flying through the air' to infect cell phones.";

    //convert all alphabets in string to capital
    for (int i = 0; i < givenText.length(); i++)
    {
        if (givenText[i] >= 'A' && givenText[i] <= 'Z')
        {
            continue;
        }
        if (givenText[i] >= 'a' && givenText[i] <= 'z')
        {
            givenText[i] -= ('a' - 'A');
        }
        else
        {
            continue;
        }
    }
    //key according to the question
    string key = "GAURVPMBCDEFHIJKLOQVWXYZ";

    // encrypting the string using the key
    for (int i = 0; i < givenText.length(); i++)
    {
        if (givenText[i] < 'A' || givenText[i] > 'Z')
        {
            continue;
        }
        givenText[i] = key[givenText[i] - 'A'];
    }
    cout << givenText;
    return 0;
}
