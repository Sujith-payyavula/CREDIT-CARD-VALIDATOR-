#include<bits/stdc++.h>

using namespace std;

bool isValidCard(string cardNumber)
{
    string validCardNumber;
    for (char ch : cardNumber)
    {
        if (isdigit(ch))
            validCardNumber += ch;
    }

    if (validCardNumber.size() < 13 || validCardNumber.size() > 16)
        return false;

    int sum = 0;

    for (int i = validCardNumber.size() - 1; i >= 0; --i)
    {
        int digit = validCardNumber[i] - '0';

        // Add digits at odd indices
        if ((validCardNumber.size() - i) % 2 != 0)
        {
            sum += digit;
        }
        else
        {
            // Double digits at even indices (excluding the check digit)
            digit *= 2;
            if (digit > 9)
                digit = digit % 10 + digit / 10;
            sum += digit;
        }
    }

    return (sum % 10 == 0);
}

string getCardType(string cardNumber)
{
    if (cardNumber.empty())
        return "Unknown";

    if (cardNumber[0] == '4')
        return "Visa Card";
        
    else if (cardNumber[0] == '5','2')
        return "Mastercard";
        
    else if (cardNumber[0] == '6')
        return "Rupay Card";
        
    else if (cardNumber[0] == '3' && (cardNumber[1] == '4' || cardNumber[1] == '7'))
        return "American Express";

    return "Unknown";
}

int main()
{
    string cardNumber;
    cout << "Enter credit card number: ";
    cin >> cardNumber;

    if (isValidCard(cardNumber))
    {
        cout << "Valid card number" << endl;
        string cardType = getCardType(cardNumber);
        cout << "Card type: " << cardType << endl;
    }
    else
    {
        cout << "Invalid card number" << endl;
    }

return 0;
}
