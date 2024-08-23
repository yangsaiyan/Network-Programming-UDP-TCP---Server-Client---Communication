Network Programming
Language: C

Task 1 UDP client-server programs
1.	Modify the UDP client program as follows:
2.	
a.	Create a menu with the following options:
    i.	Convert characters to uppercase letters.
  	
    ii.	Convert characters to lowercase letters.
  	
    iii.	Reverse the order of characters.
  	
    iv.	Print the sockaddr_in structure.
  	
  b.	Get user input (option) and send it to the server.
  
  c.	Get user input (message) and send it to the server.
  
  d.	Print the server’s reply on the terminal.
  

4.	Modify the UDP server program as follows:
	
  a.	Receive the client’s input (option and message).

  b.	Modify the message based on the option selected by the user.
  
  c.	Return the modified message in the following way
    i.	Convert the characters to uppercase letters, e.g., “Hello” becomes “HELLO”.
    ii.	Convert the characters to lowercase letters, e.g., “Hello” becomes “hello”.
    iii.	Reverse the order of the message, e.g., “Hello” becomes “olleH”.

Task 2 TCP client-server programs

1.	Modify the TCP client program as follows:
2.	
  a.	Get user’s input (message) and send it to the server.

  b.	Print the server’s reply on the terminal.
  
4.	Modify the TCP server program as follows:
   
  a.	Print the received message on the terminal.
  
  b.	Reply to the user with the received message (no change is required).
