#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <map>

struct opTable{
    char mnemonic[6];
    char opcode [2];
    int format;
};

opTable object[60];

struct symtab_s{
    char label[10];
    char loc[10];
    char value[10];
};

//symtab sym[100];

struct assembly_s{
    char label [10];
    char mnemonic[10];
    char operand[10];
    char location[5];
    char objCode[8];
};

//assembly assem[100];

void createOpTable(){
    strcpy(object[0].mnemonic, "WD");
	strcpy(object[0].opcode, "DC");
	object[0].format = 3;

	strcpy(object[1].mnemonic, "ADD");
	strcpy(object[1].opcode, "18");
	object[1].format = 3;

	strcpy(object[2].mnemonic, "ADDF");
	strcpy(object[2].opcode, "58");
	object[2].format = 3;

	strcpy(object[3].mnemonic, "ADDR");
	strcpy(object[3].opcode, "90");
	object[3].format = 2;

	strcpy(object[4].mnemonic, "AND");
	strcpy(object[4].opcode, "40");
	object[4].format = 3;

	strcpy(object[5].mnemonic, "CLEAR");
	strcpy(object[5].opcode, "B4");
	object[5].format = 2;

	strcpy(object[6].mnemonic, "COMP");
	strcpy(object[6].opcode, "28");
	object[6].format = 3;

	strcpy(object[7].mnemonic, "COMPF");
	strcpy(object[7].opcode, "88");
	object[7].format = 3;

	strcpy(object[8].mnemonic, "COMPR");
	strcpy(object[8].opcode, "A0");
	object[8].format = 2;

	strcpy(object[9].mnemonic, "DIV");
	strcpy(object[9].opcode, "24");
	object[9].format = 3;

	strcpy(object[10].mnemonic, "DIVF");
	strcpy(object[10].opcode, "64");
	object[10].format = 3;

	strcpy(object[11].mnemonic, "DIVR");
	strcpy(object[11].opcode, "9C");
	object[11].format = 2;

	strcpy(object[12].mnemonic, "FIX");
	strcpy(object[12].opcode, "C4");
	object[12].format = 1;

	strcpy(object[13].mnemonic, "FLOAT");
	strcpy(object[13].opcode, "C0");
	object[13].format = 1;

	strcpy(object[14].mnemonic, "HIO");
	strcpy(object[14].opcode, "F4");
	object[14].format = 1;

	strcpy(object[15].mnemonic, "J");
	strcpy(object[15].opcode, "3C");
	object[15].format = 3;

	strcpy(object[16].mnemonic, "JEQ");
	strcpy(object[16].opcode, "30");
	object[16].format = 3;

	strcpy(object[17].mnemonic, "JGT");
	strcpy(object[17].opcode, "34");
	object[17].format = 3;

	strcpy(object[18].mnemonic, "JLT");
	strcpy(object[18].opcode, "38");
	object[18].format = 3;

	strcpy(object[19].mnemonic, "JSUB");
	strcpy(object[19].opcode, "48");
	object[19].format = 3;

	strcpy(object[20].mnemonic, "LDA");
	strcpy(object[20].opcode, "00");
	object[20].format = 3;

	strcpy(object[21].mnemonic, "LDB");
	strcpy(object[21].opcode, "68");
	object[21].format = 3;

	strcpy(object[22].mnemonic, "LDCH");
	strcpy(object[22].opcode, "50");
	object[22].format = 3;

	strcpy(object[23].mnemonic, "LDF");
	strcpy(object[23].opcode, "70");
	object[23].format = 3;

	strcpy(object[24].mnemonic, "LDL");
	strcpy(object[24].opcode, "08");
	object[24].format = 3;

	strcpy(object[25].mnemonic, "LDS");
	strcpy(object[25].opcode, "6C");
	object[25].format = 3;

	strcpy(object[26].mnemonic, "LDT");
	strcpy(object[26].opcode, "74");
	object[26].format = 3;

	strcpy(object[27].mnemonic, "LDX");
	strcpy(object[27].opcode, "04");
	object[27].format = 3;

	strcpy(object[28].mnemonic, "LPS");
	strcpy(object[28].opcode, "D0");
	object[28].format = 3;

	strcpy(object[29].mnemonic, "MUL");
	strcpy(object[29].opcode, "20");
	object[29].format = 3;

	strcpy(object[30].mnemonic, "MULF");
	strcpy(object[30].opcode, "60");
	object[30].format = 3;

	strcpy(object[31].mnemonic, "MULR");
	strcpy(object[31].opcode, "98");
	object[31].format = 2;

	strcpy(object[32].mnemonic, "NORM");
	strcpy(object[32].opcode, "C8");
	object[32].format = 1;

	strcpy(object[33].mnemonic, "OR");
	strcpy(object[33].opcode, "44");
	object[33].format = 3;

	strcpy(object[34].mnemonic, "RD");
	strcpy(object[34].opcode, "D8");
	object[34].format = 3;

	strcpy(object[35].mnemonic, "RMO");
	strcpy(object[35].opcode, "AC");
	object[35].format = 2;

	strcpy(object[36].mnemonic, "RSUB");
	strcpy(object[36].opcode, "4C");
	object[36].format = 3;

	strcpy(object[37].mnemonic, "SHIFTL");
	strcpy(object[37].opcode, "A4");
	object[37].format = 2;

	strcpy(object[38].mnemonic, "SHIFTR");
	strcpy(object[38].opcode, "A8");
	object[38].format = 2;

	strcpy(object[39].mnemonic, "SIO");
	strcpy(object[39].opcode, "F0");
	object[39].format = 1;

	strcpy(object[40].mnemonic, "SSK");
	strcpy(object[40].opcode, "EC");
	object[40].format = 3;

	strcpy(object[41].mnemonic, "STA");
	strcpy(object[41].opcode, "0C");
	object[41].format = 3;

	strcpy(object[42].mnemonic, "STB");
	strcpy(object[42].opcode, "78");
	object[42].format = 3;

	strcpy(object[43].mnemonic, "STCH");
	strcpy(object[43].opcode, "54");
	object[43].format = 3;

	strcpy(object[44].mnemonic, "STF");
	strcpy(object[44].opcode, "80");
	object[44].format = 3;

	strcpy(object[45].mnemonic, "STI");
	strcpy(object[45].opcode, "D4");
	object[45].format = 3;

	strcpy(object[46].mnemonic, "STL");
	strcpy(object[46].opcode, "14");
	object[46].format = 3;

	strcpy(object[47].mnemonic, "STS");
	strcpy(object[47].opcode, "7C");
	object[47].format = 3;

	strcpy(object[48].mnemonic, "STSW");
	strcpy(object[48].opcode, "E8");
	object[48].format = 3;

	strcpy(object[49].mnemonic, "STT");
	strcpy(object[49].opcode, "84");
	object[49].format = 3;

	strcpy(object[50].mnemonic, "STX");
	strcpy(object[50].opcode, "10");
	object[50].format = 3;

	strcpy(object[51].mnemonic, "SUB");
	strcpy(object[51].opcode, "1C");
	object[51].format = 3;

	strcpy(object[52].mnemonic, "SUBF");
	strcpy(object[52].opcode, "5C");
	object[52].format = 3;

	strcpy(object[53].mnemonic, "SUBR");
	strcpy(object[53].opcode, "94");
	object[53].format = 2;

	strcpy(object[54].mnemonic, "SVC");
	strcpy(object[54].opcode, "B0");
	object[54].format = 2;

	strcpy(object[55].mnemonic, "TD");
	strcpy(object[55].opcode, "E0");
	object[55].format = 3;

	strcpy(object[56].mnemonic, "TIO");
	strcpy(object[56].opcode, "F8");
	object[56].format = 1;

	strcpy(object[57].mnemonic, "TIX");
	strcpy(object[57].opcode, "2C");
	object[57].format = 3;

	strcpy(object[58].mnemonic, "TIXR");
	strcpy(object[58].opcode, "B8");
	object[58].format = 2;
}

void fileReader(){
    std::map<std::string, int> opTable;
    opTable["ADD"] = 3;
    std::string currentLine = "";
    std::string token = "";
    std::ifstream file("basic.txt");   //edit file name here!
    if (file){
        while (getline(file, currentLine, '\n')){
            if (currentLine[0] != '.' && currentLine != "") {
                std::stringstream lineStream(currentLine);
                while (getline(lineStream, token, '\t')) {
                    if (token[0] != '.' && token != "") {
                             std::cout << token + "\n";
                        for( int i = 0; i < 1000; i++){
                            if(token == object[i].mnemonic){
                                std::cout << token + " belongs to OpTable!" << std::endl;
                            }
                        }
                    }
                }
            }
            std::cout << "end of line \n\n";
        }
    }
    else {
        //throw std::invalid_argument("File was not found.");
    }
}

int main(){
    createOpTable();
    fileReader();
    return 0;
}


