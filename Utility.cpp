#include "Utility.h"

void Warning(std::string error)
{
	MessageBox(nullptr, error.c_str(), "Warning!", MB_OK | MB_ICONWARNING | MB_TASKMODAL);
}

void Error(std::string error)
{
	MessageBox(nullptr, error.c_str(), "Error!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
	std::exit(EXIT_FAILURE);
}

std::string OpenFileDialog(const char* filter)
{
	char filename[MAX_PATH];

	OPENFILENAME ofn;
	ZeroMemory(&filename, sizeof(filename));
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = nullptr;
	ofn.lpstrFilter = filter;
	ofn.lpstrFile = filename;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = "Open";
	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;

	GetOpenFileNameA(&ofn);

	return std::string(filename);
}

void Split(const std::string& str, const std::string& delimiters, std::vector<std::string>& tokens)
{
	// Skip delimiters at the beginning
	std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);

	// Find first non-delimiter
	std::string::size_type pos = str.find_first_of(delimiters, lastPos);

	unsigned int iter = 0;

	while (std::string::npos != pos || std::string::npos != lastPos)
	{
		if (iter == 6)
		{
			break;
		}

		// Found a token, so add it to the vector
		tokens.push_back(str.substr(lastPos, pos - lastPos));

		// Skip the specified delimiters
		lastPos = str.find_first_not_of(delimiters, pos);

		// Find the next non-delimiter
		pos = str.find_first_of(delimiters, lastPos);

		iter++;
	}
}
