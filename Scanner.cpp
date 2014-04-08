//
//  Scanner.cpp
//  Lab4
//
//  Created by Bryce Holton.
//

#include "Scanner.h"
#include "Print.h"

typedef struct
{
    char *string;
    TokenCode token_code;
}
RwStruct;

const RwStruct rw_table[9][10] = {
    {{"do",DO},{"if",IF},{"in",IN},{"of",OF},{"or",OR},{"to",TO},{NULL,NO_TOKEN}}, //Reserved words of size 2
    {{"and",AND},{"div",DIV},{"end",END},{"for",FOR},{"mod",MOD},{"nil",NIL},{"not",NOT},{"set",SET},{"var",VAR},{NULL,NO_TOKEN}}, //Reserved words of size 3
    {{"case",CASE},{"else",ELSE},{"file",FFILE},{"goto",GOTO},{"then",THEN},{"type",TYPE},{"with",WITH},{NULL,NO_TOKEN}}, //Reserved words of size 4
    {{"array",ARRAY},{"begin",BEGIN},{"const",CONST},{"label",LABEL},{"until",UNTIL},{"while",WHILE},{NULL,NO_TOKEN}},  //Reserved words of size 5
    {{"downto",DOWNTO}, {"packed",PACKED},{"record",RECORD}, {"repeat",REPEAT},{NULL,NO_TOKEN}},  // Reserved words of size 6
    {{"program", PROGRAM},{NULL,NO_TOKEN}}, // Reserved words of size 7
    {{"function", FUNCTION},{NULL,NO_TOKEN}}, // Reserved words of size 8
    {{"procedure", PROCEDURE},{NULL,NO_TOKEN}}  // Reserved words of size 9
};

Scanner::Scanner(FILE *source_file, char source_name[], char date[], Print printer) : print(printer)
{
    src_file = source_file;
    *line_ptr = NULL;
    strcpy(src_name, source_name);
    strcpy(todays_date, date);
    
    /*******************
     initialize character table, this table is useful for identifying what type of character
     we are looking at by setting our array up to be a copy the ascii table.  Since C thinks of
     a char as like an int you can use ch in get_token as an index into the table.
     *******************/
    unsigned int i;
    for (i = 0; i < CHAR_TABLE_SIZE; i++)
    {
        if (i >= '0' && i <= '9')
        {
            char_table[i] = DIGIT;
        }
        else if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))
        {
            char_table[i] = LETTER;
        }
        else
        {
            char_table[i] = SPECIAL;
        }
    }
    char_table['\''] = QUOTE;
    char_table[EOF_CHAR] = EOF_CODE;
    
    line_number = 0;
    source_line[0] = '\0';
}
Scanner::~Scanner()
{
    
}
int Scanner::getLineNumber()
{
    return line_number;
}
bool Scanner::getSourceLine(char source_buffer[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    
    if (fgets(source_buffer, MAX_SOURCE_LINE_LENGTH, src_file) != NULL)
    {
        ++line_number;
        sprintf(print_buffer, "%4d: %s", line_number, source_buffer);
        print.printLine(print_buffer);
        return true;
    }
    else
    {
        return false;
    }
}
Token* Scanner::getToken()
{
    char ch = '\0'; //This can be the current character you are examining during scanning.
    char token_string[MAX_TOKEN_STRING_LENGTH] = {'\0'}; //Store your token here as you build it.
    char *token_ptr = token_string; //write some code to point this to the beginning of token_string
    Token *new_token = new Token();
    
    //1.  Skip past all of the blanks
    if (line_ptr == NULL)
    {
        line_ptr = source_line;
    }
    skipBlanks(source_line);
    ch = *line_ptr;
    
    //2.  figure out which case you are dealing with LETTER, DIGIT, QUOTE, EOF, or special, by examining ch
    switch (char_table[ch])
    {//3.  Call the appropriate function to deal with the cases in 2.
        case LETTER:
            getWord(token_string, token_ptr, new_token);
            break;
        case DIGIT:
            getNumber(token_string, token_ptr, new_token);
            break;
        case QUOTE:
            getString(token_string, token_ptr, new_token);
            break;
        case EOF_CODE:
            new_token->setCode(END_OF_FILE);
            break;
        default:
            getSpecial(token_string, token_ptr, new_token);
            break;
    }
    
    return new_token; //What should be returned here?
}
char Scanner::getChar(char source_buffer[])
{
    /*
     If at the end of the current line (how do you check for that?),
     we should call get source line.  If at the EOF (end of file) we should
     set the character ch to EOF and leave the function.
     */
    char ch;
    
    if (*line_ptr == '\0')
    {
        if (!getSourceLine(source_buffer))
        {
            ch = EOF_CHAR;
            return ch;
        }
        line_ptr = source_buffer;
    }
    
    /*
     Write some code to set the character ch to the next character in the buffer
     */
    ch = *line_ptr;
    if ((ch == '\n') || (ch == '\t') || (ch == '\r'))
    {
        ch = ' ';
    }
    if (ch == '{')
    {
        skipComment(source_buffer);
    }
    return ch;
}
void Scanner::skipBlanks(char source_buffer
