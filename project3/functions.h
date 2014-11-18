
std::tuple<std::string, std::vector<std::string>, std::string> parseFastaFile(std::string);

std::map<std::string, int> digramFreqScores(std::string);

std::vector< std::vector<int> > digramFreqMatrix(std::map<std::string, int>);

std::vector< std::vector<int> > parseScoringFile(std::string);

std::pair<int, int> scoreSequence(std::string, std::string, std::vector< std::vector<int> >);

std::tuple<int, int, std::string> findHighScore(std::string, std::vector<std::string>, std::vector< std::vector<int> >);
