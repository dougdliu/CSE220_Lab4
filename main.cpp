/*
 *Authors: Aaron Chasse, Jake Borg, Deming Liu
 *CSE 220 - Lab 4
 *04/09/2014
 *
 *Program Description: main.cpp
 *Takes a file containing text as a parameter. Opens the file and creates a new Scanner object to iterate 
 *through the file line by line tokenizing the text. A pointer to the new token is returned from Scanner
 *and its type is checked to see if it is an identifer. If it is an identifer, the binary tree object determines
 *where in the tree it should be placed based on alphabetical precedence. If the token is not an identifer
 *it is deleted by called in the deconstructor and freeing the memory. When a period '.' is reached, signifying
 *the end of file, the binary tree is printed and each token is deleted. Then the final period token is deleted
 *and the source file is closed.
 *
 *Created by Bryce Holton.
 *
*/


#include <iostream>
#include "common.h"
#include "Print.h"
#include "Scanner.h"
#include "Token.h"
#include "bTree.h"
#include "LinkedList.h"

FILE *init_lister(const char *name, char source_file_name[], char dte[]);
void quit_scanner(FILE *src_file, Token *list);
void add_token_to_list(Token *list, Token *new_token);

int main(int argc, const char * argv[])
{

    Token *token = NULL;
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];
    FILE *source_file = init_lister(argv[1], source_name, date);
    Print print(source_name, date);
    Scanner scanner(source_file, source_name, date, print);
    bTree tree;   //call default constructor of bTree


    do
    {
        token = scanner.getToken();
        print.printToken(token);
        if (token->getCode() != PERIOD && token->getCode() != END_OF_FILE)
        {
            if(token->getCode() == IDENTIFIER)
            {

                /*
                    call the add method of bTree class on the identifer token,
                    bTree will further find the proper place in the tree structure
                    and either add it alphabetically or add a line number to the linked list.
                    The current line number is also fetched and passed to add()
                */

                tree.addToTree(token, scanner.getLineNumber());

            }
            else
                delete token;
        }
    }
    while (token->getCode() != PERIOD && token->getCode() != END_OF_FILE);

    //print the reference information header strings
    print.printReferenceHeader();

    //code to recursively print the binery tree and then delete the tokens
    tree.printTree();

    //delete the last token which is the period after everything has been printed
    delete token;
    //then close the src file
    fclose(source_file);
    return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;

    strcpy(source_file_name, name);
    file = fopen(source_file_name, "r");
    time(&timer);
    strcpy(dte, asctime(localtime(&timer)));
    return file;
}

