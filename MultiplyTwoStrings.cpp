/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


string SumStrings(string s1, string s2)
{
    //cout << "input " << s1 << " " << s2 << endl;
    string bigString = "";
    string smallString = "";
    string outString = "";
    if(s1.size() > s2.size())
    {
        bigString = s1;
        smallString = s2;
    }
    else
    {
        bigString = s2;
        smallString = s1;
    }
    
    int i = bigString.size() - 1;
    int j = smallString.size() - 1;

    if(i >= 0 && j < 0)
    {
        //cout << "output " << bigString << endl;
        return bigString;
    }

    int carry = 0;
    while(i >= 0 || j >= 0)
    {
           if(j >= 0)
           {
               int num1 = bigString[i] - '0';
               int num2 = smallString[j] - '0';
               int finalNumber = num1 + num2 + carry;
               if(finalNumber >= 10)
               {
                   carry = 1;
                   finalNumber = finalNumber%10;
               }
               else
                    carry = 0;
               outString = std::to_string(finalNumber) + outString;
               j--;
               i--;
           }
           else
           {
               int num1 = bigString[i] - '0';
               int finalNumber = num1 + carry;
               if(finalNumber >= 10)
               {
                   carry = 1;
                   finalNumber = finalNumber%10;
               }
               else
                 carry = 0;
               outString = std::to_string(finalNumber) + outString;
               i--;
           }
    }
    if(carry > 0)
    {
        outString = std::to_string(carry) + outString;
    }
    //cout << "output " << outString << endl;
    return outString;
}
/*You are required to complete below function */
string multiplyStrings(string s1, string s2) {
    
    string bigString = "";
    string smallString = "";
    string outString = "";
    
    if(s1.size() > s2.size())
    {
        bigString = s1;
        smallString = s2;
    }
    else
    {
        bigString = s2;
        smallString = s1;
    }
    
    for(int i = smallString.size() - 1; i >= 0; i--)
    {
        string middleString = "";
        int multFactor = smallString[i] - '0';
        for(int k = 0; k < multFactor; k++)
            middleString = SumStrings(bigString, middleString);
        
        for(int k = smallString.size() - 1; k > i; k--)
            middleString = middleString + "0";
        
        outString = SumStrings(outString, middleString);
    }
    
    return outString;
    
}
