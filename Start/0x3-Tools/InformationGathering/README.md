## Passive Information Gathering
```
Also known as Open Source Intelligence, the goal is to optain information that expands the attack surface either by phishing or password attacks etc...
We never communicate with the target directly, we can rely on third parties for information.
We can only interact as a normal user but never scan or access the vulnerablities of target system or server in this phase.
```

### Website Recon
```
This is fairly simple, just visit the target website and look for:
```
***About Page: This reveals the employees emails which start commonly with their lastname@target.com, but the CEO would use his firstname@target.com, we could use these emails in a social media information gathering campaign which is helpful, also look for social media accounts if available on the target website which would save us some time.***

### whois
```
whois is a TCP service, tool and database which provides information about a domain name such as the nameserver.
```

***This can be used in terminal or on the [whois website](https://www.whois.com/)***
***I'll take megcorpone.com as an example:***
```bash
$~ whois www.megacorpone.com | less
```
***Not all information can be useful, but we can see who registered the domain which is Alan Grofield.
![image](https://user-images.githubusercontent.com/75253629/227758929-a6e5a926-928d-4533-b89e-01a2e062248a.png)

