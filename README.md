# myshell

What is a shell?
A shell is a terminal/text based program/application that takes text based user inputs and performs or executes some actions based on the command provided by the user.  Fully featured shells, like BASH, can execute reasonably complex instructions that run macros or executibles to perform various tasks on the user's computer.  For example, the shell can be used to navigate through the files system, list the contents of various folders, open files for editiing (there are even file editors whose user interfaces are implemneted in the terminal window rather than a seperate GUI window), create directories, rename files/folders, move files/folders, deleting files/folders as well as displaying help for the various features/commands.

What is myshell?
myshell, is a terminal program written in c that "suppliments" the normal BASH shell.  Since it is a program that runs in the terminal the user interaction consists entirely of text based commands that the user inputs into the program followed by the associated response from the system.  Generally speaking, the results of the response from the system should have a corresponding response in the terminal window for the user to observe.   However, the myshell application has a smaller set of functions compated to the BASH shell.  The commands that it does support are: 1) mycd - a command used to change the currently active directory 2) myclr - which clears the terminal screen 3) myenviron - which prints out the system environment variables 4) myecho - which displays any comment on the screen which is input by the user 5) myhelp - which displays text explaining the myshell functions 6) mypause - that holds large text strings on the screen so the user can scroll though it 7) myquit - which quits the shell.



non-myshell commands
    
How does myshell interact with BASH commands?
It should be noted that myshell acts as a suppliment to the BASH shell.  This means that myshell features are overlapping with some of the BASH ones.  While myshell is running, the myshell implementation of that feature will be used while the BASH implementation won't.  However, for commands that are not implemented in myshell but are in BASH, those commands will be executed in BASH as a fork process.  Then control will be returned to the myshell process once the fork's execution is complete.



# mycd <directory>
      
Supports the ability for the user to change the current default directory to <directory>. When this command is entered into the shell, adding the argument <directory> [eg "/User/bobby"], will change to that directory.  If the directory does not exist then the user is provided feedback to indicate so.  After carrying out this command, the environment variable keeping track of the present working directory [PWD] will be updated to reflect the new active directory.
Usage: at any point where myshell is awaiting input from the user she can type "mycd" followed by a space  and then a directory path location such as "/bin/hogwarts_farm/" followed by hitting enter.  After running this command the current/present working directory will be changed to that location OR feedback is provided to indicate no such location exists.



# myclr
      
In certain cases it may be desirable for the user to clear the previous command from the screen.  The clear the screen command allows the user to remove all of the text from the terminal window.  When this command is executed, the terminal screen is cleared and the user prompt is displayed (displaying username and current folder location)
Usage:  at any point where myshell is awaiting input from the user she can type "myclr" and the clear function will be carried out



# mydir <directory>
      
Supports the ability for the user to display the contents of a specific folder.  On it's execution, this command lists the contents of directory <directory> where <directory> is the directory location entered as a parameter.  The function will list the files and folders in the directory of question.  If no target <directory> parameter is entered, the command will return the currents of the current directory.
Usage:   example "mydir /bin/" (without quotes).  At any point where myshell is awaiting input form the user she can type "mydir" followed by a space and a directory path location such as "/bin/".
"." will return the contents of the current directory
".." will return the contents of the parent directory



# myenviron
      
Environment strings are a series of values that are stored by the system to describe certain attributes of the sytem.  These attributes are stored this way so that they are easily accessible for various programs when they run.  A few examples of environment strings are:
"HOME=/Users/bobby"              [the path to the users home directory]
"PWD=/Users/bobby/testing"    [the path of the present working directory]
"USER=bobby"                           [the user name of the currently logged in user]
Usage: at any point where myshell is awaiting input from the user she can type "myenviron" followed by hitting enter, no additional argumenst needed.  At this point the shell will display all of the environment variables/stings



# myecho <comment>
      
Invoking the echo command along with an argument <comment> will result in that comment being printed on the display of the terminal window.  At the end of the comment a new line action will be taken so the next command will start on that next line (rather than right after the echo comment).  Whits space characters will reduce multiple spaces and or tabs into a single spaceon the display followed by a new line (multiple spaces/tabs may be reduced to a single space)
Usage: at any point where myshell is awaiting input from the user she can type something like "myecho lemmings are very cute" and the terminal will display "lemmings are very cute" followed by a carriage return.



# myhelp <topic>
      
This command will serve as a similar feature to this manual in that it can be used to display the user manual with an explanation of the functionality of the various features of myshell.   However, it can be invoked from the command line and will display the instructions in the terminal window itself.  In addition using the more filter, the user can add an argument after "myhelp" command in order to bring up a specific topic.  For example typing the command "myhelp myenviron" will bring up the help section for the myenviron command.
Usage: at any point where myshell is awiting input from the user she can type either "myhelp" to observe the full help catalogue or "myhelp" followed by a space then a <topic> per the list below followed by enter.  The appropriate help content will then be displayed on the terminal screen.
Available <topics>:
mycd, myclr, mydir, myenviron, myecho, myhelp, mypause, myquit, non-myshell commands



# mypause
        
During the display of large amounts of text, there will be some circumstances where there is too much text to be displayed in the terminal window at one time.  The pause operation allows the myshell shell to select an amount of the text that can be displayed at once without overlapping to unseen areas of the terminal window.  To view the remainder of the text the user can press the "Enter" button and the screen will continue to display more of the text.
Usage: simply press "Enter" when more of the desired text is to be displayed on the terminal screen



# myquit
        
In order to exit the myshell shell, when the user is presented with any input prompt she can enter "myquit" followed by the hitting enter and the myshell application will quit, the terminal will return to BASH.











