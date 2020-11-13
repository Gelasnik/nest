#include "tokens.hpp"
#include <iostream>
#include <cstring>

//Spaces are ignored, besides in string
//all numbers are type int
//after recognizing token, this line is printed (only 1 space between words and ending is LF (\n):
//<line number> <token name> <value>
int main()
{
	int token;
    bool readMode;
//    char yytext2[100];
	while(token = yylex()) {
//	    yyleng=5;//TODO DELETE THIS
//	    std::cin>>yytext2;//TODO DELETE THIS
//	    token=STRING;//TODO DELETE THIS
	using namespace std;
	switch(token){
	    case VOID:
	        cout <<"VOID\n";
            break;
        case ID:
            cout <<"ID\n";
            break;
	    case INT:
	        cout <<"INT\n";
            break;
	    case BYTE:
	        cout <<"BYTE\n";
	        break;
	    case B:
	        cout<<"B\n";
	        break;
        case BOOL:
            cout<<"BOOL\n";
            break;
        case AND:
            cout<<"AND\n";
            break;
        case OR:
            cout<<"OR\n";
            break;
        case NOT:
            cout<<"NOT\n";
            break;
        case TRUE:
            cout<<"TRUE\n";
            break;
        case FALSE:
            cout<<"FALSE\n";
            break;
        case RETURN:
            cout<<"RETURN\n";
            break;
        case IF:
            cout<<"IF\n";
            break;
        case ELSE:
            cout<<"ELSE\n";
            break;
        case WHILE:
            cout<<"WHILE\n";
            break;
        case BREAK:
            cout<<"BREAK\n";
            break;
        case CONTINUE:
            cout<<"CONTINUE\n";
            break;
        case SC:
            cout<<"SC\n";
            break;
        case COMMA:
            cout<<"COMMA\n";
            break;
        case LPAREN:
            cout<<"LPAREN\n";
            break;
        case RPAREN:
            cout<<"RPAREN\n";
            break;
        case LBRACE:
            cout<<"LBRACE\n";
            break;
        case RBRACE:
            cout<<"RBRACE\n";
            break;
        case RELOP:
            cout<<"RELOP\n";
            break;
        case ASSIGN:
            cout<<"ASSIGN\n";
            break;
        case COMMENT:
            cout<<"COMMENT\n";
            break;
        case BINOP:
            cout<<"BINOP\n";
            break;
        case NUM:
            cout<<"NUM\n";
            break;
	    case STRING:
	        cout<<"STRING: "<< yytext<<"\n";
	        readMode= false;
	        yyleng=yyleng-2;//" not count
            for(char* c = yytext+1; yyleng>0;c++){
                if(!readMode){
                    //normal char reading
                    if(*c=='\\'){
                        readMode =true;
                    }else{
                        cout<<*c;
                    }
                } else{
                    //found '\'
                    switch (*c) {
                        case 'n':
                            cout<<"\n";
                            break;
                        case '"':
                            cout<<"\"";
                            break;
                        case '\\':
                            cout<<"\\";
                            break;
                        case 'r':
                            cout<<"\r";
                            break;
                        case 't':
                            cout<<"\t";
                            break;
                        case '0':
                            cout<<"\0";
                            yyleng=0;//End of string after \0
                            break;
                        case 'x':
                            string hexString = {*(c+1),*(c+2)};
                            uint16_t hexNum = stoi(hexString, nullptr,16);
                            uint8_t charToPrint[sizeof(hexNum)];
                            memcpy( charToPrint, &hexNum, sizeof( hexNum ) );
                            cout<<charToPrint;
                            c=c+2;
                            yyleng=yyleng-2;
                            break;
                    }
                    readMode = false;
                }

                yyleng--;
            }
            cout<<"\n";
	        break;
        default:
            cout<<"Something else\n";
            break;
	}


	}
	return 0;
}