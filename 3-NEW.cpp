#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c, d, prefix;
    char separator;

    cout << "Enter base IP address (e.g., 192.168.10.0): ";
    cin >> a >> separator >> b >> separator >> c >> separator >> d;

    cout << "Enter CIDR prefix (e.g., 26 for /26): ";
    cin >> prefix;

    if (prefix < 24 || prefix > 30) {
        cout << "Error: This program currently supports Class C subnetting (CIDR 24 to 30)." << endl;
        return 1;
    }

    int h = 32 - prefix;
    int size = static_cast<int>(pow(2, h));
    int subnets = 256 / size;
    int hosts = size - 2;
    int mask = 256 - size;

    cout << "\n--- General Subnet Information ---" << endl;
    cout << "Calculated Subnet Mask : 255.255.255." << mask << endl;
    cout << "Total Usable Hosts     : " << hosts << " per subnet" << endl;
    cout << "Total Subnets Created  : " << subnets << "\n" << endl;

    for (int n = 0; n < subnets; n++) {
        int start = n * size;
        int first = start + 1;
        int last = start + hosts;
        int end = start + size - 1;

     
        cout << "Subnet " << n + 1 << endl;
    
        cout << "Network Address   : "
             << a << "." << b << "." << c << "." << start << endl;

        cout << "First Host        : "
             << a << "." << b << "." << c << "." << first << endl;

        cout << "Last Host         : "
             << a << "." << b << "." << c << "." << last << endl;

        cout << "Broadcast Address : "
             << a << "." << b << "." << c << "." << end << endl;

        cout << "\nUsable IP Addresses:" << endl;

        for (int ip = first; ip <= last; ip++) {
            cout << "  " << a << "." << b << "." << c << "." << ip << endl;
        }

        cout << endl;
    }

    return 0;
}
