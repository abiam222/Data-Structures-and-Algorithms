 Javascript Strings

length
indexOf()
includes()
search()  //method searches a string for a value and returns the position of the match
slice(<start>,<end>) 
substring(<start>,<end>) 7,13 //different from slice because can't accept negative values
substr(<start>,<end>)// of where I want to stop>) 7,6 or just <start> wait till ends of string
replace(<from string>, <to this string>)
toUpperCase()
toLowerCase()
concat()
charAt(<index>)
codeCharAt()
toString()

data types
primitive types

object, map, dictionary, set, hashmap (same as hashtable but allows null as key and value
	and does not guarantee that the order of the map will remain constant over time), hashtable

obj - collection of key value pairs but you can add functions, implementation to conversations
values 

map - collection of key value pairs. Each possible key appears at least once
var myMap = new Map()
myMap.set('you', "other");
myMap.get('you')
get()
has()
set()
keys()
delete()

arr.prototype.map - creates a new array with the results of calling a provided function
on every element in the calling array 
var array1 = [1, 4, 9, 16];
const map1 = array1.map(x => x * 2);

map, dictionary, and associative array are the same

const set1 = new Set([1, 2, 3, 4, 5]); - collection of distinct objects
console.log(set1.has(1));//true
console.log(set1.has(6));//false
add()
delete()
keys()
has()

**Read my Javascript interview notes
call,apply, and bind - binds to the object "this"

palindrome - reads same forward and backwords
anagram - cinema turned to iceman. Formed by rearagging words


var animals = ['ant', 'bison', 'camel', 'duck', 'elephant'];

console.log(animals.slice(2));
// expected output: Array ["camel", "duck", "elephant"]

console.log(animals.slice(2, 4));
// expected output: Array ["camel", "duck"]

console.log(animals.slice(1, 5));
// expected output: Array ["bison", "camel", "duck", "elephant"]Ï



const array1 = [1, 2, 3, 4];
const reducer = (accumulator, currentValue) => accumulator + currentValue;

// 1 + 2 + 3 + 4
console.log(array1.reduce(reducer));
// expected output: 10

// 5 + 1 + 2 + 3 + 4
console.log(array1.reduce(reducer, 5));
// expected output: 15



//sum all valuesin an array
var total = [ 0, 1, 2, 3 ].reduce(
  ( accumulator, currentValue ) => accumulator + currentValue,
  0
);


//sum valueobject array
var initialValue = 0;
var sum = [{x: 1}, {x:2}, {x:3}].reduce(
    (accumulator, currentValue) => accumulator + currentValue.x
    ,initialValue
);

console.log(sum) // logs 6





//=====================================================================
C++ String and Char

//Array size is  size_of(arr)/size_of(arr[0])
size() //Others I can to vector.size() map.size(), 
length() //USE THIS THOUGh
[] operator

string you = "Hello"

you[0] = "H"



//=====================================================================
Promises and Async
Angular and Node/Express


//Node #1 Async Await
 try {
    const groceriesPromise = fetch(`http://groceries:3003/${apiVersion}/groceries`);
    const ratingsPromise = fetch(`http://groceries:3003/${apiVersion}/groceries/ratings`);
    const promises = [groceriesPromise, ratingsPromise];
    const [groceriesResponse, ratingsResponse] = await Promise.all(promises);
    const groceriesJSON = await groceriesResponse.json();
    const ratingsJSON = await ratingsResponse.json();
  
    res.json({ groceries: groceriesJSON, ratings: ratingsJSON});
  } catch(e) {
  	console.log( e )   
  }


 //Node #1 Promises
 return new Promise (function(resolve, reject){
 	//do something or whatever you want
 	request.get(url, (err, resp, body) => {
 		if (err) {
 			reject(err);
 		} 
 		resolve(JSON.parse(body))
 	})
 })

 //to call this promise do the following
 initializePromise()
 	.then( (result) => {
 		//do something with data
 	})
 	//function error or .catch?! or both


//Ang 1
 http.get(url)
 	.then(function(resp){
 		return resp.data //get Promise and return it
 	})
 	.catch(function(err){
 		console.log(err)
 	})

//call above
getStatus()
.then(function(data)){
	//data and err here
	//received Promise value
}) //does function err work?

//chaining Promisses
readFile()
.then(dosomething)
.then(domsomethingelse)
.then(dosomethingelse)


//Ang 2 > 
//Observable
return http.get(url)
	.map(
		(res:Response) => //do whatever res.json()
	)
	.catch(
		(err:any) => Observable.throw(err.json().error)
	)


//turn observable to promise
return http.get(url)
	.map(
		res => response.json().toPromise()
	)...


//subscribe to it, if observable
service.getFunction()
	.subscribe(
		res => res,
		err => err,
		() => optional? else 
	)


//if promise

service.getFunction()
	.then( 
		data => //do whatever data
		err => //console log err
	)
	.then(something else)
	.then(something else)

//=====================================================================
SQL / Mongo (JOINS, Indexes, Differences)

https://www.w3schools.com/sql/sql_count_avg_sum.asp
https://www.google.com/search?q=cap+theorem&oq=CAP+theor&aqs=chrome.0.0j69i57j69i60j0l3.1448j0j7&sourceid=chrome&ie=UTF-8

INNER JOIN - returns records that have matching values in both tables
LEFT JOIN - returns all records form the left table, and the matched records from the right table
RIGHT JOIN - returns all records form the right table, and the matched records from the left table
FULL JOIN (OUTTER) - Returns all records when there is a match in either left or right table 

The Union Operator is used to combine the result-set of two or more SELECT statements
SELECT <column_name> from table
UNION (ADD "UNION ALL" to allow duplicates)
SELECT <column_name> from table2


Index: Are used to retrieve data from the DB very fast.  (slow on update though )

CREATE INDEX <index_name>           (UNIQUE IF YOU WANT NO DUPLICATES)
ON <table_name> (col1, col2,...)


SELECT *
FROM Table WITH(INDEX(Index_Name))


Normalization:

Database normalization is the process of structuring a 
relational database in accordance with a series of so-called normal 
forms in order to reduce data redundancy and improve data integrity. 
It was first proposed by Edgar F. Codd as part of his relational model.

1NF: Eliminate repeating groups in individual tables
Create Separate table for each set of related data
Identify each set of related data with a primary key.
Each recored need to be unique 


2NF: Put simply, a relation is in 2NF if it is in 1NF and every non-prime
attribute of the relation is dependent on the whole of every candidate key.
Single column primary key (foreign key and primary keys )


3NF: is a normal form that is used in normalizing a database design to reduce the duplication 
of data and ensure referential integrity by ensuring that:-


ACID
Atomicity - transactions are often composed of multiple statements
Consistency - ensures that a transaction can only bring the DB from one valid state to another 
Isolation - transactions are often executed concurrently. Isolation ensures that concurrent execution
of transaction leaves the DB in the same state that would have been obtrained if the transactions
were executed sequentially. 
Durability - guarentees that once a transaction has been committed, it will remain even in the 
case of a system failure 




//=====================================================================
C++ classes and OOP

**OOP notest I have 

The only difference between a 'class' and a struct in C++ is that structs have default public members and 
bases and classes have default private members and bases. Both classes and structs can have a mixture of 
public and private members, can use inheritance, and can have member functions


https://stackify.com/solid-design-principles/
//First Head Java if I get the job and other java book


Java
static - global, not pertained to 1 instance. 
Final - pretty much a js const. Can only be initialized once. 

interface.
An interface in java is a blueprint of a class. 
It has static constants and abstract methods. 
The interface in Java is a mechanism to achieve abstraction. 
There can be only abstract methods in the Java interface, not method body. 
It is used to achieve abstraction and multiple inheritance in Java.

OOP Concepts

SOLID
Single resposibility - module,classes, etc should have responsibility ofver a single
part of the functionality

open/close principle software entities(classes,modules,functions,etc)should be open for 
extension but closed for modification. Can allow its behaviour to be extended without
modifying its source code.

liskov substitution principle - if S is a subtype of T, then objects of type T may be
replaced with objects of type S without altering any of the desirable properties of the
program. 

interface segregation - no client should be forced to depend on methods it does not use.
ISP splits interfaces that are very large into smaller and more specific ones so that clients
will noly have to know about the methods that are of interest to them. Keep a system decoupled

dependency inversion - decoupling software modules. (by adding interfaces or etc)


SOA

 is the principle that classes should achieve polymorphic behavior and code reuse by their 
 composition (by containing instances of other classes that implement the desired functionality) 
 rather than inheritance from a base or parent class4

//=====================================================================
Monitoring (create dashboard, etc etc, learn) AWS (Cloudwatch),
Chrome inspect

https://www.wisdomjobs.com/e-university/aws-cloudwatch-interview-questions.html
https://www.google.com/search?q=iam+interview+questions&oq=iam+inter&aqs=chrome.0.0l2j69i57j0l3.1333j0j7&sourceid=chrome&ie=UTF-8

Cloudwatch logs - let you monitor and troubleshoot your system and applications using
your existing system, application and custom log files. With CW logs, you can monitor
your logs, in near real time . You can set an alarm on the number of errors that occur in your
systm logs or view graphs of latency of web request from you application logs.

What statistics can I view and graph in cloudwatch? You can view sum, min, max, average 


------
Groups vs Users vs Roles vs Policies vs Identity Providers 

Groups - is a set of users that define a particular policy/ies (e.g. EC2 read, write access)

Users - IAM AWS Users. There is a root user but you most likely log in as an ec2 user

Roles - secure way to grant permissions to entities that you trust. E.g. If you want your
EC2 to talk to your S3, instead of having your key and pass available to access both
you can create a role so they can talk to each other. E.g. SAML 

policy - Policies and Permissions. You manage access in AWS by creating policies and attaching 
them to IAM identities or AWS resources. A policy is an object in AWS that, when associated with 
an entity or resource, defines their permissions. AWS evaluates these policies when a principal, such as a user, makes a request.
e.g.
{
    "Version": "2012-10-17",
    "Statement": [
        {
            "Effect": "Allow",
            "Principal": "*",
            "Action": "s3:GetObject",
            "Resource": "arn:aws:s3:::jobtraxx/*"
        }
    ]
}


identity providers - With an identity provider (IdP), you can manage your user identities outside of AWS and give these external user 
identities permissions to use AWS resources in your account. This is useful if your organization already has its own identity system, 
such as a corporate user directory. It is also useful if you are creating a mobile app or web application that requires access to AWS resources.
When you use an IdP, you don't have to create custom sign-in code or manage your own user identities; the IdP provides that for you. Your external 
users sign in through a well-known identity provider, such as Login with Amazon, Facebook, Google, and many others. You can give those external
identities permissions to use AWS resources in your account. Identity providers help keep your AWS account secure because you don't have to distribute 
or embed long-term security credentials, such as IAM access keys, in your application


image vs instance

AMI (amazon machine image) - Is a special type of virtual applicance that is used
to create a virtual machine (VM) within the EC2. It serves at the basic unit of deployment
for services delivered using EC2

snapshot vs AMI - The major difference is between the type of service referred to.
A snapshot is of an EBS volume where you are able to save staete and reboot with the same
data at a certain point in time. An AMI is similar, but its for the EC2 instances themselves.
----

Cloud Watch

Track metrics, collect and monitor log files, set alarms. and create dashboards.

Basic Monitoring - It provides monitoring of data every 5 minutes which is free of cost
Detailed Monitoring - charges you every minute

CW is to monitor Amazon Services (not user services). 

You can create an alarm
You can create dashboard - is a CW monitoring template just for a certain type of metric 

CloudWatch Monitoring:
Basic Monitoring for Amazon EC2 instances:  Ten pre-selected metrics at five-minute frequency, free of charge
Detailed Monitoring for Amazon EC2 instances: Seven pre-selected metrics at one-minute frequency, for an additional charge
Amazon EBS volumes: Ten pre-selected metrics at five-minute frequency, free of charge
Elastic Load Balancers: Ten pre-selected metrics at one-minute frequency, free of charge
Auto Scaling groups: Seven pre-selected metrics at one-minute frequency, optional and charged at standard pricing
Amazon RDS DB instances: Thirteen pre-selected metrics at one-minute frequency, free of charge.
Metrics
Namespaces:  It is a grouping to know what this metric belongs to. For example: AWS/EC2, AWS/AutoScaling/ AWS/ELB
Dimensions:  Dimension is a name/value pair that you uniquely identify a metric. For example: AutoScalingGroupName, ImageId, InstanceID, InstanceType, Volume ID.
Timestamps: To know what timestamp it had captured.
Units: Unit represents the statistic’s unit of measure. For example: EC2 NetworkIn metric in bytes.

What statistic can I view and graph in CW?
You can retrive, graph, and set alarms on the following statistical metrics:average,sum,min,max,and sample count 

What log monitoring does CW provide?
CW logs lets you monitor and troubleshoot your systems and apps using your existing system, application and custom log files.
With CW logs, you can monitor your logs, in near real time, for specific phrases, values and patterns
Logs is capable of monitoring and storing your logs to help you better understand and operate your systems and apps.
You can configure the wc2config service to send a variety of data and log files to CW including:
custom text logs, even logs, evnt racing logs, and performance counter data. 

What is the syntax of metric filter patterns?
a metric filter pattern can contain serach terms or a specification of your commong lor or JSON event format.
CW logs can also be used to extract values form a log even in common log or JSON format.

How Do I retieve my log data?
You can retrieve any of your log data using the CW logs console or through the CW logs CLI. 
Log events are retrieved based on the Log Group, Log Stream and time with which they are associated.

What type of CW alarms can be created?
You can create an alarm to monitor any CW metric in your account. You can also create an alarm on custom metrics that are specific
to your custom application or infrastructure.

What actions can I take form a CW alarm?
WHen you create an alarm, you can configure it to perform one or more automate d actoins when th metric you chose to montor exceeds a threshold you define.
e.g. send an email, publihsh to SQS, stop/terminate an EC2 instance, or execute an auto-scaling policy

What threshold can I set to trigger a cloudwatch alarm?
WHen you create an alarm, you first choose the cloudwatch metric you wan t it to monitor. Nexst, you choose the 
evaluation period and a statistical vlaue to measure. TO set a threashold, set a target value and choose whether the alarm
will trigger when the value is greater, equal, or less than that value. 

//=====================================================================
Data Structure and Algorithms (Node, trees)

selection sort - iterate through array. Make first index smallest and during your iteration if 
there is smaller then make that index smallest. After iteration swap where your currently in with
index smallest

insertion sort - while in array choose current element if left to you is bigger while loop back to where 
you arent bigger not smaller

bubble sort - swap 01 if 0 is bigger then 12 if 1 is bigger. You will continue to 'do' this 
until all sort. The first iteration the biggest number will end at the end. The second iteration
the second largest will be found. etc, etc 

merge sort - decompose array into two. For each two sort from left to right. Then bring 
together n/2 arrays and then sort that. Do this until there is one array left which will
be sorted. 


//=====================================================================
HTTP


HTTP Status Code - 
  1xx Information Response. Received and Understood
  2xx Success. 200 Ok, 201 created ... Action requested by client was received, understood, and accepted, 204 No Content 
  3xx Redirection. 301 Moved Permenently. 302 Found. Take additional action to complete request, 304 Not Modified 
  4xx Client Errors. 400 Bad request(server cant process request), 401 Unathorized, 403 Forbidden, 404 Not found, 409 Conflict
  5xx Server Error. 500 Internal Server Error. 502 bad gateway

VERBS - GET(200 ok), POST (201created), PUT (update/replace), DELETE(delete), PATCH(update/modify) 

What is CORS - Cross Origin Resource Sharing. A mechanism that allows many resources (e.g
font, Javascript, etc) on a web page to be requested from another domain outside the domain
which the resource originated.

MIME type - acronym for Multi-purpose internet mail extensions. It is used as a standard way
of classifying file types over the internet. 
A MIME type actually has two parts: a type and a subtype that are separated by a slash.
"application/json"

Advantages of HTTP/2 as compared with HTTP1.1
HTTP/2 provides decreased latency to improve page load speed by supporting
	* Data compression of HTTP HEADERS
	* Server push technologies
	* Loading of page elements in parallel over a single TCP connection
	* Prioritization of requests


stateless vs stateful protocols - 
stateless communications protocol treats each request as an independent transaction. It therefore
does not require the server to retain any session, identity, or status information spanning multiple
requests from the same source. 
In contrast, a stateful communicatoins protocol is one in which the responder maintains "state'
information (session data, identity, status,) across multiple request from the same source. 

HATEOAS- hypermedia as the engine of application state is a component of the REST application
architecture that distinguishes if rom other network application architectures. With HATEOS,
a client interacts with a network application whose application servers provide information
dynamically through hypermedia 

HTTP Headers - are the name or value pairs that are displayed in the request and response messages
ofmessage headers for Hypertext Transfer Protocol (HTTP). HTTP headers are the code that transfers data
between a Web server and a browser. HTTP headers are mainly intended for the communication between
the server and client inboth directions.


//=====================================================================
Linux and , SRE 

https://syedali.net/engineer-interview-questions/

grep - command for searching plain-text data sets for lines that match a regular expression

Process vs Thread - A thread is a lightweight process. Each process has a separate stack, text, data and heap. 
Threads have their own stack, but share text, data and heap with the process. Text is the actual 
program itself, data is the input to the program and heap is the memory which stores files, locks, sockets
Both processes and threads are independent sequences of execution. The typical difference is that threads (of the same process) 
run in a shared memory space, while processes run in separate memory spaces.
Threads are used for small tasks, whereas processes are used for more 'heavyweight' tasks – basically the execution of applications.
Another difference between a thread and a process is that threads within the same process share the same address space, whereas different processes do not.


Zombie Process - has completed execution, however its entry its still in the process table
to allow the parent to read the childs exit status. Parent process normally issue the wait 
system to call to read the childs exit status whereupon the zombie is removed.

The process that invoked fork is the parent process and the newly created process is the child process. 
Every process (except process 0) has one parent process, but can have many child processes. The operating system kernel 
identifies each process by its process identifier. 

https://stackoverflow.com/questions/16354460/forking-vs-threading

latency - is a time interval between the stimulation and response. A time delay between the cause and
the effect of some physical change in the system being observed. 

bandwidth - maximum rate of data tranfer across a given path. 

Inter-process communication IPC - mechanism an OS provides to allow the processes to manage
shared data. Typically apps can use IPC, categorized as clients and servers, where the client
requests data and the server responds to client requests. Methods for doing IPC are divided inter-communication
categories which vary based on software requirements, such as performance and modularity requirements,
and system circumstances such as network bandwidth and latency 

Describe ways of process inter-communication 
 * Client and Server for distributed computer. Client sending request and server sending response 
 * POSIX mmap, message queues, semaphores, and Shared memory
 * Anonymous pipes and named pipes
 * Unix domain sockets
 * RPC

daemon - is a computer program that runs as a background process

How to daemonize a process - 
 * fork() used to create a separate process
 * setsid() detach process from the parent 
 * ps see current running processes 


TCP - Transmission Control Protocol. A set of rules that governs the delivery of data over the
internet or other network that uses the Internet protocol, and sets up a connection betwen the
sending and receiving computers

TCP Connection states - 
	* LISTEN - server is listening on a port, such as HTTP
	* SYNC-SENT - Sent a SYN request waiting for a response
	* SYN-RECEIVED - SErver waiting for an ACK, occurs after sending an ACK from the server
	* ESTABLISHED - 3 way TCP handshak has completed

TCP packet field (HEADERS) - part of the packaging message data for transfer over network connection
	SOURCE PORT 	DESTINATION PORT
			SEQUENCE number
			ACKNOWLEDGMENT number
	DATA OFFSET RESERVED FLAGS	WINDOW
	CHECKSUM		URGENT POINTER
	 		OPTIONS (+ padding)
	 		DATA (variable)


DNS - The DNS it the phonebook of the Internet. Humans access information online through
domain names, like nytimes or espn.com. Web browsers interact through the internet protocol IP
addresses. DNS translates domain names to IP addresses so browswers can load internet resources 

Telnet - is a network protocol that allows a user on one computer to log onto another computer
that is part of the same network

UDP (protocol) - In computer networking, the User Datagram protocol is one of the core members of the internet
protocol suite. Computer applications can send messages, in this case referred to as datagrams, to other
host on an IP network. Prior communications are not required in order to set up communication channels
or data paths

TCP vs UDP
 - Reliable / Unreliable
 - Ordered / Unordered
 - Heavyweight / lightweight
 - Streaming
 - Header size
 - Host to Host / Process To Process


Default Ports
FTP (20 and 21), SSH (22), TELNET (23), SMTP (25), HTTP over SSL/TLS aka HTTPS (443), and HTTP (80)
Database 3306, TCP/DNS/UDP 53


--------

NAT vs SNAT 

NAT Gateway - You can use a network address translation (NAT) gateway to enable instances in a private
subnet to connect to the internet or other AWS services, but prevent the internet from initiating
a connnection with those instances. 

SNAT - Source Network Address Translation allows traffic from a private network to go out to the internet
The gateway has one arm on the public network and as part of SNAT, it replaces the source IP of the originating
packet with its own public side IP 


What are the different kind of NAT available?
There is SNAT and DNAT. SNAT occurs when the source IP address if RFC 1918 and is changed to be non-RFC 1918.


Network Address Translation (NAT) occurs when one of the IP addresses in an IP packet header is changed. 
There is SNAT and DNAT. SNAT stands for source network address translation. DNAT stands for destination network 
address translation. SNAT occurs when the source IP address if RFC 1918 and is changed to be non-RFC 1918. For instance 
if you are at home using your cable model and want to connect to and external site such as http://www.cnn.com, then your 
router will change the source address of the TCP packet to be it’s external public IP. This is called SNAT. DNAT is when the 
destination IP address is changed. For instance when your packet reaches the http://www.cnn.com router, and the web server behind 
the router is using RFC 1918 space, then the router might change the destination to be the RFC 1918 IP address of the web server. This is called DNAT.

-------

Subnet (subnetwork) - is a logical subdivision of an IP network. The practice of dividing a network into two
or more networks is called subnetting. 
Computers that belong to a subnet are addressed with an identical most-significat bit-group in their IP addresses.


 Unix Signals - signals are an inter process communication method. The default signal in Linux
 is SIG-TERM. SIG-KILL cannot be ignored and causes an application to be forcefully killed. 
 Use the 'kill' command to send signals to a process. Another popular signal is the 'HUP'
 signal which is used to 'reset' or 'hang up' applications. 


 Protocol - is a set of rules that governs the communicaton between computers on a network

 Telnet - a protocol used on the internet or LAN to provide a bidirectional interactive text-oriented
 communcicatoin facitlity using a virtual terminal connection 

 Type of protocols - 
 	Application HTTP, FTP, SMTP, DNS, Telnet
 	Presentation
 	Session
 	Transport TCP, SPX
 	Network IP, IPX
 	Data Link Ethernet 
 	Physical Ethernet


What is an inode? Is a data Structure in a unix-style file system that describes a Filesystem
object such as a file or a directory. Each inode stores the attributes and sick block location of the 
objects data. Filesystem object attributes may include metadata(time of last change, access, modification)
as well as owner and permission data. 
An inode is a data structure in Unix that contains metadata about a file. Some of the items contained in an inode are:
1. mode
2. owner (UID, GID)
3. size
4. atime, ctime, mtime
5. acls
6. blocks list of where the data is 
The filename is present in the parent directorys inode structure

What is the difference between a soft link and a hard link?
1) Hardlink shares the same inode number as the source link. Softlink has a different inode number
e.g.
touch a 
ln a background
ls -i about
24 a 24 b
ln -s a c 
ls -i a c
24 a 25 c 
2) in the data portion of the softelink is the name of the source file
3) hardlinks are only vlaid in the same filesystem, soflinks can be across filesystems 

When would you use a hardlink over a softlink?
A hardlink is useful when the source file is getting moved around, because renaming the source
does not remove the hardlink connection. On the other hand, if you rename the source of a 
softlink, the softlink is broken. This is because hardlinks share the same inode and softlink uses the source
filename in its data portion 


RAID - is a data storage virtualization technology that combines multiple physical disk drive components into one
or more logical units for the purposes of data redundancy, performance improvement, or both. 
Each scheme, or RAID level provides a different balance among the key goals: reliability, availability, performance and capacity


If a filesystem is full, and you see a large file that is taking up a lot of space, how do make space on the filesystem?
1) If no process has the filehandle open, you can delete the file
2) If a process has the filehandle open, it is better if you do not delete the file, instead you can ‘cp /dev/null’ on the file, which will reduce it’s size to 0.
3) A filesystem has a reserve, you can reduce the size of this reserve to create more space using tunefs.

What is the difference between character device and block device?

Block devices are generally buffered and are read/written to in fixed sizes, for instance hard drives, cd-roms. Characters devices read/writes are one character at a time, such as from a keyboard or a tty, and are not buffered.


What is the difference between Continuous Integration and Continuous Delivery and which is more important to you?
Delivery - delivering software. Integration - continous deliver code

What are deployment strategies? A deployment startegy is a way to change or upgrade an application. 
The aim is to make the change wihtou downtime in a way that the user barely notices the improvements
The most common strategy is to use a The most common strategy is to use a blue-green deployment. 
The new version (the blue version) is brought up for testing and evaluation, while the users still use the stable 
version (the green version). When ready, the users are switched to the blue version. If a problem arises, you can 
switch( back to the green version. 
A common alternative strategy is to use A/B versions that are both active at the same time and some users use one version,
and some users use the other version. This can be used for experimenting with user interface changes and other features to get 
user feedback. It can also be used to verify proper operation in a production context where problems impact a limited number of users.

6 stages of Linux Boot Process - 
	BIOS - basic input/output system
	MBR - master boot record exectues GRUB
	GRUB - bootload executes kernel
	KERNEL - executes /sbin/init. Computer program that is the core of the comp OS
	INIT  - executes runlevel programs
	RUNLEVEL - run level programs 



In computer science, garbage collection (GC) is a form of automatic memory management. The garbage collector, or just collector, attempts to reclaim garbage, or memory occupied by objects that are no longer in use by the program.


nslookup google.com
All ip address with that dns name

traceroute google.com
ip address (of routers) and time to get from my router to destination router 
//=============================================
too look into


Network switch
https://en.wikipedia.org/wiki/Network_switch

load balancing

CAP theorem
consistency patterns
availability patterns
databases
caching
asynchronism patterns
etc
https://blog.balthazar-rouberol.com/preparing-the-sre-interview (videos)


The systems part of the interviews is usually targeted towards Linux.
It includes Filesystem knowledge (What are Inodes?), knowledge about the process lifecycle (What is fork+exec? 
	How do signal handlers work? Thread vs Process?), Linux internals (What is load? Describe the boot process? How does dynamic linking work?).


The networking interviews targeted more on the application side of things.
A lot of conversations about TCP (Nagle’s algorithm, TCP CORK, …), DNS (Glue Records, recursive resolvers, …), IP (CIDR), SSL, …

I was once even asked what my favorite protocol was. Luckily I had skimmed my thesis on anonymous filesharing on the flight over, so I had some talking points :)

A lot of the time, you will hear open ended questions (“You type a URL in your browser and hit enter, what happens?”) and can go down the stack to your heart’s desire :)



How to stacktrace

 “What is saved on an inode?”, …)


UNIX questions, like how you can delete a file starting with a dash as well as basic networking - how does a switch work.


sbrk() and mmap() 

TCP Illustrated; Volume 3 by W. Richard Stevens, but you don’t really need to dive into the details of TCP for Transactions, which turned out to have security flaws. Understanding of IP, TCP/IP and UDP/IP is a must.
The Design and Implementation of the 4.4BSD Operating System by Marshall Kirk McKusick
The UNIX Programming Environment by Brian Kernighan and Rob Pike
The Practice of System and Network Administration by Tom Limoncelli, Christina Hogan and Strata R Chalup


// class User {
// 	constructor(username){
// 	this.username = username}

// 	displayUser(){
// 	return this.username;
// 	}
// }

// class Moderator extends User {
// 	constructor(username, role){
// 	super(username)
// 	this.role = role;
// }
// 	displayUser() {
// 	return super.displayUser() + '-' + this.role;	
// }

// }


// var obj = new User("Abiam");
// console.log( obj.displayUser() );

// var obj2 = new Moderator("Nick", "Admin");
// console.log( obj2.displayUser() );



// var words = ['abiam', 'arrangement', 'candy', 'mike', 'candy', 'person', 'person', 'person'] //do this in JS and in C++/C


// let uniqueWords = {}

// words.forEach(value => {
// 	if (!uniqueWords.hasOwnProperty(value)) { //IF MY OBJECT DOESN"T HAVE PROPERTY "WORD" THEN ADD IT
// 		uniqueWords[value] = 1; //ADD COUNT TO 1
// 	} else {
// 		uniqueWords[value]++;//IF OBJECT ALREADY HAS THIS WORD THEN ADD TO COUNTER BY 1
// 	}
// });

// console.log(uniqueWords)


var objectArray = [
	{ id: 0, parentId: null },
	{ id: 4, parentId: 3 },
	{ id: 1, parentId: 0 },
	{ id: 3, parentId: 2 },
	{ id: 2, parentId: 0 },
]

var counter = 0
getObjectCount(2, 0)

function getObjectCount(id, index) {
	if (index === objectArray.length) return

	if (objectArray[index].parentId === id) {
		counter++;
		getObjectCount(objectArray[index].id, 0)
	}
	return getObjectCount(id, index + 1);
}

console.log(counter)
