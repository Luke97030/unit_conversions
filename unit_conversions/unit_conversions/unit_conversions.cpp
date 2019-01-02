// Program: Haoyu Kong
// Start Date: 2018/05/18
// End Date: 2018/05/28


#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;




string unitResult(string s)
{
	string gUnit = "g";
	string ozUnit = "oz";
	string kgUnit = "kg";
	string lbUnit = "lb";
	string ltUnit = "longtn";
	string AlertLtUnit = "tonne";
	string stUnit = "shtn";
	string grUnit = "gr";
	string dwtUnit = "dwt";
	string strResult;

	// find the "g" string in the user input string
	if (strstr(s.c_str(), gUnit.c_str()) && s.find_first_of(gUnit) == s.size() - 1 && s.find_first_of(kgUnit) != s.size() - 2)
	{
		std::size_t pos = s.find("g");

		if (pos != 0)
		{

			string newS = s.replace(pos, 1, " ");
			double originalNum = atof(newS.c_str());
			// 1 g = 0.03527396195 oz
			double result = originalNum * 0.03527396195;
			strResult = std::to_string(result) + " oz";
		}
	}
	else if (strstr(s.c_str(), ozUnit.c_str()) && s.find_first_of(ozUnit) == s.size() - 2)
	{
		std::size_t pos = s.find("oz");

		if (pos != 0)
		{

			string newS = s.replace(pos, 2, " ");
			double originalNum = atof(newS.c_str());
			// 1 oz = 28.34952 g
			double result = originalNum * 28.34952;
			strResult = std::to_string(result) + " g";
		}
	}
	else if (strstr(s.c_str(), kgUnit.c_str()) && s.find_first_of(kgUnit) == s.size() - 2)
	{
		std::size_t pos = s.find("kg");

		if (pos != 0)
		{

			string newS = s.replace(pos, 2, " ");
			double originalNum = atof(newS.c_str());
			//1 kg = 2.20462262185 lb
			double result = originalNum * 2.20462262185;
			strResult = std::to_string(result) + " lb";
		}
	}
	else if (strstr(s.c_str(), lbUnit.c_str()) && s.find_first_of(lbUnit) == s.size() - 2)
	{
		std::size_t pos = s.find("lb");

		if (pos != 0)
		{

			string newS = s.replace(pos, 2, " ");
			double originalNum = atof(newS.c_str());
			//1 lb = 0.45359237 kg
			double result = originalNum * 0.45359237;
			strResult = std::to_string(result) + " kg";
		}
	}





	/*string ltUnit = "longtn";
	string AlertLtUnit = "tonne";
	string stUnit = "shtn";*/
	else if (strstr(s.c_str(), ltUnit.c_str()) && s.find_first_of(ltUnit) == s.size() - 6)
	{
		std::size_t pos = s.find("longtn");

		if (pos != 0)
		{

			string newS = s.replace(pos, 6, " ");
			double originalNum = atof(newS.c_str());
			// 1 Long tons = 1.12 Short tons
			double result = originalNum * 1.12;
			strResult = std::to_string(result) + " Short tons(sh tn)";
		}
	}

	else if (strstr(s.c_str(), AlertLtUnit.c_str()) && s.find_first_of(AlertLtUnit) == s.size() - 5)
	{
		std::size_t pos = s.find("tonne");

		if (pos != 0)
		{

			string newS = s.replace(pos, 5, " ");
			double originalNum = atof(newS.c_str());
			// 1 Long tons = 1.12 Short tons
			double result = originalNum * 1.12;
			strResult = std::to_string(result) + " Short tons(sh tn)";
		}
	}

	else if (strstr(s.c_str(), stUnit.c_str()) && s.find_first_of(stUnit) == s.size() - 4)
	{
		std::size_t pos = s.find("shtn");

		if (pos != 0)
		{

			string newS = s.replace(pos, 4, " ");
			double originalNum = atof(newS.c_str());
			// 1 Short tons = 0.907185 long tons
			double result = originalNum * 0.907185;
			strResult = std::to_string(result) + " Long tons(longtn or tonne)";
		}
	}

	else if (strstr(s.c_str(), grUnit.c_str()) && s.find_first_of(grUnit) == s.size() - 2)
	{
		std::size_t pos = s.find("gr");

		if (pos != 0)
		{

			string newS = s.replace(pos, 2, " ");
			double originalNum = atof(newS.c_str());
			//1 gr = 0.64301493 dwt
			double result = originalNum * 0.64301493;
			strResult = std::to_string(result) + " pennyweight (dwt)";
		}
	}
	else if (strstr(s.c_str(), dwtUnit.c_str()) && s.find_first_of(dwtUnit) == s.size() - 3)
	{
		std::size_t pos = s.find("dwt");

		if (pos != 0)
		{

			string newS = s.replace(pos, 3, " ");
			double originalNum = atof(newS.c_str());
			//1 dwt = 1.55517384 gr
			double result = originalNum * 1.55517384;
			strResult = std::to_string(result) + " grams (g)";
		}
	}
	return strResult;

}

int main() {

	string originalInput = "";
	string noSpaceInput = "";


	// need to reset this varibale every time do input
	cout << "Mass converter, (c)2018: Haoyu Kong" << endl;
	cout << "Enter the mass: ";

	std::getline(std::cin, originalInput);

	// convert all chars in string to lower case		
	for (auto& c : originalInput)
	{
		c = tolower(c);
		noSpaceInput += c;
	}



	// the program allows user enter white space at anywhere when they are inputing 
	std::string::iterator end_pos = std::remove(noSpaceInput.begin(), noSpaceInput.end(), ' ');
	// remove all the white space between a string
	noSpaceInput.erase(end_pos, noSpaceInput.end());




	stringstream ss;
	ss << noSpaceInput;
	double theNumber;
	string theString;
	ss >> theNumber >> theString;

	if (theString == "g" || theString == "oz" || theString == "kg" || theString == "lb" || theString == "longtn" || theString == "tonne" || theString == "shtn" || theString == "gr" || theString == "dwt")
	{
		string result;
		result = unitResult(noSpaceInput);
		cout << noSpaceInput << " is : " << result << endl;

	}
	else
	{
		cout << "\"" << originalInput << "\"" << " has an unknown unit and cannot be converted" << endl;
	}
}
