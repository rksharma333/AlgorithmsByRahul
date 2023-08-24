#include<bits/stdc++.h>
using namespace std;

/// before 
string stringMultiplication(string &s1, string &s2)
{
	int len1 = s1.size();
	int len2 = s2.size();

	if(len1 == 0 or len2 == 0) return "0";

	vector<int> result(len1+len2, 0); // for storing resulting array

    // Below two indexes are used to find positions
	// in result.
	int n1_pos = 0;
	int n2_pos = 0;
    
    // Go from right to left in num2
	for(int i=len2-1; i>=0; i--)
	{
		int carry = 0;
		int n2 = s2[i]-'0';

		n1_pos = 0;

		for(int j=len1-1; j>=0; j--)
		{
			int n1 = s1[j]-'0';

			int sum = n1*n2 + result[n1_pos + n2_pos] + carry;

			carry = sum/10;
			result[n1_pos + n2_pos] = sum%10;

			n1_pos++;
		}

		if(carry > 0)
			result[n1_pos + n2_pos] = carry;

		n2_pos++;

	}

	// now remove zeros from back

	int i = len1 + len2 - 1;
	while(i >= 0 && result[i] == 0) i--;

	if(i == -1) return "0"; // means either second or first string
	// contains all zeros

	string s = "";

	while(i >= 0) s += (result[i--] + '0');

	return s;

}
int main()
{

	// we are supposed that string has no leading zero character as well
	// as only number is there
	string s1 = "654154154151454545415415454";
	string s2 = "63516561563156316545145146514654";
	// 41549622603955309777243716069997997007620439937711509062916
	string s = stringMultiplication(s1, s2);


	cout<<s<<endl;
	if(s == "41549622603955309777243716069997997007620439937711509062916")
	{
		cout<<"Hii Rahul You Are Smart"<<endl;
	}

	return 0;
}


