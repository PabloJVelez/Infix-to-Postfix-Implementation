//#include <iostream>
//#include <cstring>
//#include <fstream>
//#include <string>
//#include <ctype.h>
//#include "ArgumentManager.h"
//
//
//char * clear(char * str);
//bool missingOperators(string &str);
//// bool to check and see if an operand is being read or not
//bool isSymbol(char c)
//{
//    if (c == '+' || c == '-' ||
//        c == '*' || c == '/' ||
//        c == '.' )
//    {
//        return true;
//    }
//    else if (c == '(' || c == ')' ||
//             c == '{' || c == '}' ||
//             c == '[' || c == ']' )
//    {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//// bool to check and see whats taking precedence
//
//bool takesPrecedent(char c, char c2, int &num)
//{
//    if(c == ')' || c == ']' || c == '}')
//    {
//        if (c2 == '(' || c2 == '[' || c2 == '{') {
//            num--;
//            return false;
//        }
//        return true;
//    }
//    if (c == '+' || c == '-' ) {
//        if (c2 == '*' || c2 == '/') {
//            return true;
//        }
//        else{
//            return false;
//        }
//    }
//    
//    return false;
//}
//// bool to check and make sure we have the right number of parenthesis
//bool parenthesisCheck(char * str)
//{
//    char ops[strlen(str)+1];
//    int position = 0;
//    for (int i = 0; i < strlen(str); ++i)
//    {
//        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
//        {
//            ops[position++] = str[i];
//        }
//        
//        if (str[i] == ')' || str[i] == '}' || str[i] == ']')
//        {
//            if (str[i] == ')' && ops[position-1] == '(')
//            {
//                position -= 1;
//            }
//            else if (str[i] == ']' && ops[position-1] == '[')
//            {
//                position -= 1;
//            }
//            else if (str[i] == '}' && ops[position-1] == '{')
//            {
//                position -= 1;
//            }
//            else {
//                return false;
//            }
//        }
//    }
//    
//    if (position > 0)
//    {
//        return false;
//    }
//    
//    return true;
//}
//// checking through the equation
//void checkEquation(char * str)
//{
//    char ops[strlen(str)+1];
//    int position = 0;
//    bool foundSymbol = false;
//    for (int i = 0; i < strlen(str); ++i)
//    {
//        if (str[i] >= '0' && str[i] <= '9')
//        {
//            ops[position++] = str[i];
//            foundSymbol = false;
//        }
//        else if (str[i] == '*' || str[i] == '/' ||
//                 str[i] == '+' || str[i] == '-' )
//        {
//            if (foundSymbol)
//            {
//                str[position]= ' ';
//                foundSymbol = false;
//            }
//            else {
//                position = i;
//                foundSymbol = true;
//            }
//        }
//    }
//}
//
////function to print the characters
//void printChar(std::ofstream & myfile, char c)
//{
//    if(c != '(' && c != ')' &&
//       c != '[' && c != ']' &&
//       c != '{' && c != '}' &&
//       c != '\0')
//    {
//        //std::cout << c << " ";
//        myfile << c << " ";
//    }
//}
//
//int main(int argc, char * argv [])
//{
//    // reading input
//    char * out;
//    char * in;
//    
//    ArgumentManager am(argc, argv);
//    string infilename = am.get("A");
//    string outfilename = am.get("C");
//    
//    out = strtok (argv[1],";");
//    
//    in = strtok (NULL,";");
//    out += 2;
//    in += 2;
//    
//    ifstream file;
//    file.open(infilename.c_str());
//    
//    
//    string txt;
//    ofstream writeOut(outfilename.c_str());
//    //reading in the length of the equation
//    
//    getline(file, txt);
//    long SIZE = txt.length()+1;
//    if (!missingOperators(txt))
//    {
//        return 0;
//    }
//    file.seekg(0, ios::beg);
//    char * postFix = new char[SIZE];
//    file.read(postFix, SIZE);
//    
//    file.close();
//    
//    // Tokenize the string, print operands and store operands on stack
//    
//    char * clearedString = clear(postFix);
//    checkEquation(clearedString);
//    
//    int N = (int) strlen(clearedString)+1;
//    char array[N];
//    int opPosition = 0;
//    double nums[N];
//    int positionNum = 0;
//    
//    for (int i =0; i < strlen(clearedString); i++) {
//        if (isSymbol(clearedString[i]))
//        {
//            while (opPosition >= 0 && takesPrecedent(clearedString[i],array[opPosition-1], opPosition)) {
//                std::cout << std::endl;
//                for (int l =0; l < opPosition; l++) {
//                    //std::cout << array[l] << " ";
//                }
//                //std::cout << std::endl;
//                printChar(writeOut, array[opPosition-1]);
//                opPosition--;
//            }
//            if (clearedString[i] != ']' && clearedString[i] != '}' && clearedString[i] != ')') {
//                array[opPosition++] = clearedString[i];
//            }
//        }
//        
//        if (!parenthesisCheck(clearedString))
//        {
//            delete[] postFix;
//            return 0;
//        }
//        
//        
//        char * str1 = new char(strlen(clearedString));
//        int pos = 0;
//        
//        while ((clearedString[i] >= '0' && clearedString[i] <= '9') || clearedString[i] == '.') {
//            str1[pos++] = clearedString[i];
//            i++;
//        }
//        str1[pos] = '\0';
//        
//        if (str1[0] >= '0' && str1[0] <= '9') {
//            nums[positionNum++] = atof(str1);
//            //std::cout << str1 << " " ;
//            
//            writeOut << str1 << " " ;
//            i--;
//        }
//        delete str1;
//    }
//    
//    int k = opPosition - 1;
//    // print out the rest of the stack after the tokens
//    while(k >= 0)
//    {
//        printChar(writeOut, array[k]);
//        k--;
//    }
//    
//    writeOut.close();
//    
//    // Calculating Postfix result
//    double stack[N];
//    int stackPos = 0;
//    fstream infile;
//    infile.open(in, std::ios_base::in | std::ios_base::out);
//    
//    char  token[N];
//    double num1 = 0.0;
//    double num2 = 0.0;
//    double ans = 0.0;
//    
//    while(!infile.eof())
//    {
//        infile >> token;
//        if (strlen(token) > 0 && token[0] >= '0' && token[0] <= '9')
//        {
//            stack[stackPos++] = atof(token);
//        }
//        else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'  )
//        {
//            num2 = stack[stackPos-2];
//            num1 = stack[stackPos-1];
//            if (token[0] == '+')
//            {
//                ans = num1 + num2;
//            }
//            else if (token[0] == '-')
//            {
//                ans = num2 - num1;
//            }
//            else if (token[0] == '*')
//            {
//                ans = num1 * num2;
//            }
//            else if (token[0] == '/')
//            {
//                ans = num2 / num1;
//            }
//            
//            stackPos -= 2;
//            stack[stackPos++] = ans;
//            
//            
//        }
//        
//    }
//    
//    infile.close();
//    
//    ofstream answerFile;
//    answerFile.open(in, std::ios_base::app);
//    answerFile << fixed;
//    answerFile.precision(2);
//    answerFile << endl << stack[0] << endl;
//    answerFile.close();
//    delete[] postFix;
//    return 0;
//}
//
////checks to see if C or CE are in the equation and performs the appropriate removals
//char * clear(char * str)
//{
//    int position = 0;
//    
//    for (int i =0; i < strlen(str); i++) {
//        
//        if (str[i] == 'C' && (i+1) < strlen(str) && str[i+1] == 'E') {
//            return clear(&str[i+2]);
//        }
//        else if (str[i] == 'C') {
//            str[position] = ' ';
//            str[i] = ' ';
//        }
//        else if (str[i] != ' ') {
//            position = i;
//        }
//    }
//    
//    return str;
//}
////checks to see if there are anymissing operrands between numbers
//bool missingOperators(string &str)
//{
//    enum {start, digit, digitspace} state;
//    for (char c : str) {
//        switch (state) {
//            case start:
//                if (isdigit(c)) state = digit;
//                break;
//            case digit:
//                if (c == ' ') state = digitspace;
//                else if (!isdigit(c)) state = start;
//                break;
//            case digitspace:
//                if (isdigit(c)) return false;
//                else if (c != ' ') state = start;
//        }
//    }
//    return true;
//}
//
//
//
