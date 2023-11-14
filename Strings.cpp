#include<iostream>
#include<string>
using namespace std;

string compose(const string& firstname, const string& lastname)
{
	return firstname + "@" + lastname;
}

int main()
{
	string temp = "Someone";
	string temp2 = "someone";
	bool contains = temp2.find("eon") != string::npos;
	cout << contains << endl;
	u16string str = u"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (char16_t c : str) cout << char(c) << endl;



	//substr(index,size)
	cout << compose(temp.substr(0,1), temp.substr(5,1)) << endl;
	cout << temp.replace(0, 4, "No-") << endl; 
	cout << compose("nomaan", "ahmed") << endl;
	temp[5] = toupper(temp[5]);
	cout << temp << endl;

	//without using string literals
	string test = string("Nomaan") + " ahmed";
	cout << test << endl;

	//with using stringliterals 
	using namespace std::string_literals;
	string test1 = "Nomaan"s + " Ahmed";
	cout << test1 << endl;

	const char* example = R"(Line1
    Line2
    Line3)";
	cout << example << endl;



	
}
