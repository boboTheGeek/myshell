CSC521 Operating system
Project:  	  myShell Program
Programmer:   Rob Miles
Professor:    Dr. Lee
File Created: October 10, 2018

Info block
======================

Project Description
======================

Algorithm
======================

[Procedure:]

1.    Start
1.1       declare *cmdin, **arglist, shell_location[255]
1.2.      shell_location = currentWorkingDirectory()
1.3.      set environment variable SHELL=shell_location
1.4       set os signals QUIT and INTERRUPT = default behavior

2.    print shell header
2.1       clearScreen( print "\033[H\033[J" )
             [Output:]  screen erased
2.2       print welcomescreen()
             [Output:]  string "Welcome to myShell"
2.3       set userName = environment variables("USER")
2.4       print "Logged in as: " userName
             [Output:]  string e.g. "Logged in as: rm7322"

3.    while(userInput != NULL)
3.1         prompt()
3.1.1             print(current working directory)
             [Output:]  string <cwd>  e.g. "/Users/rm7322/myshell$ "
        
             [Input:]   string <input> e.g. "myecho blueberry pancakes"
3.2         userInput = getUserInput(<input>)
3.2.1           declare *buffer, pos, c  = 0
3.2.2           while ((c = nextcharacter(<input>)) != EOF) {
3.2.2.1             if (c == '\n')
3.2.2.1.1               break while
3.2.2.2 			buffer = append(c);
3.2.3			if (c == EOF && position == 0)
3.2.3.1   			return NULL;
3.2.4			buffer = append('\0')
3.2.5			return buffer
3.2		    userInput = buffer

3.3         arguments = splitAtDelimiters(userInput)
3.3.1	        set i = 0; c = 0; j = 0, arguments[]
3.3.2           while (userInput[j] != " ")
3.3.2.1	            arguments[i] += getcharacter(userInput[c])
3.3.2.2		        c++
3.3.2.3             if(userInput[c] == " " )
3.3.2.3.1			    i++ 
3.3.3			arguments[i++]=NULL
3.3.4			return arguments

3.4.a       if arguments != NULL && 
3.4.b       if arguments[0] != "cd"||"quit"||"echo"||"ls"||"env"||"clear"|| "help"

             [Input assumed:] "myquit"
3.4.1            if (arguments[0] == "myquit")
3.4.1.1              exit(0)
             [output:]  program exits

             [Input assumed:] "mycd /bin"
3.4.2            if (arguments[0] == "mycd")
3.4.2.1              changeDirectory(arguments)
3.4.2.1.1                if sizeof(args)>2 print warn return fail
             [Output:] "Only one directory argument allowed" return 1
                       back to main prompt
3.4.2.1.2                if sizeof(args) == 2
3.4.2.1.2.1                 changeDirectory(arguments[1])
             [Output:] working directory changed to "/bin"
3.4.2.1.3                set environment var PWD=getcwd()
3.4.2.1.4                print CWD, PWD
             [Output:] "current working directory is: /bin; PWD: /bin"j

             [Input assumed:] "mypause"
3.4.3            if(arguments[0] == "mypause")
3.4.3.1 		     pause()
3.4.3.1.1 		         prompt "press enter"
             [Output:] "Press ENTER to coninue"
             [Input:] ENTER
3.4.3.1.2 		         return success                         

             [Input assumed:] "myecho peanuts are yummy"
3.4.4            if(arguments[0] == "myecho")
3.4.4.1             arguments[1] == userInput "peanuts are yummy"
3.4.4.2				execute as shown in 3.4.5.1
             [output:] "peanuts are yummy"
 
3.4.5.           else
3.4.5.1             execute(arguments, shell_location)
3.4.5.1.1               location = shell_location + "/" + argv[0]
3.4.5.1.2      	        set os signals QUIT and INTERRUPT = ignore
3.4.5.1.3               fork() process
3.4.5.1.4               if fork() failed print "fork failed" and exit(1)
             [output:] "fork failed"  process exit = 1
3.4.5.1.4               if process is child process
3.4.5.1.4.1                set os sig QUIT and INTERRUPT = default behavior 
3.4.5.1.4.1                set environment var "PARENT=shell_location"
3.4.5.1.4.2                execute(process=args[0], parameters=args[1 to n])
3.4.5.1.4.3                if still executing perror and exit(1)
             [output:] "cannot execute command"  process exit = 1
3.4.5.1.5               else parent process 
3.4.5.1.5.1                wait(childExit == 0)
3.4.5.1.5.2                set os sig QUIT and INTERRUPT = default behavior 
3.4.5.1.5               return success

4.    return success

5.    end


Analysis
======================

Alrorithm:                                    	Analysis:

1. Start
1.1 declare *cmdin, 
	**arglist, shell_location              	char *cmdin, **arglist, shell_location[255]
1.2 shell_location =                    
	currentWorkingDirectory()              	shell_location = /Users/rm7322/myshell
1.3 set environment variable 
	SHELL=shell_location                   	envt var "SHELL=/Users/rm7322/myshell"
1.4 set os signals QUIT and INTERRUPT 
	= default behavior                     	interrupt/quit signals allowed and default

2.  print shell header                   
2.1 print "\033[H\033[J"                   	output: terminal screen erased
2.2 print welcomeText                      	output: "Welcome to myShell"
                                                   "***if you're interested in help, type 'myhelp'"
2.3       set uName = environment 			uName = rm7322
          variables("USER")
2.4       print userName           			output: "Logged in as: rm7322"
                                                
3.  while((userInput=getInput(stdin) != NULL) 
3.1   getInput(stdin)                              
3.1.1 print ~current working directory$     output: "~/Users/rm7322/myshell$ " 
													process waits


		user enters text=>>>>>>>>>>>		Input:  "mycd /bin"  ENTER

3.2  userInput = getUserInput(<input>)
3.2.1 declare c, buf                       c=buf=NULL 
3.2.2 while ((c = nextcharacter(<input>)). c="m"
              != EOF)
3.2.2.1   if (c == '\n').                  false
3.2.2.1.1    break while
3.2.2.2   buf = append(c)                  buf="m"
3.2.3	if (c == EOF && position == 0)     false
3.2.3.1   return NULL;
                                           c="y";buf="my"
                                           c="c";buf="myc"
                                           c="d";buf="mycd"
                                           c=" "; buf="mycd "  
                                           c="/"; buf="mycd /" 
                                           c="b"; buf="mycd /b"
                                           c="i"; buf="mycd /bi"
                                           c="n"; buf="mycd /bin"
                                           c="\n"; buf="mycd /bin"  break                                   

3.2.4  buf = append('\0')                  buf="mycd /bin\0"
3.2.5  return buf
3.2	 userInput = buf                       userInput="mycd /bin\0"
3.3  arguments= \                          
     splitAtDelimiters(userInput)
3.3.1   set i = j= c = 0; arguments[]      i=c=j=0, arguments[]=""
3.3.2   while (c= userInput[j] != " ")     c='m'    
3.3.2.1   arguments[i] += \                arguments[0]='m'
          getcharacter(userInput[c])
3.3.2.2	  c++                              c='y'
3.3.2.3   if(userInput[c] == " " )         false
3.3.2.3.1   i++ 
                                           j=0,c="y";arguments[0]="my"
                                           j=1,c="c";arguments[0]="myc"
                                           j=2,c="d";arguments[0]="mycd"
                                           j=3,c=" ";arguments[0]="mycd"; i=1 
                                           j=4,c="/";arguments[0]="/"
                                           j=5,c="b";arguments[1]="/b"
                                           j=6,c="i";arguments[1]="/bi"               
                                           j=7,c="n";arguments[1]="/bin"
                                           break   
3.3.3  args[c++] = NULL;                   arguments[2]=NULL
3.3.4  return arguments                    {"mycd","/bin", NULL}

3.1.a   if arguments != NULL &&            agruments={"mycd","/bin", NULL} 
3.1.b   if arguments[0] != "cd"            both statements = TRUE
		|| "quit" || "echo" || "ls" 
		|| "env" || "clear" || "help"

3.1.1   if (arguments[0] == "myquit")      FALSE
3.1.2   if (arguments[0] == "mycd")        TRUE
3.4.2.1  changeDirectory(arguments)
3.4.2.1.1   if sizeof(args)>2              FALSE
             print warn return fail
3.4.2.1.2   if sizeof(args) == 2           TRUE
3.4.2.1.2.1 changeDirectory(arguments[1])  "working directory changed to "/bin"
3.4.2.1.3 set environment variable \       *environment PWD=/bin
	       PWD=getcwd()
3.4.2.1.4   print CWD, PWD                 "current working directory is:    \
                                              /bin; PWD: /bin"

		user enters text=>>>>>>>>>>>		Input:  "mypause"  ENTER

3.2  userInput = getUserInput(<input>)
3.2.1 declare c, buf                       c=buf=NULL 
3.2.2 while ((c = nextcharacter(<input>)). c="m"
              != EOF)
3.2.2.1   if (c == '\n').                  false
3.2.2.1.1    break while
3.2.2.2   buf = append(c)                  buf="m"
3.2.3	if (c == EOF && position == 0)     false
3.2.3.1   return NULL;
                                           c="y";buf="my"
                                           c="p";buf="myp"
                                           c="a";buf="mypa"
                                           c="u"; buf="mypau"  
                                           c="s"; buf="mypaus" 
                                           c="e"; buf="mypause"
                                           c="\n"; buf="mypause"  break                                   

3.2.4  buf = append('\0')                  buf="mypause\0"
3.2.5  return buf
3.2	 userInput = buf                       userInput="mypause\0"
3.3  arguments= \                          
     splitAtDelimiters(userInput)
3.3.1   set i = j= c = 0; arguments[]      i=c=j=0, arguments[]=""
3.3.2   while (c= userInput[j] != " ")     c='m'    
3.3.2.1   arguments[i] += \                arguments[0]='m'
          getcharacter(userInput[c])
3.3.2.2	  c++                              c='y'
3.3.2.3   if(userInput[c] == " " )         false
3.3.2.3.1   i++ 
                                           j=0,c="y";arguments[0]="my"
                                           j=1,c="p";arguments[0]="myp"
                                           j=2,c="a";arguments[0]="mypa"
                                           j=3,c="u";arguments[0]="mypau"
                                           j=4,c="s";arguments[0]="mypaus"
                                           j=5,c="e";arguments[1]="mypause"
                                           break   
3.3.3  args[c++] = NULL;                   arguments[2]=NULL
3.3.4  return arguments                    {"mypause",NULL}

3.1.a   if arguments != NULL &&            agruments={"mypause",NULL} 
3.1.b   if arguments[0] != "cd"            both statements = TRUE
		|| "quit" || "echo" || "ls" 
		|| "env" || "clear" || "help"

3.1.1   if (arguments[0] == "myquit")      FALSE
3.1.2   if (arguments[0] == "mycd")        FALSE
3.1.2   if (arguments[0] == "mypause")     TRUE


		user enters text=>>>>>>>>>>>		Input:  "myecho hello there"  ENTER

3.2  userInput = getUserInput(<input>)
3.2.1 declare c, buf                       c=buf=NULL 
3.2.2 while ((c = nextcharacter(<input>)). c="m"
              != EOF)
3.2.2.1   if (c == '\n').                  false
3.2.2.1.1    break while
3.2.2.2   buf = append(c)                  buf="m"
3.2.3	if (c == EOF && position == 0)     false
3.2.3.1   return NULL;
                                           c="y";buf="my"
                                           c="p";buf="mye"
                                           c="e";buf="myec"
                                           c="c";buf="myech"  
                                           ...
                                           c="e";buf="myecho hello there" 
                                           c="\n";buf="myecho hello there"
                                             break                                   

3.2.4  buf = append('\0')                  buf="myecho hello there\0"
3.2.5  return buf
3.2	 userInput = buf                       userInput="myecho hello there\0"
3.3  arguments= \                          
     splitAtDelimiters(userInput)
3.3.1   set i = j= c = 0; arguments[]      i=c=j=0, arguments[]=""
3.3.2   while (c= userInput[j] != " ")     c='m'    
3.3.2.1   arguments[i] += \                arguments[0]='m'
          getcharacter(userInput[c])
3.3.2.2	  c++                              c='y'
3.3.2.3   if(userInput[c] == " " )         false
3.3.2.3.1   i++ 
                                           j=0,c="y";arguments[0]="my"
                                           j=1,c="p";arguments[0]="mye"
                                           j=2,c="a";arguments[0]="myec"
                                           j=3,c="u";arguments[0]="myech"
                                           j=4,c="s";arguments[0]="myecho"
                                           j=5,c=" ";arguments[1]="myecho"; i++
                                           break   
3.3.3  args[c++] = NULL;                   arguments[4]=NULL
3.3.4  return arguments                    {"mypause",NULL}

3.1.a   if arguments != NULL &&            agruments={"myecho", "hello", "there",NULL} 
3.1.b   if arguments[0] != "cd"            both statements = TRUE
		|| "quit" || "echo" || "ls" 
		|| "env" || "clear" || "help"

3.1.1   if (arguments[0] == "myquit")      FALSE
3.1.2   if (arguments[0] == "mycd")        FALSE
3.1.3   if (arguments[0] == "mypause")     FALSE
3.1.3   if (arguments[0] == "myecho")      TRUE

		user enters text=>>>>>>>>>>>		Input:  "myquit"  ENTER

3.2  userInput = getUserInput(<input>)
3.2.1 declare c, buf                       c=buf=NULL 
3.2.2 while ((c = nextcharacter(<input>)). c="m"
              != EOF)
3.2.2.1   if (c == '\n').                  false
3.2.2.1.1    break while
3.2.2.2   buf = append(c)                  buf="m"
3.2.3	if (c == EOF && position == 0)     false
3.2.3.1   return NULL;
                                           c="y";buf="my"
                                           c="q";buf="myq"
                                           c="u";buf="myqu"
                                           c="i"; buf="myqui"  
                                           c="t"; buf="myquit"                     
                                           c="\n"; buf="myquit"  break                                   

3.2.4  buf = append('\0')                  buf="myquit\0"
3.2.5  return buf
3.2	 userInput = buf                       userInput="myquit\0"

3.3  arguments= \                          
     splitAtDelimiters(userInput)
3.3.1   set i = 0; c = 0; arguments[]      i=c=0, arguments[]=""
3.3.2   while (c= userInput[j] != " ")     c='m'    
3.3.2.1   arguments[i] += \                arguments[0]='m'
          getcharacter(userInput[c])
3.3.2.2	  c++                              c='y'
3.3.2.3   if(userInput[c] == " " )         false
3.3.2.3.1   i++ 
                                           c="y";arguments[0]="my"
                                           c="q";arguments[0]="myq"
                                           c="u";arguments[0]="myqu"
                                           c="i";arguments[0]="myqui"  
                                           c="t";arguments[0]="myquit"
                                           c=" "
                                           break   
3.3.3  args[c++] = NULL;                   arguments[1]=NULL
3.3.4  return arguments                    

3.1.a   if arguments != NULL &&             agruments={"myquit","NULL"} 
3.1.b   if arguments[0] != "cd"             both statements = TRUE
		|| "quit" || "echo" || "ls" 
		|| "env" || "clear" || "help"

3.1.1   if (arguments[0] == "myquit")      arguments[0] == "myquit" is TRUE
3.1.1.1   exit(0)                          ./myshell exits, 0 = success


























