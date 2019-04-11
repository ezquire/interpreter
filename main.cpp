#include <iostream>
#include <vector>
#include <memory>

#include "Token.hpp"
#include "Tokenizer.hpp"
#include "Parser.hpp"
#include "TypeDescriptor.hpp"

int main(int argc, char *argv[]) {

    if( argc != 2) {
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile\n";
        exit(1);
    }

    std::ifstream inputStream;

    inputStream.open(argv[1], std::ios::in);
    if( ! inputStream.is_open()) {
        std::cout << "Unable to open " << argv[1] << ". Terminating...\n";
        exit(2);
	}

    Tokenizer tokenizer(inputStream);

	/*Token tok = tokenizer.getToken();
	while( !tok.eof() )
		tok = tokenizer.getToken();

		tokenizer.printProcessedTokens();*/
	
	
	Parser parser(tokenizer);

	std::unique_ptr<Statements> statements = parser.statements();
    SymTab symTab;

    //statements->print();
    statements->evaluate(symTab);
	
    return 0;
}
