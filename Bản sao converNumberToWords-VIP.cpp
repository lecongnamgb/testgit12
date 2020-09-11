#include <iostream>
#include <string>

using namespace std;

string empty = "";

string X[] = {empty,"one","two","three","four","five","six","seven","eight","nine","ten",
             "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"
             };
string Y[] = {empty,empty,"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

string convert2digit(int n, string suffix)
{
    if (n==0) return empty;
    if (n>19&&n%10!=0) return Y[n/10]+"-"+X[n%10]+suffix;
    if (n%10==0) return Y[n/10]+suffix;
    return X[n]+suffix;
}

string convertNumberToWords(unsigned long long n)
{
    string res;
    res=convert2digit(n%100, "");
    res=convert2digit((n/100)%10, " hundred ")+res;
    res=convert2digit((n/1000)%100, " thousand ")+res;
    res=convert2digit((n/100000)%10, " hundred ")+res;
    res=convert2digit((n/1000000)%100, " million ")+res;
    res=convert2digit((n/100000000)%10, " hundred ")+res;
    return res;
}
int main()
{
    int n;
    cin >>n;
    if (n<0) cout <<"negative ";
    n=abs(n);
    cout <<convertNumberToWords(n);
    cout <<endl;
}
