Data Types - a defined by the value the variables takes. The type of operation it can be performed on it 

Promitive Types - the most basic data types available. 
* Boolean
* null
* undefined
* Number
* String
* Symbol (ES6)
* Object 


https://javascript.info/map-set-weakmap-weakset

Talk about other MAP the prototype as well


JS - Map vs Set vs Object vs WeakMap vs WeakSet vs ...


Data structures that are very similary and confuse people

Object
Map / WeakMap
Dictionary
HashMap / hashtable **brief
//Divided into two 
Set / WeakSet
Array 


==
*I'm' not going into much implementation

Object, Map (WeakMap), Dictionary, Hashtable, HashMap - collection of key value pairs

Object - Stores key value pairs. You can add functions, doo complicated implementation
values unlike Map,HashMap,etc, which are stricted to just key, value pair implementation.
Use objects when there is a logic that operates on individual elements.

e.g.
let obj = {}

let obj = {
	name: "Rachael"
	myName: function() {
		console.log(this.name)
	}
}
//you can build a whole game inside an object. 

Map - (map vs hashmap or same??)
Collection of key value pairs. 
Each possible key appears at least once??. 
Also allows keys of any type (unlike object which are technically strings).
You can even use objects as keys. 
We can even pass an array with key-value pairs. 
Much broader range of functions than dictionary.
Use maps over object when keys are unknown until run time, 
??Use maps when all keys are the same type and all values are the same type.
Implementation - Map()

e.g.

let myMap = new Map();

myMap.set('name', "Rachael")
myMap.set(1,'five')


let obj = { name: "Abiam"}
myMap.set(obj, "other")



Dictionary - 
Same as Map. 
Map is prefered for implementation, which on JS there is only
the Map call. 
OOP perspective, dictionary is an abstarct classs, where Map is an interface, and also Dictionary classs is obsolete and map is perfered (JAVA).
Dictionary is a type of Map. Some people say its the same thing (no difference) //you will hear it so that is why I will say it
Implementation - Object or Map


Hastable and HashMap don't' have a specific data structure in JS. You can use arrays, objects,
or maps to implement these if you wanted to. 


//So keys will map to an array of values (which have indicies)

//key           maps 

//John Smith    Hash Function    Will give you the index of array [01]  [01]="value"
//Lisa Smith    Hash Function      [12]				[12]="value"


//Big part of Hastable is for speed (performance). is to get Big O(1) read (lookup)

Hashtable - 
Is a data structure that implements an array. 
Uses a hash functionn to compute an index into an array of buckets or slots which the desired value can be found. You can doo this in JS using an object, or array.
We don't' want to look for every value in the array. Our key will product an index 
and give us the value. 

HashMap - 
Implement this using an Object.
The HashMap classs is roughly equivalent to Hashtable, except that it is non synchronized and permits nulls. 
(HashMap allows null values as key and value whereas Hashtable doesn't allow nulls). '
HashMap does not guarantee that the order of the map will remain constant over time

Hashtable == HashMap + null values + doesn't' guarrentee order will remain constant

let arr = [1000] //use an array

setUpHastable()

getIndex(arr,4)

getIndex(arr,index4) { //hash function
	return val = arr%index*1//some mathematical formula to output value 
}

//instead of doing an
for loop through an array

or
//Why would I need a key to get a value when I can use indexOf

const index = arr.indexOf('John Smith')
//seems like constant time but is not. Way slower than that
//index of the value
//but this is slow
//The array is being re-cast to an object
//From Index is being cast to a Number
//Theyre using Math.max instead of a ternary
//Theyre using Math.abs

//slower and not technically O(1)



Set (WeakSet), Array - storing data or a collection


//All stro
Array - data ordered. Not unique.

let arr = []
let arr = new Array()//has constructor

arr = [1,2,3,4,5,5] 
//1,2,3,4,5,5

Set - unique data. Unlike an array, it does not allow to reorder elements. Keeps the insertion in order. 

let arr = new Set([1,2,3,4,5,5]);
//1,2,3,4,5
let mySet = new Set()

mySet.add(1)
mySet.add(1)
mySet.add(5)

Set vs Array - Set is much better for optimized internally for uniqueness





WeakMap and WeakSet are used as "secondary" data structures in addition to the "main"
object storage. Once the object is removed from the main storage, so it only stays in 
WeakMap/WeakSet, they clean up automatically


WeakMap -
special type of "MAP" that does not prevent JS from removing its items from memory.
Keys must be objects, not primitive types.


WeakSet - 
special type of "SET" that does not prevent JS from removing its items from memory
Only stores object and removes them once they become inaccessible by other means.
Does not support size/clear() and iterations.


Garbage collection perspective
JavaScript engine stores a value in memory while it is reachable (and can potentially be used).


let john = { name: "John" }
let visitCountMap = new Map()

//john is the key for the map
visitsCountMap.set(john,123)

//now john leaves us, 
john = null

console.log( visitisCountMap.size ) //1

...now using weakMap

let john = { name: "John" }
let visitingCountMap = new WeakMap()

visitsCountMap.set(john, 123)

john = null


console.log( visitisCountMap.size ) //0

With a regular Map, cleaning up after a user has left becomes a tedious take
We not only need to remove the user from its main storage (be it a variable or an array)
but also need to clean up the additional sotres like visitCountMap
and it can become cumbersome in more complex cases when a users are managed in one palce of the complicated
and the additional structure is at another place and is getting no informaiotn about removals


WeakMap can make things simpler, because it is cleaned up automatically. The information in it like visits count in the example above lives
only while the key object exists.

WeakSet behaves similarly - 


Map vs WeakMap - Have a Map of an object or elem, if you want to
keep on using the same instances elsewhere use WeakMap so it deletes
all info if the main Map is deleted and doesn't' stay in memory 

WeakMap, WeakSet - Used as "secondary" data structures in addition to the "main" object storage.
Once the object is removed from the main storage, so it only stays in 
WeakMap/WeakSet, they clean up automatically

That is why instead of using multiple Maps use 1 Map and then all weakMap (only for same instance (object))


Compare it with the regular Map example above. Now if john only exists as the key of WeakMap – it is to be automatically deleted


Use weakMap and weakSet if you want JS to remove the reference from memory
after being used. Unlike Map or Set, because JS engine stores a value in memory
while it is reachable (and can potentially be used)




Talk about the array prototype MAP. With Example

//////



The first difference from Map is that its keys must be objects, not primitive values:

let weakMap = new WeakMap();
let obj = {};

weakMap.set(obj, "ok"); // works fine (object key)
weakMap.set("test", "Whoops"); // Error, because "test" is a primitive




WeakMap/WeakSet does not prevent the object removal from the memory.





=============================================

* Object - storing keyed collections. You can add functions, implementation, and conversation
values unlike Map,Set,HashMap,etc
* Arrays - storing ordered collections


HashMap vs HashTable - HashTable is the same as a HashMap but it allows null as key and value
and does not guarantee that the order of the map will remain constant over time. 


============================================================
There is actually two types of map in JS. 
The data structure and the Array prototype map.


Map - Collection of key value pairs. Each possible key appers at least once. Also allows keys
of any type (unlike object). You can even use objects as keys. We can even pass an array with key-value
pairs.

let myMap = new Map()
myMap.set('you', "other");
myMap.get('you')

API
get()
has()
set()
keys()
delete()

e.g. Object as keys

let john = { name: "John" };
let visitsCountMap = new Map();
visitsCountMap.set(john,123);
console.log(visitsCountMap.get(john));//123


e.g. array of key value pairs.

let map = new Map([
	['1', 'str1'],
	[1, 'num1'],
	[true, 'bool1']
])

e.g. or even

let map = new Map(Object.entries({
	name: "John",
	age: 30
}))


e.g. Iterate over map 

API
keys()
values()
entries()

for .. of 

Map also has forEach method, similar to Array

///

Array.prototype.map - creates a new array with the results of calling a provided function
on every element in the calling array 


let array1 = [1, 4, 9, 16];
const map1 = array1.map(x => x * 2);

//map, dictionary, and associative array are the same????

Set - Collection of distinct objects

const set1 = new Set([1, 2, 3, 4, 5]); - collection of distinct objects
console.log(set1.has(1));//true
console.log(set1.has(6));//false

API
add()
delete()
keys()
has()
///


SET - 





