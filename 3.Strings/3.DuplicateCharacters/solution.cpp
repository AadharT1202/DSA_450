// C++ program to count all duplicates
// from string using maps
#include <iostream>
#include<unordered_map>
using namespace std;
void printDups(string str)
{
	unordered_map<char, int> count;
	for (int i = 0; i < str.length(); i++) {
		count[str[i]]++;
	}
    unordered_map<char,int>::iterator it;
	for (it=count.begin(); it!=count.end(); it++) {
		if (it->second > 1)
			cout << it->first << ", count = " << it->second
				<< "\n";
	}
}
/* Driver code*/
int main()
{
	string str = "test string";
	printDups(str);
	return 0;
}
// This code is contributed by yashbeersingh42
