#include <iostream>
#include <vector>
#include <string>

#include <fstream>
#include <map>


enum Operation {
	None,
	Add,
	Subtract,
	Multiply,
	Divide,
	Modulo,
	LShift,
	RShift,
	And,
	Or,
	Xor,
	Not,
	Nand,
	Nor,
	Equal,
	NotEqual,
	Greater,
	Less,
	For,
	While,
	Block,
	Do,
	Let,
	If,
	Else,
	Jamp,
	Label,
	Address,
	Pointer,
	String,
	Number,
	Char,
	Structuer,
	Struct,
	Function,
	put,//for stdout.
	get, //for stdin.
	Return,
	Begin,
	End,
	Malloc,
	Alloca,
	mainf,
	UCFS,
	Name,
	FreeTag,
	kakko,
	kokka,
	comma,
	Break,
	Continue,
	include,
	define,
	pragma,
	open,
	close,
	variable,
	dot,
	space,
	coron,
	semicoron,
};

struct Line {
	std::vector<Operation> operations;
	std::vector<std::string> operands;
};

struct MacroC {
	std::vector<Line> lines;
};

typedef std::map<std::string, Operation> OperationMap;

OperationMap createOperationMap() {
	OperationMap opMap;
	opMap["add"] = Operation::Add;
	opMap["subtract"] = Operation::Subtract;
	opMap["multiply"] = Operation::Multiply;
	opMap["divide"] = Operation::Divide;
	opMap["modulo"] = Operation::Modulo;
	opMap["and"] = Operation::And;
	opMap["or"] = Operation::Or;
	opMap["xor"] = Operation::Xor;
	opMap["not"] = Operation::Not;
	opMap["nand"] = Operation::Nand;
	opMap["nor"] = Operation::Nor;
	opMap["equal"] = Operation::Equal;

	opMap["+"] = Operation::Add;
	opMap["-"] = Operation::Subtract;
	opMap["*"] = Operation::Multiply;
	opMap["/"] = Operation::Divide;
	opMap["%"] = Operation::Modulo;
	opMap["&"] = Operation::And;
	opMap["|"] = Operation::Or;
	opMap["^"] = Operation::Xor;
	opMap["!"] = Operation::Not;
	opMap["!&"] = Operation::Nand;
	opMap["!|"] = Operation::Nor;
	opMap["=="] = Operation::Equal;

	opMap["!="] = Operation::NotEqual;
	opMap["<"] = Operation::Greater;
	opMap[">"] = Operation::Less;

	opMap["!>"] = Operation::Greater;
	opMap["!<"] = Operation::Less;

	opMap["not_equal"] = Operation::NotEqual;
	opMap["greater"] = Operation::Greater;
	opMap["less"] = Operation::Less;
	opMap["for"] = Operation::For;
	opMap["while"] = Operation::While;
	opMap["block"] = Operation::Block;
	opMap["do"] = Operation::Do;
	opMap["let"] = Operation::Let;
	opMap["if"] = Operation::If;
	opMap["else"] = Operation::Else;
	opMap["jamp"] = Operation::Jamp;
	opMap["label"] = Operation::Label;
	opMap["address"] = Operation::Address;
	opMap["pointer"] = Operation::Pointer;
	opMap["string"] = Operation::String;
	opMap["number"] = Operation::Number;
	opMap["char"] = Operation::Char;
	opMap["structuer"] = Operation::Structuer;
	opMap["struct"] = Operation::Struct;
	opMap["function"] = Operation::Function;
	opMap["put"] = Operation::put; // for stdout
	opMap["get"] = Operation::get; // for stdin
	opMap["return"] = Operation::Return;
	opMap["begin"] = Operation::Begin;
	opMap["end"] = Operation::End;
	opMap["malloc"] = Operation::Malloc;
	opMap["alloca"] = Operation::Alloca;
	opMap["mainf"] = Operation::mainf;
	opMap["UCFS"] = Operation::UCFS; // User-Defined Control Flow Statement
	// Add more operations as needed.
	opMap["{"] = Operation::kakko;
	opMap["}"] = Operation::kokka;
	opMap[","] = Operation::comma;
	opMap["("] = Operation::open;
	opMap[")"] = Operation::close;
	opMap["{"] = Operation::Begin;
	opMap["}"] = Operation::End;

	opMap["#include"] = Operation::include;
	opMap["#define"] = Operation::define;
	opMap["#pragma"] = Operation::pragma;

	opMap[" "] = Operation::space;
	opMap[";"] = Operation::coron;
	opMap[":"] = Operation::semicoron;
	return opMap;
}



int main() {
	std::ifstream file("test.mc");
	if (!file.is_open()) {
		std::cerr << "Failed to open the file." << std::endl;
		return 1;
	}

	MacroC macroC;
	OperationMap opMap = createOperationMap();

	std::string line;	
	while (std::getline(file, line)) {
		std::cout << line << std::endl; // Just print the line for now.
		Line currentLine;
		std::string S;
		int  L = 0;
		for (std::size_t i = 0; i < line.length();i++) {
			int o = line[i];
			S += tolower(o);
			if (isalnum(o) || o == '_' || o == '.' || o == '#') {
				continue;
			}
			i--;
			if (L == i) { i++; }
			L = i;
			if (S.length() > 1) {
				S.pop_back();
			}
			if (!S.empty()) {
				auto it = opMap.find(S);
				if (it != opMap.end()) {
					currentLine.operands.push_back(S);
					currentLine.operations.push_back(it->second);
				}
				else {
					currentLine.operands.push_back(S);
					currentLine.operations.push_back(Operation::FreeTag);
				}
				S.clear();
			}
		}

		macroC.lines.push_back(currentLine);


	}

	return 0;

}


