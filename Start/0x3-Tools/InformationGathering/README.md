# Passive Information Gathering
```
Also known as Open Source Intelligence, the goal is to optain information that expands the attack surface either by phishing or password attacks etc...
We never communicate with the target directly, we can rely on third parties for information.
We can only interact as a normal user but never scan or access the vulnerablities of target system or server in this phase.
```

## Website Recon
```
This is fairly simple, just visit the target website and look for:
```
***About Page: This reveals the employees emails which start commonly with their lastname@target.com, but the CEO would use his firstname@target.com.***
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

***If we visit the [megacorpone.com](https://www.megacorpone.com/contact.html) we can see that Alan Grofield is an IT and security director.***
![image](https://user-images.githubusercontent.com/75253629/227772554-d4e2bdab-17ad-4503-8b5e-c81d8d25352d.png)

***Also we can see the nameservers which are components of DNS, we won't get into them right now but its worth keeping it in our notes.***
![image](https://user-images.githubusercontent.com/75253629/227772792-fd7b91e1-e904-4492-ad30-2fdf2c140e36.png)

```
Note: you can do a reverse-lookup with whois but instead of writing megacorpone.com you can ping it and get its IP then run whois <IP> in terminal.
Reverse lookups gives more information regarding subdomains of the website and extra information that the normal lookup won't give.
```
![image](https://user-images.githubusercontent.com/75253629/227772978-fc52de6e-6551-4d3d-ac36-5f8b54e38ab5.png)
