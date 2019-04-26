//
// Created by Sebastian on 23.04.2019.
//

#include <iostream>
#include <vector>
#include "YeetInterpreter.h"
#include "YeetParser.h"
#include "Logger.h"

YeetInterpreter::YeetInterpreter(int *ec, int memSize):exitCode(ec), env(YeetEnv(memSize)){
	ArithmeticAddInstruction addInstruction = ArithmeticAddInstruction();
	ArithmeticSubtractInstruction subtractInstruction = ArithmeticSubtractInstruction();
	SaveFromAccInstruction saveFromAccInstruction = SaveFromAccInstruction();
	ReadToAccInstruction readToAccInstruction = ReadToAccInstruction();
	PushIntToPrintQueueInstruction pushIntToPrintQueueInstruction = PushIntToPrintQueueInstruction();
	PushCharToPrintQueueInstruction pushCharToPrintQueueInstruction = PushCharToPrintQueueInstruction();
	ClearPrintQueueInstruction clearPrintQueueInstruction = ClearPrintQueueInstruction();
	PrintPrintQueueInstruction printPrintQueueInstruction = PrintPrintQueueInstruction();

	instructionList = std::vector<Instruction*>{
		&addInstruction,
		&subtractInstruction,
		&saveFromAccInstruction,
		&readToAccInstruction,
		&pushIntToPrintQueueInstruction,
		&pushCharToPrintQueueInstruction,
		&clearPrintQueueInstruction,
		&printPrintQueueInstruction
	};

};


int YeetInterpreter::interpretLine(std::string line) {
	std::vector<std::string> str_vec = std::vector<std::string>();

	std::string delimiter = " ";
	std::size_t pos = 0;
	std::string str;
	while ((pos = line.find(delimiter)) != std::string::npos){
        str = line.substr(0,pos);
	    if(str.length() > 0){
	        str_vec.push_back(str);
	    }
	    line.erase(0, pos + delimiter.length());
	}

	std::vector<IYeet> parsed;
	parsed.reserve(str_vec.size());
	for (auto &it : str_vec) {
		parsed.push_back(YeetParser::parseYeetStatement(&it));
	}

	Instruction* instruction = instructionList.at((unsigned long long int)(parsed.front().value));
	parsed.erase(parsed.begin());

	instruction->execute(parsed, env);

}
