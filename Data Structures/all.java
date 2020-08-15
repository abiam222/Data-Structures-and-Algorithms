import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;
import java.util.Collection;
import java.util.Collections;
import java.util.Map;
import java.util.Iterator;
import java.util.Comparator;


static class all {
    public static void main(String[] args){
        //all me = new all();
        arrays();
    }

    public static void arrays() {
    //     int[] A = {1,55,22,13,12};
    //     String B = "me";
         List<Integer> myIntList = new ArrayList<>();//List(ArrayList) doesn't take primitives
        
         myIntList.add(7);
         myIntList.add(4);
         myIntList.add(15);
    //     //add in a particular index
    //     //addAll([add another list of same type])

    //    //Sorting #1
        //Collections.sort(myIntList);
    //    //printArray(myIntList);
         myIntList.sort((x,y) -> x.compareTo(y));

       myIntList.forEach(val -> {
            System.out.println(val);
        });
    }

    public static sets() {
        Set<Integer> numList = new HashSet<>();

        numList.add(2);
        numList.add(13);

        System.out.println(numList.contains(2));
    }

    public static hashmaps() {}
    


    
}

/*
1. Instead of deleting an entry consider overwriting 
2. Know you array libraries

https://www.callicoder.com/java-arraylist/

List 
ArrayList (better than Array) - Dynamically sized collection of elements
Collection - a group of individual objects represented as a single unit.

    * Syntax initialize array
    * Call 2D array
    * Array.length, Collections.size(),String.length(), ArrayList.size()
    * asList, binarySearch, copyOf, copyOfRange, equals, fill, 
    find, sort, toString

List (ArrayList)

CREATE 
addAll(x), x=> ArrayList
add(x) x=> value, 
set(x,y) => x (index), y (value)

READ
get(x) => x (given index)

DELETE
remove(x) => x (index)
remove(x) => x (object)
removeAll() => removes all elem from a collection in ArrayList, removeIf() => remove all elem in collection from Arraylist if match a predicate
clear() => clear ArrayList

ITERATORS / SEARCH 
*Above, Collections and ArrayList
forEach
iterator()
forEachRemaining()
listIterator(), 
for (regular), 
simple for-each

contains(x) => x(value looking) boolean answer
indexOf(x) => x(index) find index of first occurrence of elem in ArrayList, else -1
lastIndex(x) => same above but last occurrence 

iterator and listIterator are useful when you need to modify ArrayList while traversing
I don't think you can modify ArrayList while traversing in others

Other
isEmpty() => boolean, size(),, 
f
 You can even add Objects to ArrayLists

You can sort arraylist one of two ways
 Collections.sort()
 ArrayList.sort() //this has 3 different ways
*You can also sort ArrayList that have objects in them

 */