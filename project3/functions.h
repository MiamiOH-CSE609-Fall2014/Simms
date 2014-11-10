
std::tuple<std::string, std::vector<std::string>, std::string> parseFastaFile(std::string);

std::map<std::string, int> digramFreqScores(std::string);

std::vector< std::vector<int> > digramFreqMatrix(std::map<std::string, int>);
