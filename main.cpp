/*
 use . , - , '+'to represent end of letter, / to represent end of word
 every alphabet or digit should end with a +
 every word should end with / without preceded by + ending the last digit of the alphabet of digit
*/



#include <iostream>
#include<cstdlib>
#include<string.h>

using namespace std;

const int codel=7;

int screen1();
void mainmenu();
char decrypt(char letter[codel]);
string Morselist(char code_letter);
void msgtoMorse();
void Morsetomsg();
void Morsequiz();

int main()
{
     mainmenu();
    return 0;
}

// This function is the main menu which the user uses to select one of the available features of the program

int screen1(){
     int op1;
     cout<<"\n\n------------------------------------------------------------------------------------\n\n";
     cout<<"\t\t\t\t\t MORSO";
     cout<<"\n\n------------------------------------------------------------------------------------\n\n";
     cout<<"\tSelect what you want to do with MORSO:\n";
     cout<<"\t\t1. Code your message to Morse Code\n";
     cout<<"\t\t2. Decode your Morse Code message\n";
     cout<<"\t\t3. Quit\n";
     cout<<"\tSelect :\t";
     cin>>op1;

     while(op1>3 || op1<1){
          cout<<"\n\tInvalid selection!!!\n\tReselect :\t";
          cin>>op1;
     }
  return op1;
}

void mainmenu(){
     char again;
  do{
     system("cls");
     int choice;
     choice = screen1();
     system("cls");
     switch(choice){
     case 1:
          msgtoMorse();
          break;
     case 2:
          Morsetomsg();
          break;
     case 3:
     default:{
          cout<<"See you again!\n";
          exit(0);
          }

     }
    cout<<"\nReturn to the Main Menu(Y/N) :\t";
    cin>>again;
  }while(again == 'Y' || again == 'y');
}

//Function to create a list of alphabets and digits and their equivalent Morse Codes

string Morselist(char code_letter){
     string code;
          switch(code_letter){
          case 'A':
          case 'a':
               code=".-";
               break;

          case 'B':
          case 'b':
               code="-...";
               break;

          case 'C':
          case 'c':
               code="-.-.";
               break;

          case 'D':
          case 'd':
               code="-..";
               break;

          case 'E':
          case 'e':
               code=".";
               break;

          case 'F':
          case 'f':
               code="..-.";
               break;

          case 'G':
          case 'g':
               code="--.";
               break;

          case 'H':
          case 'h':
               code="....";
               break;

          case 'I':
          case 'i':
               code="..";
               break;

          case 'J':
          case 'j':
               code=".---";
               break;

          case 'K':
          case 'k':
               code="-.-";
               break;

          case 'L':
          case 'l':
               code=".-..";
               break;

          case 'M':
          case 'm':
               code="--";
               break;

          case 'N':
          case 'n':
               code="-.";
               break;

          case 'O':
          case 'o':
               code="---";
               break;

          case 'P':
          case 'p':
               code=".--.";
               break;

          case 'Q':
          case 'q':
               code="--.-";
               break;

          case 'R':
          case 'r':
               code=".-.";
               break;

          case 'S':
          case 's':
               code="...";
               break;

          case 'T':
          case 't':
               code="-";
               break;

          case 'U':
          case 'u':
               code="..-";
               break;

          case 'V':
          case 'v':
               code="...-";
               break;

          case 'W':
          case 'w':
               code=".--";
               break;

          case 'X':
          case 'x':
               code="-..-";
               break;

          case 'Y':
          case 'y':
               code="-.--";
               break;

          case 'Z':
          case 'z':
               code="--..";
               break;

          case '1':
               code=".----";
               break;

          case '2':
               code="..---";
               break;

          case '3':
               code="...--";
               break;

          case '4':
               code="....-";
               break;

          case '5':
               code=".....";
               break;

          case '6':
               code="-....";
               break;

          case '7':
               code="--...";
               break;

          case '8':
               code="---..";
               break;

          case '9':
               code="----.";
               break;

          case '0':
               code="-----";
               break;

          default:
               code="?";

          }
     return code;
}

void msgtoMorse(){
     string msg;

     cout<<"\n\n------------------------------------------------------------------------------------\n\n";
     cout<<"\t\t\t\t\t MORSO";
     cout<<"\n\n------------------------------------------------------------------------------------\n\n";
     cout<<"\t\t\tEnter the Morse Code message to encrypt";
     cout<<"\n\n------------------------------------------------------------------------------------\n\n";
     cout<<"\t\t\t\t\tMessage\n\t";

     cin.ignore();
     getline(cin,msg);
     int msglen= msg.length();

     cout<<"\n\n------------------------------------------------------------------------------------\n\n";
     cout<<"\tMorse Code for the message\n";
     for(int i=0;i<msglen;i++){
     if(msg.at(i)==' ')
          cout<<"/";
     else
          cout<<Morselist(msg.at(i))<<"+";
     }
}



//Function to decrypt the morse code message
void Morsetomsg(){
     string msg;
     char letter[codel]={'x','x','x','x','x','x'};
     cout<<"\n\n------------------------------------------------------------------------------------\n\n";
     cout<<"\t\t\t\t\t MORSO";
     cout<<"\n\n------------------------------------------------------------------------------------\n\n";
     cout<<"\t\t\tEnter the Morse Code message to decrypt";
     cout<<"\n\n------------------------------------------------------------------------------------\n\n";
     cout<<"\t\t\t\t\tMessage\n\t";
     cin>>msg;
     int msglen= msg.length();

     // cout<<letter;
     char decode;
     cout<<"\t";

     int k=0;
     for(int i=0;i<msglen;i++){

          if(msg.at(i)=='+'){
               letter[k] = msg.at(i);
               decode=decrypt(letter);
               if(decode=='?')
                    cout<<"\tInvalid Morse Code\n";
               else
                    cout<<decode;
               k=0;
          }
          else if(msg.at(i)=='/'){

               cout<<" ";
               for(int j=0;j<codel;j++)
                    letter[j]='x';
               k=0;
          }
          else if(msg.at(i)=='.' || msg.at(i)=='-'){
           letter[k] = msg.at(i);
           k++;
          }
          if(k>codel-2 && (msg.at(i+1)!='/' || msg.at(i+1)!='+')){
              cout<<"\tInvalid morse code\n";
              // mainmenu();
          }
     }
     // cout<<letter;
}

// Decrypting the morse code using the decision tree algorithm
char decrypt(char letter[codel]){
     char decode;
     switch(letter[0]){
     case '.':                                    //.
          {
               switch(letter[1]){
               case '.':                          //..
                    {
                         switch(letter[2]){
                         case '.':                //...
                              {
                                   switch(letter[3]){
                                   case '.':                //....
                                        {
                                             switch(letter[4]){
                                             case '.':                //..... = 5
                                                  {
                                                        decode='5';
                                                  }
                                                  break;
                                             case '-':                //....- = 4
                                                  {
                                                       decode='4';
                                                  }
                                                  break;
                                             case '+':                //.... = H
                                                  {
                                                      decode='H';
                                                  }
                                                  break;
                                             }
                                        }
                                        break;
                                   case '-':           //...-
                                        {
                                             switch(letter[4]){

                                             case '-':           //...-- = 3
                                                  {
                                                       decode='3';
                                                  }
                                                  break;
                                             case '+':           //...- = V
                                                  {
                                                       decode='V';
                                                  }
                                                  break;
                                             }
                                        }
                                        break;
                                   case '+':           //... = S
                                        {
                                             decode='S';
                                        }
                                        break;
                                   }         //letter 3 ends here
                              }
                              break;
                         case '-':           //..-
                              {
                                   switch(letter[3]){
                                   case '.':           //..-. = F
                                        {    if(letter[4]=='+')
                                             decode = 'F';
                                        }
                                        break;
                                   case '-':           //..-- = 2
                                        {
                                             if(letter[4]=='+')
                                             decode='2';
                                        }
                                        break;
                                   case '+':      //..- = U
                                        {
                                             decode='U';
                                        }
                                        break;
                                   }
                              }
                              break;
                         case '+':           //.. = I
                              {
                                   decode='I';
                              }
                              break;
                         }         //letter 2 ends here
                    }
                    break;

               case '-':           //.-
                    {
                         switch(letter[2]){
                         case '.':           //.-.
                              {
                                   switch(letter[3]){
                                   case '.':           //.-.. = L
                                        {
                                             if(letter[4]=='+')
                                             decode='L';
                                        }
                                        break;
                                   case '+':           //.-. = R
                                        {
                                             decode='R';
                                        }
                                        break;
                                   }
                              }
                              break;
                         case '-':           //.--
                              {
                                   switch(letter[3]){
                                   case '.':           //.--. = P
                                        {
                                             if(letter[4]=='+')
                                             decode='P';
                                        }
                                        break;
                                   case '-':           //.---
                                        {
                                             switch(letter[4]){
                                             case '-':{               //.---- = 1
                                                  decode = '1';
                                             }
                                             break;
                                             case '+':{               //.--- = J
                                                  decode = 'J';
                                             }
                                             break;
                                             }
                                        }
                                        break;
                                   case '+':           //.-- = W
                                        {
                                             decode='W';
                                        }
                                        break;
                                   }

                              }
                              break;
                         case '+':           //.- = A
                              {
                                   decode='A';
                              }
                              break;
                         }
                    }
                    break;

               case '+':      //. = E
                    {
                         decode='E';
                    }
                    break;
               }
          }    //letter 1 ends here
          break;


     case '-':           //-
          {
               switch(letter[1]){
               case '.':           //-.
                    {
                        switch(letter[2]){
                         case '.':                //-..
                              {
                                   switch(letter[3]){
                                   case '.':                //-...
                                        {
                                             switch(letter[4]){
                                             case '.':           //-.... = 6
                                                  {
                                                       decode='6';
                                                  }
                                                  break;

                                             case '+':      //-... = B
                                                  {
                                                       decode='B';
                                                  }
                                                  break;
                                             }
                                        }
                                        break;
                                   case '-':           //-..- = X
                                        {
                                             if(letter[4]=='+')
                                             decode='X';
                                        }
                                        break;
                                   case '+':           //-.. =D
                                        {
                                             decode='D';
                                        }
                                        break;
                                   }
                              }
                              break;
                         case '-':           //-.-
                              {
                                   switch(letter[3]){
                                   case '.':           //-.-. = C
                                        {
                                             if(letter[4]=='+')
                                             decode='C';
                                        }
                                        break;
                                   case '-':         //-.-- = Y
                                        {
                                             if(letter[4]=='+')
                                             decode='Y';
                                        }
                                        break;
                                   case '+':           //-.- = K
                                        {
                                             decode='K';
                                        }
                                        break;
                                   }
                              }
                              break;
                         case '+':           //-. = N
                              {
                                   decode='N';
                              }
                              break;
                         }
                    }
                    break;
               case '-':           //--
                    {
                         switch(letter[2]){
                                   case '.':           //--.
                                        {
                                             switch(letter[3]){
                                             case '.':                //--..
                                                  {
                                                       switch(letter[4]){
                                                       case '.':                //--... = 7
                                                            {
                                                                 decode='7';
                                                            }
                                                            break;

                                                       case '+':      //--.. = Z
                                                            {
                                                                 decode='Z';
                                                            }
                                                            break;
                                                       }
                                                  }
                                                  break;
                                             case '-':           //--.- = Q
                                                  {
                                                       if(letter[4]=='+')
                                                       decode='Q';
                                                  }
                                                  break;
                                             case '+':           //--. = G
                                                  {
                                                       decode='G';
                                                  }
                                                  break;
                                             }
                                        }
                                        break;
                                   case '-':           //---
                                        {
                                             switch(letter[3]){
                                             case '.':           //---.(.) = 8
                                                  {
                                                       if(letter[4]=='+')
                                                       decode='8';
                                                  }
                                                  break;
                                             case '-':           //----
                                                  {
                                                       switch(letter[4]){
                                                       case '.':           //----. = 9
                                                            {
                                                                 decode='9';
                                                            }
                                                            break;
                                                       case '-':           //----- = 0
                                                            {
                                                                 decode='0';
                                                            }
                                                            break;
                                                       }
                                                  }
                                                  break;
                                             case '+':           //--- = O
                                                  {
                                                       decode='O';
                                                  }
                                                  break;
                                             }
                                        }
                                        break;
                                   case '+':      //-- = M
                                        {
                                             decode='M';
                                        }
                                        break;
                                   }
                    }
                    break;
               case '+':      //- = T
                    {
                         decode='T';
                    }
                    break;
               }
          }
          break;
                    // letter 0 ends here
     default:
          decode='?';
          break;

     }

     return decode;
}

