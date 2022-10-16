#include "Utility.h"

using namespace std;

int main()
{
	string input, file_in, line_input;

	vector<string> tokens, tokens_seperated, card_names;

	auto file = OpenFileDialog("*.csv");

	ifstream fin(file);
	
	if (!fin)
	{
		Error("Invalid/Corrupt File!");
	}

	unsigned int iter = 0;
	while (getline(fin, line_input))
	{
		if (iter == 0)
		{
			iter++;
			continue;
		}

		Split(line_input, ",", tokens);

		iter++;
	}

	ofstream fout;
	fout.open("card_names.txt");

	if (!fout)
	{
		Error("Failed to write output file!");
	}

	for (auto i = 0; i < tokens.size(); i++)
	{
		if (tokens.at(i).length() >= 4)
		{
			cout << tokens.at(i) << "\n";
			fout << tokens.at(i) << "\n";
		}
	}

	fout.close();

	return 0;
}