import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

class hashmap {
    public static void main(String[] args){
        // Map<String, String> countryISOCodeMapping = new HashMap<>();

        // countryISOCodeMapping.put("India", "IN");
        // countryISOCodeMapping.put("United States of America", "US");
        // countryISOCodeMapping.put("Russia", "RU");
        // countryISOCodeMapping.put("Japan", "JP");
        // countryISOCodeMapping.put("China", "CN");

        // System.out.println(countryISOCodeMapping);

        // // HashMap's entry set
        // Set<Map.Entry<String, String>> countryISOCodeEntries = countryISOCodeMapping.entrySet();
        // System.out.println(countryISOCodeEntries);

        // // HashMap's key set
        // Set<String> countries = countryISOCodeMapping.keySet();
        // System.out.println(countries);

        // // HashMap's values
        // Collection<String> isoCodes = countryISOCodeMapping.values();
        // System.out.println(isoCodes);
        Set<Integer> numList = new HashSet<>();

        numList.add(2);
        numList.add(13);

        System.out.println(numList.contains(2));

    }
}

/*
Set (interface), HashSet, TreeSet  
Map (interface), HashMap, TreeMap
HashTable 
LinkedHashMap -  will iterate in the order in which the entries were put into the map 

Set, Map. Are interfaces, define how something can be used
Set is the interface HashSet/TreeSet is the implementationd

Visual Representation of HashMap, TreeMap, and LinkedHashMap
https://stackoverflow.com/questions/2889777/difference-between-hashmap-linkedhashmap-and-treemap


Set: A Set is a Collection that cannot contain duplicate elements. It models the mathematical set abstraction.

HashSet: HashSet extends AbstractSet and implements the Set interface. It creates a collection that uses a hash table for storage.

Map: The Map interface maps unique keys to values. A key is an object that you use to retrieve a value at a later date.

HashMap: The HashMap class uses a hashtable to implement the Map interface. This allows the execution time of basic operations, such as get( ) and put( ), to remain constant even for large sets.

TreeSet: TreeSet provides an implementation of the Set interface that uses a tree for storage. Objects are stored in sorted, ascending order. Access and retrieval times are quite fast, which makes TreeSet an excellent choice when storing large amounts of sorted information that must be found quickly.

TreeMap: The TreeMap class implements the Map interface by using a tree. A TreeMap provides an efficient means of storing key/value pairs in sorted order, and allows rapid retrieval. You should note that, unlike a hash map, a tree map guarantees that its elements will be sorted in ascending key order.

For Clarification a hash table: A hash table stores information by using a mechanism called hashing. In hashing, the informational content of a key is used to determine a unique value, called its hash code. The hash code is then used as the index at which the data associated with the key is stored. The transformation of the key into its hash code is performed automatically


==================================================================================

HashMap

A HashMap cannot contain duplicate keys.
Java HashMap allows null values and the null key.
HashMap is an unordered collection. It does not guarantee any specific order of the elements.
Java HashMap is not thread-safe. You must explicitly synchronize concurrent modifications to the HashMap.

CRUD
https://www.callicoder.com/java-hashmap/


CREATE
put(x,y) => key value pair
putIfAbsent(x,y) => key value pair. If key and pair aren't in the hashmap
Put objects in the map (value)

READ
get()

SEARCH / ITERATOR
constainsKey(x) => x(key) returns boolean 
constainsValue(y) => y(value) returns boolean
forEach
Iterator - entry set
for-each
Iterate of HashMap key set


DELETE 
remove(x) => x(key)
remove(x,y) => key value pair. Has to match key and value


OTHER
isEmpty()
size()


===================================================================

https://stackoverflow.com/questions/5139724/whats-the-difference-between-hashset-and-set
A Set represents a generic "set of values". 
A TreeSet is a set where the elements are sorted (and thus ordered)
HashSet is a set where the elements are not sorted or ordered.

A HashSet is typically a lot faster than a TreeSet
A TreeSet is typically implemented as a red-black tree


HashSet

CREATE
add(x) => x(value)
addAll(x) => x(collection)  add all elem from existing collection

READ

DELETE
remove(x) => x(value)
removeAll(w) => w(collection)
removeIf(p) => p (statement)
clear()


SEARCH / ITERATION
contains(x) => x(value) boolean
forEach
Iterator
forEachRemaining
simple for-each

OTHER
isEmpty()  => boolean
size() => number 
*/