# Passive Information Gathering
```
Also known as Open Source Intelligence, the goal is to optain information that expands the attack surface either by phishing or password attacks etc...
We never communicate with the target directly, we can rely on third parties for information.
We can only interact as a normal user but never scan or access the vulnerablities of target system or server in this phase.

Note: If any tool mentioned gives you not found run: sudo apt install <toolname> and use the <toolname> --help for extra functionalities of every tool
```

## Website Recon
```
This is fairly simple, just visit the target website and look for:
```
- ***About Page: This reveals the employees emails which start commonly with their lastname@target.com, but the CEO would use his firstname@target.com.***
***We could use these emails in a social media information gathering campaign which is helpful.***

### whois
```
whois is a TCP service, tool and database which provides information about a domain name such as the nameserver.
```

***This can be used in terminal or on the [whois website](https://www.whois.com/)***
***I'll take megcorpone.com as an example:***

```bash
$~ whois www.megacorpone.com
```

***Not all information can be useful, but we can see who registered the domain which is Alan Grofield.***

![image](https://user-images.githubusercontent.com/75253629/227772437-852a38d0-8101-4efa-814b-69f83d576065.png)

```
If we visit the megacorpone.com we can see that Alan Grofield is an IT and security director.
```

<img src=https://user-images.githubusercontent.com/75253629/227772554-d4e2bdab-17ad-4503-8b5e-c81d8d25352d.png>

```
Also we can see the nameservers which are components of DNS, we won't get into them right now but its worth keeping it in our notes.
```

![image](https://user-images.githubusercontent.com/75253629/227772792-fd7b91e1-e904-4492-ad30-2fdf2c140e36.png)

```
Note: you can do a reverse-lookup with whois but instead of writing megacorpone.com you can ping it and get its IP then run whois <IP> in terminal.
Reverse lookups gives more information regarding subdomains of the website and extra information that the normal lookup won't give.
```

<img src=https://user-images.githubusercontent.com/75253629/227772978-fc52de6e-6551-4d3d-ac36-5f8b54e38ab5.png>

### Recon-NG
```
Recon-NG is a Module-based framework for web-based information gathering and it can be used in terminal.
```
- ***To get started let's open open our terminal and run:***
```bash
$~ recon-ng
```
- ***If you don't have it pre-installed you can run:***
```bash
$~ sudo apt-get install recon-ng
```
![image](https://user-images.githubusercontent.com/75253629/229310421-83e4cd59-b6e3-4d77-9621-eea93511ff40.png)

```
Let's start by searching for a module ( It will be a github module as an example):
[recon-ng][default] > marketplace search github
```
![image](https://user-images.githubusercontent.com/75253629/229310486-488e0dfa-713f-44cc-823c-e4b0eb4de816.png)

- ***Here we can take a look at all github modules available.***
- ***The K row is all the modules that require registration to access the API of it and they are marked with a "*"***
- ***You can use the keys to access key-required modules from [here](https://github.com/lanmaster53/recon-ng-marketplace/wiki/API-keys), there are paid and free keys to use.***
```
We can get information about a module using:
[recon-ng][default] > marketplace info <module>
```
![image](https://user-images.githubusercontent.com/75253629/229310793-49d0c9de-e13e-45c0-8c13-3a9e203599be.png)

- ***According to info this module doesn't require API key and its used to harvest hosts from google.***

```
Let's install this module by:
[recon-ng][default] > marketplace install recon/domains-hosts/google_site_web

Then we use it by:
[recon-ng][default] > modules load recon/domains-hosts/google_site_web

Let's then use info to see how to use this module:
```
![image](https://user-images.githubusercontent.com/75253629/229311062-0014fd49-d97f-4617-aa1c-14f48638fb0a.png)

- ***Seems they are asking for a source which is megacorpone.com for this example:***
```
[recon-ng][default][google_site_web] > options set SOURCE megacorpone.com
[recon-ng][default][google_site_web] > run
```
![image](https://user-images.githubusercontent.com/75253629/229311252-b3cfbc67-4f6b-47b7-a7be-8ee2259fe391.png)

- ***When the module is finished we can run:***
```
[recon-ng][default][google_site_web] > back
[recon-ng][default] > show hosts
```
![image](https://user-images.githubusercontent.com/75253629/229311356-d5101785-1bc0-4091-a120-6ca1bacaf291.png)

```
But now we have a problem, we don't have that much information of the target, thats why we use different module to resolve the IP of this host such as:
> recon/hosts-hosts/resolve

Let's download and use it ( the same steps as the first module we installed):
```
![image](https://user-images.githubusercontent.com/75253629/229311552-af52fb0a-05de-4d95-ad66-60d13f7d07aa.png)

```
Now we just run the module because we already got the source host so this module already knows what we are looking for.
```
![image](https://user-images.githubusercontent.com/75253629/229311660-0c88dd64-b966-4aa3-8292-e6fdd3d902ef.png)


```
There are many OSINT tools available, I won't be covering all of them but here's some to keep an eye on:
```
- ***[Osintframework](https://osintframework.com/)***
- ***[NetCraft](https://www.netcraft.com/)***
- ***[Maltego](https://www.maltego.com/)***
- ***[Shodan](https://www.shodan.io/)***
- ***[Osint.sh](https://osint.sh/)***

# Active Information Gathering

```
This involves direct interaction with target to collect information.
This will include port scanning, DNS, SMB, SMTP enumerations.
```
## DNS Enumeration
```
DNS is the naming system of the internet, it translates user-friendly website names to IP addresses.
```
![image](https://user-images.githubusercontent.com/75253629/229312038-ac65789c-f643-455a-86f6-d370028c89ed.png)

### Interacting with a DNS server

- ***We can use the "host" command to view the DNS server of a host:***

```
$~ host <website.com>
```
![image](https://user-images.githubusercontent.com/75253629/229312456-74f02f7d-5e25-4a46-8b2f-ee80adb0361c.png)

- ***Or to view additional information of the DNS server such as: mx which is servers that handles emails for the domain or txt records, using the -t argument:***
```
$~ host -t mx <website.com>
$~ host -t txt <website.com>
```
![image](https://user-images.githubusercontent.com/75253629/229312541-d8ca531f-c7e2-4dc4-9923-f00a2c7267a3.png)

### Automating DNS Lookups

```
We will attempy to guess DNS host names by using a wordlist that uses common hostnames with a bash one liner on terminal:
```
```bash
$~ for ip in $(cat wordlist.txt); do host $ip.megacorpone.com; done | grep -v "not found"
```
- ***You can create your own custom wordlist that has several common hostnames such as: mail, owa, ftp, router etc... every word is seperated by a new line in a file.***
- ***"grep -v "not found" is to filter out invalid results (doesn't show any results that has not found in it).***
- ***Or you can download pre-made wordlists by:***
```bash
$~ sudo apt install seclists
```

### DNS Zone Transfers
```
It is a database replication between related DNS servers in which a zone file is copied from a master DNS server to a slave server.
The zone file contains a list of all the DNS names configured for that zone.
Zone transfers must only be allowed for authorized slave DNS servers, but misconfiguration can lead to unauthorized transfer.
```
- ***We can run a zone transfer with the "host -l" command followed by the "domain" and "DNS nameserver".***
- ***Firstly lets get the nameserver:***
```bash
$~ host -t ns htu.edu.jo 
```
- ***Then we run the zone transfer command:***
```bash
$~ host -l htu.edu.jo ns1.nitc.gov.jo
```
![image](https://user-images.githubusercontent.com/75253629/229322720-442d37a6-b4b2-4b7e-924f-732328d494d4.png)

- ***The first nameserver doesn't allow zone transfers which is unlucky, maybe try the second nameserver (ns2) of megacorone.com and check what happens.***

### DNS Tools
```
There are several tools to automate the enumeration of DNS some are:
```
```
DNSRecon: It is an advanced DNS enumeration script.
```
- ***Lets try automating the zone transfer with DNSRecon:***
```bash
$~ dnsrecon -d htu.edu.jo -t axfr
```
- ***-d option: Specify a domain name.***
- ***-t option: Specify the type of enumeration which is zone transfer (axfr).***

![image](https://user-images.githubusercontent.com/75253629/229322912-a5ba8066-215a-422c-8dc2-bb8f39c47b3c.png)

```
Dig: It collects data about Domain Name Servers, it's helpful to display DNS information.
```
- ***It is pretty straight forward just open a terminal and run:***
```bash
$~ dig <domain.com>
```
![image](https://user-images.githubusercontent.com/75253629/229323068-96d6a6ed-8a3e-442a-b5eb-7291b756752b.png)

## Port Scanning
```
Its the process of inspecting TCP & UDP ports on a machine to detect what services they are running and what potential attacks may exist.
We can run a full port scan on a target in the background while we do other information gathering.
When port scanning is finished we can then narrow our scans to aim for more and more information.
```

```
We will start with understanding how sockets work and building them using C-language, I hope you are all familiar with it.
```
- ***Sockets are usually made for server and user (client) interactions.***
- ***We will code our own server and client.***

```
Server side:

For server side we use these functions:

socket(): To create a socket object, we will create a TCP socket which uses ipv4 for communication.
bind(): To bind the server on a port and a host, which the host will be our machine ip and any port you like.
listen(): To listen for incoming connections.
accept(): To accept any connection that is coming.
send(): After accepting connection we send data.
recv(): After accepting connection we receive data.

These are all included within the sys/socket.h header which we will import.
The functions until now are self-explanatory, but we will further explain them.
```

```
Client Side:

We will be using winsock2 library on windows for programming our client.

For client side we use these functions:

socket(): To create a socket object.
connect(): Connect to the server side.
send(): Send to the server side.
recv(): Receive from the server side.

Because I will be using windows as my client, I should use winsock2.
But if you want to use a linux client such as: kali linux, you should use the sys/socket.h header we mentioned above.

No difference between winsocks2 and sys/socket.h, its just a simple syntax difference.
No need to understand these stuff for now, just understand the workflow and you are good to go.
```
```c
/*
This code is meant to be executed in a linux machine.
*/

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>

int main()
{
    // Integer variable for creating the socket
    int server_socket;

    /*
    Creating the TCP socket: socket(domain, type, protocol)

    AF_INET: Means that we have to use the ipv4 address, if we use AF_INET6 it would be ipv6, etc.
    SOCK_STREAM: Means that we are going to use TCP protocol, if we use SOCK_DGRAM it would be UDP, etc.
    0: Means that we are going to use the default protocol which is TCP, if we use 1 it would be UDP, etc.

    Read more: https://www.geeksforgeeks.org/socket-programming-cc/
    */
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Structure required for the connection to be accepted ( bind() )
    // A structure is a collection of variables of different types
    struct sockaddr_in server_address;

    /*
        IMPORTANT: These structure .sin_family, .sin_port, .sin_addr.s_addr are used to store the address of the client which came from the header <netinet/in.h>
    */

    // This is the structure that will be used to store the client address
    server_address.sin_family = AF_INET;

    // This is the port that will be used for the connection
    // htons() function is used to convert the port number to the correct format, 9002 is the port number, it can be any number
    server_address.sin_port = htons(1337);

    // This is the IP address that will be used for the connection
    // inet_addr() function is used to convert the IP address to the correct format
    server_address.sin_addr.s_addr = inet_addr("YOUR IP ADDRESS");

    // --------------------------------------------------------------------------------------------------------------

    /*
    Binding the socket to our specified IP and port: bind(socket, address, address_len)

    1. Pass the socket that we created before
    2. Pass a pointer to the structure that we created before, (struct server_address *) "*" is used to convert the structure to a pointer
    3. Pass the address of the structure that we created before ( &server_address ) "&" is used to get the address of the variable
    4. Pass the size of the structure, sizeof(server_address) is used to get the size of the variable

    Manual for bind(): https://man7.org/linux/man-pages/man2/bind.2.html
    */
    bind(server_socket, (struct server_address *)&server_address, sizeof(server_address));

    // --------------------------------------------------------------------------------------------------------------

    /*
    Listening for connections: listen(socket, backlog)

    1. Pass the socket that we created before
    2. Pass the backlog, 5 is used because it is the maximum number of connections that can be queued

    Manual for listen(): https://man7.org/linux/man-pages/man2/listen.2.html
    */
    listen(server_socket, 5);

    // --------------------------------------------------------------------------------------------------------------

    // Used for accepting the connection
    int client_socket;

    /*
     Accepting the connection: accept(socket, address, address_len)

     It takes 3 arguments, the socket, the address of the client and the size of the address
     NULL is used because we don't need the address of the client and the size of the address

     Manual for accept(): https://man7.org/linux/man-pages/man2/accept.2.html
    */
    client_socket = accept(server_socket, NULL, NULL);
    printf("Client connected! \n");

    // --------------------------------------------------------------------------------------------------------------

    // This server_message variable will be sent to the client when the connection is accepted
    char server_message[256] = "You have reached the server!";
    // This client_message variable will be sent to the server when the connection is accepted
    char client_message[256] = "You have reached the client!";

    /*
    Sending the message to the client: send(socket, message, message_len, flags)

    1. Pass the socket that we created before
    2. Pass the message that we want to send
    3. Pass the size of the message, sizeof(server_message) is used to get the size of the variable
    4. Pass the flags, 0 is used because we don't need any flags

    Manual for send(): https://man7.org/linux/man-pages/man2/send.2.html
    */
    send(client_socket, server_message, sizeof(server_message), 0);
    recv(client_socket, client_message, sizeof(client_message), 0);
    printf("Client sent: %s \n", client_message);

    // --------------------------------------------------------------------------------------------------------------

    // Closing the socket
    close(server_socket);

    return 0;
}
```
![image](https://user-images.githubusercontent.com/75253629/231585692-1a702f86-8e8d-48aa-b2ad-084ff79f0ca3.png)
