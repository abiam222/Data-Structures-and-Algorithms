//find missing
main();

function main() {
    let p1 = [4, 12, 9, 5, 6];
    let p2 = [4, 9, 12, 6];

    //find missing (1), but if there is multiple
    //add all values of p1 and subtract by p2 = missing value
    //On+n
    
    //loop over p1 and p2 (since is larger (will always be))
    //but thats O(n^2)

    //loop p1 in a map 4=1,12=1,9=1,5=1,6=1 n
    //loop p2 in map 4=2,9=2,12=2,6=2 n
    //I could probably do 1 loop for both above
    //loop map and whichever has 1 return it n
    //return n

    //put val in sets and substract the two sets 
    let test = new Set(p1);
    let test2 = new Set(p2);
    let final = [...test].filter(x => !test2.has(x));//filter only works in array
    console.log(final)
}

//reverse a string