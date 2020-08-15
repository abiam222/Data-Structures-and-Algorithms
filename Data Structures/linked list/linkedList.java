import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class linkedList {
    public static void main(String[] args){
        //Created linked list
        LinkedList<String> friends = new LinkedList<>();

        friends.add("Abiam");
        friends.add("John");
        friends.add("David");
        friends.add("Chris");

        friends.add(1, "Nick");
        friends.addFirst("Nate");
        friends.addLast("Naho");

        System.out.println(friends);
    }

}

/*
CRUD

https://www.callicoder.com/java-linkedlist/

CREATE
add(x) => x(value), add(x,y)=> x(index), y(value)
addFirst(x) => x(value) add elem at beginning of LL
addLast(x) => x(value) add elem at end of LL
addAll(x) => x(list collection) add elem of a collection to end of LL 

READ
getFirst()
getLast()
get(x) => x(value) elem at index d

DELETE 
removeFirst()
removeLast()
remove(x) => x(value) first occurence of specified elem x
removeIf(w) based on predicate
e.g.
programmingLanguages.removeIf(programmingLanguage -> programmingLanguage.startsWith("C"));

clear()

SEARCH
contains(x) => x(value) check if LL contains an elem
indexOf(x) => find the index of the first occurrence of an elem in LL
lastIndexOf(x) => x(value) find the index of the last occurrence of an elem in LL


ITERATIONS
iterator()
iterator() and Java 8 forEachRemaining() method
descendingIterator()
listIterator()
simple for-each loop.
*/