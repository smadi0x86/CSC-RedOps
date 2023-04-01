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
- ***[Osint.sh](OSINT.SH)**

# Active Information Gathering
