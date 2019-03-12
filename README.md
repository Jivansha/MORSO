# MORSO
MORSO is a C++ based menu driven Morse Code Translator application for encryption and decryption of Morse Codes to/from normal English sentances containing sets of alphabets and digits. Morse Code was discovered during World War. Since, then it has been a popular coded communication technique.

The application developed here has following features-
  1. A main menu that lets the user select whether to encrypt message, decrypt morse code or quit application.
  2. A secondary screen that appears when user inputs his/her option and enters the message in the assigned form.
  3. Output appears on the same screen below the message.

Program Functions- 

  1. mainmenu()- Used for displaying the main menu or home screen and input the users' choice. This function is the main menu which the       user uses to select one of the available features of the program. Uses another function called 'screen1()'.
  
  2. msgtoMorse()- Function to encrypt message. This uses another function Morselist() that is used to find morse equivalent of single       letter or to create a list of alphabets and digits and their equivalent Morse Codes.
  
  3.Morsetomsg()- Function to decrypt the morse code message. Uses another function called as 'decrypt()' to find letter equivalent of       morse code by using the decision tree algorithm.
  
  
  
  
