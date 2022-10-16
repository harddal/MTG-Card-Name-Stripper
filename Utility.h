#include <algorithm> 
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <windows.h>

void Warning(std::string error);
void Error(std::string error);

std::string OpenFileDialog(const char* filter);

void Split(const std::string& str, const std::string& delimiters, std::vector<std::string>& tokens);